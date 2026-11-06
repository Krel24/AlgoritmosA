//
// Created by User on 6/11/2026.
//
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

struct OrdenProduccion {
    int id;
    int cant_botella;
    int prioridad;
};

struct LineaDeProduccion {
    int id;
    int tiempo;
    vector<OrdenProduccion> producciones;
};

struct Solucion {
    vector<LineaDeProduccion> lineas;
    int makespan;
};

bool comparar(OrdenProduccion a,OrdenProduccion b) {
    return a.cant_botella>b.cant_botella;
}
Solucion faseConstruccion(const vector<OrdenProduccion> ordenes) {
    Solucion solucion;
    solucion.lineas.resize(5);
    for (int i = 0; i < 5; ++i) {
        solucion.lineas[i].id=i+1;
        solucion.lineas[i].tiempo=0;
    }
    vector<OrdenProduccion> v_ordenes=ordenes;
    sort(v_ordenes.begin(),v_ordenes.end(), comparar);

    while (!v_ordenes.empty()) {
        vector<int> RCL;
        int beta=v_ordenes[0].cant_botella;
        int tau=v_ordenes[v_ordenes.size()-1].cant_botella;

        int T = beta + 0.2*(tau-beta);

        for (int i = 0; i < v_ordenes.size(); ++i) {
            if (v_ordenes[i].cant_botella>=T) {
                RCL.push_back(i);
            }
        }
        if (RCL.empty())break;

        int ind_rand=rand()%RCL.size();
        int indE=RCL[ind_rand];

        OrdenProduccion ordenElegida=v_ordenes[indE];
        int idBase=0;
        for (int i = 1; i < solucion.lineas.size(); ++i) {
            if (solucion.lineas[i].tiempo<solucion.lineas[idBase].tiempo) {
                idBase=i;
            }
        }

        solucion.lineas[idBase].producciones.push_back(ordenElegida);
        solucion.lineas[idBase].tiempo+=6*ordenElegida.cant_botella;

        v_ordenes.erase(v_ordenes.begin()+indE);
    }
    int mk=-99;
    for (int i = 0; i < solucion.lineas.size(); ++i) {
        if (mk<solucion.lineas[i].tiempo) {
            mk=solucion.lineas[i].tiempo;
        }
    }
    solucion.makespan=mk;

    return solucion;
}

void grasp(int N, int M, vector<OrdenProduccion> ordenes, vector<LineaDeProduccion> lineas) {
    srand(time(NULL));
    int makespan=999999;
    Solucion solucionGlobal;
    for (int i = 0; i < 1000; ++i) {
        Solucion solucionLocal=faseConstruccion(ordenes);

        if (solucionLocal.makespan<makespan) {
            makespan=solucionLocal.makespan;
            solucionGlobal=solucionLocal;
        }
    }

    cout<<"Mejor makespan: "<<makespan<<endl;
    for (LineaDeProduccion line : solucionGlobal.lineas) {
        cout<<"Linea: "<<line.id<<endl;
        for (OrdenProduccion orden : line.producciones) {
            cout<<orden.id<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int N=20;
    vector<OrdenProduccion> ordenes{
                {1, 103 ,2},
                {2, 58, 1},
                {3 ,88, 3},
                {4, 126 ,1},
                {5, 195, 2},
                {6, 90, 2},
                {7, 54, 3},
                {8, 195, 1},
                {9, 124, 2},
                {10, 113, 3},
                {11, 193, 2},
                {12, 55, 1},
                {13, 97, 1},
                {14, 97, 2},
                {15, 169, 2},
                {16, 50 ,2},
                {17, 167 ,3},
                {18, 74 ,1},
                {19, 79 ,2},
                {20, 109, 1}
    };
    int M=5;
    vector<LineaDeProduccion> lineas;

    grasp(N, M, ordenes, lineas);
}
