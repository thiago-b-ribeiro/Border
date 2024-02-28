/**
 * @brief Analyze words containing in a vector.
 * @copyright All rights reserved to the author.
 * @author Thiago Barbosa Ribeiro
*/

#include <vector>
#include <string>

#ifndef ANALYZESTRING_H
#define ANALYZESTRING_H

/** 
 * @class cAnalyzeString 
 */
class cAnalyzeString{
    public:
        /** 
         * @brief Class construtor
        */
        cAnalyzeString();

        /**
         * @brief Class destructor
        */
        ~cAnalyzeString();

        /**
         * @brief Tells the size of the largest word.
         * @param oVector Relationship of words.
         * @return Size of largest word.
        */
        int SizeLargestString(std::vector<std::string> & oVector);

        /**
         * @brief Tells the size of the Smallest word.
         * @param oVector Relationship of words.
         * @return Size of smallest word.
        */
        int SizeSmallestString(std::vector<std::string> & oVector);

        /**
         * @brief Tells what the longest word is.
         * @param oVector Relationship of words.
         * @return Largest word.
        */
        std::string WhichIsBiggest(std::vector<std::string> & oVector);

        /**
         * @brief Tells what the smallest word is.
         * @param oVector Relationship of words.
         * @return Smallest word.
        */
        std::string WhichIsSmallest(std::vector<std::string> & oVector);

    private:
};
        std::string oString;      ///< Temporary variable for word manipulation.
        std::size_t iSizeString;  ///< Temporary variable for storage information.

#endif