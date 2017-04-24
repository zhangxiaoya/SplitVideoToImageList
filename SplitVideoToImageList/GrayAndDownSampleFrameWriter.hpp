#pragma once
#include "FrameWriter/FrameWriterBase.hpp"
#include <iostream>
#include <imgproc/imgproc.hpp>

class GrayAndDownSampleFrameWriter: public FrameWriterbase
{
public:
	explicit GrayAndDownSampleFrameWriter(std::string output_folder_name="");

	int OutputFrameStream() const override;
};

inline GrayAndDownSampleFrameWriter::GrayAndDownSampleFrameWriter(std::string output_folder_name):FrameWriterbase(output_folder_name)
{
}

inline int GrayAndDownSampleFrameWriter::OutputFrameStream() const
{
	if (videoSpliter == nullptr)
		return -1;

	std::cout << "Splitting ..." << std::endl;

	char outputFileNameBuffer[100];
	auto index = 0;
	while (true)
	{
		auto nextFrame = videoSpliter->getNextFrame();

		if (nextFrame.empty() && videoSpliter->SplitStatus() == -1)
			return -2;   // Cannot Open Video File

		if (nextFrame.empty() && videoSpliter->SplitStatus() == -2)
			return 0;    // To The End

		cv::Mat grayFrame;
		cvtColor(nextFrame, grayFrame, CV_BGR2GRAY);

		cv::Mat downSampleMat;
		cv::pyrDown(grayFrame, downSampleMat);

		sprintf_s(outputFileNameBuffer, "%d.png", index);
		imwrite(outputFileNameBuffer, downSampleMat);

		std::cout << index << "...";
		++index;
	}
}
