#include "graph.h"
#include "err.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "kesheterr.h"
using namespace std;
int main(int argc,char* argv[]) {
    graph g;
    std::ofstream outfile;
    outfile.open("-o.txt"); // opens the file
    try {
        for (int i = 1; i < argc; i++) {
            ifstream file(argv[i]);
            if (file.is_open()) {
                string line;
                getline(file, line);
                stringstream ss(line);
                string source;
                string target;
                int num;
                ss >> source;
                ss >> target;
                ss >> num;
                g.addpoint(source);
                g.addpoint(target);
                g.addE(source, target, num);

                file.close();
            } else {
                throw err(string(argv[i]));
            }
        }
        g.printgraph();
        string s;
        while(s != "exit") {
            cin >> s;
            g.userprint(s);
        }
    }catch(err& e)
    {
        cerr<<e.what()<<endl;
    }
    catch(kesheterr& e)
    {
        cerr<<"ERROR: node definition in " <<e.what()<<" is invalid\n";
    }
    catch (std::out_of_range& e) {
        cerr<<"An out of range error occurred: "<<e.what()<<"\n";
    }
    outfile.close(); // closes the file

    return 0;
}
