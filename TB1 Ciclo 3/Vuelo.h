#ifndef __VUELO__
#define __VUELO__

#include <map>
#include <vector>
#include<string>
#include "Asientos.h"

using namespace std;

// --- Clase Vuelo --- 

class Vuelo {
private:
	string origen, destino;
	int diaIda, mesIda, diaVuelta, mesVuelta;
    Asientos asientos;

public:
	Vuelo(string origen, string destino, int diaIda, int mesIda, int diaVuelta, int mesVuelta)
		: origen(origen), destino(destino), diaIda(diaIda), mesIda(mesIda), diaVuelta(diaVuelta), mesVuelta(mesVuelta) {}
	~Vuelo() {}

    void mostrarVuelo() {
        cout << "Vuelo de " << origen << " a " << destino << " - Ida: " << diaIda << "/" << mesIda
            << " - Vuelta: " << diaVuelta << "/" << mesVuelta << endl;
    }

    string getOrigen() { return origen; }
    string getDestino() { return destino; }
    int getDiaIda() { return diaIda; }
    int getMesIda() { return mesIda; }
    int getDiaVuelta() { return diaVuelta; }
    int getMesVuelta() { return mesVuelta; }
};

// --- Variables Universales ---

string paises[] = { "Peru", "Chile", "Argentina", "Brasil", "Colombia", "Ecuador", "Mexico", "EE.UU", "Espania", "Italia" };

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

    return new Vuelo(origen, destino, diaIda, mesIda, diaVuelta, mesVuelta);
}

#endif // !__VUELO__

