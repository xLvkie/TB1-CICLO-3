#ifndef __PASAJERO__
#define __PASAJERO__

#include <iostream>
#include <string>	
#include <sstream>

using namespace std;

// --- Clase Pasajero --- 

class Pasajero {
private:
    string nombres;
    string apellidos;
    string correo;
    string dni;
public:
    Pasajero(){}
    Pasajero(string nombres, string apellidos, string correo, string dni)
        : nombres(nombres), apellidos(apellidos), correo(correo), dni(dni) {
    }
    ~Pasajero() {}

    string getNombres() { return nombres; }
    string getApellidos() { return apellidos; }
    string getCorreo() { return correo; }
    string getDni() { return dni; }

    string toString() {
        ostringstream ss;
        ss << "Nombres: " << nombres << endl;
        ss << "Apellidos: " << apellidos << endl;
        ss << "Correo: " << correo << endl;
        ss << "DNI: " << dni << endl;
        return (ss.str());
    }

    void mostrar() {
        cout << "Nombres: " << nombres << endl;
        cout << "Apellidos: " << apellidos << endl;
        cout << "Correo: " << correo << endl;
        cout << "DNI: " << dni << endl;
    }
};

#endif // !__PASAJERO__