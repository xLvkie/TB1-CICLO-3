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

// --- Funciones externas ---


Vuelo* pedirDatosVuelo() {
    int opcionOrigen, opcionDestino;
    int diaIda, diaVuelta, mesIda, mesVuelta;

    cout << "=== Lista de países disponibles ===\n";
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << " - " << paises[i] << endl;
    }

    do {
        cout << "Seleccione el número del país de origen: ";
        cin >> opcionOrigen;
        if (opcionOrigen < 1 || opcionOrigen > 10)
            cout << "Opción inválida. Intente de nuevo.\n";
    } while (opcionOrigen < 1 || opcionOrigen > 10);

    do {
        cout << "Seleccione el número del país de destino: ";
        cin >> opcionDestino;
        if (opcionDestino < 1 || opcionDestino > 10)
            cout << "Opción inválida. Intente de nuevo.\n";
    } while (opcionDestino < 1 || opcionDestino > 10);

    do {
        cout << "Día de ida (1-30): ";
        cin >> diaIda;
        if (diaIda < 1 || diaIda > 30)
            cout << "Día inválido.\n";
    } while (diaIda < 1 || diaIda > 30);

    do {
        cout << "Mes de ida (1-12): ";
        cin >> mesIda;
        if (mesIda < 1 || mesIda > 12)
            cout << "Mes inválido.\n";
    } while (mesIda < 1 || mesIda > 12);

    do {
        cout << "Día de vuelta (1-30): ";
        cin >> diaVuelta;
        if (diaVuelta < 1 || diaVuelta > 30)
            cout << "Día inválido.\n";
    } while (diaVuelta < 1 || diaVuelta > 30);

    do {
        cout << "Mes de vuelta (1-12): ";
        cin >> mesVuelta;
        if (mesVuelta < 1 || mesVuelta > 12)
            cout << "Mes inválido.\n";
    } while (mesVuelta < 1 || mesVuelta > 12);


    cin.ignore();

    string origen = paises[opcionOrigen - 1];
    string destino = paises[opcionDestino - 1];

    return new Vuelo(origen, destino, diaIda, mesIda, diaVuelta, mesVuelta, 1);
}

#endif // !__VUELO__