#ifndef _RESERVA_
#define _RESERVA
#include "Pasajero.h"
#include "Vuelo.h"
#include "Asiento.h"

class Reserva
{
private:
	Vuelo *vuelo;
	Asiento *asiento;
	Pasajero user;
public:
	Reserva(){}
	Reserva(Vuelo *vuelo, Asiento *asiento) {
		asiento->setEstado(1);

		this->vuelo = vuelo;
		this->asiento = asiento;
	}
	~Reserva(){}

	void mostrar() {
		cout << "Vuelo: \n";
		vuelo->mostrarVuelo();
		cout << "Asiento: ";
		asiento->mostrarAsiento();
	}

};

#endif // _RESERVA_
