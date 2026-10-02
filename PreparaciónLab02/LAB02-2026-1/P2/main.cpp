//
// Created by User on 18/09/2026.
//

#include "main.h"
#include <iomanip>
#include <algorithm>
using namespace std;
int main() {
    int totalA=95000, lima=35200, extran=2300;
    int n=8;
    int numActas[8]={lima, 6000, 12000, 8000, 12000, 15000, extran, 4500};
    int dp[8+1][totalA+1]={};

    //llenamos el dp
    //analizamos cómo debe ser esta matriz de dp
    //dp[i][j] es: con las i primeros datos puedo conseguir el valor de j = 0/1
    for (int i=0;i<n+1; i++) dp[i][0]=1;
    for (int j=1;j<=totalA; j++) dp[1][j]=0;
     //falta completar, de paso tambien el de dolares e intentar hacer unos tú solo
    for (int i=1; i<n+1; i++) {
        for (int j=1; j<totalA+1; j++) {
            if (numActas[i-1]<j) {
                dp[i][j]=dp[i-1][j];
            }else {
                dp[i][j]=dp[i-1][j-numActas[i-1]];
            }
        }
    }

}