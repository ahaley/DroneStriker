#if defined _WIN32 || defined _WIN64
#include "stdafx.h"
#endif
#include "DroneStriker.h"

extern "C" {
#include <stdio.h>
#include <time.h>
}

using namespace cv;

DroneStriker::DroneStriker()
{
	target = new Target();
};

DroneStriker::~DroneStriker()
{
	if (target != NULL) {
		delete target;
		target = NULL;
	}
}

void DroneStriker::Annihilate(Mat image, Mat &result, double orientation, int magnitude)
{
	image.copyTo(result);
}

void DroneStriker::PaintTarget(cv::Mat &result, int x, int y)
{
	target->Paint(result, x, y);
}
