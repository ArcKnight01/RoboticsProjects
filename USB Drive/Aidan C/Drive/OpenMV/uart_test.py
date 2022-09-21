## Untitled - By: iD Student - Mon Jul 8 2019

#import sensor, image, time

#sensor.reset()
#sensor.set_pixformat(sensor.RGB565)
#sensor.set_framesize(sensor.QVGA)
#sensor.skip_frames(time = 2000)

#clock = time.clock()

#while(True):
    #clock.tick()
    #img = sensor.snapshot()
    #print(clock.fps())


import time
from pyb import UART

uart = UART(3, 9600)

while True:
    # For sending messages
    uart.write("Hello!\n")
    time.sleep(1000)
    # For receiving messages
    #test_string = uart.readline().decode()
    #print(test_string)
