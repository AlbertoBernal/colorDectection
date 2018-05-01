/**
* @file Morphology_1.cpp
* @brief Erosion and Dilation sample code
* @author OpenCV team
*/
#include <iostream>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include "colores.h"
#include "formaSimple.h"
using namespace cv;
using namespace std;
/**
* @function main
*/
typedef uchar Pixel;
struct Operator
{
	void operator() (unsigned char& pixel,const int* position) const
	{
		std::cout << format("[%d,%d] = %d \n ", position[0], position[1], (int)pixel);
	}
};
/*
int main(int, char** argv)
{
	Mat src;
	char* img = "../data/lena.jpg";
	src = imread(img, IMREAD_COLOR);
	Mat dst, grey_image;
	cvtColor(src, grey_image, CV_BGR2GRAY);
	
	if (!src.data)
	{
		return -1;
	}

	/// Separate the image in 3 places ( B, G and R )
	vector<Mat> bgr_planes;
	split(src, bgr_planes);

	/// Establish the number of bins
	int histSize = 256;

	/// Set the ranges ( for B,G,R) )
	float range[] = { 0, 256 };
	const float* histRange = { range };

	bool uniform = true; bool accumulate = false;
	Mat mTest(Size(3, 2), CV_8UC1, Scalar(0));
	Mat b_hist, g_hist, r_hist;
	Mat grey_hist(Size(src.rows, src.cols), CV_8UC1, Scalar(0));
	/// Compute the histograms:
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&grey_image, 1, 0, Mat(), grey_hist, 1, &histSize, &histRange, uniform, accumulate);
	
	
	// Draw the histograms for B, G and R
	int hist_w = 512; int hist_h = 400; //512x400 anchoxalto
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	Mat grey_hist_image(256, 256, CV_8UC1, Scalar(0));
	/// Normalize the result to [ 0, histImage.rows ]
	normalize(grey_hist,grey_hist,0, grey_hist_image.rows, NORM_MINMAX, -1, Mat());
	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	for (int i = 0; i < 256; i++)
	{
		cout << r_hist.at<float>(i)<<endl;
	
	}
	
	randn(mTest, Scalar(125), Scalar(125));
	//grey_image.forEach<Pixel>(Operator());

	/// Draw for each channel
	for (int i = 1; i < histSize; i++)
	{
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}
	for (int i = 1; i < 256; i++)
	{
		int bin = cvRound((double)256 / 256);
		line(grey_hist_image,
		     Point(bin*(i-1),256 - cvRound(grey_hist.at<float>(i-1))),
			 Point(bin*(i), hist_h - cvRound(b_hist.at<float>(i))),
			 Scalar(255, 0, 0)	, 2, 8,0);
	}

	/// Display
	namedWindow("GreyHist", CV_NORMAL);
	namedWindow("calcHist Demo", CV_WINDOW_AUTOSIZE);
	namedWindow("GrayLena", CV_NORMAL);
	imshow("calcHist Demo", histImage);
	imshow("GrayLena", grey_image);
	imshow("GreyHist", grey_hist_image);
	waitKey(0);

	return 0;
	/*
	Mat src;
	char* imagen = "../data/albertoJepetoJPG.jpg";
	/// Load an image
	src = imread(imagen, IMREAD_COLOR);

	if (src.empty())
		return -1;

	cv::Mat resultMat(src.rows, src.cols, CV_8UC1);

	cv::cvtColor(src, resultMat, CV_RGB2GRAY);
	cv::namedWindow("alberto_blanco_negro", cv::WINDOW_AUTOSIZE);
	cv::imshow("alberto_blanco_negro", resultMat);
	waitKey(0);
	return 0;
		*/
//}
//![dilation]

