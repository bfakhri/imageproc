#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
int main()
{
 const char* imagename = "test.jpg"; //the input image location
 cv::Mat img = cv::imread(imagename);
 if(img.empty())
 return -1;
 if(!img.data)
 return -1;
 cv::namedWindow("image", CV_WINDOW_AUTOSIZE);
 cv::imshow("image", img);
 cv::waitKey();
 return 0;
}
