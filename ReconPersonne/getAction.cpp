/* 
 * File:   getAction.cpp
 * Author: abdi
 * 
 * Created on 29 janvier 2014, 15:07
 */

#include "getAction.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <iostream>
#include <string>

#include <string.h>
#include "speak_lib.h"
using namespace std;


void says(string name2){
    
    espeak_Initialize(AUDIO_OUTPUT_PLAYBACK, 0, NULL,0);
int Buflength = 500;
int Options=0;
char Voice[] = {"default"};
unsigned int Size,position=0, end_position=0, flags=espeakCHARS_AUTO, *unique_identifier;
char *name;
strcpy (name, name2.c_str());
//  cout << espeak_Synth(name, strlen(name)+1, 0, POS_CHARACTER, 0, espeakCHARS_AUTO, NULL, NULL) <<endl;
espeak_Synchronize();

}

