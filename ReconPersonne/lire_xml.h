/* 
 * File:   lire_xml.h
 * Author: abdi
 *
 * Created on 4 novembre 2013, 13:53
 */

#ifndef LIRE_XML_H
#define	LIRE_XML_H
#include <list>
#include <vector>
#include <cv.h>
#include <highgui.h>
#include "tinyxml/tinyxml.h"
#include "tinyxml/tinystr.h"
#include "Personne.h"

class lire_xml {
 public:
        int acquerir(std::vector<cv::Mat>& images, std::vector<int>& labels);
        int recherche(std::vector<std::string>& nom, std::vector<int>& indices);
    private:
        TiXmlDocument *doc;
        TiXmlElement *elem;
        TiXmlElement *elem1;
        TiXmlElement *elem2;
        TiXmlElement *elem3;
        TiXmlElement *elem4;
        TiXmlElement *elem5;
        TiXmlText *text;
        std::vector<int> labels;
        std::vector<cv::Mat> images;
};

#endif	/* LIRE_XML_H */

