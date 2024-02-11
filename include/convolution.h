//
// Created by Kazem on 2024-02-10.
//

#ifndef GTEST_TUTORIAL_CONVOLUTION_H
#define GTEST_TUTORIAL_CONVOLUTION_H

#include <vector>

namespace swiftware {
  namespace teaching {
/// convolve array x with filter array h
/// \param x input array
/// \param h filter array
/// \param y output array
/// \param N length of x
/// \param M length of h
    void convolveYHNK(const std::vector<float> &x, const std::vector<float> &h, std::vector<float> &y);

    void convolveYHKN(const std::vector<float> &x, const std::vector<float> &h, std::vector<float> &y);

    void convolve_blocked(const std::vector<float>& x, const std::vector<float>& h, std::vector<float> &y);
  }
}
#endif //GTEST_TUTORIAL_CONVOLUTION_H
