// DroneStroker.CLI.cpp : Defines the entry point for the console application.
//

#include "DroneStriker.h"
extern "C" {
#include <math.h>
#include <stdlib.h>
}

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace cv;

int main(int argc, char* argv[])
{
	if (argc != 4) {
		fprintf(stderr, 
			"Usage %s <image filename> <wind orientation> <wind magnitude>\n",
			argv[0]);
		return -1;
	}
	double orientation = atof(argv[2]);
	int magnitude = atoi(argv[3]);

	Mat image = imread(argv[1], 1);

	if (image.data == NULL) {
		fprintf(stderr, "Could not load image file.\n");
		return -1;
	}

	DroneStriker d;

	Mat resultantImage;

	d.Annihilate(image, resultantImage, orientation, magnitude);

	imwrite("output.jpg", resultantImage);
	return 0;
}

