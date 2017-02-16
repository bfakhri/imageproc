// Bijan Fakhri
// Exercise 1.1
// 2-2-17

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	std::cout << "OpenCV Version: " << CV_MAJOR_VERSION << "." << CV_MINOR_VERSION << std::endl;
	// A)
	// B) Load and display the image 
	const char* imagename = "zebras.jpg";	// Name of image
	cv::Mat img = cv::imread(imagename, CV_LOAD_IMAGE_GRAYSCALE);	// Read image into Mat
	std::cout << "Image is of type: " << img.type() << " and has: " << img.channels() << " channels" << std::endl;
	std::cout << "Image is of shape: (" << img.rows << ", " << img.cols << ")" << std::endl;

	// Checks to make sure image loaded properly
	if(img.empty() || !img.data){
		std::cout << "Error loading image" << std::endl;
		return -1;
	}

	cv::namedWindow("Zebras", CV_WINDOW_AUTOSIZE);
	cv::imshow("Zebras", img);
	cv::waitKey();					// Waits for keypress before destroying window
	cv::destroyWindow("Zebra");

	// C) Compute the DFT matrix F(K1, K2)
	// Compute the DFT
	cv::Mat img_dft;
	cv::Mat dft_inv;
	for(int L=255; L>1; L-=10){
		// Convert to right format
		img.convertTo(img, CV_32FC1);
		// Perform the DFT
		cv::dft(img, img_dft, cv::DFT_SCALE|cv::DFT_COMPLEX_OUTPUT);
		// Perform truncation with L
		for(int r=L; r<img_dft.rows-L; r++){
			for(int c=L; c<img_dft.cols-L; c++){
				img_dft.at<int>(r,c) = 0;
			}
		}
				
		// Get inverse of DFT
		cv::dft(img_dft, dft_inv, cv::DFT_INVERSE|cv::DFT_REAL_OUTPUT);
		std::cout << "L = " << L << std::endl;
		// Convert back to CV_8UC1 and Display
		dft_inv.convertTo(dft_inv, CV_8U);	
		//cv::imwrite(dft_in
		cv::namedWindow("Zebras", CV_WINDOW_AUTOSIZE);
		cv::imshow("Zebras", dft_inv);
		cv::waitKey();					// Waits for keypress before destroying window
		cv::destroyWindow("Zebra");
	}
	

	return 0;
}
