#include "movie.h"
#include "util.h"
using namespace std;

std::set<std::string> Movie::keywords() const
{
    set<string> keywords = parseStringToWords(name_);
    keywords.insert(genre_);
    return keywords;
}

std::string Movie::displayString() const 
{
    string output = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + 
    "\n"  + std::to_string(price_) + "\n" + std::to_string(qty_) + " left.";
    return output;
}

void Movie::dump(std::ostream& os) const
{
    Product::dump(os);
    os << genre_ << '\n' <<  rating_ << endl;
}