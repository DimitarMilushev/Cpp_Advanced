#ifndef ARRAYOFPOINTERS_H
#define ARRAYOFPOINTERS_H

#include "Company.h"
#include <vector>

class ArrayOfPointers
{
    std::vector<Company*> companies;

public:

    ArrayOfPointers() : companies(std::vector<Company*>{}) {}

    void add(Company* c)
    {
        this->companies.push_back(c);
    }

    size_t getSize() const
    {
        return this->companies.size();
    }

    Company* get(size_t pos)
    {
        return this->companies[pos];
    }

    virtual ~ArrayOfPointers()
    {
        for(auto element : this->companies)
        {
            delete element;
        }
    }
};

#endif // ARRAYOFPOINTERS_H
