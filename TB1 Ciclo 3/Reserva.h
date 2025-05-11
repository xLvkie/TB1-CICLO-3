#ifndef _RESERVA_
#define _RESERVA
#include "Pasajero.h"
#include "Vuelo.h"
#include "Asiento.h"

class Reserva
{
private:
	Vuelo* vuelo;
	vector<Asiento*> asiento;
	Pasajero* user;
public:
	Reserva(){}
	Reserva(Vuelo *vuelo, vector<Asiento*> asiento, Pasajero* user) {
		for (int i = 0; i < asiento.size(); i++)
		{
			asiento[i]->setEstado(1);
		}

		this->vuelo = vuelo;
		this->asiento = asiento;
		this->user = user;
	}
	~Reserva(){}

	void mostrar() {
		cout << "Pasajero: \n";
		user->toString();
		cout << "Vuelo: \n";
		vuelo->mostrarVuelo();
		cout << "Asientos: \n";
		for (int i = 0; i < asiento.size(); i++)
		{
			asiento[i]->mostrarAsiento();
		}
	}

	Pasajero* getPasajero() { return user; }
	Vuelo* getVuelo() {	return vuelo; }
};

#endif // _RESERVA_
