%% This Script Initializes Global Parameters used in AudioSmartSpeakerOnRaspberryPi Simulink Model

speechFs = 16000;
musicFs = 44100;

windowDuration = 0.1; % 100 ms
frameLengthSpeech = windowDuration*speechFs;
frameLengthMusic = windowDuration*musicFs;
