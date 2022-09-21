import sensor, image, time

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
sensor.skip_frames(time = 2000)
clock = time.clock()

threshold1 = (50, 80, -128, 2, 2, 82) #green
threshold2 = (70, 95, -38, 102, 62, 112) #yellow
threshold3 = (50, 60, 63, 82, 62, 82) #red

def red():
    print("RED")

def green():
    print("GREEN")

def yellow():
    print("YELLOW")

while(True):
    clock.tick()
    img = sensor.snapshot()
    #shapes = img.find_lines()
    #shapes = img.find_line_segments()
    shapes = img.find_circles()
    for shape in shapes:
        #img.draw_line(shape.line(), color=(255,0,0))
        img.draw_circle(shape.x(), shape.y(), shape.r(), color=(255,0,0))
    print(clock.fps())

threshold1 = (50, 80, -128, 2, 2, 82) #green
threshold2 = (70, 95, -38, 102, 62, 112) #yellow
threshold3 = (50, 60, 63, 82, 62, 82) #red

