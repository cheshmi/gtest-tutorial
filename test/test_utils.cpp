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