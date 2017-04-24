#pragma once
#include "VideoSplitBase.hpp"

class FrameWriterbase
{
public:
	virtual ~FrameWriterbase() = default;
	explicit FrameWriterbase(std::string output_folder_name = "");

	void SetVideoSpliter(VideoSplitBase* video_spliter);

	virtual int OutputFrameStream() const;

protected:
	std::string outputFolderName;
	VideoSplitBase* videoSpliter;
};

inline FrameWriterbase::FrameWriterbase(std::string output_folder_name): outputFolderName(output_folder_name), videoSpliter(nullptr)
{
}

inline void FrameWriterbase::SetVideoSpliter(VideoSplitBase* video_spliter)
{
	this->videoSpliter = video_spliter;
}

inline int FrameWriterbase::OutputFrameStream() const
{
	if (videoSpliter == nullptr)
		return -1;

	char outputFileNameBuffer[100];
	auto index = 0;
	while (true)
	{
		auto nextFrame = videoSpliter->getNextFrame();

		if (nextFrame.empty() && videoSpliter->SplitStatus() == -1)
			return -2;   // Cannot Open Video File

		if (nextFrame.empty() && videoSpliter->SplitStatus() == -2)
			return 0;    // To The End

		sprintf_s(outputFileNameBuffer, "%d.png", index);
		imwrite(outputFileNameBuffer, nextFrame);
		std::cout << index << "...";
		++index;
	}
}
