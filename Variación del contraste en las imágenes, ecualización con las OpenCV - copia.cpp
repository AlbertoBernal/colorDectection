
//#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "forma.h"
#include "colores.h"
#include <iostream>

using namespace std;
using namespace cv;
void drawHistogram(Mat&, Mat&, const int, const Scalar, const int);

void hsv();
/*****************************************************************************************************/
/*      funcion que toma como entrada una mascara binaria y dibuja sobre otra imagen el contorno     */
/*       de esa mascara binaria, esto se hace mediante la funcion HoughsP                            */
/*                                                                                                   */
/*****************************************************************************************************/
void ContourOfBinaryImage(const cv::Mat& binaryMask, cv::Mat& outImageWithContourDraw, const cv::Scalar lineColor,
						  const unsigned int HoughLinesThreshold, const unsigned int HoughLinesMinLinLength,
						  const unsigned int HoughLinesMaxLineGap);

void programaHSV(const Mat&);

int main()
{/*
	//Nombre de la imagen que se va a cargar
	char NombreImagen[] = "../data/ivvi_low_contrast.jpg";
	Mat original_img, equaliz_img;

	//Cargamos la imagen y se comprueba que lo ha hecho correctamente
	original_img = cv::imread(NombreImagen, CV_LOAD_IMAGE_GRAYSCALE);
	if (!original_img.data) {
		cout << "Error al cargar la imagen: " << NombreImagen << endl;
		exit(1);
	}

	//Variables para el histograma
	int histSize = 256;
	/// el rango del nivel del gris 0-255
	float range[] = { 0, 256 };
	const float* histRange = { range };

	/// imagen del histograma
	int hist_w = 512; int hist_h = 400;
	int bin_w = cvRound((double)hist_w / histSize);
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));
	Mat equalizedHistImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	//calcular el histograma
	Mat original_hist, normalized_hist, equalized_hist, equalized_normalized_hist;
	calcHist(&original_img, 1, 0, Mat(), original_hist, 1, &histSize, &histRange, true, false);

	// Mostrar los valores del histograma de la imagen original

	cout << "Original histogram" << endl;
	for (int h = 0; h < histSize; h++)
	{
		float binVal = original_hist.at<float>(h);
		cout << " " << binVal;
	}
	cout << endl;

	/// Normalizar el resultado a [ 0, histImage.rows ]
	normalize(original_hist, normalized_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	// Mostrar los valores
	cout << "Normalized histogram" << endl;
	for (int h = 0; h < histSize; h++)
	{
		float binVal = normalized_hist.at<float>(h);
		cout << " " << binVal;
	}
	cout << endl;

	// Equalize histogram from a grayscale image	
	equalizeHist(original_img, equaliz_img);
	calcHist(&equaliz_img, 1, 0, Mat(), equalized_hist, 1, &histSize, &histRange, true, false);

	// Mostrar los valores
	cout << "Equalized histogram" << endl;
	for (int h = 0; h < histSize; h++)
	{
		float binVal = equalized_hist.at<float>(h);
		cout << " " << binVal;
	}
	cout << endl;

	// Normalizar el histograma ecualizado
	normalize(equalized_hist, equalized_normalized_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	// Mostrar los valores
	cout << "Equalized normalized histogram" << endl;
	for (int h = 0; h < histSize; h++)
	{
		float binVal = equalized_normalized_hist.at<float>(h);
		cout << " " << binVal;
	}
	cout << endl;
	
	/// dibujar los histogramas
    drawHistogram(equalized_normalized_hist,equalizedHistImage, 256, Scalar{ 255, 0, 0 }, 8);
	drawHistogram(normalized_hist, histImage, 256, Scalar{ 0, 255, 0 }, 8);

	//Mostrar las imagens
	namedWindow("Original picture", CV_WINDOW_AUTOSIZE);
	namedWindow("Equalized picture", CV_WINDOW_AUTOSIZE);
	namedWindow("Original histogram", CV_WINDOW_AUTOSIZE);
	namedWindow("Equalized histogram", CV_WINDOW_AUTOSIZE);

	imshow("Original picture", original_img);
	imshow("Equalized picture", equaliz_img);
	imshow("Original histogram", histImage);
	imshow("Equalized histogram", equalizedHistImage);*/

	//hsv();
	Mat bright = cv::imread("../data/colores6.jpg", IMREAD_COLOR);
	programaHSV(bright);
	waitKey(0);
	return 0;
}

