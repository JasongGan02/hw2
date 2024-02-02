#include <book.h>
#include "util.h"
using namespace std;

std::set<std::string> Book::keywords() const
{
    set<string> keywords = parseStringToWords(name_);
    set<string> authorNameKeywords = parseStringToWords(author_);
    keywords.insert(authorNameKeywords.begin(), authorNameKeywords.end());
    keywords.insert(isbn_);
    return keywords;
}

std::string Book::displayString() const 
{
    string output = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + 
    "\n"  + std::to_string(price_) + std::to_string(qty_) + " left.";
    return output;
}

void Book::dump(std::ostream& os) const
{
    Product::dump(os);
    os << isbn_ << '\n' << author_ << endl;
}