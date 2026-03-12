# Two-Body Problem — Gravitational Orbit Simulator

A C++ n-body gravitational simulator using the Velocity Verlet integration method. Simulates a planet orbiting a star, exports trajectory data to CSV, and plots the results via Python.

---

## Prerequisites

| Tool | Version | Purpose |
|------|---------|---------|
| C++ compiler | C++20 or later | Build the simulation (`g++` or `clang++`) |
| CMake | 3.15+ | Build system |
| Python | 3.8+ | Orbit plotting |
| pip packages | — | `pandas`, `matplotlib`, `numpy` |

Install Python dependencies:

```bash
pip install pandas matplotlib numpy
```

---

## Project Structure

```
TwoBody_Problem/
├── docs/
    ├── main.tex
    ├── main.pdf
    ├── figures/
    │   └── problem_setup.png
    └── sections/
        ├── formulae.tex
        ├── problem_setup.tex
        ├── distance.tex
        ├── grav_acceleration.tex
        ├── orbital_velocities.tex
        ├── velocity_direction.tex
        ├── total_energy.tex
        └── verlet.tex
        
│
├── include/
│   ├── Vec2.h
│   ├── stellar_object.h
│   ├── physics.h
│   ├── verlet.h
│   └── world.h
├── src/
│   ├── main.cpp
│   ├── physics.cpp
│   ├── verlet.cpp
│   └── world.cpp
├── scripts/
│   ├── plot_orbit.py
│   └── __init__.py
├── data/                  # auto-created on first run
│   └── orbit_data.csv
└── CMakeLists.txt
```

---

## Build Instructions

### 1. Clone / download the project

```bash
git clone <your-repo-url>
cd TwoBody_Problem
```

### 2. Create the data output directory

```bash
mkdir -p data
```

### 3. Configure with CMake

```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
```

> **Note:** `CMakeLists.txt` must define `PROJECT_ROOT` as a compile definition so the binary can locate the `data/` and `scripts/` directories. Ensure it contains something like:
> ```cmake
> add_compile_definitions(PROJECT_ROOT="${CMAKE_SOURCE_DIR}")
> ```

### 4. Build

```bash
cmake --build build
```

The compiled binary will be placed in `build/` (e.g. `build/TwoBody_Problem`).

---

## Running the Simulation

```bash
./build/TwoBody_Problem
```

The program will:
1. Initialise the star and planet with randomised orbital velocity
2. Run **10,000 Verlet integration steps**
3. Export trajectory data to `data/orbit_data.csv`
4. Automatically invoke the Python plotter

Expected output:

```
Orbit data exported to: /path/to/project/data/orbit_data.csv

Launching Python plotter...
Saved orbit_path.png
```

---

## Running the Python Plotter Manually

If you want to re-plot without rerunning the simulation:

```bash
python3 scripts/plot_orbit.py data/orbit_data.csv
```

This generates `orbit_path.png` in your current working directory showing the orbital trajectory with the star at origin, the planet's start/end positions, and the initial speed annotated.

---

## Bug Fix Note

If you move the star away from the origin `(0, 0)`, make sure `update_acceleration` in `verlet.cpp` uses the **relative displacement** between the planet and the star — not the planet's absolute position. See the fix:

```cpp
// verlet.cpp
Vec2 update_acceleration(float m, float distance, const Vec2& planet_pos, const Vec2& star_pos) {
    return -1.f * (m / pow(distance, 3)) * (planet_pos - star_pos);
}
```

Without this, the planet will fall straight into the star whenever the star is not at the origin.

---

## Configuration

Key simulation parameters are set in `world.cpp`:

| Parameter | Default | Description |
|-----------|---------|-------------|
| Star mass | `1000` | Gravitational source mass |
| Planet mass | `20` | Orbiting body mass (negligible in force calc) |
| Planet start position | `(100, 80)` | Initial XY coordinates |
| Timestep `dt` | `1` | Integration step size |
| Steps | `10000` | Total integration steps |

Initial orbital velocity is randomised between `0.5` and the escape velocity each run.