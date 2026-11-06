//
// Created by User on 6/11/2026.
//
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Proyectos {
    int id;
    int costo;
    int ganancia;
    vector<int> idPredecesores;
};

struct Solucion {
    vector<Proyectos> proyectos;
    int gananciaT;
};

vector<Proyectos> faseConstruccion(const vector<Proyectos> proyectos, int N) {
    vector<Proyectos> solucion;
    solucion.resize(N);
    for (int i = 0; i < N; ++i) {

    }
}

void grasp(const vector<Proyectos> & proyectos, int N) {
    srand(time(NULL));
    int maxGanancia = -9999;
    vector<Proyectos> solucionGlobal;
    for (int i = 0; i < 1000; ++i) {
        vector<Proyectos> solucionLocal=faseConstruccion(proyectos,N);

    }
}

int main() {
    int N=7;
    vector<Proyectos> proyectos{
        {1,100,200, {}},
        {2,50,300,{1}},
        {3,150,300,{1}},
        {4,50,400,{}},
        {5,50,200,{4}},
        {6,150,800,{2,4}},
        {7,100,250,{}}
    };

    grasp(proyectos, N);
}
