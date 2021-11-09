from threading import Thread
import serial

class Comms:
    def __init__(self, port, baud_rate):
        self.port = port
        self.baud_rate = baud_rate
        ser = serial.Serial(self.port, self.baud_rate)
        self.ser.close()
        self.ser.open()
        
    def run(self):
        while True:
            packet = ser.read()
            packets = packet.split(chr(127))
            self.photoResistor = packets[0]
            self.rpm = packets[1]
            self.temp = packets[2]
            lightVal = int(photoResistor)/255 * 1053 
            fan_speed = int(lightVal/1053 * 255)   
            new_packet = ser.write(fan_speed)

    def start_thread(self):
        start_thread = Thread(target = self.run) #initializing the thread 
        start_thread.start()
        

ob = Comms("/dev/tty.usbmodem14201", 9600)
ob.start_thread()



