/*###############################################################################x
#      This program plots batman function by taking random x coordinate.      #
###############################################################################*/

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <stdio.h>
#include <opencv2/features2d.hpp>

using namespace cv;
using namespace std;

vector<float> F(float x);

int main(int argc, char **argv){
  srand (time(NULL));
  Mat m = cv::Mat(cv::Size(1000, 1000), CV_64FC3, Scalar(255,255,255));

  
  for (;;){ 
    //Batman
    //Lets set the origin at the centre of image.
    //
    float x = (rand()%16)+((rand()%10)/10.0)+((rand()%10)/100.0)-8.00; //randomly choosing the x-coordinate.

    //pixel location is 50*x+tenth_val*50+100th_val*50;
    vector <float> ys = F(x);
    //once tenth hundreth
    int a = int(x)*50; //increasing resolution. 0.02 is one pixel
    int b = int((x-(a/50.))*50);
    int c = int((x-((a/50.)+(b/50.)))*50);
    int x0 = a+b+c+500; //+500 to shift origin
    
    for(int i=0; i<ys.size(); i++){
      int a = int(ys[i])*50;
      int b = int((ys[i]-(a/50.))*50);
      int c = int((ys[i]-((a/50.)+(b/50.)))*50);
      int y0 = 1000-(a+b+c+600);
      circle(m,Point(x0,y0),2,Scalar (0, 0, 255),-1);
    
    }
    imshow("live",m);
    if (waitKey(5) >= 0)
      break;
  }

  return 0;
}
//Batman Function
vector <float> F(float x){
  vector <float>ys;
  
  if(fabs(x)>3){
    float y = 3.0*sqrt(-((x/7.0)*(x/7.0))+1);
    if(!isnan(y)){
      ys.push_back(y);
    }
    }
  if(fabs(x)>4){
    float y = -3.0*sqrt(-((x/7.0)*(x/7.0))+1.0);
    if(!isnan(y)){
    ys.push_back(y);
    }
  }
  if(true){
  float y = fabs(x/2.0)-((((3.0*sqrt(33))-7.0)/112.0)*(x*x))+sqrt(1.0-((fabs(fabs(x)-2.0)-1.)*(fabs(fabs(x)-2.0)-1.)))-3.0;
    if(!isnan(y)){
    ys.push_back(y);
    }
    }
  if(fabs(x)>0.75 && fabs(x)<1.0){
    float y = 9.0-(8.0*fabs(x));
    if(!isnan(y)){
    ys.push_back(y);
    }
  }

  if(fabs(x)>0.5 && fabs(x)<0.75){
    float y = (3.0*fabs(x))+0.75;
    if(!isnan(y)){
    ys.push_back(y);
    }
  }
  if(fabs(x)<0.5){
    float y = 2.25;
    if(!isnan(y)){
      ys.push_back(y);
    }
  }
  if(fabs(x)>1.0){
    float y = 1.5-0.5*fabs(x)-(6.0*sqrt(10)/14.0)*(sqrt(3.0-(x*x)+(2.0*fabs(x)))-2.0);
    if(!isnan(y)){
      ys.push_back(y);
    }
    }

  return ys;
}
