#include "StrategyModifyWB.h"

StrategyModifyWB::StrategyModifyWB()
{

}

void StrategyModifyWB::modify(cv::Mat& mat) const
{
	cv::cvtColor(mat, mat, cv::COLOR_RGB2GRAY);
	cv::cvtColor(mat, mat, cv::COLOR_GRAY2RGB);
}
