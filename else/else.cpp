#include <string>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include "algo.h"
#include "stdafx.h"

using namespace std;
using namespace cv;
using namespace ELSE;

RNG rng(12345);

int main(int argc, char** argv) {

	if (argc != 2)
	{
		cout << "Database directory not definid!" << endl;
		return -1;
	}

	VideoCapture cap(argv[1]);

	if (!cap.isOpened()) {
		cout << "Error opening video stream or file" << endl;
		return -1;
	}

	while (1) {

		Mat frame;
		cap >> frame;

		if (frame.empty())
			break;

		RotatedRect center = run(frame);
		
		Point2f vertices[4];
		center.points(vertices);

		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		ellipse(frame, center, color, 2, 8);

		imshow("Frame", frame);

		// Press  ESC on keyboard to exit
		char c = (char) waitKey(25);
		if (c == 27)
			break;

		//Sleep(100000);
	}

	cap.release();
	destroyAllWindows();

	return 0;
};