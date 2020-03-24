#pragma once

#include "opencv2/opencv.hpp"

class StrategyModify
{
public:
	StrategyModify();
	virtual ~StrategyModify();

	virtual void modify(cv::Mat& mat) const;
};
