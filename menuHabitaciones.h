#ifndef MENUHABITACIONES_H_INCLUDED
//#include "menuClientes.h"
//#include "misFunciones.h"
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<time.h>
#include"string.h"
#include <conio.h>
//#include"menuClientes.h"
//#include"misFunciones.h"
#define MENUHABITACIONES_H_INCLUDED




using namespace std;
#include "misFunciones.h"
#include "recepcion.h"
#include "menuReservas.h"
 const char *FILE_TIPO_HABITACION = "tipo_habitacion.dat";
 const char *FILE_HABITACIONES = "habitaciones.dat";
 const char *FILE_ESTADIAS = "habitacion_ocupada.dat";
int menuHabitaciones();

void listaDeTipos();
int contarTiposHabitaciones();/// devuelve la cantidad de registros que tiene el archivo tipo habitacion
bool verificarTipoHabitacion(char*);
int CodigoTipoHabitacion();
int mostrarHabitaciones();
void mostrarTodasHabitaciones();
void mostrarHabLibres();
void mostrarHabOcupadas();
void mostrarHabEnLimpieza();
void mostrarHabEnMantenimiento();
bool verificarNumeroHabitacion(char*);
int asignarNumEstadia();
void cargarEstadia();
const char* asignarHabitacion(char);





class FechaSistema{
private:
    int anio,mes,dia,hora,minuto;
    time_t tiempo;
    char cad[80];
    struct tm *tmPtr;
public:
    FechaSistema(int a,int b,int c,int d,int e)
    {
        anio=a;
        mes=b;
        dia=c;
        hora=d;
        minuto=e;
    }
    FechaSistema()
    {
        tiempo = time(NULL);
        tmPtr = localtime(&tiempo);

        anio=tmPtr->tm_year+1900;
        mes=tmPtr->tm_mon+1;
        dia=tmPtr->tm_mday;
        hora=tmPtr->tm_hour;
        minuto=tmPtr->tm_min;
        /*printf("FECHA ACTUAL \n%d/%d/%d %d:%d:%d", tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
        strftime(cad, 80, "%A %d de %B de %Y", tmPtr);
        printf("\n\n%s", cad);*/
    }
    int mostar_anio()
    {
        return anio;
    }
    int mostar_mes()
    {
        return mes;
    }
    int mostar_dia()
    {
        return dia;
    }
    int mostar_hora()
    {
        return hora;
    }
    int mostar_minuto()
    {
        return minuto;
    }
    void set_dia(int d)
    {
        dia=d;
    }
    void set_mes(int m)
    {
        mes=m;
    }
    void set_anio(int a)
    {
        anio=a;
    }
    void hora_standar()
    {
        hora=12;
        minuto=00;
    }
};


void convertir_fecha(char v[11],int vint[3])
{
    vint[0]=(((v[0]-'0')*10)+(v[1]-'0'));
    vint[1]=(((v[3]-'0')*10)+(v[4]-'0'));
    vint[2]=(((v[8]-'0')*10)+(v[9]-'0'))+2000;

}
bool comparar_fechas(char ini[11],char fin[11],int a,int m,int d)
{
    //if((a-1900>=strcat(ini[8],ini[9])-'0')&&(m>=strcat(ini[3],ini[4])-'0')&&(d>=strcat(ini[0],ini[1])-'0')&&(a-1900<=strcat(fin[8],fin[9])-'0')&&(m<=strcat(fin[3],fin[4])-'0')&&(d<=strcat(fin[0],fin[1])-'0'))
    int di1,di2,mi1,mi2,ai1,ai2,df1,df2,mf1,mf2,af1,af2;
    di1=ini[0]-'0';
    di2=ini[1]-'0';
    mi1=ini[3]-'0';
    mi2=ini[4]-'0';
    ai1=ini[8]-'0';
    ai2=ini[9]-'0';
    df1=fin[0]-'0';
    df2=fin[1]-'0';
    mf1=fin[3]-'0';
    mf2=fin[4]-'0';
    af1=fin[8]-'0';
    af2=fin[9]-'0';
    if((a-2000)>=((ai1*10)+ai2)&&(m>=((mi1*10)+mi2))&&(d>=(di1*10)+di2)&&(a-2000)<=((af1*10)+af2)&&(m<=(mf1*10)+mf2)&&(d<=(df1*10)+df2))
    {
        return true;
    }
    else
    {
        return false;
    }
}
class Gasto
{
private:
    int id,tipo;
    char habitacion[4];
    float importe;
    char descripcion[240];
    FechaSistema fec;
public:
    void consulta_habitacion(); ///Muestra los gastos correspondientes al ultimo cambio de estado
    void consulta_total();///Muestra todos los gastos
    void consulta_habitacion_fecha(); ///Muestra los gastos dentro de 2 fechas
    void consulta_habitacion_tipo(); ///Muestra todos los gastos de la habitacion y tipo seleccionado
    float get_importe();///Devuelve el importe del gasto
    float get_total(); ///Devuelve el total del ultimo cambio de estado
    void cargar();///carga nuevo gasto
    void anular(); ///anula ultimo gasto
    void modificar(); ///modifica ultimo gasto
};
class Tipo_habitacion /// tipo de habitacion /// son 4 y son fijas
{
private:
    int cod_tipo;
    char nombre[30];
    float costo;
    char adultos;
    char ninios;
    char vista[100];
    char tecnologias[100];
    char camas[100];




public:
    void cargar();
    void mostrar();

