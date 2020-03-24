#pragma once

#include "StrategyModify.h"

class StrategyModifyWB :
		public StrategyModify
{
public:
	StrategyModifyWB();

	void modify(cv::Mat& mat) const override;
};
