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
	int precioFinal; 
public:
	Reserva(){}
	Reserva(Vuelo *vuelo, vector<Asiento*> asiento, Pasajero* user, int precioFinal) {
		for (int i = 0; i < asiento.size(); i++)
		{
			asiento[i]->setEstado(1);
		}

		this->vuelo = vuelo;
		this->asiento = asiento;
		this->user = user;
		this->precioFinal = precioFinal;
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
		cout << "Monto a pagar: " << precioFinal << endl; 
	}

	int getPrecioFinal() { return precioFinal; }
};

#endif // _RESERVA_
