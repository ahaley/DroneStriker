#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Target.h"

class DroneStriker
{
public:
	DroneStriker();
	~DroneStriker();
	void Annihilate(cv::Mat image, cv::Mat &result, double orientation, int magnitude);
private:
	void PaintTarget(cv::Mat &result, int x, int y);
	cv::vector<cv::Point2f> DroneStriker::GetCenterMasses(cv::Mat image);
	void DroneStriker::AdjustForWind(std::vector<cv::Point2f> &centerMasses, double orientation, int magnitude);

	Target *target;
};