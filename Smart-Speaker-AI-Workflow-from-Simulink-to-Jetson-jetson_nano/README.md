# Audio Smart Speaker on NVIDIA Jetson Nano Using MATLAB & Simulink
> Real-time voice-command audio smart speaker implemented on the NVIDIA Jetson Nano using MATLAB & Simulink, supporting commands such as Go, Stop, Volume Up, and Volume Down with live music output verification.

## Table of Contents
- [Requirements](#-requirements)
- [Hardware Setup](#-hardware-setup)
- [Getting Started](#-getting-started)
- [Running the Demo](#-running-the-demo)
- [Reference](#-reference)

---

## Requirements

| Item | Details |
|------|---------|
| MATLAB Version | R2026a |
| Hardware | NVIDIA Jetson Nano |
| Peripherals | Speaker, Microphone |
| Power Supply | 4A power adapter |
| Network | Ethernet cable (for Wi-Fi sharing) |
| Support Package | MATLAB Support Package for NVIDIA Jetson |

---

## Hardware Setup

### 1. Connect the Power Adapter
Connect the **4A power adapter** to the Jetson Nano to power on the board.

### 2. Connect Speaker and Microphone
Plug the speaker and microphone into the appropriate audio ports on the Jetson Nano.

---

## Getting Started

### 3. Set Up Ethernet Connection
Connect an Ethernet cable between your host PC and the Jetson Nano.

<img width="900" height="467" alt="Ethernet connection setup" src="https://github.com/user-attachments/assets/0c7eea01-c3f1-4070-aa76-bfee0281e526" />

### 4. Enable Wi-Fi Sharing Through Ethernet Port
On your host PC, enable **Internet Connection Sharing** so that the Jetson Nano can access the internet through the Ethernet connection.

<img width="800" height="667" alt="Wi-Fi sharing through Ethernet" src="https://github.com/user-attachments/assets/baf75bbc-3a7f-495d-bbee-d2cff5c71c60" />

> **Windows:** Go to *Network Connections → Wi-Fi Properties → Sharing* and enable sharing to the Ethernet adapter connected to the Jetson Nano.

### 5. Verify Jetson Nano is Reachable
From the host PC terminal, ping the Jetson Nano to confirm it is up and connected on the network:
```bash
ping <jetson-nano-ip-address>
```

<img width="800" height="355" alt="Ping Jetson Nano output" src="https://github.com/user-attachments/assets/4f6d9eca-7e4f-4d6b-b755-10ac270e96b7" />

### 6. SSH into the Jetson Nano
SSH into the Jetson Nano from your host PC:

<img width="800" height="340" alt="SSH into Jetson Nano" src="https://github.com/user-attachments/assets/a145f760-6898-4056-aecf-10aebd9459f2" />

Once connected, verify that the Jetson Nano itself has internet access by pinging an external server:
```bash
ping google.com
```

### 7. Install Required System Library
While still in the SSH session, install the required C library:
```bash
sudo apt-get install -y libc6-dev
```

### 8. Run Jetson Setup in MATLAB
Back on the host PC, run the following command in the MATLAB Command Window and follow the on-screen setup instructions:
```matlab
jetsonSetup
```

<img width="800" height="617" alt="jetsonSetup in MATLAB" src="https://github.com/user-attachments/assets/01223a66-6420-4a34-ad6c-aa25f0f5a338" />

### 9. Open the Simulink Model
Open the primary smart speaker Simulink model:
```
AudioSmartSpeakerOnJetsonNano.slx
```

### 10. Select Target Hardware
In the **Hardware** tab of Simulink, select **NVIDIA Jetson** as the target hardware.

<img width="900" height="177" alt="Select NVIDIA Jetson as target hardware" src="https://github.com/user-attachments/assets/9329dac0-b8eb-4e25-abfb-d546a264331c" />

### 11. Set Code Replacement Library
Open **Model Configuration Parameters** and change the **Code Replacement Library** to:
```
ARM Cortex-A CMSIS
```

<img width="1280" height="796" alt="Code Replacement Library set to ARM Cortex-A CMSIS" src="https://github.com/user-attachments/assets/87939af9-278b-4fb2-a798-c2f8a11b2e61" />

### 12. Verify Manual Switch Directions
In the Simulink model, confirm that all **Manual Switches** are pointing in the correct direction for your configuration before proceeding.

<img width="1280" height="679" alt="Manual switch directions in Simulink model" src="https://github.com/user-attachments/assets/560f9e61-5ef0-4f2e-b61e-5f38f6c70c6f" />

### 13. Run the Initialization Script
Open and run the initialization live script in MATLAB:
```
runThisForJetsonNano.mlx
```

### 14. Verify Initialization Output
Review the output of the script and confirm that all device details (IP address, username, board name, etc.) are correct before proceeding.

<img width="800" height="803" alt="Initialization script output" src="https://github.com/user-attachments/assets/ea510310-24ad-4837-b9be-8cdbddcbbf56" />

---

## Running the Demo

### 15. Monitor & Tune
Return to the Simulink model (`AudioSmartSpeakerOnJetsonNano.slx`) and click **Monitor & Tune** from the **Hardware** tab to deploy and connect to the Jetson Nano in real time.

<img width="900" height="170" alt="Monitor and Tune button in Hardware tab" src="https://github.com/user-attachments/assets/bb179929-226a-453c-9063-f71c888b9275" />

### 16. Test Voice Commands
Once the model is running, issue the following voice commands and verify the corresponding audio output response:

| Command | Expected Behaviour |
|---------|-------------------|
| `Go` | Music playback starts |
| `Stop` | Music playback stops |
| `Up` | Volume increases |
| `Down` | Volume decreases |

Confirm that each command is correctly recognized and that the speaker output reflects the expected response.

---

## Reference

- [Deploy Smart Speaker Model on Raspberry Pi Demo — MathWorks Documentation](https://www.mathworks.com/help/audio/ug/deploy-smart-speaker-model-on-raspberry-pi.html)
