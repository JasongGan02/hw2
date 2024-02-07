#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
class MyDataStore : public DataStore {
public:
    MyDataStore();
    virtual ~MyDataStore();

    void addProduct(Product* p) override;
    void addUser(User* u) override;
    void addToCart(string u, Product* p);
    bool isValidUser(string u);
    void displayCart(string u);
    void buyCart(string u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void dump(std::ostream& ofile) override;

private:
    std::set<Product*> products_;
    std::map<std::string, User*> users_;
    std::map<std::string, std::set<Product*>> keywords_;
    std::map<User*, std::queue<Product*>> carts_;
};

#endif
