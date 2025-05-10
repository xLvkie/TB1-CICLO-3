#include "Sistema.h"
#include "ListaDoble.h"
#include "GestorVuelo.h"

int main() {
    srand(time(NULL));

    Lista<Pasajero*> pLista;
    /*Lista<GestorVuelos*> gLista;*/

    GestorVuelo gVuelos;
    gVuelos.generarVuelosAutomaticos();

    //prueba para mostrar pasajeros wazaaa
    pLista.insertarInicio(new Pasajero("buki", "buki2", "hola@gmail.com", 75202855));
    pLista.insertarInicio(new Pasajero("buki2", "buki3", "hola2@gmail.com", 65202855));
    pLista.insertarInicio(new Pasajero("buki4", "buki5", "hola3@gmail.com", 55202855));

    int opcion;
    string destino, origen;
    Pasajero* nuevo;

    do {
        system("cls"); portada(); cin.get();

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
                    nuevo = pedirDatosPasajero();
                    pLista.insertarInicio(nuevo);
                    // -- Conclusión --
                    cout << "Pasajero registrado correctamente\n";
                    system("pause"); break;
                case 2:
                    // -- Mostrar Pasajeros ---
                    system("cls"); tituloUsuario();
                    pLista.mostrarPasajero();
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
                case 5: system("pause"); break;
                default: cout << "Opción no válida\n"; system("pause"); break;
                }
            } while (auxVuelo != 3);
            break;
        case 3: system("cls"); cout << "En trabajo\n"; system("pause"); break;
        case 4: cout << "Gracias por usar el sistema\n"; system("pause"); break;
        default: cout << "Opción inválida\n"; system("pause"); break;
        }

    } while (opcion != 5);

    return 0;
}