#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include <iostream>

using namespace  cv;
using namespace std;

int main()
{
//	VideoCapture videoSource("testVideoTrim.mp4");
//	if(videoSource.isOpened())
//	{
//		Mat currentFrame;
//		Mat lrFrame;
//		Mat grayImage;

//		auto currentFrameWinname = "Current Frame";
//		auto lowResolutionFrameWinname = "Low Resolution Frame";
//		namedWindow(currentFrameWinname);
//		namedWindow(lowResolutionFrameWinname);

//		auto idx = 0;
//		char framename[10];

//		while (true)
//		{
//			videoSource >> currentFrame;
//			if(currentFrame.empty())
//				break;

//			cvtColor(currentFrame, grayImage, CV_BGR2GRAY);

//			Mat tempMat;
//			pyrDown(grayImage, tempMat);
//			pyrDown(tempMat, lrFrame);

//			imshow(currentFrameWinname, currentFrame);
//			imshow(lowResolutionFrameWinname,lrFrame);
//			waitKey(100);

//			sprintf(framename, "%d.png", idx);
//			imwrite(framename, lrFrame);
//			idx++;
//		}

//		destroyAllWindows();
//	}
//	else
//	{
//		cout << "Cannot get this video file!" << endl;
//		system("pause");
//	}
	return 0;
}