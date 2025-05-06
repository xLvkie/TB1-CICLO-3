#ifndef __LISTA_DOBLE__
#define __LISTA_DOBLE__

#include <iostream>
#include "Nodo.h"
#include "Vuelo.h"
#include "Pasajero.h"
//vuelos y pasajeros

using namespace std;

template<class T>
class Lista {
private:
	Nodo<T>* inicio;

public:
	Lista() { inicio = nullptr; }
	~Lista();
	void insertarInicio(T v);
	void insertarFinal(T v);
    bool esVacio();
	void mostrar();
};

// ---
template<class T>
Lista<T>::~Lista() {
	Nodo<T>* temp;
	while (!esVacio()) {
		temp = inicio;
		inicio = inicio->siguiente;
		delete temp;
		temp = nullptr;
	}
	delete inicio;
	inicio = nullptr;
}

// ---
template<class T>
void Lista<T>::insertarInicio(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);

	if (esVacio()) inicio = nodo;
	else {
		inicio->anterior = nodo;
		nodo->siguiente = inicio;
	}
	inicio = nodo;
}

// ---
template<class T>
void Lista<T>::insertarFinal(T v) {
	Nodo<T>* nodo = new Nodo<T>(v);

	if (esVacio()) inicio = nodo;
	else {
		Nodo<T>* aux = inicio;

		while (aux->siguiente != nullptr) {
			aux = aux->siguiente;
		}

		aux->siguiente = nodo;
	}
}

// ---
template<class T>
bool Lista<T>::esVacio() {
	if (inicio == nullptr) return true;
	else return false;
}

// --- Registro Pasajeros ---

template<class T>
void Lista<T>::mostrar() {
	Nodo<T>* nodo = inicio; //Nodo<tipo T> apunta (*) hacua 'nodo'
	cout << "# Lista de Pasajeros:\n";

	int i = 1;
	while (nodo != nullptr) {
		Pasajero* psj = (Pasajero*)(nodo->dato); //Pasajero apunta a psj con valor Pasajero que apunta al dato del nodo
		cout << "# " << i++ << ". ---\n";
		cout << psj->toString();
		cout << "->\n";

		nodo = nodo->siguiente;
	}
	cout << endl;
}

#endif // !__LISTA_DOBLE__

