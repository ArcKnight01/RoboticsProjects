# Untitled - By: iD Student - Wed Jul 10 2019

import sensor, image, time
import pyb

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QQVGA)
sensor.skip_frames(time = 2000)
clock = time.clock()

img_writer = image.ImageWriter("/test.bin")
print("Recording started")
start = pyb.millis()

while pyb.elapsed_millis(start) < 5000:
    clock.tick()
    img = sensor.snapshot()
    img_writer.add_frame(img)

img_writer.close()
print("Recording finished")

img_reader = image.ImageReader("/test.bin")

while True:
    img = img_reader.next_frame(copy_to_fb=True, loop=True)
