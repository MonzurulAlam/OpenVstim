# <P align="center"> OpenVstim - Open Source Transcutaneous Electrical Stimulator 
 
### DEVELOPED BY:
Dr Monzurul Alam <br/>
Profile: https://scholar.google.com.au/citations?user=a2yhqEQAAAAJ&hl=en&oi=ao <br/>
Contact: md.malam@connect.polyu.hk <br/>

### PROJECT OBJECTIVE:
<P align="justify"> The objective of the project was to develop an open-source electrical stimulator for transcutaneous spinal cord stimulation.

### STIMULATOR SPECIFICATIONS:
- Channel: 1 (can be expanded to more channels) <br/>
- Waveform: Biphasic square wave  <br/>
- Pulse Intensity: 0-128 mA peak into 500Ω load <br/>
- Output Voltage: maximum 64V peak-to-peak <br/>
- Pulse duration: 50µs (can be reprogrammed) <br/>
- Interpulse Interval: 1µs (can be reprogrammed) <br/>
- Stimulation Frequency: 20Hz (can be reprogrammed) <br/>
- Carrier Frequency: 10kHz (can be reprogrammed) <br/>
- Power: One 9 V battery <br/>

### DESIGN:
<P align="justify"> Block diagram of the transcutaneous voltage stimulator (OpenVstim) for spinal cord stimulation. The stimulator is built with 3 stand-alone modules, a linear potentiometer and a 9V battery. The potentiometer is used to vary the stimulation intensity as well as power on and off the stimulator.

![Block-Diagram](https://github.com/OpenXStim/openVstim/blob/main/Images/BlockDiagram.png)
 
### Module 1: DC-DC Boost converter (XL6009)
<P align="justify"> Schematic diagram of XL6009 DC-DC boost converter powered by a 9V battery and power switch. The dotted area indicates the off-the-shelf XL6009 module.

![Boost-Converter](https://github.com/OpenXStim/openVstim/blob/main/Images/BoostConverter.png)

**Step 1: Replace the potentiometer of XL6009 DC-DC boost converter module**
<P align="justify"> To have easier access for varying the stimulation intensity and to power on/off the stimulator, on-board trimmer potentiometer (ex. 10kΩ) needed to be replaced with an external linear single gang potentiometer of the same value. For easier prototyping, the on-board trimmer is removed (de-soldered), and 3 pin headers are soldered as shown in the following image.

![XL6009-Module](https://github.com/OpenXStim/openVstim/blob/main/Images/XL6009Module.png)
 
### Module 2: Full H-bridge driver (DRV8871) 
<P align="justify"> Schematic diagram of DRV8871 H-bridge driver controlled by two logic inputs (LOGIC1 and LOGIC2). The stimulation electrodes are connected to the output terminals: OUT1 and OUT2.

![H-Bridge](https://github.com/OpenXStim/openVstim/blob/main/Images/HBridgeDrive.png) 

**Step 2: Solder all components and connections on the Arduino Uno Shield board**
<P align="justify"> To complete the circuit between the XL6009 DC-DC converter, DRV8871 H-bridge driver and the Microcontroller, an Arduino Uno Shield prototyping board is used. Connectors (PCB receptacles), connecting wires, the 10kΩ linear single gang potentiometer with build-in on/off switch and a 9V battery snap are soldered onto the shield board as shown in following image. Since, the Arduino Uno Shield comes with PCB tracks, carefully disconnecting any unwanted track to the modules and connections are needed. The connections were carefully tested for any short-circuits using a multimeter before powering up the board.

![ArduinoUno-Shield](https://github.com/OpenXStim/openVstim/blob/main/Images/ArduinoUnoShield.png)

### Module 3: Microcontroller (Arduino Uno)
<P align="justify"> Two GPIO pins (D9 and D10) of Arduino Uno Microcontroller are used for logic control of the H-bride driver circuit (see DRV8871). The Arduino Uno has also an on-board LED connected to GPIO pin D13.

**Step 3: Program the Arduino Uno Microcontroller to generate biphasic stimulation**
<P align="justify"> To program the Microcontroller, the Arduino Uno board is connected to a PC via an USB cable. After successfully selecting Arduino Uno board from the menu of Arduino IDE, the Microcontroller is programmed for GPIO 9 and 10 to logic control (HIGH/LOW) the DRV8871 H-bridge driver to generate biphasic stimulation. Finally, to visualization that the stimulation is in operation, the Arduino Uno on-board LED (GPIO pin D13) is being toggled. The program runs in a continuous loop until it is powered off. The flushing rates of LED represents the stimulation frequency. 

![Arduino-Uno](https://github.com/OpenXStim/openVstim/blob/main/Images/Flowchart.png) 
 
### Prototype: OpenVstim
<P align="justify">OpenVstim, open-source transcutaneous electrical stimulator with standard EMS/TENS lead wires to connect stimulation electrodes. The linear potentiometer controls the intensity of the stimulation as well as switches on and off the stimulator. A 9V battery is used to power the stimulator.

![Open-V-stim](https://github.com/OpenXStim/openVstim/blob/main/Images/OpenVstim.png) 

<P align="justify">Biphasic stimulation (10kHz burst of 10 biphasic pulses) with maximum peak-to-peak voltage of 64V. 

![Stimulation](https://github.com/OpenXStim/openVstim/blob/main/Images/Stimulation.png) 

### TUTORIALS:
### For more on this, please visit: [OpenXstim](https://www.youtube.com/channel/UCbJmVIHp6DNizZjKjeSPdPg)

### DISCLAIMER:
<P align="justify"> The design is offered as it is. Although it has been regorously tested with utmost care and to the best of my knowledge, I do not provide any warranty in any aspect.

### WARNING:
- The desing is inteded strickly for research and education purpose. 
- The stimulator is not approved for human or animal use without receving prior approval from a local ethics committee such as Institutional Review Board
- The stimulator can generate high voltage and under no circumstances it should be placed across the chest or close to the heart
- The stimulator should never be powered or charged from external adapter, USB or power source while being used or connected to the body.

### LICENSE:
##### Documentation licensed under the Creative Commons Attribution Share Alike 4.0 International License
