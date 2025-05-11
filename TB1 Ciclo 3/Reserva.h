#ifndef _RESERVA_
#define _RESERVA
#include "Pasajero.h"
#include "Vuelo.h"
#include "Asiento.h"

class Reserva
{
private:
	Vuelo *vuelo;
	vector<Asiento*> asiento;
	Pasajero user;
public:
	Reserva(){}
	Reserva(Vuelo *vuelo, vector<Asiento*> asiento) {
		for (int i = 0; i < asiento.size(); i++)
		{
			asiento[i]->setEstado(1);
		}

		this->vuelo = vuelo;
		this->asiento = asiento;
	}
	~Reserva(){}

	void mostrar() {
		cout << "Vuelo: \n";
		vuelo->mostrarVuelo();
		cout << "Asientos: \n";
		for (int i = 0; i < asiento.size(); i++)
		{
			asiento[i]->mostrarAsiento();
		}
	}

};

#endif // _RESERVA_
