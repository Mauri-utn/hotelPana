#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

//#include "cliente.h"
//#include "habitaciones.h"

int menuPrincipal(int);
#include "misFunciones.h"
#include "menuClientes.h"
#include "menuHabitaciones.h"
#include "menuReservas.h"


int menuPrincipal(int permisos){



    if(permisos==1){
    char opcion;
    while(true){
        borrarPantalla();
        fechaHora();
        cout << "\t\t---------PRINCIPAL---------" << endl;
        cout << "\t\t---------------------------" << endl;
        cout << "\t\t1) NUEVA RESERVA   " << endl;
        cout << "\t\t2) HABITACIONES    " << endl;
        cout << "\t\t3) CLIENTES        " << endl;
        cout << "\t\t4) EMPLEADOS       " << endl;
        cout << "\t\t5) MANTENIMIENTO   " << endl;
        cout << "\t\t6) LIMPIEZA        " << endl;
        cout << "\t\t7) CONFIGURACION   " << endl;
        cout << "\t\t0) Salir "<< endl;
        cout << endl << "Opción: ";
        cin >> opcion;
        borrarPantalla();
        switch(opcion){
      case '1':
      case 'a':
      case 'A':
    menuReservas();
        break;
      case '2':
      case 'b':
      case 'B':
          menuHabitaciones();

        break;
      case '3':
      case 'c':
      case 'C':
          menuClientes();
        break;
      case '4':
      case 'd':
      case 'D':
        break;
      case '5':
      case 'e':
      case 'E':
        break;
      case '6':
      case 'f':
      case 'F':
        break;
      case '7':
      case 'g':
      case 'H':
        break;
        case '0':
      return 0;
        break;
        default:
            break;
        }
        cout << endl;

      }
    }
    ///if(permisos==2)menuLimpieza();
    ///if(permisos==3)menuMantenimiento();
    return permisos;
}



#endif // MENUPRINCIPAL_H_INCLUDED
