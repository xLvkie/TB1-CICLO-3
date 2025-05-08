#ifndef __SISTEMA__
#define __SISTEMA__

#include <iostream>

using namespace std;

void portada() {
	cout << "\n\n\n\n\n";
	cout << " \t ____  _                           _     _                      _      _    _____                      _ " << endl;
	cout << " \t|  _ \\(_)                         (_)   | |                    | |    | |  / ____|                    | | " << endl;
	cout << " \t| |_) |_  ___ _ ____   _____ _ __  _  __| | ___     __ _       | | ___| |_| (___  _ __ ___   __ _ _ __| |_ " << endl;
	cout << " \t|  _ <| |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| |/ _` |/ _ \\   / _` |  _   | |/ _ \\ __|\\___ \\| '_ ` _ \\ / _` | '__| __|" << endl;
	cout << " \t| |_) | |  __/ | | \\ V /  __/ | | | | (_| | (_) | | (_| | | |__| |  __/ |_ ____) | | | | | | (_| | |  | |_ " << endl;
	cout << " \t|____/|_|\\___|_| |_|\\_/ \\___|_| |_|_|\\__,_|\\___/   \\__,_|  \\____/ \\___|\\__|_____/|_| |_| |_|\\__,_|_|   \\__|" << endl;

	cout << "\n\n\n\n\n";

	cout << "\t\t\t\t   -.                 `|." << endl;
	cout << "\t\t\t\t   |:\\-,              .| \\." << endl;
	cout << "\t\t\t\t   |: `.------------------------------------." << endl;
	cout << "\t\t\t\t   / /   o o o o o o o o o o o o o.-.o o   (_`. " << endl;
	cout << "\t\t\t\t  /_ \\_              .     .=     |'|         `) " << endl;
	cout << "\t\t\t\t       ``-----------//----/------------------'' " << endl;
}

void menuPrincipal() {
	cout << "=====| JetSmart |=====\n";
	cout << "1. Menu de Usuario\n";
	cout << "2. Menu de Vuelos\n";
	cout << "3. Check-In\n";
	cout << "4. Salir\n";
}

void menuUsuario() {
	cout << "=====| Menu de Usuario |=====\n";
	cout << "1. Registrar nuevo usuario\n";
	cout << "2. Registro de usuarios\n";
	cout << "3. Salir\n";
}

void menuVuelos() {
	cout << "=====|  Menu de Vuelos  |=====\n";
	cout << "1. Registrar nuevo vuelo\n";
	cout << "2. Registro de vuelos\n";
	cout << "3. Salir\n";
}

void tituloUsuario() {
	cout << "=====| Menu de Usuario |=====\n";
}

#endif // !__SISTEMA__

