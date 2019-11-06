#ifndef MENUMANTENIMIENTO_H_INCLUDED
#define MENUMANTENIMIENTO_H_INCLUDED

void cargarHabitacionMantenimiento(void);
void mostrarHabitacionesEnMantenimiento(void);
void buscarHabitacionEnMantenimiento(void);

int menuMantenimiento(){
    setlocale(LC_ALL,"spanish");
    int opcion;
    while(true){
    system("cls");
    cout << "ELIJA UNA CATEGORIA" <<endl;
    cout << "--------------" <<endl;
    cout << "1)Cargar Habitacion " <<endl;
    cout << "2)Mostrar Habitaciones en Mantenimiento" <<endl;
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
        cargarHabitacionMantenimiento();
    break;
    case 2:
        mostrarHabitacionesEnMantenimiento();
    break;
    case 3:
        buscarHabitacionEnMantenimiento();
    break;
        }
    }
}

void cargarHabitacionMantenimiento(){
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
    if(strcmpi(aux.get_limpiezaMantenimiento(),"En limpieza")==0){
        cout << "La habitacion se encuentra en Limpieza" << endl;
        pausa();
        fclose(p);
        return ;
    }
    aux.set_limpiezaMantenimiento("En mantenimiento");
    fwrite(&aux,sizeof aux,1,p);
    fclose(p);
}

void mostrarHabitacionesEnMantenimiento(){
    FILE *p; p = fopen("habitaciones.dat","rb");
    if(p==NULL){ return ;}
    Habitacion aux;
    while(fread(&aux,sizeof aux,1,p)==1){
        if(strcmpi(aux.get_limpiezaMantenimiento(),"En mantenimiento")){
            aux.mostrar_habitacion();
        }
    }
    fclose(p);
}
void buscarHabitacionEnMantenimiento(){
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




#endif // MENUMANTENIMIENTO_H_INCLUDED
