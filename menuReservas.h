#ifndef MENURESERVAS_H_INCLUDED
#define MENURESERVAS_H_INCLUDED

int menuReservas();
int asignarCodigo();
void nuevaReserva();
void mostrarReservas();
void cancelarReservaId();
void cancelarReservaDni();
int buscarReserva(char*);
int buscarReservaId(int);
bool consultarDisponibilidad(Fecha,Fecha,char);
int contarHabitacionesOcupadas(Fecha,Fecha,char);
const char* nombreTipoHabitacion(char);
void mostrarTipo(char);

void listaDeTipos();




#include "misFunciones.h"
#include "menuHabitaciones.h"
#include "menuClientes.h"

const char *FILE_RESERVAS  = "reservas.dat";

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
    ///  gets entrada
    int getDiaEntrada(){return entrada.getDia();}
    int getMesEntrada(){return entrada.getMes();}
    int getAnioEntrada(){return entrada.getAnio();}
    /// gets salida
    int getDiaSalida(){return salida.getDia();}
    int getMesSalida(){return salida.getMes();}
    int getAnioSalida(){return salida.getAnio();}
    /// get entrada/salida
    Fecha getFechaEntrada(){return entrada;}
    Fecha getFechaSalida(){return salida;}

    ///SETS
    void setIdentidad(char*);
    void setTipo(char*);

    void setNombre(char*);
    void serApellido(char*);
    void setHabitacion(char);
    void setPagado(float);
    void setEstado(bool);
    ///  sets entrada
    void setDiaEntrada(int nDia){entrada.setDia(nDia);}
    void setMesEntrada(int nMes){entrada.setMes(nMes);}
    void ssetAnioEntrada(int nAnio){entrada.setAnio(nAnio);}
    /// sets salida
    void setDiaSalida(int nDia){salida.setDia(nDia);}
    void setMesSalida(int nMes){salida.setMes(nMes);}
    void ssetAnioSalida(int nAnio){salida.setAnio(nAnio);}
    /// FUNCIONES CON ARCHIVOS
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);
    /// OPERADORES SOBRECARGADOS



};

bool comprobarFecha1(Reserva,Fecha,Fecha); /// comprueba si dentro de la fecha ingresada ya hay una reserva hecha
bool comprobarFecha2(Reserva,Fecha,Fecha); /// comprueba si se quiere reservar dentro de una fecha de reserva ya registrada
bool comprobarFecha3(Reserva,Fecha,Fecha); /// comprueba si la salida de la reserva que se quiere hacer esta dentro de una reserva ya hecha
bool comprobarFecha4(Reserva,Fecha,Fecha); /// comprueba si la entrada de la reserva que se quiere hacer esta dentro de una reserva ya hecha
///bool comprobarFecha5(Reserva,Fecha,Fecha);

int Reserva::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_RESERVAS,"rb");
	if(p==NULL)
		{
		mensajes(1);
		cout<<"Presione una tecla para continuar";
    system("pause<null");
		return 0;
		}
	fseek(p,pos*sizeof *this,0);
	x=fread(this,sizeof *this,1,p);
	fclose(p);
	return x;
}



bool Reserva::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_RESERVAS,"rb+");
	if(p==NULL){
        mensajes(1);
        pausa();
        return false;
	}
	fseek(p,pos*sizeof *this,0);
	fwrite(this,sizeof *this,1,p);
	fclose(p);
	return true;
}






bool Reserva::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_RESERVAS,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

bool Fecha::operator==(Fecha aux){
 if(dia!=aux.dia)return false;
 if(mes!=aux.mes)return false;
 if(anio!=aux.anio)return false;
 return true;
 }


void Reserva::setEstado(bool variable){ /// modifica el estado de una reserva
estado=variable;
}

int contarRegistrosReservas(){ /// cuenta los registro que hay en las reservas
    FILE *F;
    F=fopen(FILE_RESERVAS,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        fclose(F);
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

int asignarCodigo(){ /// asigna un codigo para cada nueva reserva
FILE*P;
P=fopen(FILE_RESERVAS,"rb");
if(P==NULL){
    mensajes(1);
    pausa();
    fclose(P);
    return -1;
}

if(contarRegistrosReservas()==0){
    fclose(P);
    return 1;
}
int siguiente=contarRegistrosReservas();
fclose(P);
return siguiente+1;
}

int buscarReserva(char *doc){ ///devuelve la posicion de la reserva en el archivo
	int pos=0;
	Reserva reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(strcmp(doc,reg.getIdentidad())==0 && reg.getEstado()==true)
			return pos;
		pos++;
		}
	return -1;
}

int buscarReservaId(int iden){ ///devuelve la posicion de la reserva en el archivo
	int pos=0;
	Reserva reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(iden==reg.getIdReserva()&& reg.getEstado()==true)
			return pos;
		pos++;
		}
	return -1;
}


