// TestOpencv.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	Mat img = imread("1.jpg");
	pyrDown(img,img);
	imshow("1", img);
	waitKey();
	return 0;
}

