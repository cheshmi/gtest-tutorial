//
// Created by Kazem on 2024-02-10.
//

#include "convolution.h"

namespace swiftware {
  namespace teaching {


    void convolveYHNK(const std::vector<float>& x, const std::vector<float>& h, std::vector<float> &y) {
      auto M = h.size();
      auto N = x.size();
      y.resize(N + M - 1, 0); // y = zeros(N + M - 1, 1
      for (int n = 0; n < N + M - 1; ++n) {
        for (int k = 0; k < M; ++k) {
          if (n - k >= 0 && n - k < N) {
            y[n] += x[n - k] * h[k];
          }
        }
      }
    }


    void convolveYHKN(const std::vector<float>& x, const std::vector<float>& h, std::vector<float> &y) {
      auto M = h.size();
      auto N = x.size();
      y.resize(N + M - 1, 0); // y = zeros(N + M - 1)
      for (int k = 0; k < M; ++k) {
        for (int n = 0; n < N + M - 1; ++n) {
          if (n - k >= 0 && n - k < N) {
            y[n] += x[n - k] * h[k];
          }
        }
      }
    }

    // TODO: this is placeholder code, replace with your own implementation of blocked convolution
    void convolve_blocked(const std::vector<float>& x, const std::vector<float>& h, std::vector<float> &y) {
      auto M = h.size();
      auto N = x.size();
      y.resize(N + M - 1, 0); // y = zeros(N + M - 1)
      for (int k = 0; k < M; ++k) {
        for (int n = k; n < N - 1; ++n) {
            y[n] += x[n - k] * h[k];
        }
      }
    }

  }
}