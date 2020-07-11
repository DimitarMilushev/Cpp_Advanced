#ifndef SERIALIZE_H_INCLUDED
#define SERIALIZE_H_INCLUDED

#include "Company.h"

byte* serializeToMemory(const std::string& input, size_t& bytesWritten)
{
    std::vector<Company> companies;
    std::vector<unsigned char> memoryArray;

    std::istringstream companiesIn(input);
    Company company;


    while(companiesIn >> company)
        {
            companies.push_back(company);
        };


    memoryArray.push_back(static_cast<unsigned char>(companies.size()));

    for(Company c : companies)
    {
        memoryArray.push_back(static_cast<unsigned char>(c.getId()));

        for(auto letter : c.getName())
        {
            memoryArray.push_back(static_cast<unsigned char>(letter));
        }

        memoryArray.push_back('\0');

        byte employeesCount = c.getEmployees().size();
        memoryArray.push_back(employeesCount);

        if(employeesCount != 0)
        {
            std::vector<std::pair<char, char>> employees = c.getEmployees();

            for(int i = 0; i < employeesCount; i++)
            {
            memoryArray.push_back(static_cast<unsigned char>(employees[i].first));
            memoryArray.push_back(static_cast<unsigned char>(employees[i].second));
            }

        }
    }

    byte* memory = new byte[memoryArray.size()];
    std::copy(memoryArray.begin(), memoryArray.end(), memory);

    bytesWritten = memoryArray.size();
    return memory;
}

#endif // SERIALIZE_H_INCLUDED
