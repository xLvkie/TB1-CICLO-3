#ifndef _GRESERVA_
#define _GRESERVA_
#include "Pila.h"
#include "Reserva.h"
#include "Gestortxt.h"
using namespace std;
class GestorReserva
{
private:
	Pila<Reserva> reservas;
	GestorVuelo Gvuelo;
	
public:
	GestorReserva(GestorVuelo&Gvuelo){
		this->Gvuelo = Gvuelo;
	}
	~GestorReserva(){}

	void reservar() {
		int aux;
		
		cout << "Ingrese id del vuelo: "; cin >> aux;

		Vuelo* vAux = this->Gvuelo.getVuelo(aux);

		cout << "Seleccione asiento: ";
		vAux->mostrarAsientosDisponibles();

		cout << "Seleccione asiento: \n";
		vAux->mostrarAsientos();

		cin >> aux;

		Asiento* aAux = vAux->getAsiento(aux);
		Reserva a(vAux, aAux);

		reservas.push(a);

		cout << "\n La reserva se realizo con exito."; system("pause");
	}

	void mostrarReservas() {
		Pila<Reserva> aux;

		while (!reservas.estaVacia()) {
			Reserva val = reservas.pop();
			val.mostrar();
			aux.push(val);
		}

		while (!aux.estaVacia()) {
			reservas.push(aux.pop());
		}
	}
};

#endif // !_RESERVAS_

