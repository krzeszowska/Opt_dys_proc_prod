#ifndef VECTORINTEGER_H
#define VECTORINTEGER_H

#include <vector>
#include <iostream>

class VectorInteger
{
    unsigned int c_size;
    unsigned int c_system;
    std::vector<unsigned char> c_data;
    std::vector<unsigned int> c_digitsCount;

    bool isOverflow = false;
public:
    VectorInteger(unsigned int size, unsigned int system);

    unsigned char &at(unsigned int pos);
    unsigned char at(unsigned int pos) const;
    unsigned int size() const;
    unsigned int system() const;
    bool overflow() const;
    bool hasAllDigitsUsed() const;
    void overflow(bool of);
    VectorInteger& operator++();
    unsigned int getDigists(unsigned int pos) const;
    bool isIncreasing() const;
    bool hasEqualCountOfDigites(int accurancy) const;

    std::vector<unsigned int> split(const std::vector<unsigned int>& vec, unsigned int digit) const;
};

std::ostream& operator<<(std::ostream& str, const VectorInteger& integer);

#endif // VECTORINTEGER_H
