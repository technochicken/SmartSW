# **SmartSW Documentation**

## **Scope**

**SmartSW** aims to provide DIY users with an easy and affordable solution for integrating multiple buttons with RGB backlighting. The switches are high-quality components designed for long-lasting applications, such as custom keyboards or control panels.

### **Requirements**:
- **1 PWM-capable pin** (for LED data control)
- **1 digital input-capable pin** (for each button)

### **Required Skills**:
- **Soldering**: Each button requires at least 6 solder points. These are low-difficulty but essential to complete the assembly.  
- **Programming**: To make the buttons light up, they must be interfaced with a microcontroller. A library simplifies this process.

---

## **Hardware**

### **SmartSW PCB**  
Purchase here: [eBay Link](https://www.ebay.de/itm/205130755097?mkcid=16&mkevt=1&mkrid=707-127634-2357-0&ssspo=DCpCBO_ISs2&sssrc=2047675&ssuid=DCpCBO_ISs2&widget_ver=artemis&media=COPY)  

### **Switches**  
Compatible CHERRY MX LOW Profile (RED or Silver):  
- **Amazon (Silver)**: [Link](https://amzn.eu/d/hpOrOGs)  
- **eBay (Universal)**: [Link](https://www.ebay.de/itm/387603163067?mkcid=16&mkevt=1&mkrid=707-127634-2357-0&ssspo=2scbnajzsgs&sssrc=2047675&ssuid=DCpCBO_ISs2&var=654848712781&widget_ver=artemis&media=COPY)  

### **Keycaps**  
3D print translucent keycaps. Recommended models available here: [Thingiverse Link](https://www.thingiverse.com/thing:6646520).  

---

## **SmartSW PCB Details**

### **Pinout**:
- **DI**: Data input for LED control  
- **DO**: Data output to the next PCB (for daisy-chaining)  
- **SW**: Button output. Outputs **5V** when released, and **0V** when pressed (internally pulled up with a 4.7kΩ resistor).

### **Notes**:
- PCB supports up to **200 switches** in series with **5V and GND passthrough**.  
- Connect **DI** to the microcontroller via a **500Ω resistor**.

---

## **Setup Instructions**

1. **Connect the Microcontroller**:  
   - Use a microcontroller (e.g., Arduino Pro Micro).  
   - Connect the **PWM pin** to the **DI** of your PCB.  
   - Ensure the power is unplugged before making connections.  
   - Connect **GND** and **5V** from the microcontroller to the PCB.  
   - Connect the **SW** pin to a GPIO pin of the microcontroller.

2. **Test the Setup**:  
   - Load the `BasicTest.ino` sketch.  
   - Define the **LED OUT pin** and **SW pin** in the code.  
   - Upload and start the program.

---

## **Panel Mounting**

1. **Panel Preparation**:  
   - Cut **rectangular holes (14x14mm)** with ±0.05mm tolerance.  
   - Use a panel with a thickness of **1.5mm** ±0.07mm.
   - this can also be 3d Printed

2. **Switch Installation**:  
   - Insert unsoldered **Cherry MX switches** into the panel.  

3. **Mounting PCB**:  
   - Position the **SmartSW PCB** on the opposite side, ensuring components face the switch.  
   - Align the through-hole pins of the switches with the PCB.  

4. **Soldering**:  
   - Solder the pins to the PCB.  
   - **Ensure no solder bridges** occur between the points.  

--- 

Enjoy building your custom setup with **SmartSW**!
