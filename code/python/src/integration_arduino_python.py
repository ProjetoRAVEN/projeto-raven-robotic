import serial
import time 

# Start Serial Communication
serial_one = serial.Serial('/dev/ttyUSB0', 9600) # Switch Serial Port

def send_command(command):
    serial_one.write(command.encode())

send_command('F') # Forward
time.sleep(2) # Wait 2 seconds
send_command('S') # Stop
