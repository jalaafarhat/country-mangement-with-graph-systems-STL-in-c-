//
// Created by D2022 on 21/01/2023.
//

#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
#include "graph.h"
#include "kesheterr.h"

graph::graph() {
    vecOfVecs = std::vector<targetandtime>();
    names = std::vector<std::string>();
}
graph::graph(std::string source, std::string target, int w) {
    if(w<=0){
        w=0;
    }
    names.push_back(source);
    vecOfVecs.push_back(targetandtime(source,target,w));
}

void graph::addE(std::string from, std::string to, int distance) {
    int c=-1;
    for(int i=0;i<names.size();i++)
    {
        if(names[i]==from)
        {
            c=i;
            break;
        }
    }
    if(c==-1)
    {
        names.push_back(from);
        vecOfVecs.push_back(targetandtime(from,to,distance));
        c=vecOfVecs.size()-1;
    }
    if(std::count(names.begin(), names.end(), to) == 0){
        names.push_back(to);
    }
    vecOfVecs.push_back(targetandtime(from,to,distance));
}


void graph::removeE(std::string from, std::string to) {
    int c=0;
    for(int i=0;i<names.size();i++)
    {
        if(names[i]==from)
        {
            c=i;
            break;
        }
    }
    vecOfVecs.erase(vecOfVecs.begin()+c);
}


void graph::addpoint(std::string source) {
    int c=0;
    for(auto& i:names)
    {
        if (source==i)
        {
            c=-1;
        }
    }
    if(c==0)
    {
        names.push_back(source);
    }
}

void graph::removepoint(std::string source) {
    for(int i=0 ;i<names.size();i++)
    {
        if(source==names[i])
        {
            vecOfVecs.erase(vecOfVecs.begin()+i);
        }
    }
}

int graph::weight(std::vector<targetandtime> p) {
    int sum=0;
    for(targetandtime& i:p)
    {
        sum+=i.getDistance();
    }
    return sum;
}

std::vector<std::string> graph::neighbors(std::vector<targetandtime> v) {
    std::vector<std::string> ne;
    for(targetandtime &i:v)
    {
        ne.push_back(i.getTo());
    }
    return ne;
}

void graph::printgraph() {
    ofstream outputFile("-o.txt");
    vector<string> visited;
    if (outputFile.is_open()) {
        for (auto &i: names) {
            outputFile << i;
            bool found = false;
            for (auto &j: vecOfVecs) {
                if (j.getFrom() == i && std::count(visited.begin(), visited.end(), j.getTo()) == 0) {
//                    if(j.getDistance()<=0)
//                    {
//
//                    }
                    outputFile << "\t";
                    outputFile << j.getTo();
                    visited.push_back(j.getTo());
                    found = true;
                }
            }
            visited.clear();
            outputFile << endl;
        }
    }
}

void graph::userprint(string name) {
    if(name!="exit"){
        int flag=0;
        bool found = false;
        for (auto &i: vecOfVecs) {
            if (i.getFrom() == name) {
                if(flag==0)
                {
                    cout<<name;
                    flag++;
                }
                found = true;
                cout << "\t" << i.getTo();
            }
        }
        if(flag!=0)
        {
            cout<<"\n";
        }

        if (!found) {
            for (auto &i: names) {
                if (i == name) {
                    cout << name << " : no outbound travel\n";
                }
            }
        }
        bool f = false;
        for (auto &i: names) {
            if (i == name) {
                f = true;
                break;
            }
        }
        if (!f) {
            cout << name << " does not exist in the current network\n" << "USAGE: <node> or ‘exit’ to terminate\n";
        }
    }
}




