#include "ksparser.h"
using namespace std;


ksparser::ksparser(const string& s):filename (s){
    //cout<<"parser srart"<<endl;
    k=0;
    n=0;
}

void ksparser::ksparser_f (){
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
  file.close();
  return;
}

ksparser::~ksparser (){
  if (file.is_open ()){
      file.close ();
    }
    delete[]V;
    delete[]W;
}

