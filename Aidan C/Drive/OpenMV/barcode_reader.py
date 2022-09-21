# Untitled - By: Aidan Carrier - Tue Jul 9 2019

import sensor, image, time

sensor.reset()
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.VGA)
sensor.set_windowing((640, 80))
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)
clock = time.clock()

while(True):
    clock.tick()
    img = sensor.snapshot()
    codes = img.find_barcodes()
    for code in codes:
        img.draw_rectangle(code.rect())
        print(code.payload())
    #print(clock.fps())
