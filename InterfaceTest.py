
import serial 

port = str("/dev/tty.usbmodem14201")
baud_rate = 9600
timeout = 0

ser = serial.Serial(port, baud_rate, timeout=0)


while True:
    packet = ser.read()
    lightVal = int(packet)/255 * 1053 #decoding packet into light value
    fan_speed = int(lightVal/1053 * 255) #converting to fan speed; 
    byte_data = int(fan_speed/255 * 253) #converting to data byte 
    new_packet = ser.write(fan_speed)

    



        
    
        
        
    































'''
number: int = input("Enter number: ")
print("New number is", number*2)
'''

