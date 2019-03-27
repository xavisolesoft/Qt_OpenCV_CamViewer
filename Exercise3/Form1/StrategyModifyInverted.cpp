#include "StrategyModifyInverted.h"

StrategyModifyInverted::StrategyModifyInverted()
{

}

void StrategyModifyInverted::modify(cv::Mat& mat) const
{
	cv::flip(mat, mat, 0);
}
