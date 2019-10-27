#ifndef MENURESERVAS_H_INCLUDED
#define MENURESERVAS_H_INCLUDED

int menuReservas();
#include "misFunciones.h"


int menuReservas(){
char opcion;
while(true){
    borrarPantalla();
    cout << "# # # # # # # # # # #"      << endl;
    cout << "# # MENU RESERVAS # #"      << endl;
    cout << "# # # # # # # # # # #"      << endl;
    cout << "1)NUEVA RESERVA      "      << endl;
    cout << "2)VER RESERVAS       "      << endl;/// del dia , de una fecha , todas ---> todas = ordenadas de varias maneras
    cout << "3)CANCELAR RESERVA   "      << endl;
    cout << "0)VOLVER AL MENU PRINCIPAL "<< endl;
    cout << "ESC)SALIR DEL PROGRAMA     "<< endl;
    cout << endl << "Opción: ";
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case 1:

      break;
      case 2:
        ;
      break;
      case 3:
        ;
        ;
      break;
      case 4:
        ;
      break;
      case 5:
        ;
      break;
      case 0:
        return 0;
      break;
    }
    cout << endl;

  }






}


#endif // MENURESERVAS_H_INCLUDED
