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
	void mostrarPasajero();
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
	inicio = nullptr;
}

// ---
template<class T>
void Lista<T>::insertarInicio(T v) {
	Nodo<T>* nodo = new Nodo<T>(v, nullptr, nullptr);

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

#endif // !__LISTA_DOBLE__