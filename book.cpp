#include "book.h"
#include "util.h"
#include <sstream> 
#include <iomanip> 
using namespace std;

std::set<std::string> Book::keywords() const
{
    set<string> keywords = parseStringToWords(name_);
    set<string> authorNameKeywords = parseStringToWords(author_);
    keywords.insert(authorNameKeywords.begin(), authorNameKeywords.end());
    keywords.insert(convToLower(isbn_));
    return keywords;
}

std::string Book::displayString() const {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << price_; // Format the price
    
    std::string output = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + 
    "\n" + stream.str() + "\n" + std::to_string(qty_) + " left.";
    return output;
}
void Book::dump(std::ostream& os) const
{
    Product::dump(os);
    os << isbn_ << '\n' << author_ << endl;
}