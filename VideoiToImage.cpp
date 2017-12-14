//����Ҫ��opencvͷ�ļ�
#include <opencv2/highgui/highgui.hpp> 
#include <cv.h>
//�����ļ�������Ҫ��ͷ�ļ�
#include<io.h>
#include<direct.h>

int main(int argc, char *argv[])
{
	//��ȡ������Ƶ��
	CvCapture* capture = cvCaptureFromFile(R"(C:\Users\Administrator\Desktop\UAV\UAV_InfraredDd_test1.asf)");
	int i = 0;	//֡��
	IplImage* img = NULL;	//�洢֡ͼƬ
	char image_name[25];	//֡�����֣�·����
	cvNamedWindow("RawVideo",CV_WINDOW_AUTOSIZE);
	//��ȡ����ʾ 
	while (1)
	{
		img = cvQueryFrame(capture); //��ȡһ֡ͼƬ 
		//��������while��1��ѭ��������
		if (img == NULL)
			break;

		cvShowImage("RawVideo", img); //��ʾÿһ֡ͼƬ
		cvWaitKey(5);				//֡��
		//�ж��Ƿ����frame�ļ��У�û���򴴽�
		if (_access("../Image", 0) == -1)
			_mkdir("../Image");
		//Ϊÿһ֡ͼƬ����������
		sprintf(image_name, "%s%d%s", "../Image/frame", ++i, ".jpg");//�����ͼƬ�� 
		cvSaveImage(image_name, img); //����һ֡ͼƬ 
	}
	cvReleaseImage(&img);
	cvReleaseCapture(&capture);
	cvDestroyWindow("RawVideo");
	return 0;
}