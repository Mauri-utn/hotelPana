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
#include "CargarEmpleado.h"
#include "reportes.h"
#include "check_out.h"
#include "menuConfiguracion.h"
#include "menuLimpieza.h"


int menuPrincipal(int permisos){


    cout << "\t\tvalor de permisos"<< permisos<<  endl;
    pausa();


    if(permisos==1){
    char opcion;
    while(true){
        borrarPantalla();
        fecha();
        cout << endl;
        hora();
        system("color 1F");
        cout << "\t\t---------PRINCIPAL---------" << endl;
        cout << "\t\t---------------------------" << endl;
        cout << "\t\t1) RESERVAS    --->" << endl;
        cout << "\t\t2) RECEPCIÓN   --->" << endl;
        cout << "\t\t3) CHECK OUT       " << endl;
        cout << "\t\t4) HABITACIONES--->" << endl;
        cout << "\t\t5) CLIENTES    --->" << endl;
        cout << "\t\t6) PRODUCTOS   --->" << endl;
        cout << "\t\t7) EMPLEADOS   --->" << endl;
        cout << "\t\t8) MANTENIMIENTO   " << endl;
        cout << "\t\t9) LIMPIEZA        " << endl;
        cout << "\t\tJ)CONFIGURACION    " << endl;
        cout << "\t\tK)REPORTES     --->" << endl;
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
    realizarCheckOut();
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
      case 'G':
            MenuEmpleados();
        break;
      case '8':
      case 'h':
      case 'H':
        sectorMantenimiento();
        break;
      case '9':
      case 'i':
      case 'I':
       menuLimpieza();
        break;

      case 'j':
      case 'J':
        menuConfiguracion();
        break;

      case 'k':
      case 'K':
                      menuReportes();
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
///    if(permisos==2)menuLimpieza();
    if(permisos==3)menuProductos();
    return permisos;
}



#endif // MENUPRINCIPAL_H_INCLUDED


