#include "opencv2\opencv.hpp"
#include <stdint.h>

using namespace cv;
using namespace std;

int main(int arg, char** argc)
{

	VideoCapture vid("rtsp://wowzaec2demo.streamlock.net/vod/mp4:BigBuckBunny_115k.mov");

	if (!vid.isOpened())
	{
		return -1;
	}

	namedWindow("Webcam", CV_WINDOW_AUTOSIZE);

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