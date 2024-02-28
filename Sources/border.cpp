/**
 * @brief Inserts borders around the word relationship.
 * @copyright All rights reserved to the author.
 * @author Thiago Barbosa Ribeiro
*/

#include <border.h>
#include <cstring>
#include <iostream>

cBorder::cBorder(){}

cBorder::~cBorder(){}

void cBorder::InsertBorder(std::vector<std::string> & listOfWords){
    
    int iSize = m_AnalizadorDeString.SizeLargestString(listOfWords);
    int iComp = 0;
    char oBorda[iSize + 5] = {' '};

    std::vector<std::string>::iterator it = listOfWords.begin();
    for(it = listOfWords.begin(); it != listOfWords.end(); it++){

        iComp = iSize - it->length();

        do{
            iComp--;
            it->append(" ");
        }while (iComp >= 0);
        
        it->insert(0, "* ");
        it->append("*");
    }

    std::memset(oBorda, '*', iSize + 4);

    listOfWords.insert(listOfWords.begin(), oBorda);    
    listOfWords.push_back(oBorda);        
}