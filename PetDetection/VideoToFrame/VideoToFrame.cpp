// VideoToFrame.cpp : �������̨Ӧ�ó������ڵ㡣
//ת����ƵΪͼ������

#include "stdafx.h"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void help()
{
	cout << "No such directory found!" << endl;;
}


int _tmain(int argc,char** argv)
{
	//argv[1] = "F://C#_Program//DogVideoData//Easy//test//1.mp4";
	//argv[2] = "F:/C#_Program/DogVideoData/Easy/test/";
	const string& imageDirectory = argv[2];
	const string& fileName =argv[1];// "F://C#_Program//DogVideoData//Easy//test//1.mp4";
//	if (argc != 2)
//	{
//		help( );
//#if DEBUG
//		waitKey();
//#endif
//		return 1;
//	}
	string imageName;
	char number[10];
	VideoCapture sequence(fileName);
	int num=0;

	if (!sequence.isOpened())
	{
		cerr << "Failed to open the image sequence!\n" << endl;
		return 1;
	}
	Mat image;
#if Debug
	namedWindow("ShowImage",1);
#endif
	for (;;)
	{
		sequence >> image;
		if (image.empty())
		{
			cout << "Sequence is empty!" << endl;
			break;
		}
		num++;
#if Debug
		imshow("ShowImage", image);
#endif
		sprintf_s(number, "%05d.jpg", num);
		imageName =  imageDirectory+ number;//
		//cout << imageName << endl;
		imwrite(imageName,image);

		if (waitKey(1) == 27)
			break;
	}



	return 0;
}

