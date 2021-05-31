//
// Created by arina on 23.05.2021.
//

#ifndef LAB2_BASEFUNC_H
#define LAB2_BASEFUNC_H
#include "random"
#include "complex"
#define maxInt 10000


int GetInt();
int GetInt(int up);

int GetInt(int down, int up);

int randomInt();

float randomFloat();

std::complex<int> randomComplex();

std::ostream &operator<<(std::ostream &cout, std::complex<int> num);  //красивый вывод комплексного числа

int GetType();
#endif //LAB2_BASEFUNC_H
