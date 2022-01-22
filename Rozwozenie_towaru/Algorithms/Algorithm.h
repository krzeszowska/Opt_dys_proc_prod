#ifndef ALGORITHM_H
#define ALGORITHM_H
#include"../Graph/Graph.h"

class Algorithm
{
public:
    Graph& _graph;
    double _bestSolution;
    double _currentSolution;

    double _bestTimeSolution;
    double _currentTimeSolution;

    double _bestDistanceSolution;
    double _currentDistanceSolution;

    float _timeFactor = 0.5;

    std::vector<unsigned int> destinations = {1,4,7,8,19,6,30,5,15};

    unsigned int _startVertex = 0;
    unsigned int _truckNo = 3;

private:

    std::string _name;

public:
    Algorithm(Graph& graph);
    virtual ~Algorithm();

    float timeFactor() const;
    float& timeFactor();
    float distanceFactor();
    void initGraph();

    const std::string& name() const ;

    const std::vector<unsigned int>& getDestinations() const;
    std::vector<unsigned int> &getDestinations();

    unsigned int startVertex() const ;
    unsigned int& startVertex()  ;
    unsigned int truckNo() const ;
    unsigned int& truckNo()  ;

    void setDestinations(const std::vector<unsigned int>& dest);

    template< class T>
    void removeFromVector(std::vector<T>& output, const std::vector<T>& modifier) {
        for(unsigned int i=0;i<modifier.size();++i){
            for(unsigned int j=0;j<output.size();++j){
                if(output[j] == modifier[i]){
                    output.erase(output.begin()+j);
                }
            }
        }
    }

    virtual std::vector<std::vector<unsigned int> > run() = 0;

    const Graph& getCurrentGraph() const ;

protected:

    Graph &graph() ;

public:
    double &bestSolution() ;
    double &currentSolution() ;

    double &bestTimeSolution() ;
    double &currentTimeSolution() ;

    double &bestDistanceSolution() ;
    double &currentDistanceSolution() ;

    template<class T>
    void perm(std::vector<std::vector<T>>& permutations,std::vector<T>& vector, unsigned int position = 0);
};

template<class T>
void Algorithm::perm(std::vector<std::vector<T>>& permutations,std::vector<T>& vector, unsigned int position) {
    if (position == vector.size()) {

        bool correctInPairs = true;
        bool correctInVectors = true;
        T last = vector[0];
        for(unsigned int i=0;i<vector.size();i+=2){
            if(vector[i] > vector[i+1]){
                correctInPairs = false;
            }

            if(last > vector[i]){
                correctInVectors = false;
            }

            last = vector[i];
        }

        if(correctInPairs && correctInVectors){
            permutations.push_back(vector);
        }

        return;
    } else {
        for (unsigned int i = position; i < vector.size(); i++) {
            std::swap(vector[i], vector[position]);
            perm(permutations, vector, position + 1);
            std::swap(vector[i], vector[position]);
        }
    }
}

#endif // ALGORITHM_H
