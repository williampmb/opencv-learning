#include "opencv2\opencv.hpp"

using namespace cv;

int main(int arg, char** argc)
{
	Mat test = imread("test.JPG",CV_LOAD_IMAGE_COLOR);
	Mat tstGray = imread("test.JPG", CV_LOAD_IMAGE_GRAYSCALE);
	
	imshow("tst", test);
	imshow("gray", tstGray);

	imwrite("outputGray.jpg", tstGray);

	waitKey();
}