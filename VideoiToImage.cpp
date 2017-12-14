//所需要的opencv头文件
#include <opencv2/highgui/highgui.hpp> 
#include <cv.h>
//创建文件夹所需要的头文件
#include<io.h>
#include<direct.h>

int main(int argc, char *argv[])
{
	//获取本地视频流
	CvCapture* capture = cvCaptureFromFile(R"(C:\Users\Administrator\Desktop\UAV\UAV_InfraredDd_test1.asf)");
	int i = 0;	//帧号
	IplImage* img = NULL;	//存储帧图片
	char image_name[25];	//帧的名字（路径）
	cvNamedWindow("RawVideo",CV_WINDOW_AUTOSIZE);
	//读取和显示 
	while (1)
	{
		img = cvQueryFrame(capture); //获取一帧图片 
		//设置跳出while（1）循环的条件
		if (img == NULL)
			break;

		cvShowImage("RawVideo", img); //显示每一帧图片
		cvWaitKey(5);				//帧率
		//判断是否存在frame文件夹，没有则创建
		if (_access("../Image", 0) == -1)
			_mkdir("../Image");
		//为每一帧图片进行命名，
		sprintf(image_name, "%s%d%s", "../Image/frame", ++i, ".jpg");//保存的图片名 
		cvSaveImage(image_name, img); //保存一帧图片 
	}
	cvReleaseImage(&img);
	cvReleaseCapture(&capture);
	cvDestroyWindow("RawVideo");
	return 0;
}