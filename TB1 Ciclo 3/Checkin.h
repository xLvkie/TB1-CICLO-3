#ifndef _CHECKIN_
#define _CHECKIN_

#include "GestorReserva.h"

class CheckIn {
private:
	Reserva* reserva;
	Pasajero* psj;
	int puerta, hora; 
public:
	CheckIn() {
		puerta = 100 + rand() % (299 + 1 - 100); 
		hora = 0 + rand() % 24;
	}
	~CheckIn() {}

	// --- Función algo demás --- //

	void mostrarTarjeta(Reserva* reserva) {
		if (reserva == nullptr) return;
		cout << "|=============== TARJETA DE EMBARQUE ===============|\n";
		reserva->mostrarDatosCompletos();
		cout << "Puerta: " << puerta << endl; 
		cout << "Hora de Embarque: " << hora << ":00 hrs\n";
		cout << "|===================================================|\n";
	}

	// --- Valida datos y procesa un Checkin y lo usamos en el GestorCheckIn --- //

	Reserva* procesarCheckIn(GestorReserva& gestorReserva) {
		string dni;
		int codigoVuelo;

		cout << "Ingrese el DNI del pasajero: ";
		cin >> dni;

		cout << "Ingrese Codigo del vuelo: ";
		cin >> codigoVuelo;

		Pila<Reserva> reservasAux = gestorReserva.getReservas(); //no referencia sino copia

		while (!reservasAux.estaVacia()) {
			Reserva reserva = reservasAux.pop();

			if (reserva.getPasajero()->getDni() == dni && reserva.getVuelo()->getCodigoVuelo() == codigoVuelo) {
				// Mostrar la tarjeta de embarque
				this->reserva = new Reserva(reserva);
				cout << "\nCheck-in exitoso!\n\n";
				mostrarTarjeta(this->reserva);
				return this->reserva;
			}
		}

		cout << "No se encontro una reserva con el DNI y el codigo de vuelo proporcionados\n";
		return nullptr;
	}
};

#endif