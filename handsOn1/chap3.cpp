#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;

#define NUMCNT 5
#define SEED 123885

int main()
{
	// // Exercise 1
	cout << endl << "----EXERCISE 1----" << endl << endl;
	
	// A)
	cout << "A)" << endl;
	float negNum = -7.23;
	cout<< "Original Floating Point Number: " << negNum << endl;
	cout<< "Floating Point Number after CV_IABS(): " << CV_IABS(negNum) << endl << endl;

	// B)
	cout << "B)" << endl;
	cout<< NUMCNT << " random numbers: " << endl;
	CvRNG rng = cvRNG(SEED);
	for(int i=0; i<NUMCNT; i++){
		cout<< cvRandInt(&rng) << endl;
	}	
	cout << endl;

	// C)
	cout << "C)" << endl;
	CvPoint2D32f pntf = cvPoint2D32f(1.934, 2.448);
	cout << "CvPoint2D32f: (" << pntf.x << ", " << pntf.y << ")" << endl;
	CvPoint pnti = cvPointFrom32f(pntf);
	cout << "CvPoint from cvPoint2D32f: (" << pnti.x << ", " << pnti.y << ")" << endl;
	cout << endl;

	// D)
	cout << "D)" << endl;
	
	// Setup cout so floating point numbers have a decimal point
	cout.unsetf ( std::ios::floatfield );
	cout.precision(1);	// Set mandatory 1 space of precision
	cout.setf( std::ios::fixed, std:: ios::floatfield );
	pnti = cvPoint(853, 123);
	cout << "CvPoint: (" << pnti.x << ", " << pnti.y << ")" << endl;
	pntf = cvPointTo32f(pnti);
	cout << "CvPoint2D32f from CvPoint: (" << pntf.x << ", " << pntf.y << ")" << endl;
	cout << endl;

	// // Exercise 2
	cout << endl << "----EXERCISE 2----" << endl << endl;
	
	// A)
	cout << "Matrix is displayed with circle inside of it" << endl;
	cout << "Press any key to continue: ";
	CvMat * mymat = cvCreateMat(100, 100, CV_8UC3);	// Create the matrix
	// Set all matrix values to zero	
	for(int r=0; r < mymat->rows; r++){
		for(int c=0; c<mymat->cols; c++){
			// Set all channels to zero
			*((char*)(CV_MAT_ELEM_PTR(*mymat, r, c)+0)) = 0;
			*((char*)(CV_MAT_ELEM_PTR(*mymat, r, c)+1)) = 0;
			*((char*)(CV_MAT_ELEM_PTR(*mymat, r, c)+2)) = 0;
		}
	}
	// Make the circle
	cvCircle(mymat, cvPoint(50,50), 25, Scalar(0,255,0));

	// B) Display the image
	cvNamedWindow( "Example 2", CV_WINDOW_AUTOSIZE );
	cvShowImage( "Example 2", mymat );
	cvWaitKey(0);
	cvDestroyWindow( "Example 2" );	
	cout << endl;



	
	
	return 0;
}
