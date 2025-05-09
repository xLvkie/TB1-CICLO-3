#include "Sistema.h"
#include "ListaDoble.h"
#include "GestorVuelos.h"

int main() {
    portada();
    system("pause>0");

    srand(time(0));
    
    Lista<Pasajero*> pLista;
    
    GestorVuelos gestor;
    gestor.generarVuelosAutomaticos();

    //prueba para mostrar pasajeros wazaaa
    pLista.insertarInicio(new Pasajero("buki", "buki2", "hola@gmail.com", 75202855));
    pLista.insertarInicio(new Pasajero("buki2", "buki3", "hola2@gmail.com", 65202855));
    pLista.insertarInicio(new Pasajero("buki4", "buki5", "hola3@gmail.com", 55202855));
        
    int opcion;
    Pasajero* nuevo;
    string s1, s2;
    do {
        system("cls"); menuPrincipal();
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: 
            int auxUser;
            do {
                system("cls"); menuUsuario();
                cin >> auxUser;
                cin.ignore();

                switch (auxUser) {
                case 1: system("cls"); tituloUsuario();
                    // -- Registro de pasajero --
                    nuevo = pedirDatosPasajero();
                    pLista.insertarInicio(nuevo);
                    // -- Conclusión --
                    cout << "Pasajero registrado correctamente\n";
                    system("pause"); break;
                case 2: system("cls"); tituloUsuario();
                    // -- Mostrar Pasajeros ---
                    pLista.mostrar();
                    // -- Conclusión --
                    system("pause"); break;
                case 3: system("pause"); break;
                default: cout << "Opción no válida\n"; system("pause"); break;
                }
            } while (auxUser != 3);
            break;
        
        case 2: system("cls"); //verificando
            int auxVuelo, auxMes;
            do {
                system("cls"); menuVuelos(); 
                cin >> auxVuelo; 
                cin.ignore(); 

                switch (auxVuelo) {
                case 1: system("cls"); 
                    cout << "Lista de Todos los vuelos Disponibles\n";
                    gestor.mostrarTodosLosVuelos();
                    system("pause"); break; 
                case 2: system("cls"); 
                    cout << "Lista de Vuelos por Mes\n";
                    cout << "[1] Enero\t"; 
                    cout << "[2] Febrero\n"; 
                    cout << "[3] Marzo\t"; 
                    cout << "[4] Abril\n"; 
                    cout << "[5] Mayo\t"; 
                    cout << "[6] Junio\n"; 
                    cout << "[7] Julio\t"; 
                    cout << "[8] Agosto\n"; 
                    cout << "[9] Septiembre\t"; 
                    cout << "[10] Octubre\n"; 
                    cout << "[11] Noviembre\t"; 
                    cout << "[12] Diciembre\n"; 
                    cout << "Ingrese el mes que desea listar: "; cin >> auxMes; 
                    gestor.mostrarVuelosRecomendados(auxMes); 
                    system("pause"); break;
                case 3: 
                    cout << "Lista de Paises Disponibles\n";
                    cout << "Peru\t\t";
                    cout << "Chile\n";
                    cout << "Argentina\t";
                    cout << "Brasil\n";
                    cout << "Colombia\t";
                    cout << "Ecuador\n";
                    cout << "Mexico\t\t";
                    cout << "EE.UU\n";
                    cout << "Espania\t\t";
                    cout << "Italia\n";
                    cout << "Ingrese el pais de origen: "; cin >> s1;
                    cout << "Ingrese el pais de destino: "; cin >> s2;
                    gestor.buscarVueloPorPaises(s1,s2);
                    system("pause"); break;
                default: cout << "Opción no válida\n"; system("pause"); break;
                }
            } while (auxVuelo != 5);
            break;
            

            system("pause"); break;
        case 3: system("cls"); cout << "En trabajo\n"; system("pause"); break;
        case 4: cout << "Gracias por usar el sistema\n"; system("pause"); break;
        default: cout << "Opción inválida\n"; system("pause"); break;
        }

    } while (opcion != 5);

    return 0;
}
