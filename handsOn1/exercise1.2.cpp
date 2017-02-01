// Bijan Fakhri
// Exercise 1.1
// 2-2-17

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	// A)
	const char* imagename = "bird.jpg";	// Name of image
	cv::Mat img = cv::imread(imagename);	// Read image into Mat

	// Checks to make sure image loaded properly
	if(img.empty() || !img.data){
		std::cout << "Error loading image" << std::endl;
		return -1;
	}

	// B) Show the original image
	cv::namedWindow("Birdie", CV_WINDOW_AUTOSIZE);
	cv::imshow("Birdie", img);
	cv::waitKey();					// Waits for keypress before destroying window
	cv::destroyWindow("Birdie");

	// C) Show the image after Laplacian operator
	cv::Mat laplace(img.size(), img.type());	// Make identical image shell
	CvMat cvimg = img;
	CvMat cvlaplace = laplace;
	cvLaplace(&cvimg, &cvlaplace);			// Performs laplace filter
	cv::namedWindow("Birdie Laplace Edges", CV_WINDOW_AUTOSIZE);
	cv::imshow("Birdie Laplace Edges", laplace);
	cv::imwrite("laplace_bird.jpg", laplace);	// Writes laplacian edges to file 
	cv::waitKey();					// Waits for keypress before destroying window
	cv::destroyWindow("Birdie Laplace Edges");

	// D) Show the image after Sobel operator
	cv::Mat sobel(img.size(), img.type());		// Make identical image shell
	CvMat cvsobel = sobel;
	cvSobel(&cvimg, &cvsobel, 1, 1);		// Performs Sobel Filter
	cv::namedWindow("Birdie Sobel Edges", CV_WINDOW_AUTOSIZE);
	cv::imshow("Birdie Sobel Edges", sobel);
	cv::imwrite("sobel_bird.jpg", sobel);		// Write sobel edge image to file 
	cv::waitKey();					// Waits for keypress before destroying window
	cv::destroyWindow("Birdie Sobel Edges");

	// E) Show the image after Canny operator
	cv::Mat canny(img.size(), CV_8U);		// Make identical image shell
	CvMat cvcanny = canny;
	cvCanny(&cvimg, &cvcanny, 25, 60);		// Performs Canny Filter
	cv::namedWindow("Birdie Canney Edges", CV_WINDOW_AUTOSIZE);
	cv::imshow("Birdie Canney Edges", canny);
	cv::imwrite("canny_bird.jpg", canny); 		// Write canny edge image to file
	cv::waitKey();					// Waits for keypress before destroying window
	cv::destroyWindow("Birdie Canney Edges");

	return 0;
}
