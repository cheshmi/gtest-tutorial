//
// Created by Kazem on 2024-02-10.
//


#include "sampling.h"

#include <vector>
#include "gtest/gtest.h"


namespace swiftware {
  namespace teaching {

    TEST(UpSamplingTest, SmallTest) {
      std::vector<float> x = {1, 2, 3, 4};
      std::vector<float> y(8);
      upSampling(x, y, 2);
      std::vector<float> expected = {1, 0, 2, 0, 3, 0, 4, 0};
      ASSERT_EQ(y, expected);
    }

    // TODO: add more tests for upSampling and DownSampling
    TEST(ResamplingTest, SmallTest) {
      std::vector<float> x = {1, 2, 3, 4};
      std::vector<float> y1(2), y2(8), y(8);
      downSampling(x, y1, 2);
      upSampling(y1, y2, 4);

      // TODO: call resampling function and set the expected value
      resampling(x, y, 2, 4);
      std::vector<float> expected = {0, 0, 0, 0, 0, 0, 0, 0};
      ASSERT_EQ(y, expected);
    }


  }
}
