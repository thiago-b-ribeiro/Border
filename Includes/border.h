/**
 * @brief Inserts borders around the word relationship.
 * @copyright All rights reserved to the author.
 * @author Thiago Barbosa Ribeiro
*/

#ifndef BORDER_H
#define BORDER_H

#include <vector>
#include <string>
#include <analyzeString.h>

/**
 * @class cBorder
*/
class cBorder
    {
    public:
        /**
         * @brief Class constructor
        */
        cBorder();

        /**
         * @brief Class destructor
        */
        ~cBorder();

        /**
         * @brief Inserts borders around the word relationship.
         * @param listOfWords Vector containing list of words.
        */
        void InsertBorder(std::vector<std::string> & listOfWords);

    private:
        cAnalyzeString m_AnalizadorDeString; ///< Analyzes and provides characteristics of the relationship of words.

    };

#endif