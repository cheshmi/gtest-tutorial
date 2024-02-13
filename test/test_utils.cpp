//
// Created by Kazem on 2024-02-10.
//

#include <vector>
#include <fstream>
#include <cstdlib>

namespace swiftware {
  namespace teaching {

    void randomVector(int N, std::vector<float> &x) {
      x.resize(N);
      for (int i = 0; i < N; ++i) {
        x[i] = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
      }
    }

    void generateRandomSamples(std::vector<float> &x,
	unsigned int N, unsigned short int max, unsigned char precision)
    {
      x.clear(); x.resize(N);
      int int_radom_max = 2*(max * static_cast<int>(pow(10,precision)));
      for (int i = 0; i < (int)x.size(); i++) {
        x[i] = (static_cast<float>(std::rand() % int_radom_max));
        x[i] = (x[i] - (int_radom_max/2))/pow(10,precision);
      }
    }

    void loadVectorFromFile(const std::string &filename, std::vector<float> &x) {
      std::ifstream file(filename);
      if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
          x.push_back(std::stof(line));
        }
        file.close();
      }
    }

  }
}