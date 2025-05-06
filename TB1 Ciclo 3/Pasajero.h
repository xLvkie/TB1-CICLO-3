#ifndef __PASAJERO__
#define __PASAJERO__

#include <iostream>
#include <string>	
#include <sstream>

using namespace std;

class Pasajero {
private:
	string nombres;
	string apellidos;
	string correo;
	int dni;
public:
	Pasajero(string nombres, string apellidos, string correo, int dni)
		: nombres(nombres), apellidos(apellidos), correo(correo), dni(dni) {}
	~Pasajero() {}

    string toString() {
        ostringstream ss;
        ss << "Nombres: " << nombres << endl;
        ss << "Apellidos: " << apellidos << endl;
        ss << "Correo: " << correo << endl;
        ss << "DNI: " << dni << endl;
        return (ss.str());
    }
};

// --- Funciones externas ---

Pasajero* pedirDatosPasajero() {
    string nombres, apellidos, correo;
    string dniStr;
    int dni;

    do {
        cout << "Nombres: "; getline(cin, nombres);
        if (nombres.empty()) cout << "Nombres no puede estar vacío.\n";
    } while (nombres.empty());

    do {
        cout << "Apellidos: "; getline(cin, apellidos);
        if (apellidos.empty()) cout << "Apellidos no puede estar vacío.\n";
    } while (apellidos.empty());

    do {
        cout << "Correo: "; getline(cin, correo);
        if (correo.find('@') == string::npos)
            cout << "Correo inválido.\n";
    } while (correo.find('@') == string::npos);

    do {
        cout << "DNI: "; getline(cin, dniStr);
        if (dniStr.length() != 8 || dniStr.find_first_not_of("0123456789") != string::npos)
            cout << "DNI inválido.\n";
    } while (dniStr.length() != 8 || dniStr.find_first_not_of("0123456789") != string::npos);

    dni = stoi(dniStr); // conversión segura ya que fue validado

    return new Pasajero(nombres, apellidos, correo, dni);
}

#endif // !__PASAJERO__
