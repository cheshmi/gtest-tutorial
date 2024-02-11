//
// Created by Kazem on 2024-02-10.
//

#include <vector>

#ifndef GTEST_TUTORIAL_SAMPLING_H
#define GTEST_TUTORIAL_SAMPLING_H

namespace swiftware {
  namespace teaching {

    void downSampling(const std::vector<float> &x, std::vector<float> &y, int M);

    void upSampling(const std::vector<float> &x, std::vector<float> &y, int M);

    void resampling(const std::vector<float> &x, std::vector<float> &y, int M, int N);

  }
}
#endif //GTEST_TUTORIAL_SAMPLING_H
