# 🔥 FireSense Rover: Autonomous Fire Detection and Intelligent Environmental Monitoring System

FireSense Rover is an embedded robotics project combining autonomous fire detection, firefighting, and real-time environmental monitoring.

The Arduino Uno section performs fire detection, rover navigation and water-based extinguishing. The ESP32 section monitors temperature, humidity, smoke, gas and air quality.

## Features
- Flame-based fire detection
- Autonomous rover movement
- Automatic water-pump firefighting
- Servo-controlled water spray direction
- Temperature and humidity monitoring
- Smoke and gas monitoring
- Air-quality monitoring
- OLED display

## Hardware
Arduino Uno, ESP32, flame sensor, servo motor, L298N motor driver, DHT11, MQ-2, MQ-135, OLED display, relay module, four-wheel chassis, DC motors, water pump, water tank, batteries, breadboard and jumper wires.

## Software
- Arduino IDE
- Embedded C/C++

## Working
1. Flame sensors detect fire.
2. Arduino Uno processes the detection.
3. The rover moves toward the fire source.
4. The servo aims the water spray.
5. The water pump is activated.
6. ESP32 monitors temperature, humidity, smoke, gas and air quality.
7. Environmental values are displayed on the OLED.

## Repository Structure
```text
FireSense-Rover/
├── README.md
├── LICENSE
├── .gitignore
├── src/
│   ├── arduino_fire_rover.ino
│   └── esp32_environment_monitor.ino
├── docs/
│   ├── PROJECT_DESCRIPTION.md
│   ├── HARDWARE_COMPONENTS.md
│   ├── WORKING_METHODOLOGY.md
│   ├── ADVANTAGES_LIMITATIONS.md
│   ├── APPLICATIONS.md
│   └── REFERENCES.md
└── images/
    └── README.md
```

## Team
- Shreyas N
- Naveen H
- Rahul K
- Vikas K

Guide: Prof. Anupama Hongal, Assistant Professor, ECE Department.

## Safety
This is an educational prototype for controlled testing and small-fire demonstrations. It is not a replacement for professional firefighting equipment or emergency services.
