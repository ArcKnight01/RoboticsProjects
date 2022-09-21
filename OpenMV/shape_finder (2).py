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
    lines = img.find_lines(threshold=1500, rho_margin=30, theta_margin=30)
    segs = img.find_line_segments(merge_distance = 5, max_theta_diff = 30)
    circles = img.find_circles(threshold = 3000, x_margin = 30, y_margin = 30)
    rectangles = img.find_rects(threshold = 3000)

    #img.draw_rectangle(5, 5, 150,110, color = (0, 255, 255),thickness= 2)
    for rectangle in rectangles:
        x = rectangle.rect()[0]
        y = rectangle.rect()[1]
        w = rectangle.rect()[2]
        h = rectangle.rect()[3]
        cx = x + int(w/2)
        cy = y + int(h/2)
        crossSize = abs(w - h)
        img.draw_rectangle(rectangle.rect(), color = (0, 255, 255))
        img.draw_cross(cx, cy, color = (0,255, 255), size = 3)
        #img.draw_rectangle(rectangle.x()+ 3,rectangle.y()  +3, rectangle.w()-6, rectangle.h()-6, color = (0, 255, 255), thickness = 1)
    for circleshape in circles:
        img.draw_circle(circleshape.x(), circleshape.y(), circleshape.r(), color=(255, 0, 0))
    for lineShape in segs:
        img.draw_line(lineShape.line(), color=(225, 255, 0))
    img.draw_string(0, 0, "FPS:%.2f"%(clock.fps()))
    #print(clock.fps())
