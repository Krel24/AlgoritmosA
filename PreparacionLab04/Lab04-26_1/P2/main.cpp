//
// Created by User on 6/11/2026.
//
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

struct Pedido {
    char id;
    int peso;
};

struct Camion {
    int pesoTotal;
    vector<Pedido> pedidos;
};

struct Solucion {
    vector<Camion> camiones;
};

// Devuelve el índice del camión que deja menos espacio libre.
// Si el pedido no cabe en ningún camión abierto, devuelve -1.
int buscarCamion(const vector<Camion>& camiones,
                 const Pedido& pedido, int K) {
    int indiceCamion = -1;
    int menorEspacioLibre = INT_MAX;

    for (int i = 0; i < (int)camiones.size(); ++i) {
        int espacioLibre = K - camiones[i].pesoTotal - pedido.peso;

        if (espacioLibre >= 0 && espacioLibre < menorEspacioLibre) {
            menorEspacioLibre = espacioLibre;
            indiceCamion = i;
        }
    }

    return indiceCamion;
}

// Ordena los pedidos de mayor a menor peso.
bool compara(const Pedido& p1, const Pedido& p2) {
    return p1.peso > p2.peso;
}

// Construye una solución sorteando un pedido de la RCL en cada paso.
Solucion faseConstruccion(const vector<Pedido>& pedidos, int K,
                          double alfa) {
    Solucion solucion;

    vector<Pedido> v_pedidos = pedidos;
    sort(v_pedidos.begin(), v_pedidos.end(), compara);

    while (!v_pedidos.empty()) {
        vector<int> RCL; // Índices dentro de v_pedidos.

        int beta = v_pedidos.front().peso;
        int tau = v_pedidos.back().peso;
        double T = beta + alfa * (tau - beta);

        for (int i = 0; i < (int)v_pedidos.size(); ++i) {
            if (v_pedidos[i].peso >= T) {
                RCL.push_back(i);
            }
        }

        int indRand = rand() % RCL.size();
        int indElegido = RCL[indRand];
        Pedido pedidoElegido = v_pedidos[indElegido];

        int indiceCamion = buscarCamion(solucion.camiones, pedidoElegido, K);

        if (indiceCamion == -1) {
            solucion.camiones.push_back({0, {}});
            indiceCamion = (int)solucion.camiones.size() - 1;
        }

        solucion.camiones[indiceCamion].pedidos.push_back(pedidoElegido);
        solucion.camiones[indiceCamion].pesoTotal += pedidoElegido.peso;

        v_pedidos.erase(v_pedidos.begin() + indElegido);
    }

    return solucion;
}

// Genera varias soluciones y conserva la que usa menos camiones.
void grasp(const vector<Pedido>& pedidos, int K) {
    const double alfa = 0.20;
    const int iteraciones = 1000;

    for (const Pedido& pedido : pedidos) {
        if (pedido.peso > K) {
            cout << "El pedido " << pedido.id
                 << " supera la capacidad de un camion.\n";
            return;
        }
    }

    srand(42); // Semilla fija para poder repetir la prueba.

    int minCamiones = INT_MAX;
    Solucion solucionGlobal;

    for (int i = 0; i < iteraciones; ++i) {
        Solucion solucionLocal = faseConstruccion(pedidos, K, alfa);
        int cantidadCamiones = (int)solucionLocal.camiones.size();

        if (cantidadCamiones < minCamiones) {
            minCamiones = cantidadCamiones;
            solucionGlobal = solucionLocal;
        }
    }

    cout << "GRASP CONSTRUCCION - MEDIEXPRESS S.A.C\n";
    cout << "Pedidos: " << pedidos.size() << '\n';
    cout << "Alfa: " << alfa << " | Iteraciones: " << iteraciones << '\n';
    cout << "Capacidad por camion: " << K << " kg\n\n";

    for (int i = 0; i < (int)solucionGlobal.camiones.size(); ++i) {
        const Camion& camion = solucionGlobal.camiones[i];
        cout << "Camion " << i + 1 << " (cap=" << K << "kg): ";

        for (int j = 0; j < (int)camion.pedidos.size(); ++j) {
            if (j > 0) cout << ", ";
            cout << camion.pedidos[j].id;
        }

        cout << " | Peso: " << camion.pesoTotal << '/' << K << "kg\n";
    }

    cout << "Cantidad total de camiones = " << minCamiones << '\n';
}

// Carga los pedidos del enunciado y ejecuta GRASP.
int main() {
    vector<Pedido> pedidos{
        {'A', 15},
        {'B', 32},
        {'C', 20},
        {'D', 42},
        {'E',  8},
        {'F', 18}
    };

    int K = 50;
    grasp(pedidos, K);
}