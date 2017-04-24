#pragma once
#include <core/core.hpp>
#include <highgui/highgui.hpp>

class VideoSplitBase
{
public:
	explicit VideoSplitBase(std::string video_file_name = "");

	void SetVideoSource(std::string file_name);

	int SplitStatus() const;

	cv::Mat getNextFrame();

private:
	std::string videoFileName;
	cv::VideoCapture videoCapture;

	int status;
};

inline VideoSplitBase::VideoSplitBase(std::string video_file_name) : videoFileName(video_file_name), status(0)
{
}

inline void VideoSplitBase::SetVideoSource(std::string file_name)
{
	this->videoFileName = file_name;
}

inline int VideoSplitBase::SplitStatus() const
{
	return this->status;
}

inline cv::Mat VideoSplitBase::getNextFrame()
{
	if (!videoCapture.isOpened())
	{
		videoCapture.open(videoFileName);
		if (!videoCapture.isOpened())
		{
			status = -1;
			return cv::Mat();
		}
	}
	cv::Mat returnFrame;
	videoCapture >> returnFrame;
	if (returnFrame.empty())
		status = -2;
	return returnFrame;
}
