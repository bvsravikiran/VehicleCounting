#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/video.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace cv;

stringstream SSCountl
Mat Frame;
Mat MaskedFrame;
Ptr<BackgroundSubtractor> BackgroundSubtractorObject;
int Keyboard, CarCount=0;
void ProcessVideo(char* VideoFileName);

int main(int argc, char* argv[])
{
<<<<<<< HEAD
  namedWindow("Frame");
  namedWindow("MaskedFrame");
  BackgroundSubtractorObject = createBackgroundSubtractorMOG2();
  ProcessVideo(argv[1]);
  destroyAllWindows();
  return EXIT_SUCCESS;
}

ProcessVideo(char* VideoFileName){
  VideoCapture capture(VideoFileName);
  if(!capture.isOpened()){
    cerr << "Unable to open video file" << VideoFileName <<endl;
    exit(EXIT_FAILURE);
  }
  while ((char)Keyboard!='q' && (char)Keyboard!=27)) {
    if(!capture.read(Frame)){
      cerr << "Unable to read video" <<endl;
      exit(EXIT_FAILURE);
=======
    //create GUI windows
    namedWindow("Frame");
    namedWindow("FG Mask MOG 2");
    //create Background Subtractor objects
    pMOG2 = createBackgroundSubtractorMOG2(); //MOG2 approach
        //input data coming from a video
        processVideo(argv[1]);
    //destroy GUI windows
    destroyAllWindows();
    return EXIT_SUCCESS;
}
void processVideo(char* videoFilename) {
    //create the capture object
    VideoCapture capture(videoFilename);
    if(!capture.isOpened()){
        //error in opening the video input
        cerr << "Unable to open video file: " << videoFilename << endl;
        exit(EXIT_FAILURE);
    }
    //read input data. ESC or 'q' for quitting
    while( (char)keyboard != 'q' && (char)keyboard != 27 ){
        //read the current frame
        if(!capture.read(frame)) {
            cerr << "Unable to read next frame." << endl;
            cerr << "Exiting..." << endl;
            exit(EXIT_FAILURE);
        }
        //update the background model
        pMOG2->apply(frame, fgMaskMOG2);
        //get the frame number and write it on the current frame
        stringstream ss;
        rectangle(frame, cv::Point(10, 2), cv::Point(100,20),
                  cv::Scalar(255,255,255), -1);
        ss << capture.get(CAP_PROP_POS_FRAMES);
        string frameNumberString = ss.str();
        putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
                FONT_HERSHEY_SIMPLEX, 0.5 , cv::Scalar(0,0,0));
        //show the current frame and the fg masks
	line(frame,Point(100,150),Point(120,180),Scalar( 0, 255, 0),8,0);
	if(frameNumberString>"500" && frameNumberString<"550"){
	Scalar intensity = fgMaskMOG2.at<int>(165, 110); 
	cout<<endl<<intensity.val[0]<<endl;
	}
	imshow("Frame", frame);	
	imshow("FG Mask MOG 2", fgMaskMOG2);
        //get the input from the keyboard
        keyboard = waitKey( 30 );
>>>>>>> origin/master
    }
  BackgroundSubtractorObject->apply(Frame, MaskedFrame);
  stringstream ss;
  rectangle(Frame, Point(10,2), Point(100,20), Scalar(255,255,255), -1);
  ss << capture.get(CAP_PROP_POS_FRAMES);
  string FrameNumberString = ss.str();
  putText(Frame, FrameNumberString.c_str(), Point(15,15), FONT_HERSHEY_SIMPLE, 0.5, Scalar(0,0,0));
  imshow("Frame", Frame);
  imshow("MaskedFrame", MaskedFrame);
  Keyboard = waitKey(30);
}
