#include "getFonctions.h"


using namespace std;
using namespace cv;
////getFonctions::getFonctions() {
//}
////Fonction pour avoir les images de la Kinect
//Mat getFonctions::getCaptureGRAY(Mat grayImage){ 
//if(!capture.isOpened()){ 
//cout << "Pas de Kinect Dectecté";
//} 
//capture.grab();
//capture.retrieve( grayImage, CV_CAP_OPENNI_GRAY_IMAGE );
//return grayImage;
//}
/********************Fonction pour normaliser une Image************************/
Mat getFonctions::Normaliser(Mat image){
  Mat nor_img;
  switch(nor_img.channels()){
      case 1:
          normalize(image,nor_img,0,255,NORM_MINMAX,CV_8UC1);
          break;
      case 3:
          normalize(image,nor_img,0,255,NORM_MINMAX,CV_8UC3);
          break;
      default:
          image.copyTo(nor_img);
          break;
  }
  return nor_img;
}
/******************Fonction Calcul de la similarité entre deux images**********/
double getFonctions::GetSimilarity(Mat image1,Mat image2){
double normL2=norm(image1,image2,CV_L2);
double similarity = normL2/(double)(image1.rows*image1.cols);
return similarity;
}
/************************Fonction Ficherface***********************************/
void getFonctions::Ficherface(vector<Mat> & images,vector<int> labels){
    lire_xml file;
    file.acquerir(images, labels);
    //cout << images.size();
    //images.pop_back();
    //labels.pop_back();
    //for(int i = 0;i < images.size();i++)
    //{
       // Traitement(images[i]);
        //imshow("original1", images[2]);
    //}
    model = createFisherFaceRecognizer();
    model->train(images, labels);
}
/**********************Fonction detecter visage********************************/
void getFonctions::Detect_visage(IplImage *img,CvHaarClassifierCascade *visage,CvMemStorage* storage){ 
    CvSeq *face = cvHaarDetectObjects(img, visage, storage, 1.1,2,0,cvSize(10,10)); 
if (visage) {
    for(int i=0; i<(face?face->total:0); i++){
        CvRect *r = (CvRect*)cvGetSeqElem(face, i);      
        cvRectangle(img, cvPoint(r->x, r->y), cvPoint(r->x + r->width, r->y + r->height), CV_RGB(255, 255, 0), 1, 8, 0); 
        cvSetImageROI(img, *r);
    }
} 
}
/**********************Fonction detecter des yeux********************************/
void getFonctions::Detection(IplImage *img,CvHaarClassifierCascade *dect,CvMemStorage* storage){ 
    Dect = cvHaarDetectObjects(img, dect, storage, 1.1,2,0,cvSize(10,10)); 
if (dect) {
    for(int i=0; i<(Dect?Dect->total:0); i++){
        CvRect *r = (CvRect*)cvGetSeqElem(Dect, i);      
        cvRectangle(img, cvPoint(r->x, r->y), cvPoint(r->x + r->width, r->y + r->height), CV_RGB(255, 255, 0), 1, 8, 0); 
        //cvSetImageROI(img, *r);
    }
} 
}
/*********************Fonction Image Reconstruite***************************************/
Mat getFonctions::Eigenface(Mat face_resized){
    //Obtenir les vecteurs propres 
Mat eigenvectors = model->get<Mat>("eigenvectors");
    //Obtenir la moyenne
Mat moyenne= model->get<Mat>("mean");
   
Mat projection = subspaceProject(eigenvectors, moyenne,face_resized.reshape(1,1));
Mat reconstructionRow = subspaceReconstruct(eigenvectors,moyenne, projection);
Mat reconstructionMat = reconstructionRow.reshape(1,face_resized.rows);
Mat reconstructedFace = Mat(reconstructionMat.size(), CV_8U);
reconstructedFace = Normaliser(reconstructedFace.reshape(1, face_resized.rows));
reconstructionMat.convertTo(reconstructedFace, CV_8U, 1, 0);

return reconstructedFace;
}
/************************Fonction Enregistrer**********************************/
void Enregistrer(IplImage *img){
    char s[] = "/home/abdi/Bureau/ab.jpeg";
    IplImage *monImg = cvCreateImage(cvGetSize(img), img->depth, img->nChannels);
    cvCopy(img, monImg, NULL);
    IplImage *dste = cvCreateImage(cvSize(200, 250),monImg->depth,3);
    IplImage *dstGraye = cvCreateImage(cvSize(200, 250),dste->depth,1);
         // Redimensionne l'image
    cvResize(monImg,dste, CV_INTER_LINEAR );
        // Convertie en matrice et en niveaux de gris
    cvCvtColor(dste, dstGraye, CV_RGB2GRAY);
         // Enregistre l'image retraitée
    cvSaveImage(s, dstGraye);
    cvResetImageROI(img);
    
}
/************************Fonction Reconnaissance*******************************/
Mat getFonctions::Face_resized(IplImage *img){ 
   //fonction visage redimensionné 
        int width=400;
        dste = cvCreateImage(cvSize(width, width),img->depth,3);
        dstGraye = cvCreateImage(cvSize(width, width),dste->depth,1);
        // Redimensionne l'image
        cvResize(img,dste, CV_INTER_LINEAR );
        //Convertie en matrice et en niveaux de gris
        cvCvtColor(dste, dstGraye, CV_RGB2GRAY);
        original = dstGraye;
        Mat face_resized;
        //imshow("ImageGray", original);
        resize(original, face_resized, Size(width,width), 1.0, 1.0, INTER_CUBIC);
        //imshow("original", face_resized);
        
        return face_resized;
}
/************************Fonction Reconnaissance*******************************/
double getFonctions::Prediction(Mat face_resized){
    double confiance = -1.0;
    int predicted = -1;
    model->predict(face_resized, predicted, confiance);
    
    return predicted;
}
double getFonctions::Confiance(Mat face_resized){
    confiance = -1.0;
    predicted = -1;
    model->predict(face_resized, predicted, confiance);
    
    return confiance;
}
void getFonctions::Verifie_perso(double similarity,int predicted){ 
   //fonction reconnaissance du visage
  //  if (similarity < 0.14 && similarity > 0.1) {
        vector<string> nom;
        vector<int> indices;
        lire_xml perso;
        perso.recherche(nom, indices);
        for (i = 0; i != nom.size(); i++){
         if(predicted==indices[i]){
          std::cout << similarity << " " << nom[i] << std::endl;
          //exit(EXIT_SUCCESS);
           }
       }
   // }
    
}
/************************Fonction Traitement*******************************/
Mat getFonctions::Traitement(Mat face_resized){ 
Mat warped = Mat(face_resized.rows, face_resized.rows, CV_8U, Scalar(128));
        Mat mask = Mat(warped.size(), CV_8UC1, Scalar(255));
        Point faceCenter = Point( cvRound(face_resized.rows * 0.5),cvRound(face_resized.rows * 0.4) );
        Size size = Size( cvRound(face_resized.rows * 0.5), cvRound(face_resized.rows * 0.6) );
        ellipse(mask, faceCenter, size, 0, 0, 360, Scalar(0),
CV_FILLED);
// Apply the elliptical mask on the face, to remove corners.
// Sets corners to gray, without touching the inner face.
face_resized.setTo(Scalar(128), mask);

return face_resized;
}
//tracer
void getFonctions::Tracer(Mat imGray){ 
string text = "Face dection";
int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
double fontScale = 2;
int thickness = 3;

int baseline=0;
Size textSize = getTextSize(text, fontFace,
                            fontScale, thickness, &baseline);
baseline += thickness;

// center the text
Point textOrg((imGray.cols - textSize.width)/2,
              (imGray.rows + textSize.height)/10);

// draw the box
rectangle(imGray, textOrg + Point(0, baseline),
          textOrg + Point(textSize.width, -textSize.height),
          Scalar(0,0,255));
line(imGray, textOrg + Point(0, thickness),
     textOrg + Point(textSize.width, thickness),
     Scalar(0, 0, 255));

// then put the text itself
putText(imGray, text, textOrg, fontFace, fontScale,
        Scalar::all(255), thickness, 8);
}