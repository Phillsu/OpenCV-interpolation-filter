#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;




void nearest_neighbor(Mat image);
void linear(Mat image);
void to_Graylabel(Mat image);
void to_Graylabel_sobel_filter(Mat image);
void signature(Mat image);

int main(int argc, char** argv)
{
    //Åª¹Ï

    if (argc != 2)
    {
        cout << " Usage: " << argv[0] << " ImageToLoadAndDisplay" << endl;
        return -1;
    }

    Mat image;
    image = imread(argv[1], IMREAD_COLOR); // Read the file
    if (image.empty()) // Check for invalid input
    {
        cout << "Could not open or find the image" << std::endl;
        return -1;
    }
    namedWindow("Oringinal_image", WINDOW_AUTOSIZE); // Create a window for display.
    imshow("Oringinal_image", image); // Show our image inside it.

    waitKey(0); // Wait for a keystroke in the window       

    nearest_neighbor(image);
    linear(image);
    to_Graylabel(image);
    signature(image);
    return 0;
}

void nearest_neighbor(Mat image) {
    int w = image.cols;
    int h = image.rows;
    int channel = image.channels();

    int new_width = w * 3;
    int new_height = h * 3;
    int prex, prey;
    
    Mat out(new_height , new_width, CV_8UC3); 

    for (int y = 0; y < new_height; y++) {
        prey = y / 3; 
        prey = fmin(prey, h);
        for (int x = 0; x < new_width; x++) {
            prex = x / 3;
            prex = fmin(prex,w);
            out.at<Vec3b>(y, x)[0] = image.at<Vec3b>(prey, prex)[0]; 
            out.at<Vec3b>(y, x)[1] = image.at<Vec3b>(prey, prex)[1];
            out.at<Vec3b>(y, x)[2] = image.at<Vec3b>(prey, prex)[2];
        } 
    }
    namedWindow("Nearest_neighbor", WINDOW_AUTOSIZE); 
    imshow("Nearest_neighbor", out); 
    waitKey(0);   
}

void linear(Mat image) {

    int w = image.cols;
    int h = image.rows;
    int channel = image.channels();

    int new_width = w * 3;
    int new_height = h * 3;
    int prex, prey;
    int val = 0;

    Mat out(new_height, new_width, CV_8UC3);

    for (int y = 0; y < new_height; y++) {

        for (int x = 0; x < new_width; x++) {

            
            val;
            out.at<uchar>(y, x) = val;
            
        }
    }
    namedWindow("Linear", WINDOW_AUTOSIZE); 
    imshow("Linear", out); 
    waitKey(0);       
}

void to_Graylabel(Mat image) {

    int w = image.cols;
    int h = image.rows;
    int channel = image.channels();

    Mat gray(h,w,CV_8UC3);

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            gray.at<Vec3b>(j, i)[0] = ( 0.1 * image.at<Vec3b>(j, i)[0] + 0.6 * image.at<Vec3b>(j, i)[1] + 0.3 * image.at<Vec3b>(j, i)[2]);
            gray.at<Vec3b>(j, i)[1] = (0.1 * image.at<Vec3b>(j, i)[0] + 0.6 * image.at<Vec3b>(j, i)[1] + 0.3 * image.at<Vec3b>(j, i)[2]);
            gray.at<Vec3b>(j, i)[2] = (0.1 * image.at<Vec3b>(j, i)[0] + 0.6 * image.at<Vec3b>(j, i)[1] + 0.3 * image.at<Vec3b>(j, i)[2]);
        }
    }

    namedWindow("to_Graylabel", WINDOW_AUTOSIZE); 
    imshow("to_Graylabel", gray); 
    waitKey(0);
    to_Graylabel_sobel_filter(gray);
}

void to_Graylabel_sobel_filter(Mat image) {
    int w = image.cols;
    int h = image.rows;
    int channal = image.channels();

    namedWindow("to_Graylabel_sobel_filter", WINDOW_AUTOSIZE); 
    imshow("to_Graylabel_sobel_filter", image);
    waitKey(0);      
}

void signature(Mat image) {
    namedWindow("signature", WINDOW_AUTOSIZE); 
    imshow("signature", image);
    waitKey(0); 
}