/// comprueba si dentro de la fecha ingresada ya hay una reserva hecha ///
bool comprobarFecha1(Reserva aux,Fecha entrada,Fecha salida){

int valid=0;
if (entrada.getAnio()<=aux.getAnioEntrada()){
        valid++;
    if(entrada.getMes()<=aux.getMesEntrada()){
        valid++;
        if(entrada.getDia()<=aux.getDiaEntrada()){
            valid++;
        }
    }
}

if (salida.getAnio()>=aux.getAnioSalida()){
        valid++;
    if(salida.getMes()>=aux.getMesSalida()){
        valid++;
        if(salida.getDia()>=aux.getDiaSalida()){
            valid++;
        }
    }
}
if(valid==6)return false;
else return true;


}


/// comprueba si se quiere reservar dentro de una fecha de reserva ya registrada ///
bool comprobarFecha2(Reserva aux,Fecha entrada,Fecha salida){

int valid=0;
if (aux.getAnioEntrada()<=entrada.getAnio()){
        valid++;
    if(aux.getMesEntrada()<=entrada.getMes()){
        valid++;
        if(aux.getDiaEntrada()<=entrada.getDia()){
            valid++;
        }
    }
}

if (aux.getAnioSalida()>=salida.getAnio()){
        valid++;
    if(aux.getMesSalida()>=salida.getMes()){
        valid++;
        if(aux.getDiaSalida()>=salida.getDia()){
            valid++;
        }
    }
}
if(valid==6)return false;
else return true;


}


/// comprueba si la salida de la reserva que se quiere hacer esta dentro de una reserva ya hecha ///
bool comprobarFecha3(Reserva aux,Fecha entrada,Fecha salida){

int valid=0;
if (entrada.getAnio()<=aux.getAnioEntrada()){
        valid++;
    if(entrada.getMes()<=aux.getMesEntrada()){
        valid++;
        if(entrada.getDia()<=aux.getDiaEntrada()){
            valid++;
        }
    }
}

if ((salida.getAnio()<=aux.getAnioSalida())&&(salida.getAnio()>=aux.getAnioSalida())){
        valid++;
    if(salida.getMes()<=aux.getMesSalida()&&(salida.getMes()>=aux.getMesSalida())){
        valid++;
        if(salida.getDia()<=aux.getDiaSalida()&&(salida.getDia()>=aux.getDiaSalida())){
            valid++;
        }
    }
}
if(valid==6)return false;
else return true;


}

/// comprueba si la entrada de la reserva que se quiere hacer esta dentro de una reserva ya hecha ///

bool comprobarFecha4(Reserva aux,Fecha entrada,Fecha salida){

int valid=0;
if (entrada.getAnio()>=aux.getAnioEntrada()&&entrada.getAnio()<=aux.getAnioEntrada()){
        valid++;
    if(entrada.getMes()>=aux.getMesEntrada()&&(entrada.getMes()<=aux.getMesEntrada())){
        valid++;
        if(entrada.getDia()>=aux.getDiaEntrada()&&entrada.getDia()<=aux.getDiaEntrada()){
            valid++;
        }
    }
}

if (salida.getAnio()>=aux.getAnioSalida()){
        valid++;
    if(salida.getMes()>=aux.getMesSalida()){
        valid++;
        if(salida.getDia()>=aux.getDiaSalida()){
            valid++;
        }
    }
}
if(valid==6)return false;
else return true;


}


/*bool comprobarFecha5(Reserva aux,Fecha entrada,Fecha salida){

int valid=0;
if (entrada.getAnio()==aux.getAnioEntrada()){
        valid++;
    if(entrada.getMes()==aux.getMesEntrada()){
        valid++;
        if(entrada.getDia()==aux.getDiaEntrada()){
            valid++;
        }
    }
}

if (salida.getAnio()==aux.getAnioSalida()){
        valid++;
    if(salida.getMes()==aux.getMesSalida()){
        valid++;
        if(salida.getDia()==aux.getDiaSalida()){
            valid++;
        }
    }
}
if(valid==6)return false;
else return true;


}*/






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

