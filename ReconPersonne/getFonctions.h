#ifndef GETFONCTIONS_H
#define	GETFONCTIONS_H
#include <cv.h>
#include <highgui.h>
#include "opencv2/core/core.hpp"
#include "lire_xml.h"
#include "Personne.h"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"

class getFonctions {
public:
    //getFonctions();
    //cv::Mat getCaptureGRAY(cv::Mat grayImage);
    cv::Mat Normaliser(cv::Mat image);
    double GetSimilarity(const cv::Mat image1,const cv::Mat image2);
    void Ficherface(std::vector<cv::Mat> & images,std::vector<int> labels);
    void Detect_visage(IplImage *img,CvHaarClassifierCascade *visage,CvMemStorage* storage);
    void Detection(IplImage *img,CvHaarClassifierCascade *yeux,CvMemStorage* storage);
    cv::Mat Eigenface(cv::Mat face_resized);
    void Enregistrer(IplImage *img);
    cv::Mat Face_resized(IplImage *img);
    double Prediction(cv::Mat face_resized);
    double Confiance(cv::Mat face_resized);
    void Verifie_perso(double similarity,int predicted);
    cv::Mat Traitement(cv::Mat face_resized);
    void Tracer(cv::Mat imGray);
   // cv::Rect getFonctions::drawButton(cv::Mat img, std::string text, cv::Point coord,int minWidth = 0);
   // cv::Rect drawString(cv::Mat img, std::string text, cv::Point coord, cv::Scalar color, float fontScale, int thickness,
//int fontFace);
private:
    CvSeq *Dect;
    cv::Ptr<cv::FaceRecognizer> model ;
    IplImage *dste;
    IplImage *dstGraye ;
    cv::Mat original;
    double confiance;
    int predicted ;
    int i;
};

#endif	/* GETFONCTIONS_H */

