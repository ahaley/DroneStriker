#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Target.h"

class DroneStriker
{
public:
	DroneStriker();
	void Annihilate(cv::Mat image, cv::Mat &result, double orientation, int magnitude);
private:
	void PaintTarget(cv::Mat &result, int x, int y);

	Target *target;
};