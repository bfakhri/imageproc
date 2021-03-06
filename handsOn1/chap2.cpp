#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace std;
using namespace cv;

int main()
{
		VideoCapture cap(0); // open the default camera
		if (!cap.isOpened()){  // check if we succeeded
			cout << "No capture device opened!" << endl;
			return -1;
		}

		Size S = Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH),    // Acquire input size
			(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT));

		VideoWriter outputVideo;    // open the output
		outputVideo.open("Record.avi", -1, cap.get(CV_CAP_PROP_FPS), S, true);
               
// For Windows, if the above does not work, use the following command instead:
		//outputVideo.open("Record.avi", CV_FOURCC('D', 'I', 'V', '3'), cap.get(CV_CAP_PROP_FPS), S, true);
// For MAC OS, if the above does not work, use the following instruction instead:
                //outputVideo.open("Record.avi", CV_FOURCC('S', 'V', 'Q', '3'), 30.0, S, true);
/*
		if (!outputVideo.isOpened())
		{
			cout << "Could not open the output video for write: " << endl;
			return -1;
		}
*/
		namedWindow("Video", 1);
		cout << "Start Reading and Writing" << endl;

		int cnt = 0;
		while (cnt<200)
		{
			Mat frame;
			cap >> frame; // get a new frame from camera
			outputVideo << frame;  // store the frame to the output video file

			imshow("Video", frame);
			if (waitKey(30) >= 0) break;
			cnt++;
		}
		// the camera will be deinitialized automatically in VideoCapture destructor
		cout << "Finished Writing" << endl;

		return 0;
}

