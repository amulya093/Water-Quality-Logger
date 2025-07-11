#  Water Quality Logger

This is a simple **C++ simulation project** that generates and logs water quality data to a CSV file.

###  Simulated Parameters:
- pH value
- Turbidity (NTU)
- Temperature (°C)

###  Output Format
- Time,pH,Turbidity,Temperature
- 2025-07-11 20:45:00,7.1,2.3,25.8
- 2025-07-11 20:45:02,6.3,4.5,21.1

###  How to Run

g++ main.cpp -o water_logger.exe
./water_logger.exe

###  Technologies Used 
- C++ (File I/O, Random, Thread, Chrono)
- CSV file generation
- Console-based simulation