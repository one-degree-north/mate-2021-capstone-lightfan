
from time import sleep
from threading import Thread
import serial

class Comms:
    def __init__(self, port, bdrate):
        self.port = port
        self.bdrate = bdrate
        ser = serial.Serial(self.port, self.baud_rate)
        
    def run(self):
        while True:
            packet = ser.read()
            packets = packet.split(chr(127))
            self.photoResistor = packets[0]
            self.rpm = packets[1]
            self.temp = packets[2]
            lightVal = int(photoResistor)/255 * 1053 #decoding packet into light value
            fan_speed = int(lightVal/1053 * 255) #converting to fan speed;  
            new_packet = ser.write(fan_speed)
            sleep(3)

    def start_thread(self):
        start_thread = Thread(target = self.run) #initializing the thread 
        start_thread.start()
        

ob = Comms("/dev/tty.usbmodem14201", 9600)
ob.start_thread()
