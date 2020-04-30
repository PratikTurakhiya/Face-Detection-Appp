// FaceIdentifiction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<stdlib.h>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<opencv2\highgui\highgui.hpp>
using namespace std; 
using namespace cv;
int main()
{
    CascadeClassifier fd;
    if (!fd.load("C:\\Users\\INFINIUM\\Downloads\\Programs\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml"))
    {
        cout << "file not loded";
        exit(0);
    }
    char path[100];
    cout << "enter the path image:";
    cin.getline(path, 100);
    Mat img = imread(path);
    if (img.empty())
    {
        cout << "image is not loded";
    }
    else

    {
        cout << "\nimage found";
        cout << "\nprocessing...";
        vector<Rect> faces;
        fd.detectMultiScale(img, faces);
        for (int i = 0; i < faces.size(); i++)
        {
            Point pt1(faces[i].x, faces[i].y);
            Point pt2((faces[i].x+ faces[i].height), (faces[i].y + faces[i].width));
            rectangle(img, pt1, pt2, Scalar(0, 0, 255), 2, 8, 0);
        }
        imwrite("C:\\project\\output.jpg", img);
        cout << "\n face detected";
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
