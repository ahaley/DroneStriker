#include "stdafx.h"
#include "Target.h"

using namespace cv;

static const int RADIUS = 6;

Target::Target()
{

}

void Target::Paint(Mat image, int x, int y)
{
	printf("Painting target at (%d, %d)\n", x, y);

	line(image,
		Point(x - RADIUS, y - RADIUS),
		Point(x + RADIUS, y + RADIUS),
		Scalar(0, 0, 0),
		3
	);

	line(image,
		Point(x + RADIUS, y - RADIUS),
		Point(x - RADIUS, y + RADIUS),
		Scalar(0, 0, 0),
		3
	);

}