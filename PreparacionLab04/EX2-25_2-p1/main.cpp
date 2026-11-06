//
// Created by User on 6/11/2026.
//

#include "main.h"


#include <iomanip>
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
using namespace std;

struct Pedido {
    char idChar;
    int peso;
    int zona;

    int costo;
};
struct Camion {
    int id;
    int capacidad;
    vector<Pedido> pedidos;
};
struct Asignacion {
    Camion cam;
    vector<Pedido> pedidos;
};




vector<Asignacion> faseConstruccion(int n_camiones, vector<Camion> & camiones, int n_pedidos, vector<Pedido> & pedidos, int(* costo_entrega)[4]) {
    vector<Asignacion> solucion;
    for (int i = 0; i < n_camiones; ++i) {
        solucion[i].cam=camiones[i];
    }
    //incompleto
}

void grasp(int NCamiones,vector<Camion> camiones,int NPedidos,vector<Pedido> pedidos,int costo_entrega[][4]) {
    srand(time(NULL));
    int costoTotal=999;
    vector<Asignacion> solucionGlobal;
    for (int i = 0; i < 1000; ++i) {

        vector<Asignacion> solucionLocal=faseConstruccion(NCamiones, camiones, NPedidos, pedidos, costo_entrega);

        //acá ver si es mejor o peor que los anteriores, de no haber anteriores se remplaza normal



    }
}

int main() {
    int NCamiones=3;
    vector<Camion> camiones{
        {1,40},
        { 2, 35},
        {3,50}
    };

    int NPedidos=20;
    vector<Pedido> pedidos{
        {'A',15,1},
        {'B',10,2},
        {'C',20,1},
        {'D',12,2},
        {'E',8,1},
        {'F',18,2}
    };
    int costo_entrega[NCamiones+1][4] {
        {0,0,0},
        {1,4,9},
        {2,7,3},
        {3,5,6}
    };

    grasp(NCamiones, camiones, NPedidos, pedidos, costo_entrega);

}
