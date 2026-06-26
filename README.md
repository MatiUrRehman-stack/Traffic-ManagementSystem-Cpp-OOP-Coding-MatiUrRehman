# Traffic-ManagementSystem-Cpp-OOP-Coding-MatiUrRehman
Smart Traffic Management System in a futrustic City

# Smart Traffic Signal Management System

## Overview
This repository contains a C++ console application that simulates a Smart Traffic Signal Management System. It was developed to demonstrate core Object-Oriented Programming (OOP) principles, specifically focusing on abstraction, inheritance, and polymorphism. 

## Technical Highlights
* **Abstract Base Classes:** Utilizes a `TrafficSignal` abstract class with pure virtual functions to establish a strict blueprint for all signal types.
* **Inheritance:** Implements specialized derived classes (`VehicleSensorSignal` and `PedestrianSensorSignal`) that inherit protected members and extend base functionality.
* **Polymorphism:** Leverages overridden methods (`displayStatus()`) to dynamically execute the correct behavior based on the object type.
* **Encapsulation:** Protects internal states (like green/red durations and signal IDs) using proper access modifiers (private, protected, public) and getter methods.

## Features
* **Vehicle Sensor Signals:** Tracks vehicle counts and dynamically calculates traffic flow efficiency based on green vs. red light durations.
* **Pedestrian Sensor Signals:** Monitors pedestrian traffic and supports a boolean emergency mode override.
* **Dynamic Status Reporting:** Outputs detailed, formatted reports for any given signal object in the system.

## How to Compile and Run
1. Ensure you have a C++ compiler installed (e.g., GCC, Clang, or MSVC).
2. Clone this repository to your local machine.
3. Open your terminal or command prompt and navigate to the project directory.
4. Compile the source code using the following command:
   `g++ -o TrafficSystem main.cpp`
5. Run the compiled executable:
   * On Windows: `TrafficSystem.exe`
   * On macOS/Linux: `./TrafficSystem`

## Project Context
This project was completed independently as part of the CS304 (Object-Oriented Programming) coursework to solidify foundational software engineering skills in C++.
