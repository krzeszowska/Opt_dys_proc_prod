#ifndef Data_H
#define Data_H

#include "../Operators.h"

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>

class Data
{

    std::vector<std::string> c_data;
public:
    Data(const std::string& path);
    Data();

    void readFromFile(const std::string& path);
    void writeToFile(const std::string& path);

    unsigned int size() const;
    std::vector<std::string> at(const std::vector<unsigned int>& ii) const;

    std::string at(unsigned int i) const;
    std::string toString() const;

    const std::vector<std::string>& data() const;
    std::vector<std::string>& data();

    static std::vector<std::string> formatAsAddress(const std::vector<std::string>& data);
    static std::vector<std::string> formatAsCustomer(const std::vector<std::string> &data);
};


inline std::ostream& operator<<(std::ostream& str, const Data& a){

    str<<a.size()<<std::endl;

    for(unsigned int i=0;i<a.size();++i){
        str<<a.at(i)<<std::endl;
    }

    return str;
}

inline std::istream& operator>>(std::istream& str, Data& a){

    unsigned int size = 0;
    str>>size;//there is one white sigh left at the and of the line
    a.data() = std::vector<std::string>(size, "");
    std::string d = "";
    //read a white sign
    getline (str,d);

    for(unsigned int i=0;i<size;++i){
        d = "";
        getline (str,d);
        if(d.size() > 0){
            //d.pop_back();
            a.data().at(i) = d;
        }
    }

    return str;
}

#endif // Data_H
