#ifndef _CHECKIN_
#define _CHECKIN_

#include "GestorReserva.h"

class CheckIn {
private:
	Reserva* reserva;
	Pasajero* psj;

public:
	CheckIn(){}
	~CheckIn(){}

	// --- Valida datos y procesa un Checkin y lo usamos en el GestorCheckIn --- //

	Reserva* procesarCheckIn(GestorReserva& gestorReserva) {
		string dni;
		int codigoVuelo;

		cout << "Ingrese el DNI del pasajero: ";
		cin >> dni;

		cout << "Ingrese Codigo del vuelo: ";
		cin >> codigoVuelo;

		bool reservaEncontrada = false;
		Pila<Reserva> reservasAux = gestorReserva.getReservas(); //no referencia sino copia

		while (!reservasAux.estaVacia()) {
			Reserva reserva = reservasAux.pop();

			if (reserva.getPasajero()->getDni() == dni && reserva.getVuelo()->getCodigoVuelo() == codigoVuelo) {
				// Mostrar la tarjeta de embarque
				cout << "\nCheck-in exitoso!\n\n";
				mostrarTarjeta();
				reservaEncontrada = true;
				return new Reserva(reserva);
			}
		}

		if (!reservaEncontrada) {
			cout << "No se encontro una reserva con el DNI y el codigo de vuelo proporcionados." << endl;
			return nullptr;
		}
	}

	// --- Función algo demás --- //

	void mostrarTarjeta() {
		cout << "|=============== TARJETA DE EMBARQUE ===============|\n";
		//PUEDE QUE HAYA UN ERROR ACA ....
		reserva->mostrarDatosVuelo();
		cout << "|===================================================|\n";
	}
};

#endif