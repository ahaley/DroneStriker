#pragma once

#include <opencv2/core/core.hpp>

class ITarget
{
public:
	virtual void Paint(cv::Mat image, int x, int y) = 0;
};