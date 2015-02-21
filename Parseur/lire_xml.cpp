#include <string>
#include<iostream>
#include <list>
#include <sstream>
#include "tinyxml/tinyxml.cpp"
#include "tinyxml/tinystr.cpp"
#include "tinyxml/tinyxmlerror.cpp"
#include "tinyxml/tinyxmlparser.cpp"

#include "Personne.h"
#include "lire_xml.h"


using namespace std;
using namespace cv;

/*
    pour acquerir des donnees d'un fichier xml dont le nom est passe en argument
*/
//std::string filename="filename.xml";
//int user_mgr::acquerir(const std::string& filename){
int lire_xml::acquerir(vector<Mat>& images, vector<int>& labels){
    Personne P;
    vector<Personne> personnes;
    doc = new TiXmlDocument("filexml.xml");
    if(!doc->LoadFile()){
       cerr << "erreur lors du chargement" << endl;
       cerr << "error #" << doc->ErrorId() << " : " << doc->ErrorDesc() << endl;
       return 1;
    }
    TiXmlHandle hdl(doc);
   elem = hdl.FirstChild("ListePersonnes").FirstChild("Personne").Element();
if(!elem){
	cerr << "le noeud à atteindre n'existe pas" << endl;
	return 2;
}
    while(elem){
        elem1 = elem->FirstChildElement( "Nom" );
        elem2 = elem->FirstChildElement( "Prenom" );
        elem3 = elem->FirstChildElement( "Id" );
        elem4 = elem->FirstChildElement( "Image" );
       
        if(!elem1){
	return 2;
         }
         P.Nom=elem1->GetText();
         elem2->NextSiblingElement( "Prenom" );
         P.Prenom=elem2->GetText();
         elem3->NextSiblingElement( "Id" );
         P.indice=atoi(elem3->GetText());
         elem4->NextSiblingElement( "Image" );
         while(elem4){
              labels.push_back(atoi(elem3->GetText()));
              images.push_back(imread(elem4->GetText(),0));
              personnes.push_back(P);
             elem4 = elem4->NextSiblingElement();
             
         }
       elem = elem->NextSiblingElement();     
    }
}
int lire_xml::recherche(vector<string>& nom, vector<int>& indices){
    doc = new TiXmlDocument("filexml.xml");
    if(!doc->LoadFile()){
       cerr << "erreur lors du chargement" << endl;
       cerr << "error #" << doc->ErrorId() << " : " << doc->ErrorDesc() << endl;
       return 1;
    }
    TiXmlHandle hdl(doc);
   elem = hdl.FirstChild("ListePersonnes").FirstChild("Personne").Element();
if(!elem){
	cerr << "le noeud à atteindre n'existe pas" << endl;
	return 2;
}
    while(elem){
        elem1 = elem->FirstChildElement( "Nom" );
        elem2 = elem->FirstChildElement( "Prenom" );
        elem3 = elem->FirstChildElement( "Id" );
        elem4 = elem->FirstChildElement( "Image" );
       
        if(!elem1){
	cerr << "le noeud à atteindre n'existe pas" << endl;
	return 2;
         }
          nom.push_back(elem1->GetText());
         elem3->NextSiblingElement( "Id" );
         indices.push_back(atoi(elem3->GetText()));

       elem = elem->NextSiblingElement();     
    }
}
