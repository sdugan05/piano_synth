#include "wavfile.h"
#include <math.h>

class Synth {
    int volume = 1;

    public:
        void sine_wave(int frequency, short* waveform);

        void discrete_fourier_transform(double* in_real, double* in_imag, double* out_real, double* out_imag);
};
