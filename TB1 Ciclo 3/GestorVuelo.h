#ifndef __GESTOR_VUELOS__
#define __GESTOR_VUELOS__

#include <map>
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
    bool vuelosEncontrados;  
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
                    if (mesIda == 12 && diaIda == diaVuelta) {
                        diaVuelta = (diaIda % 30) + 1; // fuerza a que sean distintos
                    }
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
        vuelosEncontrados = false;
        if (vuelosPorMes.count(mes) && vuelosPorMes[mes].count(dia)) {
            cout << "\n--- Vuelos para el " << dia << "/" << mes << " ---\n";
            for (Vuelo* v : vuelosPorMes[mes][dia]) {
                v->mostrarVuelo();
                vuelosEncontrados = true;
            }
        }
        else {
            cout << "No existen vuelos disponibles en esa fecha\n";
        }
    }

    void mostrarVuelosPorMes(int mes) {
        vuelosEncontrados = false;
        if (vuelosPorMes.count(mes)) {
            cout << "\n=== Vuelos registrados para el mes " << meses[mes - 1] << " ===\n";
            for (int dia = 1; dia <= 30; dia++) {
                if (vuelosPorMes[mes].count(dia)) {
                    cout << "\n--- Vuelos del Dia " << dia << " ---\n";
                    for (Vuelo* v : vuelosPorMes[mes][dia]) {
                        v->mostrarVuelo();
                        vuelosEncontrados = true;
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
        vuelosEncontrados = false;

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
        vuelosEncontrados = false;

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

    void mostrarVuelosDelDia(vector<Vuelo*>& vuelos, size_t i = 0) {
        if (i >= vuelos.size()) return;
        vuelos[i]->mostrarVuelo();
        mostrarVuelosDelDia(vuelos, i + 1);
    }

    void mostrarVuelosDelMes(map<int, vector<Vuelo*>>& dias, map<int, vector<Vuelo*>>::iterator itDia) {
        if (itDia == dias.end()) return;
        mostrarVuelosDelDia(itDia->second);
        mostrarVuelosDelMes(dias, next(itDia));
    }

    // iterador es lo mismo que auto, pero como lo estamos definiedo en los argumentos no puede ir auto debe ir iterador

    void mostrarTodosLosVuelosRec(map<int, map<int, vector<Vuelo*>>>& vuelosPorMes, map<int, map<int, vector<Vuelo*>>>::iterator itMes) {
        if (itMes == vuelosPorMes.end()) return;
        mostrarVuelosDelMes(itMes->second, itMes->second.begin());
        mostrarTodosLosVuelosRec(vuelosPorMes, next(itMes));
    }

    void mostrarTodosLosVuelos() {
        cout << "\n=== Todos los vuelos registrados ===\n";
        mostrarTodosLosVuelosRec(vuelosPorMes, vuelosPorMes.begin());
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

    Vuelo* getVuelo(int codeVuelo) {
        for (auto itMes = vuelosPorMes.begin(); itMes != vuelosPorMes.end(); ++itMes) {
            int mes = itMes->first;
            map<int, vector<Vuelo*>>& dias = itMes->second;

            for (auto itDia = dias.begin(); itDia != dias.end(); ++itDia) {
                int dia = itDia->first;
                vector<Vuelo*>& listaVuelos = itDia->second;

                for (Vuelo* vuelo : listaVuelos) {
                    if (vuelo->getCodigoVuelo() == codeVuelo) {
                        vuelo->mostrarVuelo();
                        return vuelo;
                    }
                }
            }
        }
        cout << "\nNo se encontro el vuelo con el codigo: " << codeVuelo;
        return nullptr;
    }

    bool isVuelosEncontrados() {
        return vuelosEncontrados;
    }

};

#endif // !__GESTOR_VUELOS__