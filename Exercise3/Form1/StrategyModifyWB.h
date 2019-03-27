#pragma once

#include "StrategyModify.h"

class StrategyModifyWB :
		public StrategyModify
{
public:
	StrategyModifyWB();

	cv::Mat modify(const cv::Mat &mat) const override;
};
