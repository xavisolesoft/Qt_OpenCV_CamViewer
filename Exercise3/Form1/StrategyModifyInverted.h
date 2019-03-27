#pragma once

#include "StrategyModify.h"

class StrategyModifyInverted :
		public StrategyModify
{
public:
	StrategyModifyInverted();

	cv::Mat modify(const cv::Mat &mat) const override;
};
