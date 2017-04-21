#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace  cv;
using namespace std;

int main()
{
	VideoCapture videoSource("testVideoTrim.mp4");
	if(videoSource.isOpened())
	{
		Mat currentFrame;
		auto winname = "Current Frame";
		namedWindow(winname);
		while (true)
		{
			videoSource >> currentFrame;
			if(currentFrame.empty())
				break;

			imshow(winname, currentFrame);
			waitKey(100);
		}

		destroyAllWindows();
	}
	else
	{
		cout << "Cannot get this video file!" << endl;
		system("pause");
	}
	return 0;
}