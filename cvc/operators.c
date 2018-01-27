#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

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

void display_image(char * name, IplImage * image)
{
  cvNamedWindow(name, CV_WINDOW_AUTOSIZE);
  cvShowImage(name, image);
  cvWaitKey(0);

  cvDestroyWindow(name);
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
    display_image("image_add", result);
 
    cvReleaseImage(&pic1);
    cvReleaseImage(&pic2);
    cvReleaseImage(&result);
    return 0;
}