cout << "---Habitación---    "<< endl;
listaDeTipos();
cout << "selec: ";
cin  >> tipoHabitacion;
cout << "---Seleccione fecha de reserva---"<<endl;
cout << "Desde: "<<endl;
entrada.cargar();
cout << "Hasta: "<<endl;
salida.cargar();
while(consultarDisponibilidad(entrada,salida,tipoHabitacion)==false){
    borrarPantalla();
    cout << "Sin disponibilidad para ese rango de fecha"<< endl;
    pausa();
    borrarPantalla();
    cout << "---Habitación---    "<< endl;
    listaDeTipos();
    cout << "selec: ";
    cin  >> tipoHabitacion;
    cout << "---Seleccione fecha de reserva---"<<endl;
    cout << "Desde: "<<endl;
    entrada.cargar();
    cout << "Hasta: "<<endl;
    salida.cargar();
    /// ponerle una funcion para salir ///

}

cout << "Pago parcial/Adelanto:$ ";
cin  >> pagado;
estado=true;

}




void Reserva::mostrar(){

cout << "ID Reserva :  "<< idReserva <<endl;
cout << "Dni cliente:  "<< identidad << endl;
cout << "Nombre:       "<< nombres   << endl;
cout << "Apellidos:    "<< apellidos << endl;
/*char nombre[30];
strcpy(nombre,nombreTipoHabitacion(tipoHabitacion));
cout << "Habitación: "<< nombre << endl;*/
mostrarTipo(tipoHabitacion);
cout << "Fecha de entrada: "; entrada.mostrarConBarra();
cout << "Fecha de salida:  "; salida.mostrarConBarra();
/// falta validar ambas fechas
cout << "Pago: $"<< pagado <<endl;
/// falta agregar el pago a gastos de la estadia ---> restar del total



}


void nuevaReserva(){

Reserva reg;
reg.cargar();
if(reg.escribirEnDisco()){
    cout << "Reserva cargada con éxito"<<endl;
    pausa();
}
/// LA RESERVA FUE HECHA
/// ACA SE DEBERIA RESERVAR LA HABITACION TIPO X ---> reg.getTipo()
/// EN EL INTERVALO FECHA ENTRADA / FECHA SALIDA --->
/// gets entrada salida, linea 41 a 48

}


void mostrarReservas(){
FILE*P;
P=fopen(FILE_RESERVAS,"rb");
if(P==NULL){
    mensajes(1);
    pausa;
    fclose(P);
    return;
}
if(contarRegistrosReservas()==0){

    char letra;
    cout << "Para visualizar reservas debe cargar una primero"<<endl;
    cout << "Desea cargar una reserva ahora?(s/n)";
    cin  >> letra;
    if (letra=='s'||letra=='S'){
            nuevaReserva();
            return;
    }
    else return;

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
void cancelarReservaDni(){
	char cod[10];
	int pos;
	Reserva reg;
	borrarPantalla();
	cout<<"Ingrese el dni del cliente para cancelar reserva: ";
	fflush(stdin);
	cin.getline(cod,10);
	pos=buscarReserva(cod);
	if(pos!=-1)
		{
		reg.leerDeDisco(pos);
		reg.setEstado(false);
		if(reg.modificarEnDisco(pos)){
            cout << "Reserva cancelada"<< endl;
            pausa();
		}

		}
	else
		{
		cout<<"No existe la reserva"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
}



void cancelarReservaId(){
    int ide;
	int pos;
	Reserva reg;
	borrarPantalla();
	cout <<"Ingrese id de reserva: ";
	cin  >> ide;
	pos=buscarReservaId(ide);
	if(pos!=-1)
		{
		reg.leerDeDisco(pos);
		reg.setEstado(false);
		if(reg.modificarEnDisco(pos)){
            cout << "Reserva cancelada"<< endl;
            pausa();
		}

		}
	else
		{
		cout<<"No existe la reserva"<<endl;
		cout<<"Presione una tecla para continuar";
		system("pause>nul");
		}
}


/// fseek(P,ftell(P)-sizeof (Reserva),0);/// uno para atras

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
          int sel;
          cout << "Cancelar por dni--->presione 1"<< endl;
          cout << "cancelar por id --->presione 2"<< endl;
          cin  >> sel;
        if(sel==1)cancelarReservaDni();
        if(sel==2)cancelarReservaId();
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

#endif // MENURESERVAS_H_INCLUDED
