#ifndef RECEPCION_H_INCLUDED
#define RECEPCION_H_INCLUDED

int menuRecepcion();
#include "misFunciones.h"
#include "menuClientes.h"


int menuRecepcion(){
    int ide;
    Reserva aux;
    Cliente reg;
cout << "Recepcionar cliente"<< endl;
cout << "Ingrese id de reserva: ";
cin  >> ide;
int pos=buscarReservaId(ide);
aux.leerDeDisco(pos);
aux.mostrar();
pausa();
if(pos==-1){
    cout << "La reserva no se encuntra registrada o fue dada de baja"<< endl;
    pausa();
    return -1;
}
cout << "antes de seguir debe cargar el cliente en el sistema..." <<endl;
nuevoCliente();
char cuarto=aux.getTipo();
cout << "asignar haitacion  " << endl;
pausa();
switch (cuarto){

case '1':
    cout << "habitaciones disponibles estandar"<< endl;
    pausa();
    break;
case '2':
    cout << "habitaciones disponibles suite"<< endl;
    pausa();
    break;
case '3':
    cout << "habitaciones disponibles master suite"<< endl;
    pausa();
    break;
case '4':
    cout << "habitaciones disponibles presidencial"<< endl;
    pausa();
    break;
}


}



#endif // RECEPCION_H_INCLUDED
