#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class DroneStriker
{
public:
	DroneStriker();
	void DroneStriker::Annihilate(cv::Mat image, cv::Mat &result, double orientation, int magnitude);
private:
};