import numpy as np
import matplotlib.pyplot as plt
import serial
import serial.tools.list_ports as comports
import time

# -------------------------------
# Serial Port Setup
# -------------------------------

def find_arduino_port():
    ports = comports.comports()
    for port in ports:
        if "Arduino" in port.description or "USB" in port.description:
            return port.device
    return None

port_name = find_arduino_port()
if not port_name:
    raise Exception("No Arduino found. Please check connection.")

# Open serial port
ser = serial.Serial(port_name, 115200, timeout=1)
time.sleep(2)  # wait for Arduino reset

print(f"Connected to Arduino on {port_name}")

# -------------------------------
# Radar Plot Setup
# -------------------------------

plt.ion()  # Interactive mode
fig = plt.figure(figsize=(8,5), facecolor='k')
ax = fig.add_subplot(111, polar=True, facecolor='#003300')

r_max = 100.0  # max distance (cm)
ax.set_ylim(0, r_max)
ax.set_xlim(0, np.pi)  # 180 degrees
ax.set_facecolor('#003300')
ax.grid(color='w', alpha=0.3)
ax.set_rticks(np.linspace(0, r_max, 5))
ax.set_thetagrids(np.linspace(0,180,10))
ax.tick_params(colors='w')

# Initial dummy data
angles = np.arange(0,181,1)
theta = np.deg2rad(angles)
dists = np.zeros_like(theta)

# Radar points and sweep line
points_plot, = ax.plot([], [], linestyle='', marker='o', color='red', markersize=6, alpha=0.8)
sweep_line, = ax.plot([], [], color='lime', linewidth=2)

fig.canvas.manager.set_window_title('Arduino Radar')

# -------------------------------
# Read & Update Loop
# -------------------------------

start_word = False

try:
    while True:
        try:
            line = ser.readline().decode('utf-8').strip()
            if not line:
                continue

            # Wait for Arduino to send start signal
            if not start_word:
                if line == "Radar Start":
                    start_word = True
                    print("Radar Starting...")
                continue

            # Parse angle,distance
            parts = line.split(',')
            if len(parts) != 2:
                continue

            angle, dist = float(parts[0]), float(parts[1])
            if dist > r_max:
                dist = 0.0  # ignore out-of-range
            dists[int(angle)] = dist

            # Update plot every 5°
            if int(angle) % 5 == 0:
                points_plot.set_data(theta, dists)
                sweep_line.set_data([np.deg2rad(angle)]*2, [0, r_max])
                fig.canvas.draw()
                plt.pause(0.001)  # small pause for GUI refresh

        except KeyboardInterrupt:
            print("Exiting...")
            break

except Exception as e:
    print("Error:", e)

finally:
    ser.close()
    plt.ioff()
    plt.show()
