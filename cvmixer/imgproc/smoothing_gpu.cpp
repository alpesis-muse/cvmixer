/*
 * Usage:
 *     $ ./path/to/smoothing_gpu <img>
 */

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/gpu/gpu.hpp"


int main (int argc, char ** argv)
{
  cv::Mat img = cv::imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
  cv::Mat img_blurred;

  cv::gpu::GpuMat img_gpu;
  cv::gpu::Stream stream;
  stream.enqueueUpload (img, img_gpu);
  stream.waitForCompletion();

  return 0;
}
