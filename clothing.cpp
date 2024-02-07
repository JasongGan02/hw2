#include "clothing.h"
#include "util.h"
#include <sstream> // For std::ostringstream
#include <iomanip> 
using namespace std;

std::set<std::string> Clothing::keywords() const
{
    set<string> keywords = parseStringToWords(name_);
    set<string> brandKeywords = parseStringToWords(brand_);
    keywords.insert(brandKeywords.begin(), brandKeywords.end());
    return keywords;
}

std::string Clothing::displayString() const 
{
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << price_;
    string output = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + 
    "\n"  + stream.str() + "\n" + std::to_string(qty_) + " left.";
    return output;
}

void Clothing::dump(std::ostream& os) const
{
    Product::dump(os);
    os << size_ << '\n' << brand_ << endl;
}