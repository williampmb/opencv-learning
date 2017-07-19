#include "opencv2\opencv.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;

void takeDFT(Mat& source, Mat& dest)
{
	Mat originalComplex[2] = { source, Mat::zeros(source.size(), CV_32F) };

	Mat dftReady;

	merge(originalComplex, 2, dftReady);

	Mat dftOfOriginal;

	dft(dftReady, dftOfOriginal, DFT_COMPLEX_OUTPUT);

	dest = dftOfOriginal;
}

void showDFT(Mat& source)
{
	Mat splitArray[2] = { Mat::zeros(source.size(),CV_32F), Mat::zeros(source.size(),CV_32F) };

	split(source, splitArray);

	Mat dftMagnitude;

	magnitude(splitArray[0], splitArray[1], dftMagnitude);

	dftMagnitude += Scalar::all(1);

	log(dftMagnitude, dftMagnitude);

	normalize(dftMagnitude, dftMagnitude, 0, 1, CV_MINMAX);

	imshow("DFT", dftMagnitude);

	waitKey();
}

int main(int arg, char** argc)
{
	Mat original = imread("test.JPG", CV_LOAD_IMAGE_GRAYSCALE);

	Mat originalFloat;

	// 1/255 = normalized
	original.convertTo(originalFloat, CV_32FC1, 1.0 / 255.0);

	Mat dftOfOriginal;

	takeDFT(originalFloat, dftOfOriginal);

	showDFT(dftOfOriginal);
}