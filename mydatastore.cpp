#include "util.h"
#include <mydatastore.h>

using namespace std;

/**
 * Adds a product to the data store
 */
void MyDataStore::addProduct(Product* p)
{
    set<string> productKeywords = p->keywords();
    keywords_.insert(productKeywords.begin(), productKeywords.end());
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
    
}

/**
 * Reproduce the database file from the current Products and User values
 */
void MyDataStore::dump(std::ostream& ofile)
{

}