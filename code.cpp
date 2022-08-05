#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///// webcam ///////
void main(){
	VideoCapture cap(0);
	Mat img ;

	CascadeClassifier plateCascade;

	plateCascade.load("Resources/haarcascade_russian_plate_number.xml");
	if(plateCascade.empty()){
	cout<< "xml file is not present "; 
	}
	vector<React> plates;

	while(true){
       cap.read(img);

       plateCascade.detectMultiScale(img,plates,1.1,10);

       for(int i=0;i<plates.size();i++){
         Mat imCrop=img(plates[i]);
       //  imshow(to_string(i),imgCrop);
       imwrite("Resources/Plates/"+to_string(i)+".png",imgCrop);
       rectangle(img,plates[i].tl(),plates.br(),Scalar(255,0,255),3);
       }

      imshow("Image",img);
      waitKey(1);
	}





}

