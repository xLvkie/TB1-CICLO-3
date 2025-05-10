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
		this->vuelo = vuelo;
		this->asiento = asiento;
	}
	~Reserva(){}

	void mostrar() {
		vuelo->mostrarVuelo();
		cout << endl;
		asiento->mostrarAsiento();
	}

};

#endif // _RESERVA_
