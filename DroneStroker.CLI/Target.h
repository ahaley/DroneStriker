#include <opencv2/core/core.hpp>
#include "ITarget.h"

class Target : public ITarget
{
public:
	Target();
	void Paint(cv::Mat image, int x, int y);
private:
};