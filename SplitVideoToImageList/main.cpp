#include <opencv2/core/core.hpp>
#include "VideoSplitBase.hpp"
#include <iostream>

using namespace  cv;
using namespace std;

int main()
{
	string videoFileName = "fog_v.avi";
	VideoSplitBase videoSpliter;
	videoSpliter.SetVideoSource(videoFileName);
	while (true)
	{
		auto NextFrame = videoSpliter.getNextFrame();
		if(NextFrame.empty() && videoSpliter.SplitStatus() == -1)
		{
			cout << "Open Video File Failed, Please Check File Existed or Not!" << endl;
			break;
		}

		if(NextFrame.empty() && videoSpliter.SplitStatus() == -2)
		{
			cout << "To The End of This Video!" << endl;
			break;
		}

		imshow("Next Frame", NextFrame);
		waitKey(100);
	}

	destroyAllWindows();

	system("pause ");

	return 0;
}