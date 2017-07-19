#include "opencv2\opencv.hpp"

using namespace cv;

int main(int arg, char** argc)
{
	Mat tst1 = imread("test.JPG", CV_LOAD_IMAGE_UNCHANGED);
	Mat tst2 = imread("test.JPG", CV_LOAD_IMAGE_GRAYSCALE);

	namedWindow("Color", CV_WINDOW_FREERATIO);
	namedWindow("Fixed", CV_WINDOW_AUTOSIZE);

	imshow("Color", tst1);
	imshow("Fixed", tst2);

	resizeWindow("Color", tst1.cols, tst1.rows);
	resizeWindow("Fixed", tst2.cols/2, tst2.rows/2);

	moveWindow("Color", 1000, 600);
	moveWindow("Fixed", 1000 + tst1.cols, 800);

	waitKey();
}