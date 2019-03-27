#include "StrategyModifyInverted.h"

StrategyModifyInverted::StrategyModifyInverted()
{

}

cv::Mat StrategyModifyInverted::modify(const cv::Mat& mat) const
{
	return cv::Scalar::all(255) - mat;
}
