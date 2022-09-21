# Untitled - By: iD Student - Tue Jul 9 2019

import sensor, image, time

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)

clock = time.clock()

while(True):
    clock.tick()
    img = sensor.snapshot()
    #shapes = img.find_lines(threshold=1500, rho_margin=30, theta_margin=30)
    #shapes = img.find_line_segments(merge_distance = 5, max_theta_diff = 30)
    #shapes = img.find_circles(threshold = 3000, x_margin = 30, y_margin = 30)
    shapes = img.find_rects(threshold = 3000)

    for shape in shapes:
        #img.draw_circle(shape.x(), shape.y(), shape.r(), color=(255, 0, 0))
        img.draw_rectangle(shape.rect(), color = (0, 255, 255))
        img.draw_rectangle(shape.x()+ 3,shape.y()  +3, shape.w()-6, shape.h()-6, color = (0, 255, 255), thickness = 2)
        #img.draw_line(shape.line(), color=(0, 255, 255))
    #print(clock.fps())
