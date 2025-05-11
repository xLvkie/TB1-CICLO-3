#ifndef _CHECKIN_
#define _CHECKIN_

#include "GestorReserva.h"

class CheckIn {
private:

    //ideas

public:
    CheckIn(){}
    ~CheckIn(){}
    void procesarCheckIn(GestorReserva& gestorReserva) {
        //deberia ser un booleano, si encuentra de que si es reserva que se muestre el checkin :v

        string dni;
        int codigoVuelo;

        cout << "Ingrese el DNI del pasajero: ";
        cin >> dni;

        cout << "Ingrese Codigo del vuelo: ";
        cin >> codigoVuelo;

        bool reservaEncontrada = false;
        Pila<Reserva> reservasAux = gestorReserva.getReservas(); //no referencia sino copia
  
        while (!reservasAux.estaVacia()) {
            Reserva reserva = reservasAux.pop();

            if (reserva.getPasajero()->getDni() == dni && reserva.getVuelo()->getCodigoVuelo() == codigoVuelo) {
                // Mostrar la tarjeta de embarque
                cout << "\nCheck-in exitoso!\n\n";
                reserva.mostrar(); 
                reservaEncontrada = true;
                break;
            }
        }

        if (!reservaEncontrada) {
            cout << "No se encontró una reserva con el DNI y el código de vuelo proporcionados." << endl;
        }
    }
};

#endif