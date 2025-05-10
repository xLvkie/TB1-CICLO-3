#ifndef _GRESERVA_
#define _GRESERVA_
#include "Reserva.h"
#include "Gestortxt.h"
using namespace std;
class GestorReserva
{
private:
	vector<Reserva> reservas;
	GestorVuelo Gvuelo;
	
public:
	GestorReserva(GestorVuelo&Gvuelo){
		this->Gvuelo = Gvuelo;
	}
	~GestorReserva(){}

	void reservar() {
		int aux;
		
		cout << "Ingrese id del vuelo: "; cin >> aux;

		Vuelo* vAux = new Vuelo(*this->Gvuelo.getVuelo(aux));

		cout << "Seleccione asiento: ";
		vAux->mostrarAsientos();
		cin >> aux;

		Asiento* aAux = new Asiento(*vAux->getAsiento(aux));
		Reserva a(vAux, aAux);

		reservas.push_back(a);

		cout << "\n La reserva se realizo con exito."; system("pause");
	}

	void mostrarReservas() {
		for (int i = 0; i < reservas.size(); i++)
		{
			reservas[i].mostrar();
		}
	}
};

#endif // !_RESERVAS_

