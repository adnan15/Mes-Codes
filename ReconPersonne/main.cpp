/* 
 * File:   main.cpp
 * Author: abdi
 *
 * Created on 31 octobre 2013, 10:48
 */

#include <cstdlib>
#include "getFonctions.h"
#include <Qt/QtGui>
//#include "Personne.h"
//#include "Personne.cpp"
#include <iostream>

using namespace std;
using namespace cv;

/**********************Declaration des variables****************************/
char key;
char keyS;
int nombre;
vector<Mat> images;
vector<int> labels;
IplImage* new_image;
IplImage Gray;
CvHaarClassifierCascade *visage;
CvHaarClassifierCascade *yeux;
CvMemStorage *storage;
Ptr<FaceRecognizer> model ;
Mat face_resized;
Mat reconstructedFace;
Mat imGray,imDepth;
int predicted;
int confiance;
const char *filename;
const char *filename1;
getFonctions fonction;

/***************************Main Programme*********************************/
int main(int argc, char** argv) {
//Classifier    
filename= "haarcascades/haarcascade_frontalface_alt.xml";
visage = (CvHaarClassifierCascade*)cvLoad(filename);

filename1= "haarcascades/haarcascade_eye.xml";
//yeux = (CvHaarClassifierCascade*)cvLoad(filename1);

//Creation des fenetres
namedWindow("grayImage",1);
//namedWindow("Detection1",1);
//namedWindow("depthMap",1);

//memoire
storage = cvCreateMemStorage(0);
//Camera PC
VideoCapture capture(0);

//Camera Kinect
//VideoCapture capture(CV_CAP_OPENNI);

//Creation de model images et labels
fonction.Ficherface(images,labels);

//Tant que La touche q n'est pas touché
while(key != 'q') {  
     if(!capture.isOpened()){ 
                cout << "Pas de Kinect Dectecté";
        } 
        capture.grab();

        
        //image gris
       // capture.retrieve( imGray, CV_CAP_OPENNI_GRAY_IMAGE );
        
         //image couleur
        capture.retrieve( imGray, CV_CAP_OPENNI_BGR_IMAGE );
        //imshow("grayImage", imGray);
        Gray=imGray;
        new_image = &Gray;
        //IplImage *Grays=imGray;
        
        //Dection du visage
        fonction.Detect_visage(new_image,visage,storage);
        
        //Dection des yeux
        //fonction.Detection(new_image,yeux,storage);
        //face_resised
        face_resized = fonction.Face_resized(new_image);
       if(new_image){
        fonction.Traitement(face_resized);
        
        // Reconstruction du visage
        reconstructedFace = fonction.Eigenface(face_resized);
        imshow("original", reconstructedFace);
        
        //Calcul de la similarité

        double similarity = fonction.GetSimilarity(face_resized,reconstructedFace);
        predicted = fonction.Prediction(face_resized);
        
        //Fenetre Confiance
        //int con;
        //cvCreateTrackbar( "Confiance","grayImage",&con, 2000);
        //int confiance = fonction.confiance(face_resized);
        //cvSetTrackbarPos("Confiance", "grayImage",confiance);
        
       // fonction.Tracer(confiance,"grayImage");
        //cout << similarity;
        fonction.Verifie_perso(similarity,predicted);
        //fonction.Tracer(new_image,"predicted");
       // cout << similarity << endl;
     

        }

       // cvResetImageROI(new_image);
        //fonction.Tracer(imGray);
        //cvShowImage("grayImage", new_image);
       imshow("grayImage", imGray);
        key = cvWaitKey(10);
        
        } 
//cin >> nombre;
//if(nombre==1){
//    while(keyS != 'a')
//    //for(i=0;i<300;i++)
//    {
//         
//        cout<<"in the while "<<endl;
//                keyS = cvWaitKey(0);
//    }
//}
 cvReleaseImage(&new_image);
 //Liberer la memoire
 //cvDestroyWindow("depthMap");  
 cvDestroyWindow("grayImage");
 //cvDestroyWindow("Detection1");
 cvReleaseHaarClassifierCascade(&visage);
 cvReleaseHaarClassifierCascade(&yeux);
 cvReleaseMemStorage(&storage);
return 0; 
}
