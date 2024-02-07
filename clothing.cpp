#include <clothing.h>
#include "util.h"
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
    string output = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + 
    "\n"  + std::to_string(price_) + std::to_string(qty_) + " left.";
    return output;
}

void Clothing::dump(std::ostream& os) const
{
    Product::dump(os);
    os << size_ << '\n' << brand_ << endl;
}