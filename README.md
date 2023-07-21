# Digital Thermostat

The Digital Thermostat is an Arduino-based project that simulates a thermostat, allowing users to set the desired temperature and control a virtual heating or cooling system accordingly. The thermostat also includes a user-friendly interface with an LCD display and buttons for temperature adjustment.

## Table of Contents

1. [Introduction](#introduction)
2. [Architecture](#architecture)
3. [Design Decisions](#design-decisions)
4. [Requirements](#requirements)
5. [Hardware Setup](#hardware-setup)
6. [Software Setup](#software-setup)
7. [Building and Running the Simulation](#building-and-running-the-simulation)

## Introduction

The Digital Thermostat project aims to provide a cost-effective and user-friendly solution for maintaining the desired temperature in an environment. The thermostat features an Arduino microcontroller, a DS18B20 temperature sensor, an LCD display, and buttons for user interaction. The temperature control algorithm regulates the virtual heating or cooling system to keep the temperature as close to the desired setting as possible.

## Architecture

The architecture of the Digital Thermostat consists of several key components:

1. **Arduino Microcontroller:** The heart of the thermostat is an Arduino board, such as Arduino Uno, responsible for reading temperature data, controlling the virtual heating system, and handling user input.

2. **DS18B20 Temperature Sensor:** This digital temperature sensor is used to measure the current temperature in the environment.

3. **LCD Display:** A 16x2 character LCD display is used to provide real-time feedback to the user, displaying the current temperature, desired temperature, and heating system status.

4. **Buttons:** Three buttons (Up, Down, Confirm) allow the user to interact with the thermostat and adjust the desired temperature.

5. **Heating System:** The heating system is simulated using a relay module connected to the Arduino. The relay turns ON or OFF based on the temperature control logic.

## Design Decisions

1. **Temperature Control Logic:** The control algorithm aims to maintain the temperature as close to the desired setting as possible. When the current temperature is below the desired temperature, the virtual heater (relay) is activated. The heater turns OFF when the current temperature reaches or exceeds the desired temperature.

2. **User Interface:** The LCD display provides essential information to the user, including the current temperature and the desired temperature. Buttons allow the user to increase, decrease, and confirm the desired temperature.

3. **Modularity:** The code is organized into functions for specific tasks, promoting readability, maintainability, and extensibility. Each function handles specific functionalities, such as temperature reading, LCD display, button handling, and temperature control.

## Requirements

To build and run the Digital Thermostat simulation, you will need the following:

### Hardware

- Arduino board (e.g., Arduino Uno).
- DS18B20 temperature sensor.
- 16x2 character LCD display (compatible with I2C interface).
- Three buttons for user interaction.
- Relay module.
- Breadboard and jumper wires.

### Software

- Arduino IDE (https://www.arduino.cc/en/software).
- OneWire library (for DS18B20 temperature sensor).
- DallasTemperature library (for DS18B20 temperature sensor).
- LiquidCrystal_I2C library (for I2C-based LCD display).
- AUnit library (for unit testing - optional).

## Hardware Setup

1. Connect the DS18B20 temperature sensor to the Arduino board:
   - VCC to +5V.
   - GND to GND.
   - DATA to digital pin 2.

2. Connect the I2C-based 16x2 LCD display to the Arduino board:
   - VCC to +5V.
   - GND to GND.
   - SDA to A4 (for I2C communication).
   - SCL to A5 (for I2C communication).

3. Connect the buttons to the Arduino board:
   - "Up" button to digital pin 7.
   - "Down" button to digital pin 8.
   - "Confirm" button to digital pin 9.

4. Connect the relay module to the Arduino board:
   - VCC to +5V.
   - GND to GND.
   - Signal pin to digital pin 10.

## Software Setup

1. Install the required libraries in the Arduino IDE:
   - OneWire library for DS18B20 temperature sensor.
   - DallasTemperature library for DS18B20 temperature sensor.
   - LiquidCrystal_I2C library for the I2C-based LCD display.

2. Download the code files and open the `thermostat.ino` file in the Arduino IDE.

## Building and Running the Simulation

1. Connect the Arduino board to your computer using a USB cable.

2. Upload the code to the Arduino board by clicking on the "Upload" button in the Arduino IDE.

3. After successful upload, open the Serial Monitor to view the temperature readings and test results (if using AUnit library).

4. The LCD display will show the current temperature and the initial desired temperature (25°C).

5. Use the "Up" and "Down" buttons to adjust the desired temperature. Press the "Confirm" button to finalize the new desired temperature.

6. Observe how the virtual heating system (relay) turns ON or OFF based on the temperature control logic to maintain the temperature close to the desired setting.
