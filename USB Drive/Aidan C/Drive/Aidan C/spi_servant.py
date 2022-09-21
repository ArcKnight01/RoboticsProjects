# Untitled - By: iD Student - Tue Jul 9 2019

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
import pyb, ustruct

spi = pyb.SPI(2, pyb.SPI.MASTER, polarity=0, phase=0)
ss_pin = pyb.Pin("P3", pyb.Pin.IN, pull=pyb.Pin.PULL_UP)

message = "Hello!"
packet = ustruct.pack("<BI%ds" % len(message), 170, len(message), message)
print("OpenMV is ready!")

while True:
    while ss_pin.value() == True:
        pass
    try:
        spi.send(packet, timeout=1000)
        print("Sent Data!")
    except OSError as err:
        pass
    while not ss_pin.value():
        pass
