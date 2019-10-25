#include <iostream>

#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

namespace ELSE {

	void show(Mat img) {
		imshow("Out", img);
		char c = (char) waitKey(25);

	}
}