void drawHistogram( Mat& histogram, Mat& histogramImage, const int histogramSize,
	const Scalar lineColor, const int lineTicknes) {

	Point endPoint{ 0 , 0 }, iniPoint{ 0, histogramImage.cols };
	int bin_w = cvRound((double)histogramImage.cols / histogramSize);

	/// dibujar los histogramas
	for (int i = 1; i < histogram.rows; i++) {

		int delt_x = histogramImage.rows - cvRound(histogram.at<float>(i - 1));
		int delt_x_1 = histogramImage.rows - cvRound(histogram.at<float>(i));

		if (delt_x_1 < 400) {

			endPoint = { bin_w*i, delt_x_1 };

			line(histogramImage, iniPoint, endPoint, lineColor, bin_w, lineTicknes, 0);

			iniPoint = endPoint;
		}
	}
}


void hsv() 
{
	using namespace cv;

	char* imgAzul = "../data/azul.jpg";
	Mat imagenAzulBGR, imagenAzulHSV;

	char* imgVerde = "../data/verde.jpg";
	Mat imagenVerdeBGR, imagenVerdeHSV;

	char* imgRoja = "../data/rojo.jpg";
	Mat imagenRojaBGR, imagenRojaHSV;


	namedWindow("imagen Roja" , CV_WINDOW_AUTOSIZE);
	namedWindow("imagen Verde", CV_WINDOW_AUTOSIZE);
	namedWindow("imagen Azul" , CV_WINDOW_AUTOSIZE);

	imagenAzulBGR  = imread(imgAzul);
	imagenVerdeBGR = imread(imgVerde);
	imagenRojaBGR  = imread(imgRoja);

	imshow("imagen Roja", imagenRojaBGR);
	imshow("imagen Verde", imagenVerdeBGR);
	imshow("imagen Azul", imagenAzulBGR);

	cv::cvtColor(imagenVerdeBGR, imagenVerdeHSV, cv::COLOR_BGR2HSV);
	
	namedWindow("imagen Verde HSV", CV_WINDOW_AUTOSIZE);
	imshow("imagen Verde HSV", imagenVerdeHSV);

}





void ContourOfBinaryImage(const cv::Mat& binaryMask, cv::Mat& outImageWithContourDraw, const cv::Scalar lineColor,
						  const unsigned int HoughLinesThreshold, const unsigned int HoughLinesMinLinLength,
						  const unsigned int HoughLinesMaxLineGap) {

	//saca las lineas del resultado de aplicar canny
	std::vector<Vec4i> lines; //vector de pares de puntos

							  //obten  la silueta del cuadrado verde
	HoughLinesP(binaryMask, lines, 1, CV_PI / 180, HoughLinesThreshold, HoughLinesMinLinLength, HoughLinesMaxLineGap);//obten los pares de putnos que forman las lineas
															 //representa los pares de puntos sobre la imagen original
	for (size_t i = 0; i < lines.size(); i++) {
		Vec4i l = lines[i];
		line(outImageWithContourDraw, Point(l[0], l[1]), Point(l[2], l[3]), lineColor, 3, CV_AA);
	}
}

