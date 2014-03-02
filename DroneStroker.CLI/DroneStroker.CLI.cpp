// DroneStroker.CLI.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DroneStriker.h"
extern "C" {
#include <math.h>
#include <stdlib.h>
}

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include <direct.h>
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

	// There is a bug with win32 and opencv2's imread preventing us from
	// reading the image directory into the Mat.
	IplImage* imageRead = cvLoadImage(argv[1], 1);
	Mat image(imageRead);

	if (image.data == NULL) {
		printf("Could not load image file.\n");
		printf("cwd = %s\n", _getcwd(NULL, 0));
		printf("f = %s\n", argv[1]);
		return - 1;
	}

	DroneStriker d;

	Mat resultantImage;

	d.Annihilate(image, resultantImage, orientation, magnitude);

	imwrite("output.jpg", resultantImage);
	return 0;
}

