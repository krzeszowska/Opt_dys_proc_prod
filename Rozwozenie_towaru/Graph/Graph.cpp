#include "Graph.h"

void Graph::setSize(unsigned int vertices)  {
    edges = std::vector<std::vector<double> >();
    for(unsigned int i=0;i<vertices;++i){
        edges.push_back(std::vector<double>(vertices));
    }
}

const double &Graph::edge(unsigned int begin, unsigned int end) const {

    unsigned int b = std::min(begin, end);
    end = std::max(begin, end);
    begin = b;

    return edges.at(begin).at(end);
}

double &Graph::edge(unsigned int begin, unsigned int end){

    unsigned int b = std::min(begin, end);
    end = std::max(begin, end);
    begin = b;
    return edges.at(begin).at(end);
}


void Graph::random(unsigned int n)
{
    setSize(n);
    for(unsigned int i=0;i<n;++i){
        for(unsigned int j=i;j<n;++j){
            //wypelniamy tylko polowe grafu (mamy graf nieskierowany)
            if(i!=j){
                edges.at(i).at(j) = (rand()%100)+1;
            }
        }
    }
}

unsigned int Graph::size() const {
    return edges.size();
}

void Graph::writeToFile(const std::string &path) const  {
    //open file
    std::ofstream stream;
    stream.open(path);
    //write graph to file
    stream<<(*this);
    //close file
    stream.close();
}

void Graph::readFromFile(const std::string &path) {
    //open file
    std::ifstream stream;
    stream.open(path);

    //guard if file does not exists skip reading
    if(!stream.fail()) {
        //read graph from file
        stream>>(*this);
    }else{
        std::cerr<<"Niepoprawna sciezka do pliku"<<std::endl;
    }

    //close file
    stream.close();
}

std::string Graph::toString() const  {
    std::stringstream ss;
    ss << (*this);
    return ss.str();
}

double Graph::computeShortestComplexPath(unsigned int begin, std::vector<unsigned int> vertices, double *shortestPathVal) const {
    vertices.insert(vertices.begin(), begin);
    vertices.push_back(begin);

    double value= 0;

    for(unsigned int i=0;i<vertices.size()-1;++i){
        value += edge(vertices.at(i), vertices.at(i+1));
    }

    if(shortestPathVal){
        *shortestPathVal = value;
    }
    //std::cout<<std::endl;

    return value;
}
