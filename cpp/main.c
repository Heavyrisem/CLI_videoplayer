/**
@file videocapture_basic.cpp
@brief A very basic sample for using VideoCapture and VideoWriter
@author PkLab.net
@date Aug 24, 2016
*/

#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/videoio.hpp"
#include <iostream>
#include <stdio.h>

#include <stdlib.h>

//using namespace cv;
using namespace std;

void main()
{
   char CHARS[13] = { ' ',',', '.', '-', '~', ':', ';', '=', '!', '*', '#', '$', '@' };
   int nw = 350;
   int h, w = 0;
   int nh = 0;

   cv::VideoCapture cap;
   cap.open("C:/Users/insu/Desktop/Develop/ASCIIimg/F1.mp4");
   cv::Mat frame;
   while (true) {
      printf("\x1b[2J");
      //cout << "\x1b[2J" << endl;
      //system("cls");

      cap >> frame;
      cv::cvtColor(frame, frame, cv::COLOR_RGB2GRAY);
      w = frame.cols;
      h = frame.rows;
      nh = (int)((double)h / (double)w * nw);

      cv::resize(frame, frame, cv::Size(nw, nh));

      //int counter = 0;
      //char line[351*352] = "";
      for (int i = 0; i < frame.rows; i++) {
         char line[351] = "";
         for (int j = 0; j < frame.cols; j++) {
            uchar t = frame.at<uchar>(i, j);
            line[j] = CHARS[(int)((double)t / 255 * sizeof(CHARS) / sizeof(char)-1 )];
            //printf("%c\n", CHARS[(int)((double)t / 255 * sizeof(CHARS) / sizeof(char))]);
            //counter++;
         }
         printf("%s\n", line);
         //line[counter] = '\n';
         //counter++;
      }
      //printf("%s", line);
      //cout << line << flush;

      if (frame.empty()) {
         cout << "Could Not load the video frames. \n";
         break;
      }
      //cv::imshow("F1", frame);
   }
}