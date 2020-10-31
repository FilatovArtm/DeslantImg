#ifdef USE_GPU
#include "DeslantImgGPU.hpp"
#else
#include "DeslantImgCPU.hpp"
#endif
#include <opencv2/imgcodecs.hpp>
#include <iostream>


int main(int argc, char *argv[]) 
{
	const cv::Mat img = cv::imread(argv[0], cv::IMREAD_GRAYSCALE);
	
	
#ifdef USE_GPU 
	// deslant on GPU
	htr::CLWrapper clWrapper; // setup OpenCL, the same instance should be used for all following calls to deslantImg
	const cv::Mat res1 = htr::deslantImg(img, 255, clWrapper);
#else
	// deslant on CPU
	cv::Mat res1 = htr::deslantImg(img, 255);
#endif

	// write results to file
	cv::imwrite(argv[1], res1);

	return 0;
}

