//
// Created by User on 18/09/2026.
//

#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int N=10, M=4;
    int inicios[M]={5,2,6,4};
    int fin[M]={10,4,12,15};
    int benef[M]={30,40,80,100};

    int dp[M+1]={};
    // for(int i=0;i<M;i++) {
    //     for(int j=0;j<M;j++) {
    //         if (fin[i]<fin[j]) {
    //             int temp=inicios[i];
    //             inicios[i]=inicios[j];
    //             inicios[j]=temp;
    //             temp=fin[i];
    //             fin[i]=fin[j];
    //             fin[j]=temp;
    //             temp=benef[i];
    //             benef[i]=benef[j];
    //             benef[j]=temp;
    //         }
    //     }
    // }
    dp[0]=benef[0];
    for(int i=1;i<M+1;i++) {
        //sacamos los beneficios del actual (del i que estamos analizando) y el previo, del dp[i-1]
        int benefActual=benef[i-1];
        int benefPrevio=dp[i-1];

        //el nuevo benef es igual al primero que coincida y calze bien con la condicion de que el inicio del que está más adelante
        //debe ser mayor al fin que está atrás o más atrás hasta llegar al inicio del arreglo datos
        int nuevoBenef=0;
        for (int j=i-1;j>0;j--) {
            if (inicios[i-1]>=fin[j-1]) {
                nuevoBenef=dp[j];
                break;
            }
        }
        nuevoBenef=nuevoBenef+benefActual;
        //se suma el nuevo benef con el benef actual

        dp[i]=max(nuevoBenef,benefPrevio);
        //se decide cuál debe ser el valor del dp[i]; o es el nuevo benef ya calculado, o es el benefPrevio considerando
        //lo que se calculó una iteración antes.
    }

    for(int i=0;i<=M;i++) {
        cout<<dp[i]<<" ";
    }

}