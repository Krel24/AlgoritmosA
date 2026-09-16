//
// Created by User on 16/09/2026.
//

#include "fibonacci.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int N=8;
    int F[N+1]={};
    F[0]=0;
    F[1]=1;
    for(int i=2;i<N+1;i++) {
        F[i]=F[i-1]+F[i-2];
        cout<<"F["<<i<<"]="<<F[i]<<endl;
    }
    cout<<"El numero "<<N<<" de la funcion Fibo es: "<<F[N]<<endl;

}