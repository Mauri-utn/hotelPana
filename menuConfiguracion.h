#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

#include "misfunciones.h"
#include "menuHabitaciones.h"
int menuConfiguracion();


void nuevaHabitacionTipo();
void consultarHabitaciones();
void crearHabitacion();

void realizarBackUp();
void restaurarBackUp();


/// HABITACIONES ///
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
reg.cargar();

if(reg.escribirEnDisco()){
   cout << "Habitación creada con éxito" << endl;
   pausa();
   }
}

/// FIN HABITACIONES ///
/// BACK UPS ///


//void backUpConsumos(){
//    FILE *p;
//    p = fopen("consumos.dat","rb");
//    FILE *b;
//    b = fopen("consumos.bkp","wb");
//    if(p == NULL){
//        cout << "ERROR: no se encontro el archivo " << endl;
//        return ;
//    }
//    if(b == NULL){
//        cout << "ERROR: no se encontro el archivo " << endl;
//        return ;
//    }
//    Consumo reg;
//    while(fread(&reg,sizeof reg,1,p)==1){
//        fwrite(&reg,sizeof reg,1,b);
//    }
//    fclose(p);
//    fclose(b);
//    cout << "BackUp de Consumos realizado con exito" << endl;
//    cout << endl;
//    system("pause");
//}

void backUpHabitaciones(){
    FILE *p;
    p = fopen("habitaciones.dat","rb");
    FILE *b;
    b = fopen("habitaciones.bkp","wb");
    if(p == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    Habitacion reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "BackUp de Habitaciones realizado con exito" << endl;
    cout << endl;
    system("pause");
}

void backUpGastos(){
    FILE *p;
    p = fopen("gastos.dat","rb");
    FILE *b;
    b = fopen("gastos.bkp","wb");
    if(p == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    Gasto reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "BackUp de Gastos realizado con exito" << endl;
    cout << endl;
    system("pause");
}

void backUpEmpleados(){
    FILE *p;
    p = fopen("empleados.dat","rb");
    FILE *b;
    b = fopen("empleados.bkp","wb");
    if(p == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    Empleados reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "BackUp de Empleados realizado con exito" << endl;
    cout << endl;
    system("pause");
}

//void restaurarBackUpConsumos(){
//    FILE *p;
//    p = fopen("consumos.bkp","rb");
//    FILE *b;
//    b = fopen("consumos.dat","wb");
//    if(p == NULL){
//        cout << "ERROR: no se encontro el archivo " << endl;
//        return ;
//    }
//    if(b == NULL){
//        cout << "ERROR: no se encontro el archivo " << endl;
//        return ;
//    }
//    Consumo reg;
//    while(fread(&reg,sizeof reg,1,p)==1){
//        fwrite(&reg,sizeof reg,1,b);
//    }
//    fclose(p);
//    fclose(b);
//    cout << "Restauracion de Consumos realizado con exito" << endl;
//    cout << endl;
//    system("pause");
//}

void restaurarBackUpHabitaciones(){
    FILE *p;
    p = fopen("habitaciones.bkp","rb");
    FILE *b;
    b = fopen("habitaciones.dat","wb");
    if(p == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    Habitacion reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "Restauracion de Habitaciones realizado con exito" << endl;
    cout << endl;
    system("pause");
}

void restaurarBackUpGastos(){
    FILE *p;
    p = fopen("gastos.bkp","rb");
    FILE *b;
    b = fopen("gastos.dat","wb");
    if(p == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    Gasto reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "restauracion de Gastos realizado con exito" << endl;
    cout << endl;
    system("pause");
}

void restaurarBackUpEmpleados(){
    FILE *p;
    p = fopen("empleados.bkp","rb");
    FILE *b;
    b = fopen("empleados.dat","wb");
    if(p == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    if(b == NULL){
        cout << "ERROR: no se encontro el archivo " << endl;
        return ;
    }
    Empleados reg;
    while(fread(&reg,sizeof reg,1,p)==1){
        fwrite(&reg,sizeof reg,1,b);
    }
    fclose(p);
    fclose(b);
    cout << "restauracion de Empleados realizado con exito" << endl;
    cout << endl;
    system("pause");
}


void realizarBackUp(){
///    backUpConsumos();
    backUpHabitaciones();
    backUpGastos();
    backUpEmpleados();
}
void restaurarBackUp(){
///    RestaurarBackUpConsumos();
    restaurarBackUpHabitaciones();
    restaurarBackUpGastos();
    restaurarBackUpEmpleados();
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
    cout << "\t\t4) REALIZAR BACKUP" <<endl;
    cout << "\t\t5) RESTAURAR BACKUP" <<endl;
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
