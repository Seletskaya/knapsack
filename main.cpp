#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#include "kssolver.h"

int main(){
    int i;
    	ksparser Parser1("ks_4_0.txt");
    	Parser1.ksparser_f();
    	kssolver Solver1(&Parser1,150);

    	ksparser Parser2("ks_19_0.txt");
    	Parser2.ksparser_f();
    	kssolver Solver2(&Parser2,150);

    	ksparser Parser3("ks_100_0.txt");
    	Parser3.ksparser_f();
    	kssolver Solver3(&Parser3,150);

    	ksparser Parser4("ks_200_0.txt");
    	Parser4.ksparser_f();
    	kssolver Solver4(&Parser4,150);

	return 0;
}
