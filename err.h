//
// Created by D2022 on 25/01/2023.
//

#ifndef C__HW5_ERR_H
#define C__HW5_ERR_H
#include <iostream>
using namespace std;
class err : public exception {
    string message;
public:
    err(string file) : message("ERROR: " + file + " does not exist or cannot be opened\n") {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};
#endif //C__HW5_ERR_H
