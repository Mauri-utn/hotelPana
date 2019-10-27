#ifndef MISFUNCIONES_H_INCLUDED
#define MISFUNCIONES_H_INCLUDED
void ponerVecEnCero(int*,int);
void ponerMatEnCero(float [20][3]);
void borrarPantalla();
void pausa();
void fechaHora();
bool cadenaVacia(char*);

void borrarPantalla()
{
#ifdef __unix__
    system("clear");
#elif defined(_WIN32) || defined(WIN32)
    system("cls");
#endif
}

void pausa()
{
#ifdef __unix__
    cin.get();
    cin.get();
#elif defined(_WIN32) || defined(WIN32)
    system("pause >nul");
#endif

}
void ponerVecEnCero(int*v,int tam){
int i;
for(i=0;i<tam;i++){
    v[i]=0;
}

};

void ponerMatEnCero(float mat[20][3]){

    int i,x;
    for(i=0;i<20;i++){
        for (x=0;x<3;x++){
                mat[i][x]=0;
            }

}

}

void fechaHora(){


    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    ///FECHA ACTUAL tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year
    cout << tmPtr->tm_mday <<"/"<<tmPtr->tm_mon+1<<"/"<<1900+tmPtr->tm_year<<endl;
    cout << tmPtr->tm_hour<<":"<<tmPtr->tm_min<<":"<<tmPtr->tm_sec<<endl;

}


void mensajes(int opcion){

switch(opcion){
case 1:
    cout << "ERROR AL ABRIR ARCHIVO"<< endl;
    break;
case 2:
    cout << "OPCIÓN INVALIDA"<< endl;
    break;
case 3:
    cout << "EL CAMPO NO PUEDE ESTAR VACÍO"<< endl;

}

}

bool cadenaVacia(char * cadena){

if (strlen(cadena)==0)return false;

}


#endif // MISFUNCIONES_H_INCLUDED
