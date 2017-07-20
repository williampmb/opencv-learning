#include "opencv2\opencv.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;

int main(int arg, char** argc)
{

	VideoCapture vid(0);

	if (!vid.isOpened())
	{
		return -1;
	}

	namedWindow("Webcam");

	while (char(waitKey(1)) != 'q' && vid.isOpened())
	{
		Mat frame;
		
		vid >> frame;
		if (frame.empty())
		{
			cout << "Video Over" << endl;
		}
		imshow("webcam", frame);

	}
	return 1;
}