//
// Created by D2022 on 21/01/2023.
//

#ifndef HW5_GRAPH_H
#define HW5_GRAPH_H
#include <utility>
#include <vector>
#include <string>
class targetandtime {
private:
    std::string from="";
    std::string to="";
    int distance=0;
    //std::vector<std::string> s;
public:
    targetandtime(std::string from,std::string to,int distance):from(from),to(to){ distance = distance <=0 ? 0 : distance;}
    std::string getFrom() const{ return from;}
    std::string getTo() const{ return to;}
    int getDistance() const{ return distance;}
    void setdistance(int d){distance=d;}
    bool operator==(const targetandtime& lhs) {
        return (lhs.from == from) && (lhs.to == to) && (lhs.distance==distance);
    }
    void operator=(const targetandtime& t)
    {
        distance=t.distance;
        from=t.from;
        to=t.to;
    }
};

class graph {
private:
    std::vector<targetandtime> vecOfVecs;
    std::vector<std::string> names;
public:
    graph();
    graph(std::string source,std::string target,int distance);
    void addpoint(std::string source);//add vec to vector of vectors
    void removepoint(std::string source);//delete vec from vector of vectors
    void addE(std::string from, std::string to, int distance);// Add edge from a thing to other with distance
    void removeE(std::string from, std::string to);//remove edge from a thing to other with distance
    int weight(std::vector<targetandtime> p);
    std::vector<std::string> neighbors(std::vector<targetandtime> v);
    void printgraph();
    void userprint(std::string name);
};

#endif //HW5_GRAPH_H
