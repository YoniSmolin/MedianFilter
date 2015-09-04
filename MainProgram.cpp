/*
 * MainProgram.cpp - a test program the loads an image, adds salt and pepper noise, runs CPU and GPU versions of the median filter and compares the results.
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

#define ROWS 424
#define COLS 512

int main(int argc, char* argv[])
{
	// load and scale an image
	Mat originalImage = imread("BeautifulGirl.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat originalScaled(ROWS, COLS, CV_8UC1);
	resize(originalImage, originalScaled, originalScaled.size(), 0, 0, INTER_AREA);	

	// show the image to screen
	imshow("A beautiful girl - noise free", originalScaled);
	waitKey(0);

	return 0;
}

