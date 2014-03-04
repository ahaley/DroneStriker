#include "stdafx.h"
#include "CircleTarget.h"

using namespace cv;

static const int RADIUS = 6;

CircleTarget::CircleTarget()
{
}

void CircleTarget::Paint(Mat image, int x, int y)
{
	printf("Painting CircleTarget at (%d, %d)\n", x, y);

	circle(image, Point(x, y), 20, Scalar(255, 0, 0), 3);

}