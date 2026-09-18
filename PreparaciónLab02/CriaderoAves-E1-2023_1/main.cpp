//
// Created by User on 18/09/2026.
//
#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

void solve(int * arr, int vuelto, int cant_billetes);

int main() {
    int billetes[6]={20,20,50,50,50,100};
    int cantBilletes= sizeof(billetes)/sizeof(billetes[0]);
    int vuelto=270;
    solve(billetes, vuelto, cantBilletes);
}

void solve(int *billetes, int vuelto, int cantBilletes) {
    int dp[cantBilletes+1][vuelto+1]{};
    for(int i=0;i<=cantBilletes;i++) dp[i][0]=1;
    // for(int i=0;i<=vuelto;i++) dp[i][0]=0;

    for(int i=1;i<=cantBilletes;i++) {
        for(int j=1;j<=vuelto;j++) {
            if (billetes[i]>j) {
                dp[i][j]=dp[i-1][j];
            }else {
                dp[i][j]=dp[i-1][j-billetes[i-1]];
            }
        }
    }

    if (dp[cantBilletes][vuelto]==1) {
        cout<<"sí se puede"<<endl;
    }else cout<<"no se puede p :c"<<endl;
}
