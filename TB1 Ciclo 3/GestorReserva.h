#ifndef _GRESERVA_
#define _GRESERVA_
#include "Pila.h"
#include "Reserva.h"
#include "Gestortxt.h"
#include <conio.h>
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
		int aux; int aux2 = 0;
		
		cout << "Ingrese id del vuelo: "; cin >> aux;

		Vuelo* vAux = this->Gvuelo.getVuelo(aux); getch();
		if (vAux == nullptr) return; //REGRESA SI EL VUELO NO EXISTE
		Asiento* aAux;

		vector<Asiento*> asientos;

		cout << "Cantidad de asientos: "; cin >> aux;

		//CALCULA LA CANTIDAD DE VUELOS LIBRES
		for (int i = 0; i < vAux->getVectorAsientos().size(); i++)
		{
			if (vAux->getVectorAsientos()[i]->getEstado() == 0)aux2++;
		};
		if (aux > aux2) { cout << "\n Cantidad de asientos libres insuficientes"; getch(); return; } //REGRESA SI LA CANTIDAD DE ASIENTOS ES SUPERIOR

		for (int i = 0; i < aux; i++)
		{
			cout << "\nSeleccione asiento " << i + 1 << " \n";
			vAux->mostrarAsientosDisponibles();
			do
			{
				cin >> aux2;
				aAux = vAux->getAsiento(aux2);  getch();
				if (aAux == nullptr) return;

			} while (aAux->getEstado() != 0);
			aAux->setEstado(1);
			
			asientos.push_back(aAux);
		}

		Reserva a(vAux, asientos);

		reservas.push(a);

		cout << "\n La reserva se realizo con exito. "; system("pause");
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

