#ifndef __ASIENTOS__
#define __ASIENTOS__

#include <iostream>

using namespace std;

class Asiento {
private:
	char clasificacion;
	bool estado;
	int idAsiento;
public:
	Asiento();
	Asiento(char clasificacion, bool estado, int idAsiento) : clasificacion(clasificacion), estado(estado), idAsiento(idAsiento) {

	};
	~Asiento() {};

	void mostrarAsiento() {
		cout << idAsiento << " - " << clasificacion << " [" << estado << "]\n";
	}

	char getClasificacion() {
		return clasificacion;
	}

	bool isEstado() {
		return estado;
	}

	int getIdAsiento() {
		return idAsiento;
	}
};

#endif // !__ASIENTOS__