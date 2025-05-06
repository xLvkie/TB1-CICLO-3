#ifndef __VUELO__
#define __VUELO__

#include <iostream>

using namespace std;

class Vuelo {
private:
	string origen;
	string destino;
	int codigoPromocional;
public:
	Vuelo(string origen, string destino, int codigoPromocional)
		: origen(origen), destino(destino), codigoPromocional(codigoPromocional) {}
	~Vuelo() {}
};

#endif // !__VUELO__

