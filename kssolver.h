#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "ksparser.h"
#pragma once
using namespace std;

class Matrix{
    public:
        int **mat;
        int n,m;
        Matrix(int,int);
        void rand_matrix(int,int);
        void m_null();
        void print_matrix();
       // ~Matrix();

};

class kssolver{
    ksparser *el;
    int N;
public:
    Matrix A();
	int*out;

kssolver(ksparser *,int);

};
