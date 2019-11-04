#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

#include "misfunciones.h"
#include "menuHabitaciones.h"
int menuConfiguracion();


void nuevaHabitacionTipo();
void consultarHabitaciones();
void crearHabitacion();

void nuevaHabitacionTipo(){

Tipo_habitacion reg;
reg.cargar();
if(reg.escribirEnDisco()){
cout << "Nuevo tipo de habitación cargada "<< endl;
pausa();
}

}

void consultarHabitaciones(){
Tipo_habitacion reg;
int pos=0;
while(reg.leerDeDisco(pos++)==1){
reg.mostrar();
}
pausa();

}



void crearHabitacion(){
Habitacion reg;
if(reg.cargar_habitacion()){
   cout << "Habitación creada con éxito" << endl;
   pausa();
   }
}
int menuConfiguracion(){
short opcion;
while(true){
    borrarPantalla();
    cout << "MENU CONFIGURACIÓN" << endl;
    cout << "------------------" << endl;
    cout << "\t\t1) CREAR NUEVA HABITACIÓN               "<< endl;
    cout << "\t\t2) CREAR NUEVA TIPO DE HABITACIÓN       " << endl; /// crea una nueva habitacion
    cout << "\t\t3) MOSTRAR TIPO DE HABITACIONES CREADAS (esto desp se va)" << endl; /// consulta habitaciones disponibles
    cout << "\t\t0) Salir "<< endl;
    cout << endl << "Opción: ";
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
  case 1:
      crearHabitacion();
    break;
  case 2:
      nuevaHabitacionTipo();
    break;
  case 3:
      consultarHabitaciones();
    break;
      case 0:
        return 0;
      break;
    }
    cout << endl;

  }

}



#endif // MENUCONFIGURACION_H_INCLUDED
