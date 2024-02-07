#include "movie.h"
#include "util.h"
#include <sstream> // For std::ostringstream
#include <iomanip>
using namespace std;

std::set<std::string> Movie::keywords() const
{
    set<string> keywords = parseStringToWords(name_);
    keywords.insert(convToLower(genre_));
    return keywords;
}

std::string Movie::displayString() const 
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << price_;

    string output = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + 
    "\n"  + stream.str() + "\n" + std::to_string(qty_) + " left.";
    return output;
}

void Movie::dump(std::ostream& os) const
{
    Product::dump(os);
    os << genre_ << '\n' <<  rating_ << endl;
}