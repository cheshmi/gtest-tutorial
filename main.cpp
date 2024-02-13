//
// Created by Kazem on 2024-02-10.
//

#include <iostream>

#include "convolution.h"
#include "test_utils.h"

void test_ConvWithSmallData() {
  std::vector<float> x = {1, 2, 3, 4, 5};
  std::vector<float> h = {1, 2, 3};
  std::vector<float> y(7);
  std::vector<float> y_correct = {1, 4, 10, 16, 22, 22, 15};
  swiftware::teaching::convolveYHNK(x, h, y);
  for (int n = 0; n < 7; ++n) {
    if(y[n] != y_correct[n]){
      std::cerr << "Error: y[" << n << "] = " << y[n] <<
      " != y_correct[" << n << "] = " << y_correct[n] << std::endl;
    }
  }
  std::cout << "Success!" << std::endl;
}


void test_ConvWithNaive(int N, int M){
  std::vector<float> x(N);
  std::vector<float> h(M);
  std::vector<float> y(N + M - 1);
  for (int n = 0; n < N; ++n) {
    x[n] = n + 1;
  }
  for (int m = 0; m < M; ++m) {
    h[m] = m + 1;
  }
  swiftware::teaching::convolveYHNK(x, h, y);
  std::vector<float> y2(N + M - 1);
  swiftware::teaching::convolveYHKN(x, h, y2);

  for (int n = 0; n < N + M - 1; ++n) {
    if (y[n] != y2[n]) {
      std::cerr << "Error: y[" << n << "] = " << y[n] <<
      " != y2[" << n << "] = " << y2[n] << std::endl;
    }
  }
  std::cout << "Success!" << std::endl;
}


void test_FromFile(const std::string& pathX, const std::string& pathH,
                   const std::string& pathY){
  std::vector<float> x, h, y;
  swiftware::teaching::loadVectorFromFile(pathX, x);
  swiftware::teaching::loadVectorFromFile(pathH, h);
  swiftware::teaching::loadVectorFromFile(pathY, y);
  std::vector<float> y2;
  swiftware::teaching::convolveYHNK(x, h, y2);
  for (int n = 0; n < y.size(); ++n) {
    // floating point comparison
    if (std::abs(y[n]- y2[n]) > 1e-6) { // TODO: Why abs?
      std::cerr << "Error: y[" << n << "] = "
      << y[n] << " != y2[" << n << "] = " << y2[n] << std::endl;
    }
  }
  std::cout << "Success!" << std::endl;
}


// an example of manually testing the code
int main(int argc, char **argv) {

  // test with small data
  test_ConvWithSmallData();

  // test with a naive implementation
  test_ConvWithNaive(10000, 300);

  // test with data from file
  test_FromFile("./script/x.txt", "./script/h.txt", "./script/y.txt");

  std::cout << "All tests done!" << std::endl;


  return 0;
}