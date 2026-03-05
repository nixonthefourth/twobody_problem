"""
plot_orbit.py
Usage: python3 plot_orbit.py <csv_file>

Reads the orbit CSV exported by the C++ Verlet integrator and produces orbit_path.png — XY orbital trajectory
"""

import sys
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load data
if len(sys.argv) < 2:
    print("Usage: python3 plot_orbit.py <csv_file>")
    sys.exit(1)

csv_path = sys.argv[1]
df = pd.read_csv(csv_path)

# Derived columns
df["speed"]  = np.sqrt(df["vx"]**2 + df["vy"]**2)
df["radius"] = np.sqrt(df["x"]**2  + df["y"]**2)

# Orbital trajectory
fig, ax = plt.subplots(figsize=(7, 7))
sc = ax.scatter(df["x"], df["y"], c=df["step"], cmap="plasma", s=4, zorder=2)
ax.plot(0, 0, "y*", markersize=18, label="Star", zorder=3)
ax.plot(df["x"].iloc[0], df["y"].iloc[0], "go", markersize=8, label="Start", zorder=3)
ax.plot(df["x"].iloc[-1], df["y"].iloc[-1], "rs", markersize=8, label="End",   zorder=3)
plt.colorbar(sc, ax=ax, label="Timestep")
ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_title("Orbital Trajectory")
ax.legend()
ax.set_aspect("equal")
ax.grid(True, alpha=0.3)
# Inside the orbital trajectory section, after ax.grid(...)
ax.annotate(
    f"v₀ = {df['speed'].iloc[0]:.4f}",
    xy=(0.02, 0.95),
    xycoords="axes fraction",
    fontsize=10,
    color="white",
    bbox=dict(boxstyle="round,pad=0.3", facecolor="black", alpha=0.5)
)
fig.tight_layout()

fig.savefig("orbit_path.png", dpi=150)
print("Saved orbit_path.png")

plt.show()