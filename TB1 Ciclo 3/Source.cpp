#include "Sistema.h"
#include "ListaDoble.h"
#include "GestorVuelo.h"
#include "GestorReserva.h"
#include "GestorUsuarios.h"
#include "GestorCheckin.h"

int main() {
    srand(time(NULL));
    portada(); getch();

    GestorUsuarios gUsuario; gUsuario.leerUsuarios();

    GestorVuelo gVuelos;
    gVuelos.generarVuelosAutomaticos();
    GestorReserva gReservas(gVuelos);

    CheckIn checkIn;
    GestorCheckin gCheckIn;

    int opcion = 0;
    string destino, origen;

    //Lambda para validar los valores que se ingresan en dia y mes
    auto validarDiaMes = [](int dia, int mes) {
        return dia >= 1 && dia <= 31 && mes >= 1 && mes <= 12;
        }; 

    do {
        system("cls"); menuPrincipal();
        cin >> opcion;
        cin.ignore();

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

                    cout << "Operación conluida correctamente\n";
                    system("pause"); break;
                case 2:
                    // -- Mostrar Pasajeros ---
                    system("cls"); tituloUsuario();
                    gUsuario.mostrar();

                    system("pause"); break;
                case 3: system("pause"); break;
                default: cout << "Opcion no valida\n"; system("pause"); break;
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
                    int auxSubMenu;
                    do { // SubMenu de Ordenamiento
                        system("cls"); subMenuTodosLosVuelos();
                        cin >> auxSubMenu;
                        cin.ignore();

                        switch (auxSubMenu) {
                        case 1:
                            system("cls"); cout << "=== Ordenamiento por Precio ===\n"; 
                            gVuelos.ordenarTodosLosVuelosPorPrecio(); 
                            gReservas.reservar();
                            system("pause"); break;
                        case 2:
                            system("cls"); cout << "=== Ordenamiento por Pais de Origen ===\n";
                            gVuelos.ordenarTodosLosVuelosPorPais(); 
                            gReservas.reservar(); 
                            system("pause"); break;
                        case 3: 
                            system("cls"); cout << "=== Ordenamiento por Id Vuelo ===\n";
                            gVuelos.ordenarTodosLosVuelosPorId();
                            gReservas.reservar(); 
                            system("pause"); break;
                        case 4: system("pause"); break;
                        default: cout << "Opcion no valida\n"; system("pause"); break;
                        }
                    } while (auxSubMenu != 4);

                    break;
                case 2:
                    // -- Validar Datos --
                    int auxValor;
                    do {
                        system("cls"); tituloVuelo();
                        selecionMesVuelo();
                        cout << "Ingrese el mes: ";
                        cin >> auxValor;
                        cin.ignore();
                        if (auxValor < 0 || auxValor > 12) {
                            cout << "Opcion no valida\n"; system("pause");
                        }
                    } while (auxValor < 0 || auxValor > 12);
                    // -- Mostrar Vuelos por Mes --
                    system("cls"); tituloVuelo();
                    gVuelos.mostrarVuelosPorMes(auxValor);

                    if (gVuelos.isVuelosEncontrados()) {
                        cout << "\n";
                        gReservas.reservar();
                    }
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
                            cout << "Opcion no valida\n"; system("pause");
                        }
                    } while ((auxOrigen < 1 || auxOrigen > 10) && (auxDestino < 1 || auxDestino > 10));

                    origen = paises[auxOrigen - 1];
                    destino = paises[auxDestino - 1];

                    // -- Mostrar Vuelos por Paises --
                    gVuelos.mostrarVuelosPorPaises(origen, destino);

                    if (gVuelos.isVuelosEncontrados()) {
                        cout << "\n"; 
                        gReservas.reservar(); 
                    }

                    system("pause"); break;
                case 4:
                    int auxDia, auxMes;
                    cout << "=====|  Vuelos en Fecha  |=====\n";
                    do {
                        cout << "\nDia de Ida: "; cin >> auxDia; cout << endl;
                        selecionMesVuelo();
                        cout << "\nMes de Ida: "; cin >> auxMes;

                        if (!validarDiaMes(auxDia,auxMes)) {
                            cout << "Opcion no valida\n"; system("pause");
                        }
                    } while ((auxDia < 1 || auxDia > 31) || (auxMes < 1 || auxMes > 12));

                    gVuelos.mostrarVuelosEnFecha(auxMes, auxDia);

                    if (gVuelos.isVuelosEncontrados()) {
                        cout << "\n";
                        gReservas.reservar();
                    }
                    system("pause"); break;
                case 5: //Busqueda especifica Origen - Destino - Fecha Ida
                    int auxOrigen2, auxDestino2, auxDiaIda, auxMesIda;
                    do {
                        system("cls"); tituloVuelo();
                        seleccionPais();
                        cout << "Origen: "; cin >> auxOrigen2;
                        cout << "Destino: "; cin >> auxDestino2;

                        if ((auxOrigen2 < 1 || auxOrigen2 > 10) && (auxDestino2 < 1 || auxDestino2 > 10)) {
                            cout << "Opcion no valida\n"; system("pause");
                        }
                    } while ((auxOrigen2 < 1 || auxOrigen2 > 10) && (auxDestino2 < 1 || auxDestino2 > 10));

                    origen = paises[auxOrigen2 - 1];
                    destino = paises[auxDestino2 - 1];

                    do {
                        cout << "\nDia de Ida: "; cin >> auxDiaIda; cout << endl;
                        selecionMesVuelo();
                        cout << "\nMes de Ida: "; cin >> auxMesIda;

                        if (!validarDiaMes(auxDia, auxMes)) {
                            cout << "Opcion no valida\n"; system("pause");
                        }
                    } while ((auxDiaIda < 1 || auxDiaIda > 31) || (auxMesIda < 1 || auxMesIda > 12));

                    gVuelos.mostrarVuelosDatosIda(origen, destino, auxMesIda, auxDiaIda);
                   
                    if (gVuelos.isVuelosEncontrados()) {
                        cout << "\n";
                        gReservas.reservar();
                    }
                    system("pause"); break;
                case 6:
                    system("pause"); break;
                default: cout << "Opción no válida\n"; system("pause"); break;

                }
            } while (auxVuelo != 6);
                break;
        case 3:
            int opc;
            do
            {
                system("cls"); menuCheckin(); cin >> opc;
                switch (opc)
                {
                case 1:
                    gReservas.mostrarReservas(); 
                    system("pause"); break;
                case 2:
                    gCheckIn.realizarCheckIn(gReservas); 
                    system("pause"); break;
                case 3: break;
                default:
                    cout << "Opción no válida\n"; system("pause"); break;
                }
            } while (opc != 3);
            break;

        case 4: cout << "Gracias por usar el sistema\n"; system("pause"); break;
        default: cout << "Opción inválida\n"; system("pause"); break;
        }

    } while (opcion != 4);

    system("pause>0"); 
    return 0;
}