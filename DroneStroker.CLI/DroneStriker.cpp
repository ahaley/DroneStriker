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

void DroneStriker::Annihilate(Mat image, Mat &result, double orientation, int magnitude)
{
	image.copyTo(result);
}


void DroneStriker::PaintTarget(cv::Mat &result, int x, int y)
{
	target->Paint(result, x, y);
}