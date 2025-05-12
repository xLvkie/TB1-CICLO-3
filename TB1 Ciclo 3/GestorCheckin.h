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

    // --- Muestra todos los CheckIns de un Pasajero --- //

    void mostrarCheckinsPorUsuario() {
        string dni;
        cout << "Ingrese el DNI del usuario a consultar: ";
        cin >> dni;

        if (checkinsExitosos.esVacia()) {
            cout << "\nNo hay check-ins registrados.\n";
            return;
        }

        Cola<Reserva> aux;
        bool hayCoincidencias = false;

        cout << "\n=== CHECK-INS DEL USUARIO CON DNI: " << dni << " ===\n";
        while (!checkinsExitosos.esVacia()) {
            Reserva reserva = checkinsExitosos.dequeue();

            if (reserva.getPasajero()->getDni() == dni) {
                reserva.mostrarDatosCompletos();
                hayCoincidencias = true;
            }

            aux.enqueue(reserva); // restaurar luego
        }

        // restauramos la cola original
        while (!aux.esVacia()) {
            checkinsExitosos.enqueue(aux.dequeue());
        }

        if (!hayCoincidencias) {
            cout << "No se encontraron check-ins para el DNI proporcionado.\n";
        }
    }
};

#endif