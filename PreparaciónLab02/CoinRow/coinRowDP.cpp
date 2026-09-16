//
// Created by User on 16/09/2026.
//

#include "coinRowDP.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int N=6;
    int monedas[7]={0,5,1,2,10,6,2};
    int dp[N+1]{};
    dp[0]=monedas[0];
    dp[1]=monedas[1];
    for(int i=2;i<7;i++) {
        dp[i]=max(dp[i-2]+monedas[i], dp[i-1]);
    }
    cout<<dp[6]<<endl;


}
