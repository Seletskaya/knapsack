#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iostream>
#pragma once
using namespace std;

class ksparser {
	string filename;
	ifstream file;
public:
   	int n,k;
    int* V;
    int* W;

ksparser(const string& );

void ksparser_f ();

~ksparser ();
};
