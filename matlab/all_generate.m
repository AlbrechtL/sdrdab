% Kwant 21.02.2015
% generate all data for unit test

clear;
close all;
clc;

datadecoder_generateTimeDeInterleaver
datadecoder_generateCRC
datadecoder_generateDepuncturer
dcremoval_data_generator
remodulate
remodulate_data_generator
resampler_linear
resampler_interleaved
fft_engine_unittest_ifft
fft_engine_unittest_vol1
demodulator_deinterleaver_tab
synchronizer_unitest_all
synchronizer_unitest_phase_ref
demodulator_deqpsk
demodulator_frame_pos_fft
demodulator_process
ReedSolomon_DataGeneration
ViterbiDecoder_FIC_MSC
energy_disp_data_generator
MSCDecoder_unittest
FICDecoder_unittest
SuperFrame_unittest
synchronizer_SNR
datadecoder_generateTimeDeInterleaver
datadecoder_generateCRC
datadecoder_generateDepuncturer
dcremoval_data_generator
remodulate
resampler_linear
resampler_interleaved
fft_engine_unittest_ifft
fft_engine_unittest_vol1
demodulator_deinterleaver_tab
synchronizer_unitest_all
synchronizer_unitest_phase_ref
demodulator_deqpsk
demodulator_frame_pos_fft
demodulator_process
ViterbiDecoder_FIC_MSC
ReedSolomon_DataGeneration
energy_disp_data_generator
MSCDecoder_unittest
FICDecoder_unittest
SuperFrame_unittest
demodulator_snr_calc
clc
disp('Matlab finished successfully');



