# Insurance Quote System – C++ Project

## Description
This terminal-based C++ application simulates an Insurance Quote System. It calculates premium amounts for applicants based on their age and vehicle type. The system demonstrates:

- Use of structs and dynamic memory allocation
- Inheritance and polymorphism via an abstract class
- Basic and premium quote logic
- A clean user input-driven interface


---

## Features
- Define custom age brackets with premiums
- Enter applicant data (VIN, age, vehicle type)
- Calculate both basic and premium quotes
- Loop support for multiple applicants
- Dynamic memory management

---

## How It Works

### Structs:
- `Applicant`: Stores VIN, age, vehicle type
- `Bracket`: Holds age range and premium amount

### Abstract Class:
- `QuoteCalculator`: Defines a standard interface for all calculators

### Derived Classes:
- `BasicCalculator`: Uses base premium by age
- `PremiumCalculator`: Adds extra premium for SUVs and Trucks

---

## How to Run

### Requirements
- Any C++ compiler (supports C++11 or later)

## Sample Interaction
```
Enter number of age brackets: 2
Bracket 1: Min Age, Max Age, Premium: 18 30 250
Bracket 2: Min Age, Max Age, Premium: 31 60 180

Enter Applicant VIN (17 characters): 12345678901234567
Enter Applicant Age: 24
Enter Vehicle Type (Sedan/SUV/Truck): SUV

--- QUOTE RESULTS ---
Basic Policy Quote: RWF 250
Premium Policy Quote: RWF 300
```

---

## Notes
- Input flushing (`cin.ignore`) prevents unexpected loop behavior
- VIN input buffer is sized safely to handle exact input
- Object destruction and memory cleanup are handled at the end

