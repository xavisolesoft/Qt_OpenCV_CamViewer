#pragma once

#include "opencv2/opencv.hpp"

class StrategyModify
{
public:
	StrategyModify();

	virtual cv::Mat modify(const cv::Mat& mat) const;
};