    void get_nombre(int c, char v[30]);
    float get_costo(int c);

   /// get mauri
   const char* getNombre(){return nombre;}
   float getCosto(){return costo;}

    /// funciones con archivos
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);

} ; /// para cargar una habitacion

int Tipo_habitacion::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_TIPO_HABITACION,"rb");
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



bool Tipo_habitacion::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_TIPO_HABITACION,"rb+");
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






bool Tipo_habitacion::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_TIPO_HABITACION,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

/// moficiaciones mauri

class Habitacion /// esta crea o contruye las habitaciones
{ /// siempre consultar la cantidad de habitaciones que hay de un tipo
protected:
    char numero[4];
    int id;
    char tipo;
    bool estado;
    bool limpio;
    bool mantenimiento;

public:
    void mostrar(); /// mauri
    bool cargar_habitacion();
    void mostrar_habitacion();
    void mostrar_habitacion_tipo(int t);
    void mostrar_habitacion_estado(char e);
    ///gets
    const char* getHabitacion(){return numero;}
    int getId(){return id;}
    char getTipo(){return tipo;}
    bool getEstado(){return estado;}
    bool getLimpio(){return limpio;}
    bool getMatenimiento(){return mantenimiento;}

    /// sets
    void setHabitacion(const char*nuevoNumero){strcpy(numero,nuevoNumero);}
    void setId(int nuevaId){id=nuevaId;}
    void setTipo(char nuevoTipo){tipo=nuevoTipo;}
    void setEstado(bool nuevoEstado){estado=nuevoEstado;}
    void setLimpio(bool nuevoLimpio){limpio=nuevoLimpio;}
    void setMantenimietno(bool nuevoMante){mantenimiento=nuevoMante;}

    /// funciones con archivos
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);

};

int Habitacion::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_HABITACIONES,"rb");
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



bool Habitacion::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_HABITACIONES,"rb+");
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



bool Habitacion::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_HABITACIONES,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}



class Habitacion_ocupada:public Habitacion /// habitacion para ocupar / PARTE PRINCIPAL DEL PROGRAMA
{
private:
    int numeroDeEstadia;
    char tipoHab;
    char numeroHab[4];
    Cliente datosCliente;
    char serv_contratado[6],hora_limpieza[5];
    ///bool reserva;
    float cuenta;
    float pago_adelantado;/// sale de lo que ponga mas si puso algo en la reserva
    FechaSistema fec_salida();/// automatico cuando se carga
    FechaSistema fec_ingreso();/// automatico cuando se cargaa
    Fecha entra,sale; /// para ver la disponibilidad de habitaciones para esa fecha

    bool activa;

public:
    ///GETS
        bool getActiva(){return activa;}
        char getTipo(){return tipoHab;}
        const char* getNumero(){return numeroHab;}

