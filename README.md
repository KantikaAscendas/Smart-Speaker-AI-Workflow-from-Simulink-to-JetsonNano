# Smart Speaker AI Workflow from Simulink to Jetson Nano

This repository documents a demo workflow for deploying a smart speaker model from MATLAB and Simulink to an NVIDIA Jetson Nano.

The demo was originally based on the MathWorks example:

[Deploy Smart Speaker Model on Raspberry Pi](https://in.mathworks.com/help/audio/ug/deploy-smart-speaker-model-on-raspberry-pi.html)

As part of this development work, the original Raspberry Pi workflow was adapted to run on the NVIDIA Jetson Nano platform. The main change is in the deployment stage, where the Simulink hardware target is changed from Raspberry Pi to NVIDIA Jetson.

## Demo Goal

The goal of this demo is to run a real-time voice-command smart speaker model on Jetson Nano. The model recognizes simple speech commands and controls audio playback behavior.

Supported commands include:

- `Go`: start music playback
- `Stop`: stop music playback
- `Up`: increase volume
- `Down`: decrease volume

## Workflow Summary

1. Start from the MathWorks smart speaker workflow for Raspberry Pi.
2. Prepare the Jetson Nano hardware with speaker, microphone, power, and network access.
3. Configure the Jetson Nano connection from MATLAB using the NVIDIA Jetson support package.
4. Open the adapted Simulink model:

   ```text
   Smart-Speaker-AI-Workflow-from-Simulink-to-Jetson-jetson_nano/AudioSmartSpeakerOnJetsonNano.slx
   ```

5. Change the Simulink hardware target to NVIDIA Jetson.
6. Configure deployment settings for the Jetson Nano target.
7. Run the initialization workflow:

   ```text
   Smart-Speaker-AI-Workflow-from-Simulink-to-Jetson-jetson_nano/runThisForJetsonNano.mlx
   ```

8. Deploy the model using Monitor & Tune from Simulink.
9. Test the deployed smart speaker with voice commands and verify the speaker output.

## Repository Contents

- `Smart-Speaker-AI-Workflow-from-Simulink-to-Jetson-jetson_nano/` - adapted Simulink demo files for Jetson Nano
- `AudioSmartSpeakerOnJetsonNano.slx` - main Simulink model
- `runThisForJetsonNano.mlx` - setup and initialization live script
- `AudioSmartSpeakerOnJetsonNano_ert_rtw/` - generated deployment code
- `slprj/` - Simulink generated project/cache artifacts
- `params_2026_05_28__11_21_32.mat` - saved parameter data used by the demo

## Hardware Target Change

The original MathWorks example deploys the smart speaker model to Raspberry Pi. In this adapted version, the deployment workflow targets NVIDIA Jetson Nano instead.

The key deployment changes are:

- Use MATLAB Support Package for NVIDIA Jetson.
- Run `jetsonSetup` to configure the board connection.
- Select NVIDIA Jetson as the target hardware in the Simulink Hardware tab.
- Configure the model for Jetson Nano deployment.
- Use Monitor & Tune to build, deploy, and run the model on the Jetson Nano.

## Detailed Steps

For the full step-by-step setup and screenshots, see:

```text
Smart-Speaker-AI-Workflow-from-Simulink-to-Jetson-jetson_nano/README.md
```

## Reference

- [Deploy Smart Speaker Model on Raspberry Pi - MathWorks Documentation](https://in.mathworks.com/help/audio/ug/deploy-smart-speaker-model-on-raspberry-pi.html)
