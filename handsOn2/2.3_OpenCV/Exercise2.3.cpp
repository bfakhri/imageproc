// Bijan Fakhri
// Exercise 2.3
// 2-16-17

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	std::cout << "OpenCV Version: " << CV_MAJOR_VERSION << "." << CV_MINOR_VERSION << std::endl;

	//////////////////////////////////
	// B) Load and display the image//
	//////////////////////////////////
	const char* imagename = "zebras.jpg";	// Name of image
	cv::Mat img = cv::imread(imagename, CV_LOAD_IMAGE_GRAYSCALE);	// Read image into Mat
	std::cout << "Image is of type: " << img.type() << " and has: " << img.channels() << " channels" << std::endl;
	std::cout << "Image is of shape: (" << img.rows << ", " << img.cols << ")" << std::endl;

	// Checks to make sure image loaded properly
	if(img.empty() || !img.data){
		std::cout << "Error loading image" << std::endl;
		return -1;
	}

	std::cout << "-------------------------------------------------------" << std::endl;
	std::cout << "---Showing Original Image, Press any key to Continue---" << std::endl;
	std::cout << "-------------------------------------------------------" << std::endl;

	cv::namedWindow("Zebras", CV_WINDOW_AUTOSIZE);
	cv::imshow("Zebras", img);
	cv::waitKey();					// Waits for keypress before destroying window
	cv::destroyWindow("Zebra");

	////////////////////////////////////////
	// C) Compute the DFT matrix F(K1, K2)//
	////////////////////////////////////////
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "---Press any Key to Iterate though L(DFT) Values---" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;

	// Compute the DFT and iterate through L values
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
		if(L == 65){
			std::cout << "----------------------------------------------------" << std::endl;
			std::cout << "---Lmin,DFT = 65. This is the Corresponding Image---" << std::endl;
			std::cout << "----------------------------------------------------" << std::endl;
			cv::imwrite("./LminDFT-65.jpg", dft_inv);
		}
		cv::namedWindow("Zebras", CV_WINDOW_AUTOSIZE);
		cv::imshow("Zebras", dft_inv);
		cv::waitKey();					// Waits for keypress before destroying window
		cv::destroyWindow("Zebra");
	}
	
	////////////////////////////////////////
	// D) Compute the DFT matrix D(K1, K2)//
	////////////////////////////////////////
	std::cout << "---------------------------------------------------" << std::endl;
	std::cout << "---Press any Key to Iterate though L(DCT) Values---" << std::endl;
	std::cout << "---------------------------------------------------" << std::endl;
	// Compute the DCT and iterate through L values
	cv::Mat img_dct;
	cv::Mat dct_inv;
	for(int L=255; L>1; L-=10){
		// Convert to right format
		img.convertTo(img, CV_32FC1);
		// Perform the DCT
		cv::dct(img, img_dct);
		// Perform truncation with L
		for(int r=L; r<img_dft.rows; r++){
			for(int c=L; c<img_dft.cols; c++){
				img_dct.at<int>(r,c) = 0;
			}
		}
				
		// Get inverse of DCT
		cv::dct(img_dct, dct_inv, cv::DCT_INVERSE);
		std::cout << "L = " << L << std::endl;
		// Convert back to CV_8UC1 and Display
		dct_inv.convertTo(dct_inv, CV_8U);	
		if(L == 85){
			std::cout << "----------------------------------------------------" << std::endl;
			std::cout << "---Lmin,DCT = 85. This is the Corresponding Image---" << std::endl;
			std::cout << "----------------------------------------------------" << std::endl;
			cv::imwrite("./LminDCT-85.jpg", dft_inv);
		}
		cv::namedWindow("Zebras", CV_WINDOW_AUTOSIZE);
		cv::imshow("Zebras", dct_inv);
		cv::waitKey();					// Waits for keypress before destroying window
		cv::destroyWindow("Zebra");
	}
	

	return 0;
}