    ///SETS



    void ocupar(); ///Ocupa una habitacion y carga los datos
    void desocupar(); ///Libera una habitacion
    void consultar(); ///Consulta los datos de la habitacion seleccionada /// es como mostrar
    void consulta_fecha(); ///Consulta los datos de la habitacion entre 2 fechas

        /// funciones con archivos
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);

};

int Habitacion_ocupada::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;                                   /// se pueden contar todos los registros si contas todos los pos
	FILE *p;
	p=fopen(FILE_ESTADIAS,"rb");
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



bool Habitacion_ocupada::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_ESTADIAS,"rb+");
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


bool Habitacion_ocupada::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_ESTADIAS,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}


int asignarNumEstadia(){

    FILE *F;
    F=fopen(FILE_ESTADIAS,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(F);
    tamanioreg=sizeof(Habitacion_ocupada);
    cantidad=tam/tamanioreg;
    fclose(F);
    return cantidad+1;

}

void Habitacion_ocupada::ocupar(){
numeroDeEstadia=asignarNumEstadia();
cout << "Ingrese tipo de habitacion: ";
listaDeTipos();
cin >> tipoHab;
cout << "Ingrese Fecha de ingreso: ";
entra.cargar();
cout << "Ingrese Fecha de salida: ";
sale.cargar();
while(!consultarDisponibilidad(entra,sale,tipoHab)){
    borrarPantalla();
    cout << "Sin disponibilidad para ese rango de fecha"<< endl;
    pausa();
    borrarPantalla();
    cout << "Ingrese tipo de habitacion: ";
    listaDeTipos();
    cin >> tipoHab;
    cout << "Ingrese Fecha de ingreso: ";
    entra.cargar();
    cout << "Ingrese Fecha de salida: ";
    sale.cargar();
}

    strcpy(numeroHab,asignarHabitacion(tipoHab));
    datosCliente.cargar();
    cout << "Servicio Contratado: ";
    limpiarBuffer();
    cin.getline(serv_contratado,6);
    cout << "Hora limpieza: ";
    limpiarBuffer();
    cin.getline(hora_limpieza,5);
    cuenta=0;
    cout << "Pago adelantado: ";
    cin  >> pago_adelantado;
    activa=true;

}

void Habitacion_ocupada::consultar(){
cout << "Numero de estadia: "<< numeroDeEstadia << endl;

cout << "El resto esta en mantenimiento :D"<< endl;
pausa();






}






class Habitacion_mantenimiento:public Habitacion
{
private:
    char descripcion[240];
    float gasto_total;
    int dias_estimado;
public:
    void enviar_mantenimiento(); ///Carga una habitacion al sistema de mantenimiento
    void consultar(); ///Consulta estado de mantenimiento de una habitacion
    void consultar_general(); ///consulta todas las habitaciones en mantenimiento
    void alta();///Da de alta una habitacion y la deja desocupada
};
/*class Habitacion_reserva:public Habitacion /// para relacionar con la menu reservas
{
private:
    int id_reserva; /// viene de la reserva
    float pago_adelantado;
    FechaSistema fec_ingreso,fec_salida;
public:
    void consulta(); ///Consulta todas las habitaciones reservadas actuales
    void consulta_total();///consulta todas las reservas hechas
    void cancelar(); ///Cancela una reserva
    void cargar  (); ///Carga una nueva reserva
};*/

void Gasto::cargar() /// cambiarle tipo de gasto por codigo de producto a vender
{                    /// agregarle la cantidad a vender
    FILE *g;         /// añadir pago si / pago no
    g=fopen("gastos.dat","ab");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    fseek(g,0,2);
    id=((ftell(g)/sizeof(*this))+1);
    cout<<"Ingrese la habitacion que realizo el gasto: ";
    cin>>habitacion;
    cout<<"Ingrese el tipo de gasto: ";
    cin>>tipo;
    cout<<"Ingrese el importe del gasto: $";
    cin>>importe;
    cout<<"Ingrese la descripcion del importe: ";
    cin.ignore();
    cin.getline(descripcion,240);
    fwrite(this,sizeof(*this),1,g);

    fclose(g);

}

void Gasto::consulta_habitacion()/// consulta los gastos actuales del cliente
{
    FILE *g;
    char cons[4];
    g=fopen("gastos.dat","rb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    cout<<"Ingrese la habitacion por la que quiere consultar: ";
    cin>>cons;
    while(fread(this,sizeof(*this),1,g)==1)
    {
        if(strcmp(habitacion,cons)==0)
        {
            cout<<id<<endl;
            cout<<habitacion<<endl;
            cout<<tipo<<endl;
            cout<<importe<<endl;
            cout<<descripcion<<endl<<endl;
            cout<<fec.mostar_dia()<<"/"<<fec.mostar_mes()<<"/"<<fec.mostar_anio()<<"  "<<fec.mostar_hora()<<":"<<fec.mostar_minuto()<<endl;
            cout<<"-------------------------------"<<endl;
        }
    }
    fclose(g);
}

void Gasto::consulta_habitacion_fecha() /// gastos o consumos de habitacion entre dos fechas
{
    FILE *g;
    char cons[4],fecini[11],fecfin[11];
    g=fopen("gastos.dat","rb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    cout<<"Ingrese la habitacion por la que quiere consultar: ";
    cin>>cons;
    cout<<"Ingrese fecha de inicio de la busqueda";
    cin>>fecini;
    cout<<"Ingrese fecha de fin de la busqueda";
    cin>>fecfin;
    while(fread(this,sizeof(*this),1,g)==1)
    {
        if(strcmp(habitacion,cons)==0&&comparar_fechas(fecini,fecfin,fec.mostar_anio(),fec.mostar_mes(),fec.mostar_dia())==true)
        {
            cout<<id<<endl;
            cout<<habitacion<<endl;
            cout<<tipo<<endl;
            cout<<importe<<endl;
            cout<<descripcion<<endl<<endl;
            cout<<fec.mostar_dia()<<"/"<<fec.mostar_mes()<<"/"<<fec.mostar_anio()<<"  "<<fec.mostar_hora()<<":"<<fec.mostar_minuto()<<endl;
            cout<<"-------------------------------"<<endl;
        }
    }
    fclose(g);
}

void Gasto::consulta_habitacion_tipo()
{
    FILE *g;
    char cons[4];
    int tip;
    g=fopen("gastos.dat","rb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    cout<<"Ingrese la habitacion por la que quiere consultar: ";
    cin>>cons;
    cout<<"Ingrese el tipo de gasto que quiere consultar: ";
    cin>>tip;
    while(fread(this,sizeof(*this),1,g)==1)
    {
        if((strcmp(habitacion,cons)==0)&&(tipo==tip))
        {
            cout<<id<<endl;
            cout<<habitacion<<endl;
            cout<<tipo<<endl;
            cout<<importe<<endl;
            cout<<descripcion<<endl<<endl;
            cout<<fec.mostar_dia()<<"/"<<fec.mostar_mes()<<"/"<<fec.mostar_anio()<<"  "<<fec.mostar_hora()<<":"<<fec.mostar_minuto()<<endl;
            cout<<"-------------------------------"<<endl;
        }
    }
    fclose(g);
}

void Gasto::consulta_total()
{
    FILE *g;
    g=fopen("gastos.dat","rb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,g)==1)
    {

        cout<<id<<endl;
        cout<<habitacion<<endl;
        cout<<tipo<<endl;
        cout<<importe<<endl;
        cout<<descripcion<<endl<<endl;
        cout<<fec.mostar_dia()<<"/"<<fec.mostar_mes()<<"/"<<fec.mostar_anio()<<"  "<<fec.mostar_hora()<<":"<<fec.mostar_minuto()<<endl;
        cout<<"-------------------------------"<<endl;

    }
    fclose(g);
}


void Gasto::anular() /// anula gasto que vos quieras
{
    FILE *g,*aux;
    int idanul;
    g=fopen("gastos.dat","rb");
    aux=fopen("auxiliar.dat","wb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    if(aux==NULL)
    {
        cout<<"Fallo al abrir el archivo"<<endl;
        return;
    }
    cout<<"Ingrese el id del gasto que quiere anular";
    cin>>idanul;
    while(fread(this,sizeof(*this),1,g)==1)
    {

        if(id!=idanul)
        {
            fwrite(this,sizeof(*this),1,aux);
        }
    }
    fclose(g);
    fclose(aux);
    g=fopen("gastos.dat","wb");
    aux=fopen("auxiliar.dat","rb");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    if(aux==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,aux)==1)
    {
        fwrite(this,sizeof(*this),1,g);
    }
    fclose(g);
    fclose(aux);

}

void Gasto::modificar()
{
    FILE *g;
    g=fopen("gastos.dat","rb+");
    if(g==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    fseek(g,0,2);
    id=(ftell(g)/sizeof(*this));
    cout<<"Ingrese la habitacion que realizo el gasto: ";
    cin>>habitacion;
    cout<<"Ingrese el tipo de gasto: ";
    cin>>tipo;
    cout<<"Ingrese el importe del gasto: $";
    cin>>importe;
    cout<<"Ingrese la descripcion del importe: ";
    cin.ignore();
    cin.getline(descripcion,240);
    fseek(g,(ftell(g)-sizeof(*this)),0);
    fwrite(this,sizeof(*this),1,g);

    fclose(g);
}
/*void Habitacion_reserva::cargar()
{
    char fi[11],fs[11];
    int aux[3];
    FILE *r;
    r=fopen("reserva.dat","ab");
    if(r==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    fseek(r,0,2);
    id=((ftell(r)/sizeof(*this))+1);
    cout<<"Ingrese la habitacion que quiere reservar: ";
    cin>>habitacion;
    estado='A';
    cout<<"Ingrese el importe del pago adelantado: $";
    cin>>pago_adelantado;
    cout<<"Ingrese la fecha de entrada: ";
    cin>>fi;
    convertir_fecha(fi,aux);
    fec_ingreso.set_dia(aux[0]);
    fec_ingreso.set_mes(aux[1]);
    fec_ingreso.set_anio(aux[2]);
    fec_ingreso.hora_standar();
    cout<<"Ingrese la fecha de salida: ";
    cin>>fs;
    convertir_fecha(fs,aux);
    fec_salida.set_dia(aux[0]);
    fec_salida.set_mes(aux[1]);
    fec_salida.set_anio(aux[2]);
    fec_salida.hora_standar();

    fwrite(this,sizeof(*this),1,r);

    fclose(r);
}

void Habitacion_reserva::consulta_total()
{
    FILE *r;
    r=fopen("reserva.dat","rb");
    if(r==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,r)==1)
    {
            cout<<"Id: "<<id<<endl;
            cout<<"Habitacion: "<<habitacion<<endl;
            cout<<"Pago adelantado: $"<<pago_adelantado<<endl;
            cout<<fec_ingreso.mostar_dia()<<"/"<<fec_ingreso.mostar_mes()<<"/"<<fec_ingreso.mostar_anio()<<"  "<<fec_ingreso.mostar_hora()<<":"<<fec_ingreso.mostar_minuto()<<endl;
            cout<<fec_salida.mostar_dia()<<"/"<<fec_salida.mostar_mes()<<"/"<<fec_salida.mostar_anio()<<"  "<<fec_salida.mostar_hora()<<":"<<fec_salida.mostar_minuto()<<endl;
            cout<<"-------------------------------"<<endl;
    }
    fclose(r);
}*/
int contarTiposHabitaciones(){
    FILE *F;
    F=fopen(FILE_TIPO_HABITACION,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(F);
    tamanioreg=sizeof(Tipo_habitacion);
    cantidad=tam/tamanioreg;
    fclose(F);
    return cantidad;

}

void listaDeTipos(){
Tipo_habitacion aux;
int pos=0;
/*char **matriz;
int filas=contarTiposHabitaciones();
int columna=strlen(aux.getNombre());
matriz = new char *[fila_dinamica];
for (int i=0;i<filas;i++){
        matriz[i] = new char[columna];
    }*/
while(aux.leerDeDisco(pos++)==1){

    cout <<pos<<")"<< aux.getNombre() << endl;
}

}

bool verificarNumeroHabitacion(char *numHabitacion){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){

    if(strcmp(numHabitacion,aux.getHabitacion())==0)
        return false;

}

return true;

}



bool Habitacion::cargar_habitacion()
{
  FILE *h;
    h=fopen("habitaciones.dat","ab");
    if(h==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return false;
    }
    fseek(h,0,2);
    id=((ftell(h)/sizeof(*this))+1);
    cout<<"Ingrese el numero de la habitacion: ";
    limpiarBuffer();
    cin.getline(numero,4);
    while(!verificarNumeroHabitacion(numero)){
        borrarPantalla();
        cout << "Habitación con ese numero ya fue creada"<< endl;
        pausa();
        borrarPantalla();
        cout<<"Ingrese el numero de la habitacion: ";
        limpiarBuffer();
        cin.getline(numero,4);


    }
    listaDeTipos();
    cout << "Seleccione tipo de habitacion: "<< endl;
    cin>>tipo;
    estado=true;
    limpio=true;
    mantenimiento=false; /// se carga en false , si va a mantenimiento se pone en true
    fwrite(this,sizeof(*this),1,h);
    fclose(h);
    return true;


}

int CodigoTipoHabitacion(){
int cant=contarTiposHabitaciones();
return cant+1;
}

bool verificarTipoHabitacion(char *nombre){
Tipo_habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


    if(strcmp(nombre,aux.getNombre())==0)return false;

}
return true;

}

void Tipo_habitacion::cargar(){
    /// PANA LA CAMBIE PARA NO ABRIR EL ARCHIVO DETRO DE LA CARGA ///

    cod_tipo=CodigoTipoHabitacion();
    cout<<"Ingrese el nombre del tipo: ";
    limpiarBuffer();
    cin.getline(nombre,30);
    while(!verificarTipoHabitacion(nombre)){
            borrarPantalla();
     cout << "ya existe ese tipo de habitación" << endl;
        pausa();
        borrarPantalla();
        cout<<"Ingrese el nombre del tipo: ";
        limpiarBuffer();
        cin.getline(nombre,30);

    }

    cout<<"Ingrese el precio del tipo: $";
    cin>>costo;
    cout << "Capacidad máxima adultos: ";
    limpiarBuffer();
    cin >> adultos;
    cout << "Capacidad máxima niños: ";
    cin >> ninios;
    cout << "Ingrese tipo de camas: ";
    limpiarBuffer();
    cin.getline(camas,100);
    cout << "Ingrese tecnologías disponibles: ";
    limpiarBuffer();
    cin.getline(tecnologias,100);
    cout << "Ingrese vistas desde a habitación: ";
    limpiarBuffer();
    cin.getline(vista,500);

}
void Tipo_habitacion::mostrar(){


        cout <<"\t\tCodigo de tipo: "<<cod_tipo<<endl;
        cout <<"\t\tNombre: "<<nombre<<endl;
        cout <<"\t\tcosto: "<<costo<<endl;
        cout <<"\t\tCapacidad máxima: "<< adultos << " Adulto/s + "<< ninios << " niño/s"<< endl;
        cout <<"\t\tCARACTERISTICAS: "<< endl;
        cout <<"\t\t*"<<camas << endl;
        cout <<"\t\t*"<<tecnologias << endl;
        cout <<"\t\t*"<<vista << endl;
        cout<<"\t\t---------------------------"<<endl;
        pausa();



}

/// cuanta las habitacion del tipo que le mandes
int contarHabitaciones(char tipo){
Tipo_habitacion aux;
int pos=0;
char nombreHabitacion[30];
if (tipo=='1')strcpy(nombreHabitacion,"Estandar");
if (tipo=='2')strcpy(nombreHabitacion,"Suite");
if (tipo=='3')strcpy(nombreHabitacion,"Master Suite");
if (tipo=='4')strcpy(nombreHabitacion,"Presidencial");
int cantidad=0;
while(aux.leerDeDisco(pos++)==1){


    if(strcmp(nombreHabitacion,aux.getNombre())==0) cantidad++;

}
return cantidad;
/// cuenta y devuelve la cantidad de habitaciones de un tipo
}



float Tipo_habitacion::get_costo(int c)
{
    FILE *t;
    float cost;
    t=fopen("tipo_habitacion.dat","rb");
    if(t==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        exit;
    }
    fseek(t,((c-1)*sizeof(*this)),0);
    fread(this,sizeof(*this),1,t);
    cost=costo;
    fclose(t);
    return cost;
}
void Tipo_habitacion::get_nombre(int c,char v[30])
{
    FILE *t;
    t=fopen("tipo_habitacion.dat","rb");
    if(t==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        exit;
    }
    fseek(t,(c-1)*sizeof(*this),0);
    fread(this,sizeof(*this),1,t);
    strcpy(v,nombre);
    fclose(t);
}

void Habitacion::mostrar_habitacion()
{
    FILE *h;
    char nom[30];
    Tipo_habitacion t;
    h=fopen("habitaciones.dat","rb");
    if(h==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,h)==1)
    {
        t.get_nombre(tipo,nom);
        cout<<"ID:         "<<id<<endl;
        cout<<"Habitacion: "<<numero<<endl;
        cout<<"Tipo:       "<<nom<<endl;
        cout<<"Costo: $    "<<t.get_costo(tipo)<<endl;
        if (estado==true){
        cout<<"Estado: Disponible"<<endl;
        }
        else{
            cout<<"Estado: Ocupada" <<endl;
        }
        if(limpio==false){

            cout << "En limpieza "<< endl;
        }

        if(mantenimiento==true){
            cout << "En mantenimiento "<< endl;
        }

        cout<<"-------------------------------"<<endl;
        pausa();
    }

    fclose(h);
}

/// mostrar habitacion mauri
void Habitacion::mostrar(){
Tipo_habitacion aux;
cout << "Id: "<< id << endl;
cout << "Numero de habitación: "<< numero << endl;

aux.leerDeDisco(tipo);
cout << "Tipo de habitación: "<< aux.getNombre() << endl;
cout << "Precio por noche: "<< aux.getCosto()<< endl;
if (estado==true){
        cout<<"Estado: Disponible"<<endl;
        }
        else{
            cout<<"Estado: Ocupada" <<endl;
        }
        if(limpio==false){

            cout << "En limpieza "<< endl;
        }

        if(mantenimiento==true){
            cout << "En mantenimiento "<< endl;
        }
        cout << "----------------------"<< endl;
        pausa();

}

void Habitacion::mostrar_habitacion_tipo(int ti)
{
  FILE *h;
    char nom[30];
    Tipo_habitacion t;
    h=fopen("habitaciones.dat","rb");
    if(h==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,h)==1)
    {
        if(tipo==ti)
        {
        t.get_nombre(tipo,nom);
        cout<<"ID:         "<<id<<endl;
        cout<<"Habitacion: "<<numero<<endl;
        cout<<"Tipo:       "<<nom<<endl;
        cout<<"Costo: $"<<t.get_costo(tipo)<<endl;
        cout<<"Estado:     "<<estado<<endl;
        cout<<"-------------------------------"<<endl;
        }
    }
    fclose(h);
}
void Habitacion::mostrar_habitacion_estado(char e)
{
    FILE *h;
    char nom[30];
    Tipo_habitacion t;
    h=fopen("habitaciones.dat","rb");
    if(h==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,h)==1)
    {
        if(estado==e)
        {
        t.get_nombre(tipo,nom);
        cout<<"ID: "<<id<<endl;
        cout<<"Habitacion: "<<numero<<endl;
        cout<<"Tipo: "<<nom<<endl;
        cout<<"Costo: $"<<t.get_costo(tipo)<<endl;
        cout<<"Estado: "<<estado<<endl;
        cout<<"-------------------------------"<<endl;
        }
    }
    fclose(h);
}
/// FUNCIONES

void mostrarTodasHabitaciones(){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


      aux.mostrar();

  }

}
void mostrarHabLibres(){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


    if(aux.getEstado()==true){
            aux.mostrar();
          }
  }

}
const char* asignarHabitacion(char tipo){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){

    if((aux.getEstado()==true)&&(aux.getTipo()==tipo)){
        aux.setEstado(false);
        aux.modificarEnDisco(pos);
        return aux.getHabitacion();
                }

        }

}

