#ifndef _GESTORCHECKIN_
#define _GESTORCHECKIN_

#include "CheckIn.h"
#include "Cola.h"

class GestorCheckin {
private:
    Cola<Reserva> checkinsExitosos;

public:
    GestorCheckin() {}

    // --- Realiza un CheckIn --- //

    void realizarCheckIn(GestorReserva& gestorReserva) {
        CheckIn checkin;
        Reserva* reservaConfirmada = checkin.procesarCheckIn(gestorReserva);

        if (reservaConfirmada != nullptr) {
            checkinsExitosos.enqueue(*reservaConfirmada); 
            delete reservaConfirmada; //liberacion de memoria 
        }
    }

    // --- Muestra todos los CheckIns Realizados --- //

    void mostrarCheckinsRealizados() {
        if (checkinsExitosos.esVacia()) {
            cout << "\nNo hay check-ins registrados.\n";
            return;
        }

        Cola<Reserva> aux;
        cout << "\n=== HISTORIAL DE CHECK-INS ===\n";
        while (!checkinsExitosos.esVacia()) {
            Reserva reserva = checkinsExitosos.dequeue();
            reserva.mostrarDatosCompletos();
            aux.enqueue(reserva);
        }

        // restauramos la cola original
        while (!aux.esVacia()) {
            checkinsExitosos.enqueue(aux.dequeue());
        }
    }
};

#endif