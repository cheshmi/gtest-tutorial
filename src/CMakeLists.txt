
# making a static library
project(swift_dsp)
set(SOURCES
convolution.cpp
sampling.cpp
        fft.cpp
)
add_library( ${PROJECT_NAME} STATIC ${SOURCES} )
