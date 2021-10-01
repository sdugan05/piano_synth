#include <iostream>
#include "synth.h"
#include <complex>
#include <math.h>

void Synth::sine_wave(int frequency, short* waveform) {
    for (int i = 0; i < WAVFILE_SAMPLES_PER_SECOND; i++) {
        double time = (double)i / WAVFILE_SAMPLES_PER_SECOND;
        double wave = sin(frequency * time * M_PI * 2);
        wave += sin(440 * time * M_PI * 2);
        waveform[i] = wave * volume;
    }
}

void Synth::discrete_fourier_transform(double* in_real, double* in_imag, double* out_real, double* out_imag) {
    // Length of all arrays
    int n = WAVFILE_SAMPLES_PER_SECOND;
    
    // For each output element
    for (int i = 0; i < n; i++) {
        double sum_real;
        double sum_imag;
        // For each input element
        for (int j = 0; j < n; j++) {
            double angle = 2 * M_PI * j * i / n;
            sum_real += in_real[j] * cos(angle) + in_imag[j] * sin(angle);
            sum_imag += -in_real[j] * sin(angle) + in_imag[j] * cos(angle);
        }
        out_real[i] = sum_real;
        out_imag[i] = sum_imag;
    }
}
