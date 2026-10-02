//
// Created by User on 2/10/2026.
//

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

bool compara(int a, int b) {
    return a>b;
}

void alg_voraz(vector<int>denom,int c) {
    int residuo=c;
    sort(denom.begin(),denom.end(),compara);
    int i=0, m=denom.size()-1, cantMonedas=0;
    while (residuo>0 and i<m) {
        if (denom[i]<residuo) {
            cout<<"Se usa moneda "<<denom[i]<<endl;
            residuo-=denom[i];
            cantMonedas++;
        }else {
            i++;
        }
    }
    cout<<"Se usa monedas "<<cantMonedas<<endl;
    cout<<"Sobra: "<<residuo<<endl;
}

int main() {
    vector<int> denom={1,2,5,20,50};
    int c=36;

    alg_voraz(denom, c);
}