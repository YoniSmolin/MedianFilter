/*
 * MainProgram.cpp - a test program the loads an image, adds salt and pepper noise, runs CPU and GPU versions of the median filter and compares the results.
 */

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;

#define ROWS 424
#define COLS 512

#define WHITE 255 // in terms of CV_8UC1
#define BLACK 0   //        -||-

#define FILTER_SIZE 3 // the filter will consider a FILTER_SIZE x FILTER_SIZE window

// generates non-random salt & pepper noise, in a repeating pattern (because it's easy :-)
void SaltAndPepperNoise(Mat& image)
{
	uchar* data = image.data;
	const int primeNumber = 67;
	bool white = true;
	for(int i=0; i<ROWS*COLS; i++)
	{
		if (i % primeNumber == 0)
		{
			image.data[i] = white ? WHITE : BLACK;
			white = !white;
		}
	}
}	

int main(int argc, char* argv[])
{
	// load and scale an image
	Mat original = imread("BeautifulGirl.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat scaled(ROWS, COLS, CV_8UC1);
	resize(original, scaled, scaled.size(), 0, 0, INTER_AREA);	

	// show the image to screen
	imshow("A beautiful girl - noise free", scaled);

	// make a noise copy
	Mat noisy = scaled.clone();
	SaltAndPepperNoise(noisy);

	// show noisy copy to screen
	imshow("A beautiful girl - with Salt & Pepper noise", noisy);

	// filter noisy copy with the CPU filter
	Mat denoised(noisy.size(), CV_8UC1);
	medianBlur(noisy, denoised, FILTER_SIZE);
	
	// show denoised picture
	imshow("A beautiful girl - denoised", denoised);	
	waitKey(0); // waits infinitely, until a key is pressed

	return 0;
}

