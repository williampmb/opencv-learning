#include "opencv2\opencv.hpp"

using namespace cv;

int main(int arg, char** argc)
{
	Mat test = imread("test.JPG",CV_LOAD_IMAGE_UNCHANGED);
	imshow("tst",test);
	waitKey();
}