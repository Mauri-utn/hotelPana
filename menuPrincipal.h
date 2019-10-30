#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

//#include "cliente.h"
//#include "habitaciones.h"

int menuPrincipal(int);
#include "misFunciones.h"
#include "menuClientes.h"
#include "menuHabitaciones.h"
#include "menuReservas.h"
#include "recepcion.h"
#include "productos.h"


int menuPrincipal(int permisos){



    if(permisos==1){
    char opcion;
    while(true){
        borrarPantalla();
        fechaHora();
        system("color 1F");
        cout << "\t\t---------PRINCIPAL---------" << endl;
        cout << "\t\t---------------------------" << endl;
        cout << "\t\t1) RESERVAS    --->" << endl;
        cout << "\t\t2) RECEPCIÓN   --->" << endl;
        cout << "\t\t3) CHECK OUT       " << endl;
        cout << "\t\t4) HABITACIONES    " << endl;
        cout << "\t\t5) CLIENTES    --->" << endl;
        cout << "\t\t6) PRODUCTOS   --->(tira error)" << endl;
        cout << "\t\t7) EMPLEADOS       " << endl;
        cout << "\t\t8) MANTENIMIENTO   " << endl;
        cout << "\t\t9) LIMPIEZA        " << endl;
        cout << "\t\t10)CONFIGURACION   " << endl;
        cout << "\t\t11)REPORTES        " << endl;
        cout << "\t\t0) SALIR/ATRÁS --->" << endl;
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
    menuRecepcion();

        break;
      case '3':
      case 'c':
      case 'C':

        break;
      case '4':
      case 'd':
      case 'D':
          menuHabitaciones();
        break;
      case '5':
      case 'e':
      case 'E':
          menuClientes();
        break;
      case '6':
      case 'f':
      case 'F':
          menuProductos();
        break;
      case '7':
      case 'g':
      case 'H':

        break;
        case '0':
      return 0;
        break;
        default:
            mensajes(2);
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
