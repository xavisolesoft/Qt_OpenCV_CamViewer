#include <QtTest>

#include "StrategyModifyInverted.h"


class StrategyModifyInvertedTest : public QObject
{
	Q_OBJECT

public:
	StrategyModifyInvertedTest();
	~StrategyModifyInvertedTest();

private slots:
	void testCaseEasyMatrix();

};

StrategyModifyInvertedTest::StrategyModifyInvertedTest()
{

}

StrategyModifyInvertedTest::~StrategyModifyInvertedTest()
{

}

void StrategyModifyInvertedTest::testCaseEasyMatrix()
{
	cv::Mat mat(2, 2, 0);
	mat.at<uchar>(0, 0, 0) = 1;

	cv::Mat mat2(2, 2, 0);
	mat.at<uchar>(1, 0, 0) = 1;

	StrategyModifyInverted modifier;
	modifier.modify(mat);
	QVERIFY(cv::norm(mat, mat2, cv::NORM_L1));
}

QTEST_APPLESS_MAIN(StrategyModifyInvertedTest)

#include "tst_strategymodifyinvertedtest.moc"
