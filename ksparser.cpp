#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <iostream>
using namespace std;

class ksparser {
	string filename;
	ifstream file;
public:
   	int n,k;
    int* V;
    int* W;

ksparser(const string& s):filename (s){
    //cout<<"parser srart"<<endl;
    k=0;
    n=0;
}

void ksparser_f (){
  int i;
  file.open (filename);
    if(!file.is_open()){
        cout<<"The file is not opened";
    }
    string s,s1;
    getline (file, s,' ');
    n = stoi (s);
    cout<<"n:"<<n<<endl;
    getline (file, s);
    k = stoi (s);
    cout<<"k:"<<k<<endl;
  V = new int[n];
  W = new int[n];
  for (i = 0; i < n; i++){
      V[i] = 0;
      W[i] = 0;
    }
  for (i = 0; i < n; i++){
      getline (file, s,' ');
      V[i] = stoi (s);	//get V
      getline (file, s1);	//get W
      W[i] = stoi (s1);
    }
    /*
    cout<<"V:"<<endl;
    for(i=0;i<n;i++){
        cout<<V[i]<<" ";
    }
    cout<<endl;
    cout<<"W:"<<endl;
    for(i=0;i<n;i++){
        cout<<W[i]<<" ";
    }
    cout<<endl;
    */
  file.close();
  return;
}

~ksparser (){
  if (file.is_open ()){
      file.close ();
    }
    delete[]V;
    delete[]W;
}

};
