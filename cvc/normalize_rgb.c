#include <cv.h>
#include <highgui.h>


/*
 * r' = r / (r+g+b)
 * b' = b / (r+g+b)
 * g' = g / (r+g+b)
 * b' = 1 - r' - g'
 */
IplImage * NormalizeImage(IplImage * image)
{
  IplImage * red = cvCreateImage(cvGetSize(image), 8, 1);
  IplImage * green = cvCreateImage(cvGetSize(image), 8, 1);
  IplImage * blue = cvCreateImage(cvGetSize(image), 8, 1);

  IplImage * red_avg = cvCreateImage(cvGetSize(image), 8, 1);
  IplImage * green_avg = cvCreateImage(cvGetSize(image), 8, 1);
  IplImage * blue_avg = cvCreateImage(cvGetSize(image), 8, 1);

  IplImage * image_avg = cvCreateImage(cvGetSize(image), 8, 3);

  cvSplit(image, blue, green, red, NULL);

  for (int i = 0; i < image->width; i++)
  {
    for (int j = 0; j < image->height; j++)
    {
      int red_value = cvGetReal2D(red, j, i);
      int green_value = cvGetReal2D(green, j, i);
      int blue_value = cvGetReal2D(blue, j, i);
      double sum = red_value + green_value + blue_value;
      cvSetReal2D(red_avg, j, i, red_value/sum*255);
      cvSetReal2D(green_avg, j, i, green_value/sum*255);
      cvSetReal2D(blue_avg, j, i, blue_value/sum*255);
    }
  }

  cvMerge(blue_avg, green_avg, red_avg, NULL, image_avg);

  cvReleaseImage(&red);
  cvReleaseImage(&green);
  cvReleaseImage(&blue);
  cvReleaseImage(&red_avg);
  cvReleaseImage(&green_avg);
  cvReleaseImage(&blue_avg);

  return image_avg;
}


int main(void)
{
  IplImage * image = cvLoadImage("./surfer.jpg", CV_LOAD_IMAGE_COLOR);
  IplImage * image_avg = NormalizeImage(image);

  cvNamedWindow("example", CV_WINDOW_AUTOSIZE);
  cvShowImage("example", image_avg);
  cvWaitKey(0);
  cvDestroyWindow("example");
}
