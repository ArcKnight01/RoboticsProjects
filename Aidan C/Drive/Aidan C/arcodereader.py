# Untitled - By: iD Student - Tue Jul 9 2019

import sensor, image, time, math

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA) #160 center
sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False)
sensor.set_auto_whitebal(False)
clock = time.clock()

while(True):
    clock.tick()
    img = sensor.snapshot()
    tags = img.find_apriltags(families=image.TAG16H5)
    for tag in tags:
        img.draw_rectangle(tag.rect())
        print(tag.rect()[3])
        print("Z Dist: %d" %(tag.z_translation()))



        img.draw_cross(tag.cx(), tag.cy())
        pitch = tag.x_rotation() * 180 / math.pi
        yaw = tag.y_rotation() * 180 / math.pi
        roll = tag.z_rotation() * 180 / math.pi
        print(tag.id())
        print("X (Pitch): %d Y (Yaw): %d Z (Roll): %d" %(pitch, yaw, roll))
        #print(clock.fps())
