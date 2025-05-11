#ifndef __VUELO__
#define __VUELO__

#include <map>
#include <vector>
#include <istream>
#include <algorithm>
#include "Asiento.h"

using namespace std;

// --- Variables Universales ---

string paises[10] = { "Peru", "Chile", "Argentina", "Brasil", "Colombia", "Ecuador", "Mexico", "EE.UU", "Espania", "Italia" };

// --- Clase Vuelo --- 

class Vuelo {
private:
    string origen, destino;
    int diaIda, mesIda, diaVuelta, mesVuelta, codigoVuelo;
    vector<Asiento*> asientos;

public:
    Vuelo() {}

    Vuelo(string origen, string destino, int diaIda, int mesIda, int diaVuelta, int mesVuelta, int codigoVuelo)
        : origen(origen), destino(destino), diaIda(diaIda), mesIda(mesIda), diaVuelta(diaVuelta), mesVuelta(mesVuelta), codigoVuelo(codigoVuelo) {

        //Para asignar 20 asientos por cada Vuelo
        for (int i = 0; i < 20; i++)
        {
            //Creamos un asiento
            char clasificacion = (rand() % 2 ? 'V' : 'E'); // Vip o Economico
            bool estado = rand() % 2; // 1 lleno, 0 vacio 
            int idAsiento = i + 101; // ids unicos del 101 al 120

            asientos.push_back(new Asiento(clasificacion, estado, idAsiento));
        }
    }
    ~Vuelo() {}

    void mostrarVuelo() {
        cout << "Vuelo nro: " << codigoVuelo << " |  " << origen << " - " << destino << endl;
        cout << "Ida: " << diaIda << "/" << mesIda << "\nVuelta: " << diaVuelta << "/" << mesVuelta << endl << endl;
    }

    string getOrigen() { return origen; }
    string getDestino() { return destino; }
    int getDiaIda() { return diaIda; }
    int getMesIda() { return mesIda; }
    int getDiaVuelta() { return diaVuelta; }
    int getMesVuelta() { return mesVuelta; }
    int getCodigoVuelo() { return codigoVuelo; }
    vector<Asiento*> getVectorAsientos() { return asientos; }

    Asiento* getAsiento(int idAsiento) {
        for (int i = 0; i < asientos.size(); i++)
        {
            if (asientos[i]->getIdAsiento() == idAsiento) {
                return asientos[i];
            }
        }
        cout << "\nAsiento no valido\n";
        return nullptr;
    }

    void mostrarAsientos() {
        for (int i = 0; i < asientos.size(); i++)
        {
            asientos[i]->mostrarAsiento();

        }
    }

    void mostrarAsientosDisponibles() {
        for (int i = 0; i < asientos.size(); i++)
        {
            asientos[i]->mostrarAsientoDisponible();
        }
    }
    void ordenarAsientosPorClasificacion() {
        for (int i = 0; i < asientos.size() - 1; i++)
        {
            for (int j = 0; j < asientos.size() - 1 - i; j++)
            {
                if (asientos[j]->getClasificacion() < asientos[j + 1]->getClasificacion()) {
                    swap(asientos[j], asientos[j + 1]);
                }
            }
        }
    }

    void ordenarAsientosPorEstado() {
        for (int i = 0; i < asientos.size() - 1; i++)
        {
            for (int j = 0; j < asientos.size() - 1 - i; j++)
            {
                if (asientos[j]->isEstado() < asientos[j + 1]->isEstado()) {
                    swap(asientos[j], asientos[j + 1]);
                }
            }
        }
    }
};

#endif // !__VUELO__