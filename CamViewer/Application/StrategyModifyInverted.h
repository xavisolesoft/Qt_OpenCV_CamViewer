#pragma once

#include "StrategyModify.h"

class StrategyModifyInverted :
		public StrategyModify
{
public:
	StrategyModifyInverted();

	void modify(cv::Mat& mat) const override;
};
