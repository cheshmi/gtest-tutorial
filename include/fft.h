//
// Created by Kazem on 2024-02-13.
//

#ifndef GTEST_TUTORIAL_FFT_H
#define GTEST_TUTORIAL_FFT_H

#include <vector>
#include <complex>

// our beloved PI constant
#define PI 3.14159265358979323846
// points for the Fourier transform
#define NFFT 512

namespace swiftware{
  namespace teaching{

    void compute_twiddles(std::vector<std::complex<float>> &twiddles);
    // FFT based on first principles
    void FFT_recursive(const std::vector<std::complex<float>> &x, \
	std::vector<std::complex<float>> &Xf);


    void DFT(const std::vector<float> &x, std::vector<std::complex<float>> &Xf);


// FFT that leverages precomputation of twiddle factors
    void FFT_improved(const std::vector<std::complex<float>> &x, \
	std::vector<std::complex<float>> &Xf, \
	const std::vector<std::complex<float>> &twiddles, \
	const unsigned char recursion_level);


// in-place computation
    void FFT_optimized(const std::vector<std::complex<float>> &x, \
	std::vector<std::complex<float>> &Xf, \
	const std::vector<std::complex<float>> &twiddles);

  }
}
#endif //GTEST_TUTORIAL_FFT_H
