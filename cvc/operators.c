#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

void display_image(char * name, IplImage * image)
{
  cvNamedWindow(name, CV_WINDOW_AUTOSIZE);
  cvShowImage(name, image);
  cvWaitKey(0);

  cvDestroyWindow(name);
}


IplImage * load_image (char * filepath)
{
    if (!filepath)
    {
      printf("File not found at %s\n", filepath);
      exit(-1);
    }

    IplImage * pic = cvLoadImage(filepath, 1);
    return pic;
}

void add_images (IplImage * pic1, IplImage * pic2, IplImage * result)
{
  cvAdd(pic1, pic2, result, NULL);
}


void add_scalar (IplImage * image, CvScalar values)
{
  cvAddS(image, values, image, NULL);
}


int main(int argc, char *argv[])
{
    IplImage * pic1 = load_image(argv[1]);
    IplImage * pic2 = load_image(argv[2]);
    IplImage * result;

    int key = 0;
    CvSize size;
    size = cvGetSize(pic1);
    result = cvCreateImage(size, pic1->depth, pic1->nChannels);
    cvZero(result);
    add_images(pic1, pic2, result);
    printf("image1 (width, height): %d %d\n", pic1->width, pic1->height);
    printf("image2 (width, height): %d %d\n", pic2->width, pic2->height);
    display_image("image1", pic1);
    display_image("image2", pic2);
    display_image("image_add", result);

    CvScalar values;
    values.val[0] = 150;
    values.val[1] = 150;
    values.val[2] = 150;
    add_scalar(pic1, values);
    display_image("image_addS", pic1);
 
    cvReleaseImage(&pic1);
    cvReleaseImage(&pic2);
    cvReleaseImage(&result);
    return 0;
}
