#include "stdafx.h"
#include "DroneStriker.h"

using namespace cv;

DroneStriker::DroneStriker()
{

};

void DroneStriker::Annihilate(Mat image, Mat &result, double orientation, int magnitude)
{
	image.copyTo(result);
}