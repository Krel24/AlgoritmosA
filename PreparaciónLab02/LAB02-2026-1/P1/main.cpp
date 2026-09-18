//
// Created by User on 17/09/2026.
//

#include "main.h"
#include <iomanip>
#include <iostream>
using namespace std;
int main() {
    int N=6;
    int inicios[N]={1,4,6,6,5,8};
    int fines[N]={3,5,8,8,9,12};
    int pagos[N+1]={0,30,10,60,20,50,40};

    int dp[N+1]={};
    dp[0]=0;
    int bono=0;
    int ultimoInd=1;
    for(int i=1;i<N+1;i++) {
        if (validar(inicios, fines, pagos, bono, i, ultimoInd)) {
            dp[i]=max(dp[i-1]+pagos[i]+bono*15,pagos[i]);
            bono=0;
        }else {
            dp[i]=dp[i-1];
        }
    }
    cout<<dp[N]<<endl;
}

bool validar(int ini[6], int fin[6], int pagos[7], int &bono, int idx, int &ultiIdx) {
    if (idx==1) return true;
    int margen=ini[idx-1]-fin[ultiIdx-1];
    if (margen>=1) {
        if (margen==1) bono++;
        ultiIdx=idx;
        return true;
    }
    return false;
}