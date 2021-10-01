#include "synth.h"
#include <iostream>

int length = WAVFILE_SAMPLES_PER_SECOND;

int main() {
    short waveform[length];

    Synth* main_synth = new Synth;
    main_synth->sine_wave(262, waveform);

    double waveform_d[length];

    double out_r[length];
    double out_i[length];

    for(int i = 0; i < length; i++) {
        waveform_d[i] = waveform[i];
    }

    main_synth->discrete_fourier_transform(waveform_d, waveform_d, out_r, out_i);

    // Write file
    FILE *f = wavfile_open("output.wav");
    wavfile_write(f, (short*)out_r, length);
    wavfile_close(f);

    return 0;
}
