#include <opencv2/core/core.hpp>
#include "ITarget.h"

class CircleTarget : public ITarget
{
public:
	CircleTarget();
	void Paint(cv::Mat image, int x, int y);
private:
};