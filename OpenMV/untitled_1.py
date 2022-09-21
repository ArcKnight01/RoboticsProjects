# Untitled - By: iD Student - Mon Jul 8 2019

import sensor, image, time

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
#sensor.set_auto_gain(False)
#sensor.set_auto_whitebal(False)

clock = time.clock()

def update_clock(clock):
    clock.tick()
    print(clock.fps())

while(True):

    img = sensor.snapshot()
    update_clock(clock)
