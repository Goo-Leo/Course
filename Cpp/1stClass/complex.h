//
// Created by 10633 on 2022/3/17.
//

#ifndef LIST_COMPLEX_H
#define LIST_COMPLEX_H

#include <iostream>
using namespace std;

class complex {
    int real = 0;
    int image = 0;
    public:
        complex();
        void plus(const complex& c1) const;
        void multiply(const complex& c1) const;
        ~complex() = default;
};

complex::complex() {
    cout <<"real part:";
    cin >> real;
    cout <<"image part:";
    cin >> image;
}

void complex::plus(const complex& c1) const {
    int rel ,img = 0;
    rel = real + c1.real;
    img = image + c1.image;
    cout <<"result:("<< rel<<','<<img<<')';
}

void complex::multiply(const complex &c1) const {
    int rel ,img = 0;
    rel = real * c1.real - image * c1.image;
    img = image * c1.real + real * c1.image;
    cout <<"result:("<<rel<<','<<img<<')';
}




#endif //LIST_COMPLEX_H
