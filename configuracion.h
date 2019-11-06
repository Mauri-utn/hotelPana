#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void realizarBackUp();
void restaurarBackUp();


int configuracion(){
    int n;
    while(true){
    system("cls");
    cout << "MENU CONFIGURACION" <<endl;
    cout << "--------------" <<endl;
    cout << "1) REALIZAR BACKUP" <<endl;
    cout << "2) RESTAURAR BACKUP" <<endl;
    cout << "--------------" <<endl;
    cout << "0) VOLVER AL MENU PRINCIPAL" <<endl;
    cout << "Ingrese opcion:" << endl;
    cin >> n;
    system ("cls");
    switch(n){
    case 0:
       return 0;
    break;
    case 1:
       realizarBackUp();
    break;
    case 2:
       restaurarBackUp();
    break;
        }
    }
}

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






#endif // CONFIGURACION_H_INCLUDED
