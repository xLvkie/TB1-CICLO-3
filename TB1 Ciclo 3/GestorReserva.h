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
	GestorUsuarios gUsuarios;
	
public:
	GestorReserva(GestorVuelo&Gvuelo){
		this->Gvuelo = Gvuelo;
	}
	~GestorReserva(){}

	void reservar() {
		int aux; int aux2 = 0;
		
		cout << "\n === Reservar Vuelo ===\n"; 
		cout << "Ingrese id del vuelo: "; cin >> aux;

		Vuelo* vAux = this->Gvuelo.getVuelo(aux); system("pause");
		if (vAux == nullptr) return; //REGRESA SI EL VUELO NO EXISTE
		Asiento* aAux;

		vector<Asiento*> asientos;

		cout << "Cantidad de asientos: "; cin >> aux;

		//CALCULA LA CANTIDAD DE ASIENTOS LIBRES
		for (int i = 0; i < vAux->getVectorAsientos().size(); i++)
		{
			if (vAux->getVectorAsientos()[i]->getEstado() == 0)aux2++;
		};
		if (aux > aux2) { cout << "\n Cantidad de asientos libres insuficientes\n"; system("pause"); return; } //REGRESA SI LA CANTIDAD DE ASIENTOS ES SUPERIOR

		for (int i = 0; i < aux; i++)
		{ 
			cout << "\nSeleccione asiento " << i + 1 << " \n";
			vAux->mostrarAsientosDisponibles();
			do
			{
				cout << "Ingrese el id: "; 
				cin >> aux2;
				aAux = vAux->getAsiento(aux2);  cout << endl; system("pause>0");
				if (aAux == nullptr) return;

			} while (aAux->getEstado() != 0);
			aAux->setEstado(1);
			
			asientos.push_back(aAux);
		}

		Pasajero* pAux = gUsuarios.agregarUsuario();
		

		Reserva a(vAux, asientos, pAux);

		reservas.push(a);

		cout << "\n La reserva se realizo con exito. \n"; system("pause>0");
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

