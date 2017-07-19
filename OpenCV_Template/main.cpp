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

void recenterDFT(Mat& source)
{
	int centerX = source.cols / 2;
	int centerY = source.rows / 2;

	Mat q1(source, Rect(0, 0, centerX, centerY));
	Mat q2(source, Rect(centerX, 0, centerX, centerY));
	Mat q3(source, Rect(0, centerY, centerX, centerY));
	Mat q4(source, Rect(centerX, centerY, centerX, centerY));

	Mat swapMap;

	q1.copyTo(swapMap);
	q4.copyTo(q1);
	swapMap.copyTo(q4);

	q2.copyTo(swapMap);
	q3.copyTo(q2);
	swapMap.copyTo(q3);

}

void showDFT(Mat& source)
{
	Mat splitArray[2] = { Mat::zeros(source.size(),CV_32F), Mat::zeros(source.size(),CV_32F) };

	//Split the real and imaginary part  
	split(source, splitArray);

	Mat dftMagnitude;

	magnitude(splitArray[0], splitArray[1], dftMagnitude);

	dftMagnitude += Scalar::all(1);

	log(dftMagnitude, dftMagnitude);

	normalize(dftMagnitude, dftMagnitude, 0, 1, CV_MINMAX);

	recenterDFT(dftMagnitude);

	imshow("DFT", dftMagnitude);

	waitKey();
}

void invertDFT(Mat& source, Mat& dest)
{
	Mat inverse;

	// DFT_INVERSE = inverse of the dft processe,  DFT_REAL_OUTPUT = just the real part of the img, not imaginary. DFT_SCALE = rescale in rge to make sense
	dft(source, inverse, DFT_INVERSE | DFT_REAL_OUTPUT | DFT_SCALE);

	dest = inverse;

}

void createGuassian(Size& size, Mat& output, int uX, int uY, float sigmaX, float sigmaY, float amplitude = 1.0f)
{
	Mat temp = Mat(size, CV_32F);

	for (int r = 0; r < size.height; r++)
	{
		for (int c = 0; c < size.width; c++)
		{
			float x = ((c - uX)*((float)c - uX)) / (2.0f*sigmaX*sigmaX);
			float y = ((r - uY)*((float)r - uY)) / (2.0f*sigmaY*sigmaY);
			float value = amplitude * exp(-(x + y));

			temp.at<float>(r, c) = value;
		}
	}

	normalize(temp, temp, 0.0f, 1.0f, NORM_MINMAX);
	output = temp;

}

int main(int arg, char** argc)
{
	//Mat original = imread("test.JPG", CV_LOAD_IMAGE_GRAYSCALE);
	//Mat originalFloat;
	//original.convertTo(originalFloat, CV_32FC1, 1.0 / 255.0);
	//Mat dftOfOriginal;
	//takeDFT(originalFloat, dftOfOriginal);
	//showDFT(dftOfOriginal);
	//Mat invertedDFT;
	//invertDFT(dftOfOriginal, invertedDFT);
	//imshow("InvertDFT", invertedDFT);


	Mat output;
	createGuassian(Size(256, 256), output, 256 / 2, 256 / 2, 10, 10);
	imshow("Guassian", output);

	waitKey();
}