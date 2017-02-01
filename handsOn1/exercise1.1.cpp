// Bijan Fakhri
// Exercise 1.1
// 2-2-17

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
		VideoCapture cap(0);	// open the default camera
		if (!cap.isOpened())	// check if we succeeded
			return -1;

		// Acquire Input Size
		Size S = Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH)/2, (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT)/2);

		VideoWriter outputVideo;    // open the output
               
		// For Windows, if the above does not work, use the following command instead:
		outputVideo.open("Record.avi", CV_FOURCC('D', 'I', 'V', '3'), cap.get(CV_CAP_PROP_FPS), S, true);
		// For MAC OS, if the above does not work, use the following instruction instead:
                // outputVideo.open("Record.avi", CV_FOURCC('S', 'V', 'Q', '3'), 30.0, S, true);

		if (!outputVideo.isOpened()){
			cout << "Could not open the output video for write: " << endl;
			return -1;
		}

		// Create two windows
		namedWindow("Original Video", 1);
		namedWindow("Downsampled Video", 1);
		cout << "Start Reading and Writing" << endl;

		// Capture 200 Frames
		int cnt = 0;
		while (cnt<200)
		{
			Mat frame;
			cap >> frame; // get a new frame from camera
			// Here we downsample
			IplImage orig = frame;
			IplImage * downSmp = cvCreateImage(cvSize(frame.cols/2, frame.rows/2), 8, 3);
			cvPyrDown(&orig, downSmp);
			Mat frameDown = cvarrToMat(downSmp);
			outputVideo << frameDown;  // store the frame to the output video file

			// Display the image
			imshow("Original Video", frame);
			imshow("Downsampled Video", frameDown);
			// End the streams if key is pressed
			if (waitKey(30) >= 0) 
				break;

			// Release the memory alloted to the new image
			cvReleaseImage(&downSmp);

			cnt++;

		}
		// the camera will be deinitialized automatically in VideoCapture destructor
		cout << "Finished Writing" << endl;

		return 0;
}

