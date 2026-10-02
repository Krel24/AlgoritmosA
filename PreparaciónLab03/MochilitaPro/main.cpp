//
// Created by User on 2/10/2026.
//
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

bool compara(vector<int> a,vector<int> b) {
    return a[1]>b[1];
}

int main() {
    vector<vector<int>> objetos={
        {1,2},
        {2,8},
        {3,5},
        {4,7},
        {5,3}
    };

    int n=objetos.size();
    int pesoM=24;

    //aplicamos voraz

    sort(objetos.begin(),objetos.end(), compara);

    vector<int> indObjUsados;
    int residuo=pesoM;
    for(int i=0;i<n;i++) {
        if (objetos[i][1]<residuo) {
            residuo-=objetos[i][1];
            indObjUsados.push_back(objetos[i][0]);
        }
    }
    cout<<"Se usó: "<<endl;
    for(int i=0;i<indObjUsados.size();i++) {
        cout<<"Objeto: "<<indObjUsados[i]<<endl;
    }
    cout<<"Sobró: "<<residuo<<endl;
}