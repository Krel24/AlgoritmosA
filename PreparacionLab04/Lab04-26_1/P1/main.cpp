//
// Created by User on 6/11/2026.
//
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

struct Proyecto {
    int id;
    int costo;
    int ganancia;
    vector<int> idPredecesores;
};

struct Solucion {
    vector<Proyecto> proyectos;
    int gananciaT;
};

bool verificarPre(const vector<Proyecto> v_proyectos, int id, const vector<Proyecto>  solucionP) {
    if (v_proyectos[id-1].idPredecesores.empty()) return true;
    int conteo=0;
    for (int i = 0; i < v_proyectos[id-1].idPredecesores.size(); ++i) {
        for (int j = 0; j < solucionP.size(); ++j) {
            if (solucionP[j].id==v_proyectos[id-1].idPredecesores[i]) {
                conteo++;
            }
        }
    }
    if (conteo==v_proyectos[id-1].idPredecesores.size()) return true;
    return false;
}

bool compara(Proyecto p1, Proyecto p2) {
    return p1.ganancia > p2.ganancia;
}

Solucion faseConstruccion(const vector<Proyecto> proyectos, int N, int Presupuesto) {
    Solucion solucion;
    solucion.gananciaT = 0;

    vector<Proyecto> v_proyectos=proyectos;
    sort(v_proyectos.begin(), v_proyectos.end(), compara);
    int presupuestoRestante= Presupuesto;
    while (!v_proyectos.empty()) {
        vector<Proyecto> factibles;
        for (int i = 0; i < v_proyectos.size(); ++i) {
            const Proyecto& proyecto = v_proyectos[i];

            if (proyecto.costo <= presupuestoRestante &&
                verificarPre(v_proyectos, i+1, solucion.proyectos)) {
                factibles.push_back(v_proyectos[i]);
                }
        }

        if (factibles.empty()) break;

        vector<int> RCL;    //RCL tiene los índices pero del arreglo (no del proyecto en sí)
        int beta=factibles[0].ganancia;
        int tau=factibles[factibles.size()-1].ganancia;

        double T=beta+0.3*(tau-beta);

        for (int i = 0; i < factibles.size(); ++i) {
            if (factibles[i].ganancia>=T) {
                RCL.push_back(i);
            }
        }
        if (RCL.empty())break;

        int ind_rand=rand()%RCL.size();
        int indElegido=RCL[ind_rand];

        Proyecto proyElegido=factibles[indElegido];
        solucion.proyectos.push_back(proyElegido);
        solucion.gananciaT+=proyElegido.ganancia;

        presupuestoRestante-=proyElegido.costo;

        for (int j = 0; j < v_proyectos.size(); ++j) {
            if (v_proyectos[j].id==proyElegido.id)
                v_proyectos.erase(v_proyectos.begin()+j);
        }
    }

    return solucion;
}

void grasp(const vector<Proyecto> & proyectos, int N, int P) {
    srand(time(NULL));
    int maxGanancia = -9999;
    Solucion solucionGlobal;
    for (int i = 0; i < 1000; ++i) {
        Solucion solucionLocal=faseConstruccion(proyectos,N,P);

        if (maxGanancia<solucionLocal.gananciaT) {
            maxGanancia=solucionLocal.gananciaT;
            solucionGlobal=solucionLocal;
        }

    }

    cout<<"Proyectos seleccionados: ";
    for (Proyecto p : solucionGlobal.proyectos) {
        cout<<p.id<<" ";
    }
    cout<<endl;
    cout<<"Max ganancia: "<<maxGanancia<<endl;
}

int main() {
    int N=7;
    vector<Proyecto> proyectos{
        {1,100,200, {}},
        {2,50,300,{1}},
        {3,150,300,{1}},
        {4,50,400,{}},
        {5,50,200,{4}},
        {6,150,800,{2,4}},
        {7,100,250,{}}
    };
    int P=400;
    grasp(proyectos, N, P);
}
