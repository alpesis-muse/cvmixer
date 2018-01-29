#include <stdio.h>
#include <cv.h>
#include <highgui.h>

int main(int argc, char * argv[])
{
  IplImage * image = cvLoadImage(argv[1], CV_LOAD_IMAGE_COLOR);
  IplImage * image_resized = cvCreateImage(cvSize(1000, 384), image->depth, image->nChannels);
  cvResize(image, image_resized, CV_INTER_LINEAR);


  FILE * f = fopen("cimage.txt", "wb");
  int i, j;
  for (i = 0; i < image->height; i++)
  {
    uchar * ptr = (uchar*)(image->imageData + i * image->widthStep);
    for (j = 0; j < image->width*3; j++)
    {
      fprintf(f, "%u\n", ptr[j]);
    }
  }
  fclose(f);

  FILE * fr = fopen("cresized.txt", "wb");
  for (i = 0; i < image_resized->height; i++)
  {
    uchar * ptr1 = (uchar*)(image_resized->imageData + i * image_resized->widthStep);
    for (j = 0; j < image_resized->width*3; j++)
    {
      fprintf(fr, "%u\n", ptr1[j]);
    }
  }
  fclose(fr);
}
