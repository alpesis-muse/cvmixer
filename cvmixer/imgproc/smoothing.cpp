/*
 * Usage:
 *     $ ./path/to/smoothing <img>
 */

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"


int DELAY_CAPTION = 1500;
int DELAY_BLUR = 100;
int MAX_KERNEL_LENGTH = 31;

cv::Mat src;
cv::Mat dst;

char window_name[] = "Filter Demo";

int display_caption (char * caption)
{
  dst = cv::Mat::zeros(src.size(), src.type());
  cv::putText (dst, 
               caption,
               cv::Point(src.cols/4, src.rows/2),
               CV_FONT_HERSHEY_COMPLEX, 1, 
               cv::Scalar(255, 255, 255));
  cv::imshow (window_name, dst);
  int c = cv::waitKey(DELAY_CAPTION);
  if (c >= 0) { return -1; }
  return 0;
}


int display_dst (int delay)
{
  cv::imshow (window_name, dst);
  int c = cv::waitKey(delay);
  if (c >= 0) { return -1; }
  return 0;
}


int main (int argc, char ** argv)
{
  cv::namedWindow (window_name, CV_WINDOW_AUTOSIZE);
  src = cv::imread (argv[1], 1);

  if (display_caption("Original Image") != 0) { return 0; }
  dst = src.clone();
  if (display_dst(DELAY_CAPTION) != 0) { return 0; }

  if (display_caption("Homogeneous Blur") != 0) { return 0; }
  for (int i = 1; i < MAX_KERNEL_LENGTH; i = i+2)
  {
    blur(src, dst, cv::Size(i, i), cv::Point(-1, -1));
    if (display_dst(DELAY_BLUR) != 0) { return 0; }
  }

  if (display_caption("Gaussian Blur") != 0) { return 0; }
  for (int i = 1; i < MAX_KERNEL_LENGTH; i = i+2)
  {
    // src: source image
    // dst: destination image
    // kernel: (kernel.width, kernel.height) the size of the kernel to be used
    // sigma x: the standard deviation in x
    // sigma y: the standard deviation in y
    GaussianBlur(src, dst, cv::Size(i, i), 0, 0);
    if (display_dst(DELAY_BLUR) != 0) { return 0; }
  }

  if (display_caption("Median Blur") != 0) { return 0; }
  for (int i = 1; i < MAX_KERNEL_LENGTH; i = i+2)
  {
    medianBlur(src, dst, i);
    if (display_dst(DELAY_BLUR) != 0) { return 0; }
  }

  if (display_caption("Bilateral Blur") != 0) { return 0; }
  for (int i = 1; i < MAX_KERNEL_LENGTH; i = i+2)
  {
    bilateralFilter(src, dst, i, i*2, i/2);
    if (display_dst(DELAY_BLUR) != 0) { return 0; }
  }

  display_caption("End: Press a key!");
  cv::waitKey(0);

  return 0;
}
