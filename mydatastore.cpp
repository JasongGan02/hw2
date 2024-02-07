#include "util.h"
#include "mydatastore.h"

using namespace std;

MyDataStore::MyDataStore() {

}

/**
 * Adds a product to the data store
 */
void MyDataStore::addProduct(Product* p)
{
    set<string> productKeywords = p->keywords();
    for (std::set<string>::iterator it = productKeywords.begin(); it != productKeywords.end(); ++it)
    {
        if (keywords_.find(*it) == keywords_.end()) // not find the keyword in datastore
        {
            set<Product*> newSet;
            newSet.insert(p);
            keywords_[*it] = newSet;
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
    if (users_.find(u->getName()) == users_.end())
    {
        users_[u->getName()] = u;
        queue<Product*> newCart;
        carts_[u] = newCart;
    }
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
        (*it)->dump(ofile);
    }
    ofile << "</products>" << endl;
    ofile << "<users>" << endl;
    for (map<string, User*>::iterator it = users_.begin(); it != users_.end(); ++it)
    {

        it->second->dump(ofile);
    }
    ofile << "</users>" << endl;
}


void MyDataStore::displayCart(string u)
{
    std::queue<Product*> tempQueue;
    int index = 1;
    while (!carts_[users_[u]].empty()) 
    {
        Product* product = carts_[users_[u]].front();
        carts_[users_[u]].pop();
        std::cout << "Item " << index << endl;
        std::cout << product->displayString() << std::endl;

        tempQueue.push(product);
        index++;
    }

    carts_[users_[u]] = tempQueue;

}

void MyDataStore::buyCart(string u)
{
    User* user = users_[u];
    std::queue<Product*>& cart = carts_[user];
    std::queue<Product*> tempQueue;

    while (!cart.empty()) 
    {
        Product* product = cart.front();
        cart.pop();

        if (product->getQty() > 0 && user->getBalance() >= product->getPrice()) 
        {
            product->subtractQty(1);
            user->deductAmount(product->getPrice());
        } else 
        {
            tempQueue.push(product);
        }
    }

    while (!tempQueue.empty()) 
    {
        cart.push(tempQueue.front());
        tempQueue.pop();
    }
}

bool MyDataStore::isValidUser(string u)
{
    return users_.find(convToLower(u)) != users_.end();
}
void MyDataStore::addToCart(string u, Product* p)
{
    carts_[users_[u]].push(p);
}

MyDataStore::~MyDataStore() 
{
    for (std::set<Product*>::iterator it = products_.begin(); it != products_.end(); ++it) {
        delete *it;
    }
    products_.clear();

    for (std::map<std::string, User*>::iterator it = users_.begin(); it != users_.end(); ++it) {
        delete it->second;
    }
    users_.clear();
    keywords_.clear();
    carts_.clear();
}

