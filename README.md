# Real-time Weather Data Collection & Analysis (Arduino-based)
This project offers a compact and efficient solution for real-time weather data collection and analysis using an Arduino microcontroller. 
It leverages various sensors to gather environmental parameters and a Wi-Fi module to enable data transmission for further analysis or display.

# Features
* Temperature Monitoring: Accurately measures ambient temperature.
* Humidity Sensing: Collects real-time relative humidity data.
* Rain Detection: Identifies the presence of rain.
* Real-time Data Transmission: Utilizes Wi-Fi for efficient data transfer.
* Compact Design: Built with efficiency and minimal footprint in mind.

# Components Used
Hardware
* Arduino Uno (or compatible board)
* DHT11 Temperature & Humidity Sensor
* LM35 Temperature Sensor
* Rain Sensor Module
* ESP8266 Wi-Fi Module
* Arduino Cable (USB)
* Interfacing Wires / Jumper Wires

Software
*Arduino IDE

# Experimental Setup
The project involves straightforward connections for each sensor to the Arduino board.

LM35 Sensor Connection
The LM35 is an analog temperature sensor.
* VCC: Connect to Arduino 5V.
* OUT (Analog Output): Connect to Arduino A0.
* GND: Connect to Arduino GND.

DHT11 Sensor Connection
The DHT11 is a digital sensor for temperature and humidity.
* Positive Pin: Connect to Arduino 5V.
* Negative Pin: Connect to Arduino GND.
* OUT (Data Pin): Connect to Arduino Digital Pin 2.

Rain Sensor Connection
This sensor detects the presence of water (rain).
* VCC Pin: Connect to Arduino VIN or 5V.
* GND Pin: Connect to Arduino GND.
* AO (Analog Output) Pin: Connect to Arduino A3.

# Block Diagram
The following block diagram illustrates the overall system architecture and connections:
 ![image](https://github.com/user-attachments/assets/db9c9e0c-e925-4fe5-8262-cc64a887d8f1)

# Output & Demonstration
Once the Arduino code is uploaded and the sensors are connected, the system will start collecting and processing weather data.
The output can be viewed through the Arduino IDE's Serial Monitor, or if configured with the ESP8266, sent to a web server or cloud platform.

Here are examples of the serial output displaying the collected weather data:
* This output shows the temperature and humidity readings from the sensors.
* This output provides additional data points, including rain detection and potentially more detailed sensor readings.
![image](https://github.com/user-attachments/assets/89cf288c-d9a2-4547-91ea-e802030be3bd)
![image](https://github.com/user-attachments/assets/92efd4d9-f7e7-4d7a-9482-0c93b55a1e6b)
![image](https://github.com/user-attachments/assets/63492b29-c05b-4101-925d-cb019879ecf5)
