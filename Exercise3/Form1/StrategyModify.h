#pragma once

#include "opencv2/opencv.hpp"

class StrategyModify
{
public:
	StrategyModify();

	virtual void modify(cv::Mat& mat) const const;
};
