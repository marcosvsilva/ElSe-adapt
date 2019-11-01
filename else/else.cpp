#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/core/affine.hpp>

#include "algo.h"

using namespace std;
using namespace cv;
using namespace ELSE;

RNG rng(12345);

bool video = false;

int main(int argc, char** argv) {

	if (argc != 2)
	{
		cout << "Database directory not definid!" << endl;
		return -1;
	}

	if (video) {

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
		Mat img = imread(argv[1]);
		Mat img2 = imread("C:\\ProjetosMarcos\\ElSeAdapt\\data\\Images\\1_new.png");	

		RotatedRect center = run(img);
		
		RotatedRect center2 = run(img);

		Scalar color = Scalar(rng.uniform(0, 0), rng.uniform(0, 0), rng.uniform(0, 0));
		ellipse(img, center, color, 2, 8);

		/*Scalar color2 = Scalar(rng.uniform(0, 150), rng.uniform(0, 150), rng.uniform(0, 150));
		ellipse(img2, center2, color2, 2, 8);*/

		namedWindow("Display window", WINDOW_AUTOSIZE);
		imshow("Display window", img);
		waitKey(0);

		return 0;
	}

	return 0;
};