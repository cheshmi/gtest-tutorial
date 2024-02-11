//
// Created by Kazem on 2024-02-10.
//

#include <gtest/gtest.h>
#include "convolution.h"
#include "test_utils.h"

namespace swiftware {
  namespace teaching {

    TEST(ConvTest, SmallTest){
      std::vector<float> x = {1, 2, 3, 4, 5};
      std::vector<float> h = {1, 2, 3};
      std::vector<float> y;
      convolveYHNK(x, h, y);
      std::vector<float> y1 = {1, 4, 10, 16, 22, 22, 15};
      for (int i = 0; i < y.size(); ++i) {
        EXPECT_EQ(y[i], y1[i]);
      }
    }

    TEST(ConvTest, WithNaive){
      std::vector<float> x = {1, 2, 3, 4, 5};
      std::vector<float> h = {1, 2, 3};
      std::vector<float> y, y2;
      convolveYHNK(x, h, y);
      convolveYHKN(x, h, y2);
      for (int i = 0; i < y.size(); ++i) {
        EXPECT_EQ(y[i], y2[i]);
      }
    }

   TEST(ConvTest, RandomTest){
      // TODO : make this test more comprehensive
      const int N = 10000;
      const int M = 300;
      std::vector<float> x(N);
      std::vector<float> h(M);
      randomVector(N, x);
      randomVector(M, h);
      std::vector<float> y, y2;
      convolveYHNK(x, h, y);
      convolveYHKN(x, h, y2);
      for (int n = 0; n < N + M - 1; ++n) {
        EXPECT_EQ(y[n], y2[n]);
      }
    }

    TEST(ConvTest, FromFile){
      std::vector<float> x, h, y;
      loadVectorFromFile("./script/x.txt", x);
      loadVectorFromFile("./script/h.txt", h);
      loadVectorFromFile("./script/y.txt", y);
      std::vector<float> y2;
      convolveYHNK(x, h, y2);
      for (int n = 0; n < y.size(); ++n) {
        // floating point comparison
        EXPECT_NEAR(y[n], y2[n], 1e-6);
      }
    }

   TEST(BlockConvTest, WithNaive){
      const int N = 1000;
      const int M = 3;
      std::vector<float> x(N);
      std::vector<float> h(M);
      randomVector(N, x);
      randomVector(M, h);
      std::vector<float> y, y2;
      convolveYHNK(x, h, y);
      // TODO: create blocks
      // TODO: For each block, call convolve_blocked and pass states
      // TODO: you might need to change the prototype of convolve_blocked
      convolve_blocked(x, h, y2);
      for (int n = 0; n < N + M - 1; ++n) {
        EXPECT_EQ(y[n], y2[n]);
      }
    }

    // TODO: add more tests for convolve_blocked




  }
}


