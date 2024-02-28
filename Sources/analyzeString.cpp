/**
 * @brief Analisa strings dentro de um vetor.
 * @copyright All rights reserved to the author.
 * @author Thiago Barbosa Ribeiro
*/

#include "analyzeString.h"
#include <cstring>
#include <iterator>
#include <iostream>

cAnalyzeString::cAnalyzeString(){

}

cAnalyzeString::~cAnalyzeString(){

}

int cAnalyzeString::SizeLargestString(std::vector<std::string> & oVector){

    std::vector<std::string>::iterator it = oVector.begin();

    iSizeString = 0;

    for(; it != oVector.end(); it++){

        if(iSizeString < it->length())
            iSizeString = it->length();
    }

    return (iSizeString);

}

int cAnalyzeString::SizeSmallestString(std::vector<std::string> & oVector){

    std::vector<std::string>::iterator it = oVector.begin();

    iSizeString = it->length();

    for(; it != oVector.end(); it++){

        if(iSizeString > it->length())
            iSizeString = it->length();
    }

    return (iSizeString);

}

std::string cAnalyzeString::WhichIsBiggest(std::vector<std::string> & oVector){

    std::vector<std::string>::iterator it = oVector.begin();

    oString = *it;

    for(; it != oVector.end();it++){

        if(oString.length() < it->length()){
            oString = *it;
        }
    }

    return (oString);

}

std::string cAnalyzeString::WhichIsSmallest(std::vector<std::string> & oVector){

    std::vector<std::string>::iterator it = oVector.begin();

    oString = *it;

    for(; it != oVector.end(); it++){

        if(oString.length() > it->length()){
            oString = *it;
        }
    }

    return (oString);

}