

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Algorithms/Algorithm.cpp \
    Algorithms/BruteforceAlgorithm.cpp \
    Algorithms/GeneticAlgorithm.cpp \
    Data/Data.cpp \
    Graph/Graph.cpp \
    Graph/Vertex.cpp \
    Helpers/VectorInteger.cpp \
    main.cpp \

HEADERS += \
    Algorithms/Algorithm.h \
    Algorithms/BruteforceAlgorithm.h \
    Algorithms/GeneticAlgorithm.h \
    Data/Data.h \
    Graph/Graph.h \
    Graph/Vertex.h \
    Helpers/VectorInteger.h \
    Operators.h \

