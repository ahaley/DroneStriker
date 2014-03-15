#include "stdafx.h"
#include "DroneStriker.h"

#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

#define _USE_MATH_DEFINES

extern "C" {
#include <stdio.h>
#include <time.h>
#include <math.h>
}

#include "Target.h"
#include "CircleTarget.h"



using namespace std;
using namespace cv;

DroneStriker::DroneStriker()
{
	target = new CircleTarget();
};

DroneStriker::~DroneStriker()
{
	if (target != NULL) {
		delete target;
		target = NULL;
	}
}

vector<Moments> GetMomentsFromContours(vector<vector<Point>> contours)
{
	vector<Moments> mu(contours.size());
	for (int i = 0; i < contours.size(); i++) {
		mu[i] = moments(contours[i], false);
	}
	return mu;
}

vector<Point2f> GetCenterMassFromContours(vector<vector<Point>> contours)
{
	vector<Moments> mu = GetMomentsFromContours(contours);
	vector<Point2f> mc(contours.size());
	for (int i = 0; i < contours.size(); i++) {
		mc[i] = Point2f(mu[i].m10 / mu[i].m00, mu[i].m01 / mu[i].m00);
	}
	return mc;
}

vector<Point2f> DroneStriker::GetCenterMasses(Mat image)
{
	Mat blackAndWhite;
	inRange(image, Scalar(0, 0, 200), Scalar(0, 0, 255), blackAndWhite);
	Mat cannyOutput;
	const int thresh = 100;
	Canny(blackAndWhite, cannyOutput, thresh, thresh << 1, 3);
	vector<Vec4i> hierarchy;
	vector<vector<Point>> contours;
	findContours(cannyOutput, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE);
	vector<Point2f> mc = GetCenterMassFromContours(contours);
	imwrite("black-and-white.jpg", blackAndWhite);
	imwrite("canny.jpg", cannyOutput);
	return mc;
}

void DroneStriker::AdjustForWind(vector<Point2f> &centerMasses, double orientation, int magnitude)
{
	int dx = static_cast<int>(cos(orientation + M_PI) * magnitude);
	int dy = -static_cast<int>(sin(orientation + M_PI) * magnitude);

	for (vector<Point2f>::iterator iter = centerMasses.begin();
		iter != centerMasses.end();
		iter++) {
		iter->x += dx;
		iter->y += dy;
	}
}

void DroneStriker::Annihilate(Mat image, Mat &result, double orientation, int magnitude)
{
	vector<Point2f> centerMasses = GetCenterMasses(image);

	image.copyTo(result);

	AdjustForWind(centerMasses, orientation, magnitude);

	for (vector<Point2f>::iterator iter = centerMasses.begin();
		iter != centerMasses.end();
		iter++) {
		PaintTarget(result, static_cast<int>(iter->x), static_cast<int>(iter->y));
	}
}

void DroneStriker::PaintTarget(cv::Mat &result, int x, int y)
{
	target->Paint(result, x, y);
}