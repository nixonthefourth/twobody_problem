# Two-Body Problem
## About
This project explores ideas of Isaac Newton regarding orbital mechanics and laws of gravitational attraction.
Using prior calculations and concluding thsoe findings I decided to set these ideas in stone by developing a simple physics engine that handles vector calculus, orbital physics and symplectic integrators for a consistent system update.

## Units and Scaling
This simulation uses normalized (non-dimensional) units for demonstration purposes.
The gravitational constant is set to `G = 1`, meaning mass, distance, velocity, acceleration, and energy are expressed in relative simulation units rather than real-world SI units.
All physical quantities are internally consistent within this scaled system.

## Project Structure
```
/ include
    | physics.h
    | stellar_object.h
    | Vec2.h
/ src
    | main.cpp
    | physics.cpp
```