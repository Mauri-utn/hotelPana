#ifndef MENULIMPIEZA_H_INCLUDED
#define MENULIMPIEZA_H_INCLUDED
#include "menuHabitaciones.h"
#include "menuPrincipal.h"


void cargarHabitacionLimpieza(void);
void mostrarHabitacionesEnLimpieza(void);
void buscarHabitacionEnLimpieza(void);

int menuLimpieza(){
    setlocale(LC_ALL,"spanish");
    int opcion;
    while(true){
    system("cls");
    cout << "ELIJA UNA CATEGORIA" <<endl;
    cout << "--------------" <<endl;
    cout << "1)Cargar Habitacion " <<endl;
    cout << "2)Mostrar Habitaciones en Limpieza " <<endl;
    cout << "3)Buscar Habitacion" <<endl;
    cout << "0)Volver " << endl;
    cout << "--------------" <<endl;
    cout << "Ingrese opcion:" << endl;
    cin >> opcion;
    system ("cls");
    switch(opcion){
    case 0:
       return -1;
    break;
    case 1:
        cargarHabitacionLimpieza();
    break;
    case 2:
        mostrarHabitacionesEnLimpieza();
    break;
    case 3:
        buscarHabitacionEnLimpieza();
    break;
        }
    }
}
int buscarHabitacion(char *habitacion){
    FILE *p;
    p = fopen("habitaciones.dat","rb");
    if(p==NULL){return -1;}
    Habitacion aux;
    int pos=0;
    while(fread(&aux,sizeof aux,1,p)==1){
        if(habitacion==aux.get_habitacion()){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}

void cargarHabitacionLimpieza(){
    Habitacion aux;
    int pos;
    char hab[4];
    cout << "Ingrese el numero de Habitacion" << endl;
    cin >> hab;
    pos = buscarHabitacion(hab); if(pos==-1){ cout << "no se encontro habitacion" << endl; pausa(); return ;}
    FILE *p; p = fopen("habitaciones.dat","rb+");
    if(p==NULL){ return ;}
    fseek(p,sizeof aux*pos,0);
    fread(&aux,sizeof aux,1,p);
    if(strcmpi(aux.get_limpiezaMantenimiento(),"En mantenimiento")==0){
        cout << "La habitacion se encuentra en Mantenimiento" << endl;
        pausa();
        fclose(p);
        return ;
    }
    aux.set_limpiezaMantenimiento("En limpieza");
    fwrite(&aux,sizeof aux,1,p);
    fclose(p);
}

void mostrarHabitacionesEnLimpieza(){
    FILE *p; p = fopen("habitaciones.dat","rb");
    if(p==NULL){ return ;}
    Habitacion aux;
    while(fread(&aux,sizeof aux,1,p)==1){
        if(strcmpi(aux.get_limpiezaMantenimiento(),"En Limpieza")){
            aux.mostrar_habitacion();
        }
    }
    fclose(p);
}
void buscarHabitacionEnLimpieza(){
    char hab[4];
    int pos;
    Habitacion aux;
    cout << "ingrese el numero de Habitacion" << endl;
    cin >> hab;
    pos = buscarHabitacion(hab); if(pos==-1){ cout << "no se encontro habitacion" << endl; pausa(); return ;}
    FILE *p; p = fopen("habitaciones.dat","rb+");
    if(p==NULL){ return ;}
    fseek(p,sizeof aux*pos,0);
    fread(p,sizeof aux,1,p);
    aux.mostrar_habitacion();
    fclose(p);
}




#endif // MENULIMPIEZA_H_INCLUDED
