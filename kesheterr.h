//
// Created by D2022 on 25/01/2023.
//

#ifndef C__HW5_KESHETERR_H
#define C__HW5_KESHETERR_H
#include <iostream>
using namespace std;
class kesheterr : public exception {
    string message;
public:
    kesheterr(string file) : message(file) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif //C__HW5_KESHETERR_H
