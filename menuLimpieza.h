#ifndef MENULIMPIEZA_H_INCLUDED
#define MENULIMPIEZA_H_INCLUDED
#include "menuHabitaciones.h"
#include "menuPrincipal.h"
#include "misFunciones.h"


void cargarHabitacionLimpieza(void);
void mostrarHabitacionesEnLimpieza(void);
void buscarHabitacionEnLimpieza(void);
void sacarDeLimpieza();



/// la comente por que tenia una ya creada y es igual jaja
/*int buscarHabitacion(char *habitacion){
    FILE *p;
    p = fopen(FILE_HABITACIONES,"rb");
    if(p==NULL){return -1;}
    Habitacion aux;
    int pos=0;
    while(fread(&aux,sizeof aux,1,p)==1){
        if(strcmp(habitacion,aux.get_habitacion())==0){
            fclose(p);
            return pos;
        }
        pos++;
    }
    fclose(p);
    return -1;
}*/


void cargarHabitacionLimpieza(){ /// carga una habitacion para limpieza manualmente ///
    Habitacion aux;
    int pos;
    char hab[4];
    cout << "Ingrese el numero de Habitacion" << endl;
    limpiarBuffer();
    cin.getline(hab,4);
    pos = buscarHabitacion(hab); if(pos==-1){ cout << "no se encontro habitacion" << endl; pausa(); return ;}
    FILE *p; p = fopen(FILE_HABITACIONES,"rb+");
    if(p==NULL){ return ;}
    fseek(p,sizeof aux*pos,0);
    fread(&aux,sizeof aux,1,p);
    /*if(strcmpi(aux.get_limpiezaMantenimiento(),"En mantenimiento")==0){
        cout << "La habitacion se encuentra en Mantenimiento" << endl;
        pausa();
        fclose(p);
        return ;
    }*/ /// VERIFICA SI LA HABITACION ESTA EN MANTENIMIENTO /// PARA USARLO ANTES INGRESAR HABITACIONES EN MANTENIMIENTO
    aux.setLimpio(false);
    fwrite(&aux,sizeof aux,1,p);
    cout << "Habitación "<< aux.getNumero();cout << " en limpieza"<< endl;
    pausa();
    fclose(p);

}

void mostrarHabitacionesEnLimpieza(){ /// muestra las habitaciones en limpieza actualmente ///
    FILE *p; p = fopen("habitaciones.dat","rb");
    if(p==NULL){ return ;}
    Habitacion aux;
    while(fread(&aux,sizeof aux,1,p)==1){
        if(aux.getLimpio()==false){
            aux.mostrar();
            pausa();
        }
    }
    fclose(p);
}


void buscarHabitacionEnLimpieza(){ /// busca una habitacion , si esta en limpieza la muestra /// sino dice que esta limpia
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
    if(aux.limpio==false){
    aux.mostrar();
    pausa();
    }
    else {
        cout << "La habitación ";cout << aux.getNumero(); cout << " se encuentra limpia "<< endl;
        pausa();
    }
    fclose(p);
}

void sacarDeLimpieza(){
char hab[4];
Habitacion aux;
cout << "Ingrese habitación: ";
limpiarBuffer();
cin.getline(hab,4);
int pos=buscarHabitacion(hab);
if(pos==-1){

    cout << "No se encontro habitación"<< endl;
    pausa();
}
else {
    aux.leerDeDisco(pos);
    aux.setLimpio(true);
    if(aux.modificarEnDisco(pos)){

        cout << "Habitación ";aux.getNumero();cout << " ya se encuentra limpia "<< endl;
        pausa();
    }
}

}


int menuLimpieza(){
    setlocale(LC_ALL,"spanish");
    int opcion;
    while(true){
    system("cls");
    cout << "ELIJA UNA CATEGORIA" <<endl;
    cout << "--------------" <<endl;
    cout << "1)Cargar habitacion para limpieza  " <<endl;
    cout << "2)Sacar habitación de limpieza     " << endl;
    cout << "3)Mostrar habitaciones en limpieza " <<endl;
    cout << "4)Buscar Habitacion                " <<endl;
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
    sacarDeLimpieza();
    break;
    case 3:
        mostrarHabitacionesEnLimpieza();
    break;
    case 4:
        buscarHabitacionEnLimpieza();
        break;
    default:

        break;

        }
    }
}




#endif // MENULIMPIEZA_H_INCLUDED
