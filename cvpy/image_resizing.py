import time

import cv2
import pandas
import imageio
import itertools
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec


METHODS = [("area", cv2.INTER_AREA), 
           ("nearest", cv2.INTER_NEAREST), 
           ("linear", cv2.INTER_LINEAR), 
           ("cubic", cv2.INTER_CUBIC), 
           ("lanczos4", cv2.INTER_LANCZOS4)]


def performance(image):
    data = []

    n = 20
    scale_factors = [0.05, 0.1, 0.3, 0.5, 0.9, 1.1, 1.5, 2, 4, 7, 12]

    for m in METHODS:
        for sf in scale_factors:
            di = []
            for i in range(n):
                t0 = time.time()
                cv2.resize(image, (0,0), fx=sf, fy=sf, interpolation=m[1])
                dt = (time.time()-t0)
                di.append(dt)
            dt = np.mean(di)
            err = 2*np.std(di)
            data.append(dict(time=dt, method=m[0], err=err, scale=sf))

    return pandas.DataFrame(data)


def plot_performance(data):
    g = data.groupby("method")
    plt.figure(figsize=(10,6))
    for n, gi in g:
        plt.plot(gi["scale"], gi["time"], label=n)
    plt.loglog()
    plt.legend()
    plt.xlabel("scale factor")
    plt.ylabel("ave time (sec)")
    plt.title("speed comparison")
    plt.grid(which="both")
    plt.show()


def display(images, titles=['']):

    if isinstance(images[0], list):
        c = len(images[0])
        r = len(images)
        images = list(itertools.chain(*images))
    else:
        c = len(images)
        r = 1

    plt.figure(figsize=(4*c, 4*r))
    gs1 = gridspec.GridSpec(r, c, wspace=0, hspace=0)
    #gs1.update(wspace=0.01, hspace=0.01) # set the spacing between axes. 
    titles = itertools.cycle(titles)
    for i in range(r*c):
        im = images[i]
        title = titles.next()
        plt.subplot(gs1[i])
        # Don't let imshow doe any interpolation
        plt.imshow(im, cmap='gray', interpolation='none')
        plt.axis('off')
        if i < c:
            plt.title(title)

    plt.tight_layout()
    plt.show()


if __name__ == '__main__':

    images = ["../images/Lenna.png"]
    images_orig = [imageio.imread(im) for im in images]
    images_orig = [cv2.resize(im, (100, 100)) for im in images_orig]
    display(images_orig)
    print images_orig[0].shape

    image_set = [[cv2.resize(im, (400, 400), interpolation=m[1]) for m in METHODS] for im in images_orig]
    image_set = [[ima,]+imb for ima, imb in zip(images_orig, image_set)]
    image_set_names = ["original 100x100", ] + [m[0] + " 400x400" for m in METHODS]
    display(image_set, image_set_names)

    image_set = [[cv2.resize(im, (40, 40), interpolation=m[1]) for m in METHODS] for im in images_orig]
    image_set = [[ima,]+imb for ima, imb in zip(images_orig, image_set)]
    image_set_names = ["original 100x100", ] + [m[0] + " 40x40" for m in METHODS]
    display(image_set, image_set_names)

    # times = performance(images_orig[0])
    # plot_performance(times)
