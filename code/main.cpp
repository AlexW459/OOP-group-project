#include <iostream>
#include <filesystem>
#include <fstream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;
using namespace std;
int main()
{
    string image_path = "../resources/AUDBF.png";
    Mat img = imread(image_path, IMREAD_COLOR);

    

    Rect newRect = Rect(20, 20, 100, 100);
    rectangle(img, newRect, Scalar(0, 255, 0), FILLED);

    imshow("Display window", img);
    int k = waitKey(0); // Wait for a keystroke in the window
    return 0;
}