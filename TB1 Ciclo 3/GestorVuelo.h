#ifndef __GESTOR_VUELOS__
#define __GESTOR_VUELOS__

#include <windows.h>  // Para Sleep()
#include <iomanip>    // Para setw()
#include <map>
#include <cctype>
#include <vector>
#include "Vuelo.h" 
#include <set>

using namespace std;

// --- Varibles Universales --- //
string meses[] = {
        "Enero", "Febrero", "Marzo", "Abril", "Mayo",
        "Junio", "Julio", "Agosto", "Septiembre", "Octubre",
        "Noviembre", "Diciembre"
};

class GestorVuelo {
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
        set<string> codigosGenerados;

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
                int diaVuelta = 1 + rand() % 30;

                int mesIda = mes;
                int mesVuelta;

                do {
                    mesVuelta = mesIda + rand() % (13 - mesIda);
                } while (diaIda == diaVuelta && mesVuelta == mesIda);

                string codigoVuelo;
                do {
                    codigoVuelo = "";
                    for (int j = 0; j < 5; j++) {
                        codigoVuelo += '0' + rand() % 10;
                    }
                } while (codigosGenerados.count(codigoVuelo) > 0);

                codigosGenerados.insert(codigoVuelo);

                Vuelo* vuelo = new Vuelo(origen, destino, diaIda, mesIda, diaVuelta, mesVuelta, stoi(codigoVuelo));
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

    void mostrarVuelosPorMes(int mes) {
        if (vuelosPorMes.count(mes)) {
            cout << "\n=== Vuelos registrados para el mes " << meses[mes - 1] << " ===\n";
            for (int dia = 1; dia <= 30; dia++) {
                if (vuelosPorMes[mes].count(dia)) {
                    cout << "\n--- Vuelos del Dia " << dia << " ---\n";
                    for (Vuelo* v : vuelosPorMes[mes][dia]) {
                        v->mostrarVuelo();
                    }
                }
            }
        }
        else {
            cout << "No existen vuelos disponibles en esa fecha\n";
        }
    }

    void mostrarVuelosPorPaises(string origen, string destino) {
        cout << "\n=== Vuelos de " << origen << " a " << destino << " ==== \n";
        bool vuelosEncontrados = false;

        for (auto itMes = vuelosPorMes.begin(); itMes != vuelosPorMes.end(); ++itMes) {
            int mes = itMes->first;
            map<int, vector<Vuelo*>>& dias = itMes->second;

            for (auto itDia = dias.begin(); itDia != dias.end(); ++itDia) {
                int dia = itDia->first;
                vector<Vuelo*>& listaVuelos = itDia->second;

                for (Vuelo* vuelo : listaVuelos) {
                    if (vuelo->getOrigen() == origen && vuelo->getDestino() == destino) {
                        cout << "\n--- Vuelos del " << dia << " de " << meses[mes - 1] << " ---\n";
                        vuelo->mostrarVuelo();
                        vuelosEncontrados = true;
                    }
                }
            }
        }

        if (!vuelosEncontrados) {
            cout << "No se encontraron vuelos de " << origen << " a " << destino << endl;
        }
    }

    void mostrarVuelosDatosIda(string origen, string destino, int mesIda, int diaIda) {
        cout << "\n=== Vuelos segun Origen - Destino - Fecha de Ida ===\n";
        bool vuelosEncontrados = false;

        if (vuelosPorMes.count(mesIda) && vuelosPorMes[mesIda].count(diaIda)) {
            vector<Vuelo*>& listaVuelos = vuelosPorMes[mesIda][diaIda];

            for (Vuelo* vuelo : listaVuelos) {
                if (vuelo->getOrigen() == origen && vuelo->getDestino() == destino) {
                    cout << "\n--- Vuelo del " << diaIda << " de " << meses[mesIda - 1] << " ---\n";
                    vuelo->mostrarVuelo();
                    vuelosEncontrados = true;
                }
            }
        }

        if (!vuelosEncontrados) {
            cout << "No se encontraron vuelos de " << origen << " a " << destino
                << " para el " << diaIda << " de " << meses[mesIda - 1] << ".\n";
        }
    }

    //Borre void mostrarVuelosDatosVuelta(string origen, string destino, int mesVuelta, int diaVuelta) { 
    // Porque el map busca valores con el indice de dia ida y mes ida, no diaVuelta y mes vuelta

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

    Vuelo* getVueloPorCodigo(int codigo) {
        for (auto itMes = vuelosPorMes.begin(); itMes != vuelosPorMes.end(); ++itMes) {
            int mes = itMes->first;
            map<int, vector<Vuelo*>>& dias = itMes->second;

            for (auto itDia = dias.begin(); itDia != dias.end(); ++itDia) {
                int dia = itDia->first;
                vector<Vuelo*>& listaVuelos = itDia->second;

                for (Vuelo* vuelo : listaVuelos) {
                    if (vuelo->getCodigoVuelo() == codigo) {
                        return vuelo;
                    }
                }
            }
        }
        cout << "\nNo se encontro el vuelo con el codigo: " << codigo << endl;
        return nullptr; 
    }

    void mostrarUnVuelo(Vuelo* v) {
        v->mostrarVuelo(); 
    }


    //Asientos
    void mostrarAsientosVuelo(Vuelo* v) {
        v->mostrarAsientos();
    }

    void prueba() {
        Vuelo* prueba = new Vuelo("Peru", "Chile", 1, 5, 30, 6, 500);

        //prueba->ordenarAsientosPorClasificacion(); 
        //prueba->ordenarAsientosPorEstado(); 
        prueba->mostrarAsientos();
    }

    

};

#endif // !__GESTOR_VUELOS__