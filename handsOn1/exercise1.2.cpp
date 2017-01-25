#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


int main()
{
	// A)
	const char* imagename = "bird.jpg";	// Name of image
	cv::Mat img = cv::imread(imagename);	// Read image into Mat

	if(img.empty())
		return -1;

	if(!img.data)
		return -1;

	// B) Show the original image
	cv::namedWindow("Birdie", CV_WINDOW_AUTOSIZE);
	cv::imshow("Birdie", img);
	cv::waitKey();
	cv::destroyWindow("Birdie");

	// C) Show the image after Laplacian operator
	cv::Mat laplace(img.size(), img.type());	// Make identical image shell
	CvMat cvimg = img;
	CvMat cvlaplace = laplace;
	cvLaplace(&cvimg, &cvlaplace);
	cv::namedWindow("Birdie Laplace Edges", CV_WINDOW_AUTOSIZE);
	cv::imshow("Birdie Laplace Edges", laplace);
	cv::imwrite("laplace_bird.jpg", laplace); 
	cv::waitKey();
	cv::destroyWindow("Birdie Laplace Edges");

	// D) Show the image after Sobel operator
	cv::Mat sobel(img.size(), img.type());		// Make identical image shell
	CvMat cvsobel = sobel;
	cvSobel(&cvimg, &cvsobel, 1, 1);
	cv::namedWindow("Birdie Sobel Edges", CV_WINDOW_AUTOSIZE);
	cv::imshow("Birdie Sobel Edges", sobel);
	cv::imwrite("sobel_bird.jpg", sobel); 
	cv::waitKey();
	cv::destroyWindow("Birdie Sobel Edges");

	// E) Show the image after Canny operator
	cv::Mat canny(img.size(), CV_8U);		// Make identical image shell
	CvMat cvcanny = canny;
	cvCanny(&cvimg, &cvcanny, 25, 60);
	cv::namedWindow("Birdie Canney Edges", CV_WINDOW_AUTOSIZE);
	cv::imshow("Birdie Canney Edges", canny);
	cv::imwrite("canny_bird.jpg", canny); 
	cv::waitKey();
	cv::destroyWindow("Birdie Canney Edges");

	return 0;
}
