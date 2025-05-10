#include <conio.h>
#include "Sistema.h"
#include "ListaDoble.h"
#include "GestorVuelo.h"
#include "GestorReserva.h"
#include "GestorUsuarios.h"

int main() {
    srand(time(NULL));

    GestorUsuarios gUsuario;
    GestorVuelo gVuelos;
    gVuelos.generarVuelosAutomaticos();
    GestorReserva gReservas(gVuelos);

    int opcion = 0;
    string destino, origen;
    Pasajero* nuevo;

    portada(); getch();

    do {
        system("cls"); menuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1: // -- Menu Usuario --
            int auxUser;
            do {
                system("cls"); menuUsuario();
                cin >> auxUser;
                cin.ignore();

                switch (auxUser) {
                case 1:
                    // -- Registro de pasajero --
                    system("cls"); tituloUsuario();
                    gUsuario.agregarUsuario();
                    // -- Conclusión --
                    cout << "Pasajero registrado correctamente\n";
                    system("pause"); break;
                case 2:
                    // -- Mostrar Pasajeros ---
                    system("cls"); tituloUsuario();
                    gUsuario.mostrar();
                    // -- Conclusión --
                    system("pause"); break;
                case 3: system("pause"); break;
                default: cout << "Opción no válida\n"; system("pause"); break;
                }
            } while (auxUser != 3);
            break;

        case 2: // -- Menu Vuelo --
            int auxVuelo;
            do {
                system("cls"); menuVuelos();
                cin >> auxVuelo;
                cin.ignore();

                switch (auxVuelo) {
                case 1:
                    // -- Mostrar Todos los Vuelos --
                    system("cls"); tituloVuelo();
                    gVuelos.mostrarTodosLosVuelos();
                    // -- Conclusión --
                    system("pause"); break;
                case 2:
                    // -- Validar Datos --
                    int auxValor;
                    do {
                        system("cls"); tituloVuelo();
                        selecionMesVuelo();
                        cin >> auxValor;
                        cin.ignore();
                        if (auxValor < 0 || auxValor > 12) {
                            cout << "Opción no válida\n"; system("pause");
                        }
                    } while (auxValor < 0 || auxValor > 12);
                    // -- Mostrar Vuelos por Mes --
                    system("cls"); tituloVuelo();
                    gVuelos.mostrarVuelosPorMes(auxValor);
                    // -- Conclusión --
                    system("pause"); break;
                case 3:
                    // -- Validar Datos --
                    int auxOrigen, auxDestino;
                    do {
                        system("cls"); tituloVuelo();
                        seleccionPais();
                        cout << "Origen: "; cin >> auxOrigen;
                        cout << "Destino: "; cin >> auxDestino;

                        if ((auxOrigen < 1 || auxOrigen > 10) && (auxDestino < 1 || auxDestino > 10)) {
                            cout << "Opción no válida\n"; system("pause");
                        }
                    } while ((auxOrigen < 1 || auxOrigen > 10) && (auxDestino < 1 || auxDestino > 10));

                    origen = paises[auxOrigen - 1];
                    destino = paises[auxDestino - 1];

                    // -- Mostrar Vuelos por Paises --
                    gVuelos.mostrarVuelosPorPaises(origen, destino);
                    // -- Conclusión --
                    system("pause"); break;
                case 4:
                    gVuelos.prueba();
                    system("pause"); break;
                case 5:  
                    gReservas.reservar();
                    break;
                case 6:  break;
                default: cout << "Opción no válida\n"; system("pause"); break;
                }
            } while (auxVuelo != 6);
            break;
        case 3:
            do
            {
                system("cls"); menuCheckin(); system("pause"); cin >> opcion;
                switch (opcion)
                {
                case 1:
                    gReservas.mostrarReservas();
                    system("pause");
                    break;
                default:
                    break;
                }
            } while (opcion != 2);
            break;
            
        case 4: cout << "Gracias por usar el sistema\n"; system("pause"); break;
        default: cout << "Opción inválida\n"; system("pause"); break;
        }

    } while (opcion != 5);

    return 0;
}