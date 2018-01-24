/*
 * Usage:
 *     $ ./path/to/smoothing_gpu <img>
 */

#include <iostream>

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

  cv::gpu::GpuMat img_gpu_blurred (img_gpu.size(), img_gpu.type());

  int64 tick_count;
  for (int i = 0; i < 5; i++)
  {
    tick_count = cv::getTickCount();
    cv::blur (img, img_blurred, cv::Size(7, 7));
    std::cout << "CPU Blur: " << (cv::getTickCount() - tick_count) / cv::getTickFrequency() << std::endl;

    tick_count = cv::getTickCount();
    //cv::gpu::blur (img_gpu, img_gpu_blurred, cv::Size(7,7), cv::Point(-1, -1), stream);
    cv::gpu::GaussianBlur(img_gpu, img_gpu_blurred, cv::Size(7,7), 0);
    stream.waitForCompletion();
    std::cout << "GPU Blur: " << (cv::getTickCount() - tick_count) / cv::getTickFrequency() << std::endl;
  }

  std::cin.get();

  return 0;
}
