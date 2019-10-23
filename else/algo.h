#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>

#include "blob_gen.h"

using namespace cv;

namespace ELSE {

	static RotatedRect run(Mat input_img) {

		float rz_fakk = float(input_img.cols) / 384.0;

		Mat pic = Mat::zeros(input_img.rows / rz_fakk, input_img.cols / rz_fakk, CV_8UC1);
		resize(input_img, pic, pic.size());

		normalize(pic, pic, 0, 255, NORM_MINMAX, CV_8U);

		double border = 0.1;

		RotatedRect ellipse;

		ellipse = blob_finder(&pic, border);

		ellipse.size.height = ellipse.size.height * rz_fakk;
		ellipse.size.width = ellipse.size.width * rz_fakk;

		ellipse.center.x = ellipse.center.x * rz_fakk;
		ellipse.center.y = ellipse.center.y * rz_fakk;

		return ellipse;
	}
}