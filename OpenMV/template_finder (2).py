# Untitled - By: iD Student - Tue Jul 9 2019
import time
from pyb import UART

import sensor, image, time,pyb

uart = UART(3, 9600)
sensor.reset()
sensor.set_contrast(1)
sensor.set_gainceiling(16)
sensor.set_pixformat(sensor.GRAYSCALE)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)

clock = time.clock()
ledRED = pyb.LED(1)
ledGREEN = pyb.LED(2)
ledBLUE = pyb.LED(3)

centerXLoc = 80
centerYLoc = 60

direction = "null"
prev_dir = direction

template = image.Image("/lettertemplate.bmp")
template = template.to_grayscale()
#Kp = 0.5
#drive_speed = 150
while(True):
    #ledRED.on()
    #ledGREEN.on()
    #ledBLUE.on()
    clock.tick()
    prev_dir = direction
    time.sleep(200)
    img = sensor.snapshot()
    #img.draw_cross(centerXLoc, centerYLoc, color = (0,255,255), size = 5)
    match = img.find_template(template, 0.5)
    if match:
        #sensor.set_pixformat(sensor.RGB565)
        ledRED.off()
        ledGREEN.on()

        #cy = match.rect()[1] + int(match.rect()[3]/2)

        #img.draw_cross(cx, cy, color = (255,255, 255), size = 3)
        #rec = img.draw_rectangle(match, color = (0,255,255))
        #rec = rec.find_rects()
        #img.draw_rectangle(rec)
        x = match[0]
        y = match[1]
        w = match[2]
        h = match[3]
        #print(rec.find_rects()[0].rect())
        cy = y + int(h/2)
        cx = x + int(w/2)
        img.draw_line(cx, 0, cx, 120, color =(0,255,255) )
        #img.draw_cross(cx, cy, color = (0,255, 255), size = w)
        #print("Z Dist: %d" %(match.z_translation()))
       # sensor.set_pixformat(sensor.GRAYSCALE)

        #img.draw_string(x, y, "x:%d,y:%d"%(cx, cy), color = (0,255, 255))
        if cx < centerXLoc:
            ledBLUE.on()
            direction = "left"
        else:
            if cx > centerXLoc:
                ledRED.on()
                ledBLUE.off()
                direction = "right"
            else:
                ledBLUE.off()
                ledRED.off()
                direction = "center"

        uart.write(str(cx)+"\n")
        print(cx)
    else:
        ledGREEN.off()
        ledBLUE.off()
        ledRED.on()

        uart.write(str(0) + "\n")
        print(prev_dir)
    #img.draw_string(0, 0, "FPS:%.2f"%(clock.fps()))
    #cx = match.rect()[0] + int(match.rect()[2]/2)
    #cy = match.rect()[1] + int(match.rect()[3]/2)
