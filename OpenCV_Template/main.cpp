#include "opencv2\opencv.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;

int main(int arg, char** argc)
{
	Mat original = imread("test.JPG", CV_LOAD_IMAGE_COLOR);
	Mat modified = imread("test.JPG", CV_LOAD_IMAGE_COLOR);

	//Iterate through the img. 
	for (int r = 0; r < modified.rows;r++)
	{
		for (int c = 0 ; c < modified.cols; c++)
		{
			//GrayScale Img
			//modified.at<uint8_t>(r, c) = modified.at<uint8_t>(r,c) * 0.5f;

			//Color Img. Vec3b = 3 band, b = byte
			modified.at<cv::Vec3b>(r, c)[2] = modified.at<cv::Vec3b>(r, c)[2] * 0.0f;
		}
	}
	
	imshow("Original", original);
	imshow("Modified", modified);


	waitKey();
}