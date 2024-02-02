#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include <set>
#include <vector>
#include <iostream>

class MyDataStore : public DataStore {
public:
    MyDataStore() = default; // Default constructor
    virtual ~MyDataStore() override = default; // Virtual destructor

    void addProduct(Product* p) override;
    void addUser(User* u) override;
    std::vector<Product*> search(std::vector<std::string>& terms, int type) override;
    void dump(std::ostream& ofile) override;

private:
    std::set<Product*> products_;
    std::set<User*> users_;
    std::set<std::string> keywords_;
};

#endif
