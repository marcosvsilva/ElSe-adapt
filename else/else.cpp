#include <iostream>

#include <opencv2/core/core.hpp>

#include "algo.h"

using namespace std;
using namespace cv;
using namespace ELSE;

RNG rng(12345);

bool video = true;

int main(int argc, char** argv) {

	if (video) {

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

			Mat img_resize;
			Size size(384, 288);
			resize(frame, img_resize, size);

			//Mat kernel = Mat::zeros(5, 5, CV_8UC1);*/
			//dilate(filter_image, filter_image, kernel, Point(-1, -1), 3);
			//erode(filter_image, filter_image, kernel, Point(-1, -1), 6);
			//threshold(filter_image, filter_image, 25, 255, THRESH_BINARY);

			RotatedRect center = run(img_resize);

			Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
			ellipse(img_resize, center, color, 2, 8);

			show(img_resize);
			char c = (char)waitKey(25);
			if (c == 27)
				break;
		}

		cap.release();
		destroyAllWindows();
	}
	else {

	}

	return 0;
};