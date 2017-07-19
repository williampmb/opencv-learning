#include "opencv2\opencv.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;

int main(int arg, char** argc)
{
	Mat original = imread("test.JPG", CV_LOAD_IMAGE_COLOR);
	
	Mat sptChannels[3];

	split(original, sptChannels);

	sptChannels[2] = Mat::zeros(sptChannels[2].size(), CV_8UC1);

	Mat output;

	merge(sptChannels, 3, output);

	imshow("Merged", output);

	waitKey();
}