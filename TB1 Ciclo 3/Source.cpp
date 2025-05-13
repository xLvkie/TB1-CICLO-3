#include"GestorSistema.h"

int main() {
    srand(time(nullptr)); 
    setlocale(LC_ALL, "");
    portada(); cin.get();
    
    GestorSistema sistema;
    sistema.ejecutar(); 

    system("pause>0"); 
    return 0;
}