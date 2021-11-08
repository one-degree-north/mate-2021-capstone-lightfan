


from threading import Thread
import serial


class Comms:
    def __init__(self, port, bdrate, timeout):
        self.port = port
        self.bdrate = bdrate
        self.timeout = timeout


    def run():
        packet = ser.read()
        lightVal = int(packet)/255 * 1053 #decoding packet into light value
        fan_speed = int(lightVal/1053 * 255) #converting to fan speed;  
        new_packet = ser.write(fan_speed)


    def start_thread():
        start_thread = Thread(target = run) #initializing the thread 
        start_thread.start()
        start_thread.join()


