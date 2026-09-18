//
// Created by User on 18/09/2026.
//

#include "main.h"
#include <iomanip>
using namespace std;
int main() {
    int totalA=95000, lima=35200, extran=2300;
    int n=8;
    int numActas[n]={lima, 6000, 12000, 8000, 12000, 15000, extran, 4500};
    int dp[n+1][totalA+1]={};

    //llenamos el dp
    for (int i=0;i<n+1; i++) dp[i][0]=1;
    for (int j=1;j<totalA+1; j++) dp[0][j]=0;
     //falta completar, de paso tambien el de dolares e intentar hacer unos tú solo
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<totalA+1; j++) {
            if (j<numActas[i]) {
                dp[i][j]=dp[i-1][j];
            }else {
                dp[i][j]=dp[i-1][j-numActas[i-1]];
            }
        }
    }

}