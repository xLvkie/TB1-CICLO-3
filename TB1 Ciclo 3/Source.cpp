#include"GestorSistema.h"

int main() {
    srand(time(NULL));
    portada(); getch();

    GestorSistema sistema; 
    sistema.ejecutar(); 

    system("pause>0"); 
    return 0;
}