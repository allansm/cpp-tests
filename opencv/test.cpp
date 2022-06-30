#include <opencv2/opencv.hpp>

using namespace cv;

main(int argc, char ** argv){
	VideoCapture cap(argv[1]);

	int i = 0;
	while(cap.isOpened()){
		if(i++ == cap.get(CAP_PROP_FRAME_COUNT)){
			cap.set(CAP_PROP_POS_FRAMES, 0);
			
			i=0;
		}

		Mat frame;
		
		bool res = cap.read(frame);
		
		if(res){
			imshow("", frame);
		}
		
		waitKey(1);
	}
}
