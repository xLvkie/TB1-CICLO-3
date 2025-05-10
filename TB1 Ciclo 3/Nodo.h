#ifndef __NODO__
#define __NODO__

#include <iostream>

using namespace std;

template<class T>
class Nodo {
public:
	T dato;
	Nodo<T>* anterior;
	Nodo<T>* siguiente;

	Nodo(T v, Nodo<T>* ant = nullptr, Nodo<T>* sig = nullptr)
		: dato(v), anterior(ant), siguiente(sig) {
	}

	Nodo(T d, Nodo<T>* sig = nullptr) {
		dato = d;
		siguiente = sig;
	}
};

#endif // !__NODO__
