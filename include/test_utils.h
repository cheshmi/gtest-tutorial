//
// Created by Kazem on 2024-02-10.
//

#ifndef GTEST_TUTORIAL_TEST_UTILS_H
#define GTEST_TUTORIAL_TEST_UTILS_H

#include <vector>

namespace swiftware {
  namespace teaching {
    void randomVector(int N, std::vector<float> &x);

    void loadVectorFromFile(const std::string &filename, std::vector<float> &x);
  }
}
#endif //GTEST_TUTORIAL_TEST_UTILS_H
