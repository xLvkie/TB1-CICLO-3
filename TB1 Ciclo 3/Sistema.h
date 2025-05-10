#ifndef __SISTEMA__
#define __SISTEMA__

#include <iostream>

using namespace std;

// --- Menu Principal --- ///

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

// --- Menu Usuario --- ///

void menuUsuario() {
	cout << "=====| Menu de Usuario |=====\n";
	cout << "1. Registrar nuevo usuario\n";
	cout << "2. Registro de usuarios\n";
	cout << "3. Salir\n";
}

void tituloUsuario() {
	cout << "=====| Menu de Usuario |=====\n";
}

// --- Menu Vuelos --- ///

void menuVuelos() {
	cout << "=====|  Menu de Vuelos  |=====\n";
	cout << "1. Listar todos los vuelos\n";
	cout << "2. Listar vuelos por mes\n";
	cout << "3. Listar vuelos por pais\n";
	cout << "4. Listar vuelos por Fecha Especifica\n";
	cout << "5. Listar vuelos por Origen, Destino y Fecha de Ida\n";
	cout << "6. Salir\n";
}

void tituloVuelo() {
	cout << "=====|  Menu de Vuelos  |=====\n";
}

void selecionMesVuelo() {
	cout << "Listado de Meses\n";
	cout << "1. Enero\t 2. Febrero\t 3. Marzo\n";
	cout << "4. Abril\t 5. Mayo\t 6. Junio\n";
	cout << "7. Julio\t 8. Agosto\t 9. Septiembre\n";
	cout << "10. Octubre\t 11. Noviembre\t 12. Diciembre\n";
}

void seleccionPais() {
	cout << "Listado de paises\n";
	cout << "1. Peru\t\t 2. Chile\t 3. Argentina\n";
	cout << "4. Brasil\t 5. Colombia\t 6. Ecuador\n";
	cout << "7. Mexico\t 8. EE.UU\t 9. Espania\n";
	cout << "10. Italia\n";
}

#endif // !__SISTEMA__
