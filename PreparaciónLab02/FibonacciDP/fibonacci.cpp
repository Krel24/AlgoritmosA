//
// Created by User on 16/09/2026.
//

#include "fibonacci.h"
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int N=8;
    int F[N]={0,1};
    for(int i=2;i<N;i++) {
        F[i]=F[i-1]+F[i-2];
    }
    cout<<"El número "<<N<<" de la funcion Fibo es: "<<F[N]<<endl;

}