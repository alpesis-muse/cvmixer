import cv2
import imageio
import itertools
import matplotlib.pyplot as plt
import matplotlib.gridspec as gridspec


METHODS = [("area", cv2.INTER_AREA), 
           ("nearest", cv2.INTER_NEAREST), 
           ("linear", cv2.INTER_LINEAR), 
           ("cubic", cv2.INTER_CUBIC), 
           ("lanczos4", cv2.INTER_LANCZOS4)]


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
    display(images_orig)

    image_set = [[cv2.resize(im, (400, 400), interpolation=m[1]) for m in METHODS] for im in images_orig]
    image_set = [[ima,]+imb for ima, imb in zip(images_orig, image_set)]
    image_set_names = ["original", ] + [m[0] + " 400x400" for m in METHODS]
    display(image_set, image_set_names)

    image_set = [[cv2.resize(im, (20, 20), interpolation=m[1]) for m in METHODS] for im in images_orig]
    image_set = [[ima,]+imb for ima, imb in zip(images_orig, image_set)]
    image_set_names = ["original 400x400", ] + [m[0] + " 20x20" for m in METHODS]
    display(image_set, image_set_names)