void programaHSV(const Mat& inputImage)
{
	if (!inputImage.data)
		return;
	//C++ 
	//Mat bright = cv::imread("../data/cubes.png", IMREAD_COLOR);
	Mat outpuImage(inputImage);
	//C++ 
	Mat brightHSV, darkHSV;
	cv::cvtColor(outpuImage, brightHSV, cv::COLOR_BGR2HSV);
	cv::cvtColor(outpuImage, darkHSV, cv::COLOR_BGR2HSV);
	
	//green pixel
	cv::Vec3b bgrPixel(40, 158, 16);
	//yellow pixel
	cv::Vec3b bgrPixel2(0, 240, 255);
	//orange pixel
	cv::Vec3b bgrPixel3(0, 106, 255);
	//red pixel
	cv::Vec3b bgrPixel4(0, 0, 255);
	//blue pixel
	cv::Vec3b bgrPixel5(255, 0, 0);

	// Create Mat object from vector since cvtColor accepts a Mat object
	Mat3b bgr(bgrPixel);
	Mat3b bgr2(bgrPixel2);
	Mat3b bgr3(bgrPixel3);
	Mat3b bgr4(bgrPixel4);
	Mat3b bgr5(bgrPixel5);

	//Convert pixel values to other color spaces.
	Mat3b hsv, ycb, lab,hsv2,hsv3,hsv4,hsv5;
	cvtColor(bgr2, hsv2, COLOR_BGR2HSV);
	cvtColor(bgr3, hsv3, COLOR_BGR2HSV);
	cvtColor(bgr, hsv, COLOR_BGR2HSV);
	cvtColor(bgr4, hsv4, COLOR_BGR2HSV);
	cvtColor(bgr5, hsv5, COLOR_BGR2HSV);

	//Get back the vector from Mat
	Vec3b hsvPixel(hsv.at<Vec3b>(0, 0));
	Vec3b hsv2Pixel(hsv2.at<Vec3b>(0, 0));
	Vec3b hsv3Pixel(hsv3.at<Vec3b>(0, 0));
	Vec3b hsv4Pixel(hsv4.at<Vec3b>(0, 0));
	Vec3b hsv5Pixel(hsv5.at<Vec3b>(0, 0));

	vector<Mat> vectorHSV, planesBGR;
	split(darkHSV,vectorHSV);



		
	int threshYellow = 6, threshGreen = 10, threshOrange = 3 , threshRed = 5, threshBlue = 20;
	//blue mask
	cv::Mat onlyBlueColorHSV ,blueMaskHSV;
	cv::Scalar minHSV5 = cv::Scalar(hsv5Pixel.val[0] - threshBlue, 50, 50);//120 - 20, 50, 50);
	cv::Scalar maxHSV5 = cv::Scalar(hsv5Pixel.val[0] + threshBlue, 255, 255); //120 + 20, 255, 255);
	cv::inRange(darkHSV, minHSV5, maxHSV5, blueMaskHSV);
	imshow("azul", blueMaskHSV);

	//red mask
	Mat1b mask1, mask2;
	inRange(darkHSV, Scalar(0, 50, 50), Scalar(10, 255, 255), mask1);
	inRange(darkHSV, Scalar(170, 50, 50), Scalar(180, 255, 255), mask2);
	Mat1b redMaskHSV = mask1 | mask2;

	//green mask
	cv::Scalar minHSV = cv::Scalar(hsvPixel.val[0] - threshGreen, 20, 20);
	cv::Scalar maxHSV = cv::Scalar(hsvPixel.val[0] + threshGreen, 255, 255);
	//yellow mask
	cv::Scalar minHSV2 = cv::Scalar(hsv2Pixel.val[0] - threshYellow, 100, 20);
	cv::Scalar maxHSV2 = cv::Scalar(hsv2Pixel.val[0] + threshYellow, 255, 255);
	//orange mask
	cv::Scalar minHSV3 = cv::Scalar(hsv3Pixel.val[0] - threshOrange, 70, 50);
	cv::Scalar maxHSV3 = cv::Scalar(hsv3Pixel.val[0] + threshOrange, 255, 255);

	//blue color filtered
	cv::bitwise_and(darkHSV, darkHSV, onlyBlueColorHSV, blueMaskHSV);
	imshow("solo AZUL", onlyBlueColorHSV);
	Mat originalImage_without_blue = darkHSV - onlyBlueColorHSV;

	//red color filtered
	cv::Mat onlyRedColorHSV;
	cv::bitwise_and(originalImage_without_blue, originalImage_without_blue, onlyRedColorHSV, redMaskHSV);
	imshow("prueba Rojo", onlyRedColorHSV);
	Mat originalImage_without_red = originalImage_without_blue - onlyRedColorHSV;

	//green color filtered
	cv::Mat greenMaskHSV, onlyGreenColorHSV;
	cv::inRange(originalImage_without_red, minHSV, maxHSV, greenMaskHSV);
	cv::bitwise_and(originalImage_without_red, originalImage_without_red, onlyGreenColorHSV, greenMaskHSV);
	Mat originalImage_without_redGreen = originalImage_without_red - onlyGreenColorHSV;

	//yellow color filtered	
	Mat yellowMaskHSV, onlyYellowColorHSV;
	inRange(darkHSV, minHSV2, maxHSV2, yellowMaskHSV);
	bitwise_and(originalImage_without_redGreen, originalImage_without_redGreen, onlyYellowColorHSV, yellowMaskHSV);
	Mat originalImage_without_RedGreenYellow = originalImage_without_redGreen - onlyYellowColorHSV;
	imshow("solo amarillo", onlyYellowColorHSV);

	//orange color filtered
	cv::Mat maskHSV3, resultHSV3;
	cv::inRange(originalImage_without_RedGreenYellow, minHSV3, maxHSV3, maskHSV3);
	cv::bitwise_and(originalImage_without_RedGreenYellow,
		            originalImage_without_RedGreenYellow, resultHSV3, maskHSV3);


	Mat binaryYellow, binaryGreen, binaryOrange, binaryBlue, binaryRed, redResultHSV, orangeResultHSV, greenResultHSV, yellowResultHSV, blueResultHSV;

	//take binary of blue portion
	split(onlyBlueColorHSV, vectorHSV);
	blueResultHSV = vectorHSV[2];//in HSV the V is equals to convert HSV mat to GRAY mat
	threshold(blueResultHSV, binaryBlue, 1, 255, CV_THRESH_OTSU);


	//take binary of green portion
	split(onlyGreenColorHSV, vectorHSV);
	greenResultHSV = vectorHSV[2];//in HSV the V is equals to convert HSV mat to GRAY mat
	threshold(greenResultHSV, binaryGreen, 1, 255, CV_THRESH_OTSU);
	imshow("verde binario", binaryGreen);

	//take binary of yellow portion
	split(onlyYellowColorHSV, vectorHSV);
	yellowResultHSV = vectorHSV[2];//in HSV the V is equals to convert HSV mat to GRAY mat
	threshold(yellowResultHSV, binaryYellow, 1 /*ignored for otsu*/, 255, CV_THRESH_OTSU);

	//take binary orange portion
	split(resultHSV3, vectorHSV);
	orangeResultHSV = vectorHSV[2];
	threshold(orangeResultHSV, binaryOrange, 1, 255, CV_THRESH_OTSU);
	
	//take binary red portion
	split(onlyRedColorHSV, vectorHSV);
	redResultHSV = vectorHSV[2];
	threshold(redResultHSV, binaryRed, 1, 255, CV_THRESH_OTSU);

	medianBlur(binaryRed, binaryRed, 15);
	Canny(binaryRed, binaryRed, 150, 300, 3);

	medianBlur(binaryBlue, binaryBlue, 15);
	Canny(binaryBlue, binaryBlue, 150, 200, 3);

	medianBlur(binaryYellow, binaryYellow, 15);//vas a detectar superficies de color , puedes ser muy greedy con el kernel del filtro
	Canny(binaryYellow, binaryYellow, 150, 200, 3);

	medianBlur(binaryGreen, binaryGreen, 15);
	Canny(binaryGreen, binaryGreen, 150, 200, 3);

	medianBlur(binaryOrange, binaryOrange, 19);
	Canny(binaryOrange, binaryOrange, 150, 200, 3);


	//obten los pares de putnos que forman las lineas de silueta del color rojo
	ContourOfBinaryImage(binaryRed, outpuImage, Scalar(0, 0, 255), 5, 1, 15);
	forma formaRoja;
	formaRoja.setImagen(binaryRed);
	//obten los pares de putnos que forman las lineas de silueta del color verde
	ContourOfBinaryImage(binaryGreen, outpuImage, Scalar(0, 255, 0), 5, 1, 15);
	//obten los pares de putnos que forman las lineas de silueta del color amarillo
	ContourOfBinaryImage(binaryYellow, outpuImage, Scalar(0, 255, 255), 5, 1, 15);
	//obten los pares de putnos que forman las lineas de silueta del color naranja
	ContourOfBinaryImage(binaryOrange, outpuImage, Scalar(0, 112, 255), 5, 1, 11);
	//obten los pares de puntos que forman las lineas de silueta del color azul
	ContourOfBinaryImage(binaryBlue, outpuImage, Scalar(255, 0, 0), 5, 1, 11);

	
	imshow("hougsTf", outpuImage);

}