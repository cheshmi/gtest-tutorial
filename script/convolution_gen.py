import scipy
import numpy as np

def convolution_gen(x, h):
    return scipy.signal.convolve(x, h, mode='full')


# main entry point
if __name__ == "__main__":
    # generate a randome input signal x
    x = np.random.rand(100)
    # generate a random impulse response h
    h = np.random.rand(10)
    # perform convolution
    y = convolution_gen(x, h)
    # save the output signal y to a file
    np.savetxt('x.txt', x)
    np.savetxt('h.txt', h)
    np.savetxt('y.txt', y)
