import serial
import time
import csv
import matplotlib
matplotlib.use("tkAgg")
import matplotlib.pyplot as plt
import numpy as np

ser = serial.Serial('/dev/ttyACM0')
ser.flushInput()
plot_window = 20
y_var = np.array(np.zeros([plot_window]))
x_var = np.array(np.zeros([plot_window]))
hel=0
plt.ion()
fig, ax = plt.subplots()
line, = ax.plot(x_var,y_var)
while True:
    try:
        ser_bytes = ser.readline()
        try:
            decoded_bytes = float(ser_bytes[0:len(ser_bytes)-2].decode("utf-8"))
            print(decoded_bytes)
        except:
            continue
        with open("test_data.csv","a") as f:
            writer = csv.writer(f,delimiter=",")
            writer.writerow([time.ctime(),hel,decoded_bytes])
        y_var = np.append(y_var,decoded_bytes)
        y_var = y_var[1:plot_window+1]
        line.set_ydata(y_var)
        x_var = np.append(x_var,hel)
        x_var = x_var[1:plot_window+1]
        line.set_xdata(x_var)
        ax.relim()
        ax.autoscale_view()
        fig.canvas.draw()
        fig.canvas.flush_events()
        hel=hel+2
        if(hel-2==60):
            plt.savefig("Graph.png")
            break
    except Exception as e:
        print("Exception : ",str(e))
        break
