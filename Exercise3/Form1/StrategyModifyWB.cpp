#include "StrategyModifyWB.h"

StrategyModifyWB::StrategyModifyWB()
{

}

cv::Mat StrategyModifyWB::modify(const cv::Mat& mat) const
{
	cv::Mat res;
	cv::cvtColor(mat, res, cv::COLOR_RGB2GRAY);
	return res;
}
