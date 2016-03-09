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
