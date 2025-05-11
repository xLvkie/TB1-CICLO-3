#ifndef _GRESERVA_
#define _GRESERVA_

#include "Pila.h"
#include "GestorUsuarios.h"
#include "Reserva.h"
#include "Gestortxt.h"
#include "GestorUsuarios.h"
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
		int numAsientos; int aux2 = 0; int auxExcesoPorVip = 0; int cont = 0; 
		
		cout << "\n === Reservar Vuelo ===\n"; 
		cout << "Ingrese id del vuelo: "; cin >> numAsientos;

		Vuelo* vAux = this->Gvuelo.getVuelo(numAsientos); //system("pause");
		if (vAux == nullptr) return; //REGRESA SI EL VUELO NO EXISTE
		Asiento* aAux;

		vector<Asiento*> asientos;

		cout << "Cantidad de asientos: "; cin >> numAsientos;

		//CALCULA LA CANTIDAD DE ASIENTOS LIBRES
		for (int i = 0; i < vAux->getVectorAsientos().size(); i++)
		{
			if (vAux->getVectorAsientos()[i]->getEstado() == 0)aux2++;
		};
		if (numAsientos > aux2) { cout << "\n Cantidad de asientos libres insuficientes\n"; system("pause"); return; } //REGRESA SI LA CANTIDAD DE ASIENTOS ES SUPERIOR

		cout << "\nNota: Por cada asiento VIP se adicionan 50 USD a la tarifa\n"; 
		for (int i = 0; i < numAsientos; i++)
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

			//Calculo del extra a pagar por elegir VIP
			if (aAux->getClasificacion() == 'V') {
				cont++; 
				auxExcesoPorVip += 50;
			}
			else
				auxExcesoPorVip += 0;
			
			asientos.push_back(aAux);
		}

		//Lambda para calcular del precio final de la compra
		auto calcularPrecioFinal = [&]() -> int {
			return (vAux->getPrecio() * numAsientos) + auxExcesoPorVip;
			};


		cout << "\nEscogio " << cont << " VIP y " << numAsientos - cont << " Economico\n"; 
		cout << "Monto a pagar: " << calcularPrecioFinal() << endl << endl;

		getch(); 
		Pasajero* pAux = gUsuarios.agregarUsuario();		

		Reserva a(vAux, asientos, pAux, calcularPrecioFinal());

		reservas.push(a);

		cout << "\nLa reserva se realizo con exito. \n"; system("pause>0");
	}

	void mostrarReservas() {
		Pila<Reserva> aux;

		while (!reservas.estaVacia()) {
			Reserva val = reservas.pop();
			val.mostrarDatosVuelo();
			aux.push(val);
		}

		while (!aux.estaVacia()) {
			reservas.push(aux.pop());
		}
	}

	Pila<Reserva> getReservas() {
		return reservas;
	}
};

#endif // !_RESERVAS_

