#include <string>
#include <iostream>
#include <dirent.h>
#include <sys/types.h>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include "algo.h"

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

		Mat resize_img;
		Size size(384, 288);

		resize(frame, resize_img, size);

		kernel = np.ones(size, np.uint8)
		erode = cv2.erode(median, kernel = kernel, iterations = 1)
		dilate = cv2.dilate(erode, kernel = kernel, iterations = 1)
		threshold = cv2.threshold(dilate, self.thresh_threshold, self.maxvalue_threshold, cv2.THRESH_BINARY)[1]

		RotatedRect center = run(resize_img);
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		
		ellipse(resize_img, center, color, 2, 8);

		imshow("Out", resize_img);

		char c = (char) waitKey(25);
		if (c == 27)
			break;
	}

	cap.release();
	destroyAllWindows();

	return 0;
};