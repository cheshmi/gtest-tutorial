//
// Created by Kazem on 2024-02-10.
//

#include <vector>

namespace swiftware {
  namespace teaching {

    void downSampling(const std::vector<float> &x, std::vector<float> &y, int M) {
      auto N = x.size();
      for (int n = 0; n < N; ++n) {
        if (n % M == 0) {
          y[n / M] = x[n];
        }
      }
    }

    void upSampling(const std::vector<float> &x, std::vector<float> &y, int M) {
      auto N = x.size();
      for (int n = 0; n < N; ++n) {
        y[n * M] = x[n];
      }
    }

    // TODO: this is placeholder code, replace with your own implementation of resampling
    void resampling(const std::vector<float> &x, std::vector<float> &y, int M, int N) {
      for (int n = 0; n < N; ++n) {
        y[n * M] = x[n];
      }
    }

  }
}