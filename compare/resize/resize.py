import cv2

if __name__ == '__main__':

    image = cv2.imread("<your_image>")
    image_resized = cv2.resize(image, None, None, 3.69003690037, 3.69003690037, interpolation=cv2.INTER_LINEAR)
    f1 = open("resized.txt", "wb")
    for rgb in image_resized:
        for values in rgb:
            for value in values: f1.write("{0}\n".format(value))

    f = open("pyimage.txt", "wb")
    for rgb in image:
        for values in rgb:
            for value in values: f.write("{0}\n".format(value))
