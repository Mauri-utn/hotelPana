#ifndef MENURESERVAS_H_INCLUDED
#define MENURESERVAS_H_INCLUDED

int menuReservas();
int asignarCodigo();
void nuevaReserva();
void mostrarReservas();

#include "misFunciones.h"
const char *FILE_RESERVAS     = "reservas.dat";

class Reserva{


    private:
    int idReserva;/// numero de reserva , sirve como referencia para el cliente y para nosotros para buscar la reserva en el sistema
    char identidad[10];
    char apellidos[50];
    char nombres[50];
    char tipoHabitacion;
    Fecha entrada,salida;
    float pagado;
    bool estado;

    public:
    void cargar();
    void mostrar();
    ///GETS
    int getIdReserva(){return idReserva;}
    char* getIdentidad(){return identidad;}
    char* getNombre(){return nombres;}
    char* getApellido(){return apellidos;}
    char getTipo(){return tipoHabitacion;}
    float getPagado(){return pagado;}
    bool getEstado(){return estado;}
    ///SETS
    void setIdentidad(char*);
    void setTipo(char*);

    void setNombre(char*);
    void serApellido(char*);
    void setHabitacion(char);
    void setPagado(float);
    void setEstado(bool);
    ///
    bool escribirEnDisco();

};


void Reserva::setEstado(bool variable){
estado=variable;
}
bool Reserva::escribirEnDisco(){
FILE*P;
P=fopen(FILE_RESERVAS,"ab");
if(P==NULL)return false;
fwrite(this,sizeof(*this),1,P);
return true;
fclose(P);
}

int contarRegistrosReservas(){
    FILE *F;
    F=fopen(FILE_RESERVAS,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(F);
    tamanioreg=sizeof(Reserva);
    cantidad=tam/tamanioreg;
    fclose(F);
    return cantidad;

}

int asignarCodigo(){
FILE*P;
P=fopen(FILE_RESERVAS,"rb");
if(P==NULL){
    mensajes(1);
    pausa();
    return -1;
}
if(contarRegistrosReservas()==0)return 1;
int siguiente=contarRegistrosReservas();
return siguiente+1;
}

void Reserva::cargar(){

idReserva=asignarCodigo();
cout << "Codigo de reservación: "<< idReserva << endl;
cout << "---Cargar Cliente--- "<< endl;
cout << "DNI: ";
fflush(stdin);
cin.getline(identidad,10);
    while(strlen(identidad)==0){
    borrarPantalla();
    mensajes(3);
    pausa();
    borrarPantalla();
    cout << "DNI: ";
    cin.ignore();
    cin.getline(identidad,10);
    }
    cout << "Nombre/s: ";
    cin.getline(nombres,50);
    cout << "Apellido/s: ";
    cin.getline(apellidos,50);

cout << "---Habitación---   "<< endl;
cout << "1-estandar          "<< endl;
cout << "2-suite             "<< endl;
cout << "3-master suite      "<< endl;
cout << "4-precidencial      "<< endl;
cout << "selec: ";
cin  >> tipoHabitacion;
cout << "---Seleccione fecha de reserva---"<<endl;
cout << "Desde: "<<endl;
entrada.cargar();
cout << "Hasta: "<<endl;
salida.cargar();
cout << "Pago parcial/Adelanto: ";
cin  >> pagado;
estado=true;

}

void Reserva::mostrar(){

cout << "ID Reserva :  "<< idReserva <<endl;
cout << "Dni cliente:  "<< identidad << endl;
cout << "Nombre:       "<< nombres   << endl;
cout << "Apellidos:    "<< apellidos << endl;
char tipo[20];
switch(tipoHabitacion){
case '1':
strcpy(tipo,"Estandar");
break;
case '2':
    strcpy(tipo,"Suite");
    break;
case '3':
    strcpy(tipo,"Master Suite");
    break;
case '4':
    strcpy(tipo,"Presidencial");
    break;
}
cout << "Habitación:   "<< tipo << endl;
cout << "Fecha de entrada: "; entrada.mostrarConBarra();
cout << "Fecha de salida:  "; salida.mostrarConBarra();
/// falta validar ambas fechas
cout << "Pago: "<< pagado <<endl;
/// falta agregar el pago a gastos de la estadia ---> restar del total
pausa();


}


void nuevaReserva(){

Reserva reg;
reg.cargar();
if(reg.escribirEnDisco()){
    cout << "Reserva cargada con éxito"<<endl;
    pausa();
}
/*Cliente aux;
aux.setDni(reg.getIdentidad());
aux.setNombre(reg.getNombre());
aux.setApellido(reg.getApellido());
aux.setGenero('-');
aux.setNacionalidad("-");
aux.setDiaNac(1);
aux.setMesNac(1);
aux.setAnioNac(2000);
aux.setMail("-");
aux.setTelefono("-");
aux.setCalle("-");
aux.setNum(0);
aux.setCp(0);
aux.setLocalidad("-");
aux.setP(0);
aux.setNroTarjeta("-");
aux.setCodigoSeguridad("-");
aux.setMesVenc(1);
aux.setAnioVenc(2000);
aux.escribirDisco();
*/
}

void mostrarReservas(){
FILE*P;
P=fopen(FILE_RESERVAS,"rb");
if(P==NULL){
    mensajes(1);
    pausa;
    return;
}
Reserva aux;
while(fread(&aux,sizeof(Reserva),1,P)==1){

    if(aux.getEstado()==true){
    aux.mostrar();
    pausa();
    }

}
fclose(P);
return;
}

int menuReservas(){
char op;
while(true){
    borrarPantalla();
    cout << "\t\t                           "<< endl;
    cout << "\t\t    MENU RESERVAS          "<< endl;
    cout << "\t\t    -------------          "<< endl;
    cout << "\t\t1)NUEVA RESERVA            "<< endl;
    cout << "\t\t2)VER CALENDARIO RESERVAS  "<< endl;/// del dia , de una fecha , todas ---> todas = ordenadas de varias maneras
    cout << "\t\t3)CANCELAR RESERVA         "<< endl;/// por id , dni , o fecha de entrada
    cout << "\t\t0)VOLVER AL MENU PRINCIPAL "<< endl;
    cout << endl << "Opción: ";
    cin >> op;
    borrarPantalla();
    switch(op){
      case '1':
      case 'a':
      case 'A':
          nuevaReserva();
        break;
      case '2':
      case 'b':
      case 'B':

        mostrarReservas();
        break;
      case '3':
      case 'c':
      case 'C':

        break;
      case '0':
                    return 0;
        break;
      default:
                mensajes(2);
                pausa();

        break;


  }

 cout << endl;




}

}





}


#endif // MENURESERVAS_H_INCLUDED
