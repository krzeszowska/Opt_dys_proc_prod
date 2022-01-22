#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <iomanip>
#include <QDebug>

class Vertex
{

    std::string _value;
    int xPos;
    int yPos;

public:

    Vertex() : _value(""), xPos(0), yPos(0) {}


    Vertex(const std::string& value);

    const std::string& value() const ;
    std::string& value() ;

};

inline std::ostream& operator<<(std::ostream& str, const Vertex& v){
    str<<v.value() << " ";
    return str;
}
inline std::istream& operator>>(std::istream& str, Vertex& v){
    str>>v.value();
    return str;
}

#endif // VERTEX_H
