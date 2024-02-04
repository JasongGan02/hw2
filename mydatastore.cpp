#include "util.h"
#include <mydatastore.h>

using namespace std;

/**
 * Adds a product to the data store
 */
void MyDataStore::addProduct(Product* p)
{
    set<string> productKeywords = p->keywords();
    for (std::set<string>::iterator it = productKeywords.begin(); it != productKeywords.end(); ++it)
    {
        if (keywords_.find(*it) == keywords_.end()) // not find the keyword
        {
            set<Product*> newSet;
            newSet.insert(p);
            keywords_[*it] =  newSet;
        }
        else
        {
            keywords_[*it].insert(p);
        }
    }   
    products_.insert(p);
}

/**
 * Adds a user to the data store
 */
void MyDataStore::addUser(User* u)
{
    users_.insert(u);
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    std::set<Product*> resultProducts;

    for (std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); ++it)
    {
        if (keywords_.find(*it) != keywords_.end()) //keyword exists
        {
            std::set<Product*> curProducts = keywords_[*it];
            if (resultProducts.size() == 0)
            {
                resultProducts.insert(curProducts.begin(), curProducts.end());
            }
            else
            {
                if (type == 0) //And
                {
                    resultProducts = setIntersection(resultProducts, curProducts);
                }
                else //Or
                {
                    resultProducts = setUnion(resultProducts, curProducts);
                }
            }
        }       
    }
    
    std::vector<Product*> resultVector(resultProducts.begin(), resultProducts.end());
    return resultVector;
}

/**
 * Reproduce the database file from the current Products and User values
 */
void MyDataStore::dump(std::ostream& ofile)
{
    ofile << "<products>" << endl;
    for (set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it)
    {
        //ofile << it->dump() 
    }
}