void mostrarHabOcupadas(){
Habitacion_ocupada aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){

    if(aux.getActiva()==true){
        aux.consultar();
    }
}

}

void mostrarHabEnLimpieza(){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


    if(aux.getLimpio()==false){
            aux.mostrar();
          }
  }

}
void mostrarHabEnMantenimiento(){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


    if(aux.getMatenimiento()==true){
            aux.mostrar(); /// se deberia mostrar clase habitacion en mantenimiento
          }
  }



}


int mostrarHabitaciones(){
short opcion;
while(true){
    borrarPantalla();

    cout << "1)Habitaciones libres    " << endl;
    cout << "2)Habitaciones ocupadas  " << endl; /// las muestra con los datos de las perosnas que estan ocupandola
    cout << "3)Haitaciones en limpieza" << endl;
    cout << "4)Haitaciones en mantenimiento" << endl;
    cout << "5)MOSTRAR TODAS LAS HABITACIONES"<< endl;
    cout << "0) Salir "<< endl;
    cout << endl << "Opción: ";
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case 1:
        mostrarHabLibres();
            break;
      case 2:
        mostrarHabOcupadas();
      break;
      case 3:
        mostrarHabEnLimpieza();
      break;
      case 4:
          mostrarHabEnMantenimiento();
        break;
      case 5:
    mostrarTodasHabitaciones();
      break;

      case 0:
        return 0;
      break;
      default:
        mensajes(2);
        break;
    }
    cout << endl;

  }

}

