#include <opencv2/core/core.hpp>
#include "VideoSplitBase.hpp"
#include <iostream>
#include "FrameWriterBase.hpp"
#include "GrayFrameWriter.hpp"

using namespace cv;
using namespace std;

int main()
{
	//	string videoFileName = "fog_v.avi";
	string videoFileName = "tree.avi";
	VideoSplitBase videoSpliter;
	videoSpliter.SetVideoSource(videoFileName);

	//	FrameWriterbase frameWriter;
	//	frameWriter.SetVideoSpliter(&videoSpliter);
	//	auto outputFrameStatus = frameWriter.OutputFrameStream();

	GrayFrameWriter frameWriter;
	frameWriter.SetVideoSpliter(&videoSpliter);
	auto outputFrameStatus = frameWriter.OutputFrameStream();

	if (outputFrameStatus == -2)
		cout << "Open Video File Failed, Please Check File Existed or Not!" << endl;
	else if (outputFrameStatus == -1)
		cout << "VideoSpliter is Null! Please Set VideoSpliter Before split frames!" << endl;
	else if (outputFrameStatus == 0)
		cout << "To The End of This Video! All Done!" << endl;

	system("pause");

	return 0;
}
