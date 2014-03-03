#include "stdafx.h"
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
	inRange(image, Scalar(0, 0, 0), Scalar(0, 0, 255), result);
}

void DroneStriker::PaintTarget(cv::Mat &result, int x, int y)
{
	target->Paint(result, x, y);
}