void cargarEstadia(){
Habitacion_ocupada reg;
reg.ocupar();
if(reg.escribirEnDisco()){

    cout << "Estadia cargada con éxito"<< endl;
    cout << "Se asigno habitación "<< reg.getNumero();
    pausa();
        }



}



int menuHabitaciones()
{

    short opcion;
    while(true){
        borrarPantalla();
        cout << "\t\tMENÚ HABITACIONES    " << endl;
        cout << "\t\t-------------------- " << endl;
        /// si hay habitacion disponible cargar el cliente y le asigna la habitacion seleccionada
        /// sin necesidad de que haya reservado
        cout << "\t\t1) CARGAR NUEVA ESTADIA SIN RESERVA     "<< endl;
        cout << "\t\t2) RECEPCIÓN(misma funcion que en el menu principal)"<< endl;
        cout << "\t\t3) CHECK OUT(misma funcion que en el menu principal)"<< endl;
        cout << "\t\t4) VER HABITACIONES" << endl; ///LIBRES , OCUPADAS, EN LIMPIEZA, TODAS
        cout << "\t\t5) VENTA DE PRODUCTOS(GASTO)            " << endl;///Cargar modificar y eliminar gastos,
        cout << "\t\t6) CARGAR HABITACION PARA MANTENIMIENTO " << endl;
        cout << "\t\t7) CARGAR HABITACION PARA LIMPIEZA      " << endl;
        cout << "\t\t0) Salir "<< endl;
        cout << endl << "\t\tOpción: ";
        cin >> opcion;
        borrarPantalla();
        switch(opcion){
          case 1:
        cout << "En contruccion..."<<endl;
        pausa();
          break;
          case 2:
        menuRecepcion();
          break;
          case 3:
            cout << "En contruccion..."<<endl;
        pausa();
          break;
          case 4:
            mostrarHabitaciones();
          break;
          case 5:
           cout << "En contruccion..."<<endl;
        pausa();
          break;
          case 6:
              cout << "En contruccion..."<<endl;
        pausa();
            break;
          case 7:
              cout << "En contruccion..."<<endl;
        pausa();
            break;
          case 0:
            return 0;
          break;
          default:
              mensajes(2);
            break;
        }
        cout << endl;

      }
}


#endif // MENUHABITACIONES_H_INCLUDED
