#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "ksparser.cpp"
using namespace std;

class Matrix{
public:
int **mat;
int n,m;
Matrix(int str = 0,int col = 0)
{
    this -> n = str;
    this -> m = col;
    mat = new int*[n];
    for (int i = 0; i < n; i++){
        mat[i] = new int[m];
    }
}

void rand_matrix(int xmin,int xmax){
srand(time(0));
    int i,j,ind;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
                ind = rand()%(xmax-xmin+1)+xmin;
                if(ind<30)
            mat[i][j] = 1;
        else mat[i][j] = 0;

        }
    }
return;
}

void m_null(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            mat[i][j] = 0;
        }
    }
    return;
}

void print_matrix(){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

return;
}
~Matrix()
{
    for (int i = 0; i < n; i++)
    {
        delete[] mat[i];
    }
    delete[]mat;
}

};

class kssolver{
    ksparser *el;
    int N;
public:
    Matrix A();
	int*out;
   	kssolver(int n){
   	    N = n;
}

kssolver(ksparser *p,int n):el(p){
    srand(time(0));
   	    N = n;
   	    int i,j,summv,summw;
   	    Matrix A(N,el->n+2);
   	    A.rand_matrix(0,1000);
   	    int number = 3;
   	    int h = 0;
   	    for(i = 0;i<N;i++){
            summv = 0;
            summw = 0;
            for(j=0;j<el->n;j++){
            if(A.mat[i][j]==1){
                    summv+=el->V[j];
                    summw +=el->W[j];
            }
            }
            if(summw >(el->k)) summv = 0;
            A.mat[i][el->n] = summv;// price
            A.mat[i][el->n+1] = summw;
   	    }
    Matrix B(N,el->n+2);
    B.m_null();
    int d1,d2;
    int k;
    int *P = new int[2];
    while(h<20000){//main cicle
   	for(i = 0;i<N;i+=2){
            for(j = 0;j<2;j++){
                    P[j]=0;
                    srand(2*i+j);
                    d1 = 0;
                    d2 = 0;
        d1 = rand()%(N);
        d2 = rand()%(N);
        if(d2==d1){
            if(d2==0) d2+=1;
            else d2-=1;
        }
        int c1 = A.mat[d1][el->n],c2 = A.mat[d2][el->n];
        if(c1>c2) P[j] = d1;
        else P[j] = d2;
            }
        //делаем детей
        for(k = 0;k<el->n/2;k++)
        {
          B.mat[i][k] = A.mat[P[0]][k];
          B.mat[i+1][k] = A.mat[P[1]][k];
        }
        for(k = el->n/2;k<el->n;k++)
        {
          B.mat[i][k] = A.mat[P[1]][k];
          B.mat[i+1][k] = A.mat[P[0]][k];
        }
        // mutation
        srand(time(0));
        int ind = rand()%(2);
        if(ind==1){
             int ind4 = rand()%(2);
             int indn = rand()%(el->n);
             B.mat[i+ind4][indn] = !B.mat[i+ind4][indn];
        }
    }

    for(i = 0;i<N;i++){
            summv = 0;
            summw = 0;
            for(j=0;j<el->n;j++){
            if(B.mat[i][j]==1){
                    summv+=el->V[j];
                    summw +=el->W[j];
            }
            }
            if(summw >(el->k)) summv = 0;
            B.mat[i][el->n] = summv;// price
            B.mat[i][el->n+1] = summw;
   	    }
   	A.m_null();
   	for(int r = 0;r<N;r++){
        for (int y = 0;y<el->n+2;y++){
            A.mat[r][y] = B.mat[r][y];
        }
   	}
   	B.m_null();
   	h++;
}
out = new int [el->n+2];
cout<<"out: "<<endl;

int A_max = 0;
    for(int t = 0;t<N;t++){
        if(A.mat[t][el->n]>A_max){
            A_max = t;
        }
    }

    for(int q = 0;q<el->n+2;q++){
    out[q] = A.mat[A_max][q];
    }
    cout<<out[el->n]<<" "<<(el->k)-out[el->n+1]<<endl;
    for(int q = 0;q<el->n;q++){
    cout<<out[q]<<" ";
    }
    cout<<endl<<endl;;
    delete[]P;
   	return;
}

};
