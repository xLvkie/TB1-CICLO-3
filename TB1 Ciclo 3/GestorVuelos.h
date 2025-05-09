#include <map>
#include <vector>
#include <cctype>  //para poner en minuscula strings, me falta probarlo 
#include "Vuelo.h" 

using namespace std;

class GestorVuelos {
private:
    //clave: int | valor: [clave: int, valor: vector de vuelos]
    map<int, map<int, vector<Vuelo*>>> vuelosPorMes; 

public:
    void agregarVuelo(Vuelo* vuelo) {
        int mesIda = vuelo->getMesIda();
        int diaIda = vuelo->getDiaIda();
        vuelosPorMes[mesIda][diaIda].push_back(vuelo);
    }

    void generarVuelosAutomaticos() {
        for (int mes = 1; mes <= 12; mes++) {
            for (int i = 0; i < 10; i++) { 
                int origenIdx, destinoIdx;
                do {
                    // -- Destino (Pais) --
                    origenIdx = rand() % 10;
                    destinoIdx = rand() % 10;
                } while (origenIdx == destinoIdx);

                string origen = paises[origenIdx];
                string destino = paises[destinoIdx];

                // -- Dias de ida y vuelta --
                int diaIda = 1 + rand() % 30;
                int diaVuelta = 30;

                int mesVuelta = mes;
                if (diaVuelta > 30) {
                    diaVuelta -= 30;
                    mesVuelta = mes == 12 ? 1 : mes + 1;
                }

                Vuelo* vuelo = new Vuelo(origen, destino, diaIda, mes, diaVuelta, mesVuelta);
                agregarVuelo(vuelo);
            }
        }
    }

    void mostrarVuelosEnFecha(int mes, int dia) {
        if (vuelosPorMes.count(mes) && vuelosPorMes[mes].count(dia)) {
            cout << "\n--- Vuelos para el " << dia << "/" << mes << " ---\n";
            for (Vuelo* v : vuelosPorMes[mes][dia]) {
                v->mostrarVuelo();
            }
        }
        else {
            cout << "No existen vuelos disponibles en esa fecha\n";
        }
    }

    void mostrarVuelosRecomendados(int mes) {
        if (vuelosPorMes.count(mes)) {
            cout << "\n=== Vuelos registrados para el mes " << mes << " ===\n";
            for (int dia = 1; dia <= 30; dia++) {
                if (vuelosPorMes[mes].count(dia)) {
                    cout << "\n--- Día " << dia << " ---\n";
                    for (Vuelo* v : vuelosPorMes[mes][dia]) {
                        v->mostrarVuelo();
                    }
                }
            }
        }
        else {
            cout << "error\n";
        }
    }

    void buscarVueloPorPaises(string p1, string p2) {
        cout << "\n=== Todos los vuelos registrados ===\n";
        for (auto itMes = vuelosPorMes.begin(); itMes != vuelosPorMes.end(); ++itMes) {
            int mes = itMes->first;
            map<int, vector<Vuelo*>>& dias = itMes->second;

            for (auto itDia = dias.begin(); itDia != dias.end(); ++itDia) {
                int dia = itDia->first;
                vector<Vuelo*>& listaVuelos = itDia->second;

                for (Vuelo* vuelo : listaVuelos) {
                    if (vuelo->getOrigen() == p1 && vuelo->getDestino() == p2) {
                        vuelo->mostrarVuelo(); 
                    }
                }
            }
        } 
    }

    void mostrarTodosLosVuelos() {
        cout << "\n=== Todos los vuelos registrados ===\n";
        for (auto itMes = vuelosPorMes.begin(); itMes != vuelosPorMes.end(); ++itMes) {
            int mes = itMes->first;
            map<int, vector<Vuelo*>>& dias = itMes->second;

            for (auto itDia = dias.begin(); itDia != dias.end(); ++itDia) {
                int dia = itDia->first;
                vector<Vuelo*>& listaVuelos = itDia->second;

                for (Vuelo* vuelo : listaVuelos) {
                    vuelo->mostrarVuelo();
                }
            }
        }
    }
};
