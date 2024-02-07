#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}


/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    set<string> keywords;
    string word;
    stringstream ss(rawWords);

    while (ss >> word)
    {
        string token;
        for (size_t pos = 0; pos < word.length(); ++pos)
        {
            if (!ispunct(word[pos])) // If the character is not a punctuation, add it to token.
            {
                token += word[pos];
            }
            else if (token.length() > 1) // If punctuation is encountered, add the token if it's valid.
            {
                keywords.insert(convToLower(token));
                token.clear(); // Clear the token for the next set of characters.
            }
            else // If punctuation is found but token is not valid, just reset token without adding.
            {
                token.clear();
            }
        }
        if (token.length() > 1) // Check for any remaining token after the last punctuation.
        {
            keywords.insert(convToLower(token));
        }
    }
    
    return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
