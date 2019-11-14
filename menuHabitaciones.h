#ifndef MENUHABITACIONES_H_INCLUDED
//#include "menuClientes.h"
//#include "misFunciones.h"
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<time.h>
#include"string.h"
#include <conio.h>
#include"menuClientes.h"
//#include"misFunciones.h"
#define MENUHABITACIONES_H_INCLUDED




using namespace std;
#include "misFunciones.h"
#include "recepcion.h"
#include "menuReservas.h"
#include "productos.h"
#include "menuLimpieza.h"

#include "menuLimpieza.h"
 const char *FILE_TIPO_HABITACION = "tipo_habitacion.dat";
 const char *FILE_HABITACIONES = "habitaciones.dat";
 const char *FILE_ESTADIAS = "habitacion_ocupada.dat";
 const char *FILE_VENTAS = "ventas.dat";
 const char *FILE_MANTENIMIENTO = "mantenimiento.dat";
int menuHabitaciones();


int contarTiposHabitaciones();/// devuelve la cantidad de registros que tiene el archivo tipo habitacion
bool verificarTipoHabitacion(char*);
int CodigoTipoHabitacion();
int mostrarHabitaciones();
void mostrarTodasHabitaciones();
void mostrarHabLibres();
void mostrarHabOcupadas();
void mostrarHabEnLimpieza();
void mostrarHabEnMantenimiento(); /// funcion del menu mostrar habitaciones , no muestra detalles solo las que estan en mantenimiento, muestra clase Habitacion
bool verificarNumeroHabitacion(char*);
int asignarNumEstadia();
void cargarEstadia();
const char* asignarHabitacion(char);
int letra_a_entero(char);
void realizarCheckOut();
int contarRegistrosHabitaciones();
bool liberarHabitacion(const char*);
int contarHabitaciones(char);
int buscarHabitacionOcupada(const char*);
int buscarVentaId(int);
void mostrarVenta();
bool verificarVenta(const char*);
float totalFacturado(int);
int buscarHabitacionTipo(const char*);
bool fechaPasado(Fecha);
int sectorMantenimiento();
bool verifMantenimiento(const char*);
void sacar_de_mantenimiento();
void cargarParaMantenimiento();
void HabitacionesMantenimiento(); /// funcion del menu mantenimiento, muestra detalles , muestra clase Habitacion_mantenimiento
void mostrarTodas_Mantenimiento();/// las muestra todas ordenadas por numero ///
void listarHabMantenimiento(); /// ingresas el numero de habitacion y lista los detalles de mantenimiento ///
int contarRegistrosMantenimiento();
void modificarMantenimiento();
void historialMantenimiento();/// menu para mostrar historial
void mostrarHistorialMante(); /// las muestra todas desde tipo fifo comun ---> desde la mas antigua
void buscarEnHistorialMante();




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


/// CLASE VENTA ///

class Venta{ /// luego cuando se muestran todas las ventas se forma la factura

private:


    char habitacion[4]; /// numero de habitacion a la cual pertenece
    int id;/// automatico , se relaciona con num de estadia /// luego al final se suman todas las ventas del num de estadia
    FechaSistema fec;/// fecha y hora del sistema ver como poner esto
    char codigoProducto[5];/// codigo de producto a vender
    int cantidad; /// cantidad de unidades a vender
    float total; /// total de la venta
    bool pagado;
    int numeroCaja;
    public:

        void cargar();
        void mostrar();
        /// gets
        int getId(){return id;}
        const char* getHabitacion(){return habitacion;}
       int getCantidad(){return cantidad;}
       const char* getCodProducto(){return codigoProducto;}
       float getTotal(){return total;}
       bool getPago(){return pagado;}
        /// sets
        void setCantidad(int nuevaCant){cantidad=nuevaCant;}
        void setCodigoProducto(const char*nuevoCod){strcpy(codigoProducto,nuevoCod);}
        void setTotal(float nuevoTotal){total=nuevoTotal;}
        /// funciones con archivos

        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);


};

int Venta::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_VENTAS,"rb");
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



bool Venta::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_VENTAS,"rb+");
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

bool Venta::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_VENTAS,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

int buscarVentaId(int cod){ ///devuelve la posicion de la venta en el archivo
	int pos=0;
	Venta reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(cod==reg.getId())
			return pos;
		pos++;
		}
	return -1;
}




void Venta::cargar(){
    Producto aux;
    char pago[3];
    cout << "Ingrese número de habitación: ";
    limpiarBuffer();
    cin.getline(habitacion,4);
    /// falta ver si la habitacion esta ocupada ///
    id=buscarHabitacionOcupada(habitacion);
    while(id==-1){
        borrarPantalla();
        cout << "Ingrese una habitación valida"<< endl;
        pausa();
        borrarPantalla();
        cout << "Ingrese número de habitación: ";
        limpiarBuffer();
        cin.getline(habitacion,4);
        id=buscarHabitacionOcupada(habitacion);

    }
    id++;


    listaProductos();
    cout << "Ingrese código de producto: ";
    limpiarBuffer();
    cin.getline(codigoProducto,5);
    /// se verifica que el producto exista ///
    if(buscarProducto(codigoProducto)==-1){
        borrarPantalla();
        cout << "Codigo invalido"<<endl;
        pausa();
        borrarPantalla();
        cout << "Ingrese código de producto: ";
        limpiarBuffer();
        cin.getline(codigoProducto,5);
    }
    cout << "Ingrese cantidad: ";
    cin  >> cantidad;

    /// aca se verifica el stock disponible ///
    while(descontarStock(cantidad,codigoProducto)==false){
          borrarPantalla();
          cout << "Sin stock disponible      "<< endl;
          cout << "Ingrese una cantidad menor"<< endl;
          pausa();
          borrarPantalla();
          cout << "Ingrese cantidad: ";
          cin  >> cantidad;
          }

    int pos=buscarProducto(codigoProducto);
    aux.leerDeDisco(pos);
    float precio=aux.getPrecio();
    total=precio*cantidad;
    cout << "Total $"<< total << endl;
    cout << "Pagar ahora(si/no): ";
    limpiarBuffer();
    cin.getline(pago,3);
    if(strcmp(pago,"si")==0){pagado=true;return;}
    if(strcmp(pago,"SI")==0){pagado=true;return;}
    /// si pagado es true no se suma a la cuenta final pero igual se muestra ///
    pagado=false;
    FechaSistema fec();


}


void Venta::mostrar(){

Producto aux;
cout << "Número de estadia: "<< id << endl;
cout << "Número de habitación: "<< habitacion << endl;
cout << "Fecha de venta:       "<<fec.mostar_dia();cout<<"/"<<fec.mostar_mes();cout<<"/"<<fec.mostar_anio();cout<< endl;
cout << "Hora de venta:        "<< fec.mostar_hora();cout <<":"<<fec.mostar_minuto();cout << endl;
cout << "Código de producto:   "<< codigoProducto << endl;
int pos=buscarProducto(codigoProducto);
aux.leerDeDisco(pos);
cout << "Producto: ";cout << aux.getNombre();cout << endl;
cout << "Cantidad: "<< cantidad << endl;
cout << "Total: $" << total << endl;
if(pagado==true){

    cout << "Pagado: Si" << endl;
}
else {
    cout << "Pagado: No" << endl;
}

 /// ver de ordenar como lista productos ///
}

/// FIN CLASE VENTA ///



/// CLASE TIPO DE HABITACION ///
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
   int getCodigoTipo(){return cod_tipo;}

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

/// moficiaciones mauri ///CLASE HABITACION

class Habitacion /// esta crea o contruye las habitaciones
{ /// siempre consultar la cantidad de habitaciones que hay de un tipo
protected:
    char numero[4];
    ///int id; /// nos sirve para desocupar una habitacion
    char tipo;
    bool estado; /// true cuando se crea, false para dar de baja definitivamente ---> crear opcion de dar de baja definitivamente
    bool limpio; /// si esta en limpieza
    bool mantenimiento; /// si esta en mantenimiento

public:
    void cargar(); /// mauri
    void mostrar(); /// mauri
    bool cargar_habitacion();
    void mostrar_habitacion();
    void mostrar_habitacion_tipo(int t);
    void mostrar_habitacion_estado(char e);
    ///gets
    const char* getNumero(){return numero;}
///    int getId(){return id;}
    char getTipo(){return tipo;}
    bool getEstado(){return estado;}
    bool getLimpio(){return limpio;}
    bool getMatenimiento(){return mantenimiento;}

    /// sets
    void setHabitacion(const char*nuevoNumero){strcpy(numero,nuevoNumero);}
///    void setId(int nuevaId){id=nuevaId;}
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

int buscarHabitacion(const char* num){ ///devuelve la posicion de la habitacion en el archivo
	int pos=0;
	Habitacion reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(strcmp(num,reg.getNumero())==0)
			return pos;
		pos++;
		}
	return -1;
}

/// FIN CLASE HABITACION ///

/// CLASE HABITACION OCUPADA ///

class Habitacion_ocupada:public Habitacion /// habitacion para ocupar / PARTE PRINCIPAL DEL PROGRAMA
{
private:
    int numeroDeEstadia;
    char tipoHab;
    char numeroHab[4];
    Cliente datosCliente;
    char serv_contratado[150],hora_limpieza[20];
    ///bool reserva;
    float cuenta; /// total a pagar ///
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
    bool desocupar(); ///Libera una habitacion
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

int buscarHabitacionOcupada(const char* num){ ///devuelve la posicion de la habitacion en el archivo
	int pos=0;
	Habitacion_ocupada reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if((strcmp(num,reg.getNumero())==0)&&(reg.getActiva()==true)){
			return pos;
			}
            pos++;
		}

	return -1;
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

bool fechaPasado(Fecha aux){
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    ///FECHA ACTUAL tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year
    cout << tmPtr->tm_mday <<"/"<<tmPtr->tm_mon+1<<"/"<<1900+tmPtr->tm_year<<endl;
    ///cout << tmPtr->tm_hour<<":"<<tmPtr->tm_min<<":"<<tmPtr->tm_sec<<endl;///HORA

    if(aux.getAnio()<1900+tmPtr->tm_year)return false;
    /// si el año es menor retorna falso
    if((aux.getAnio()==1900+tmPtr->tm_year)&&(aux.getMes()<tmPtr->tm_mon+1))return false;
    /// si el año es igual pero el mes es menor retorna falso
    if((aux.getAnio()==1900+tmPtr->tm_year)&&(aux.getMes()==tmPtr->tm_mon+1)&&(aux.getDia()<tmPtr->tm_mday))return false;
    /// si el año es igual , el mes es igual y el dia es menor retorna falso
    return true;
    /// si pasa todo es significa que la fecha es valida ---> dia actual en adelante ///


}

void Habitacion_ocupada::ocupar(){
numeroDeEstadia=asignarNumEstadia();
cout << "Ingrese tipo de habitacion: "<< endl;
listaDeTipos();
cin >> tipoHab;
cout << "Ingrese Fecha de ingreso: ";cout << endl;
entra.cargar();
while(fechaPasado(entra)==false){
    borrarPantalla();
    cout<<"No puede ser una fecha menor a ";fecha(); cout << endl;
    pausa();
    borrarPantalla();
    cout << "Ingrese Fecha de ingreso: ";cout << endl;
    entra.cargar();
}
cout << "Ingrese Fecha de salida: ";cout << endl;
sale.cargar();
while(fechaPasado(sale)==false){
    borrarPantalla();
    cout<<"No puede ser una fecha menor a ";fecha(); cout << endl;
    pausa();
    borrarPantalla();
    cout << "Ingrese Fecha de salida: ";cout << endl;
    sale.cargar();

} /// puede ser que entre y salga en el dia por eso la fecha de entrada puede ser igual a la de salida ///

while(!consultarDisponibilidad(entra,sale,tipoHab)){
    borrarPantalla();
    cout << "Sin disponibilidad para ese rango de fecha"<< endl;
    pausa();
    borrarPantalla();
    cout << "Ingrese tipo de habitacion: "<< endl;
    listaDeTipos();
    cin >> tipoHab;
    cout << "Ingrese Fecha de ingreso: ";cout << endl;
    entra.cargar();
    cout << "Ingrese Fecha de salida: ";cout << endl;
    sale.cargar();
}

    strcpy(numeroHab,asignarHabitacion(tipoHab));
    datosCliente.cargar();

    datosCliente.escribirEnDisco();

    cout << "Servicio Contratado: ";
    limpiarBuffer();
    cin.getline(serv_contratado,6);
    cout << "Hora limpieza: ";
    limpiarBuffer();
    cin.getline(hora_limpieza,20);
    cuenta=0;
    cout << "Pago adelantado: ";
    cin  >> pago_adelantado;
    activa=true;

}
bool liberarHabitacion(const char *numHab){

Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos)==1){


    if(strcmp(numHab,aux.getNumero())==0){

        aux.setEstado(true);
        aux.setLimpio(false);
        aux.modificarEnDisco(pos);
        return true;
    }
    pos++;
}
return false;

}

float totalFacturado(int estadia){
Venta reg;
int pos=0;
float total=0;
cout << "--------------------------"<< endl;
while(reg.leerDeDisco(pos++)==1){


    if((estadia==reg.getId())&&(reg.getPago()==false)){

        total+=reg.getTotal();
        reg.mostrar();

    }
    else {

        if((estadia==reg.getId()))
            reg.mostrar();

    }
cout << "--------------------------"<< endl;

}

return total;


}


bool Habitacion_ocupada::desocupar(){

Venta reg;
Tipo_habitacion aux;
char pago[3];
///cout << "Numero de estadia: "<< numeroDeEstadia << endl;
///cout << "Numero de Habitación: "<< numeroHab << endl;
int pos=tipoHab-'0';
/// se le resta una unidad para que concuerde con la pos del archivo
aux.leerDeDisco(pos-1);
cout << "Tipo de habitación: "<< aux.getNombre();
cout << endl;
float precioEstadia=aux.getCosto();
cuenta=totalFacturado(numeroDeEstadia);
cout << "Precio por noche           --->$"<< precioEstadia << endl;
cout << "Precio por estadia completa--->$"<< precioEstadia << endl;
cout << "Pago adelantado            --->$"<< pago_adelantado << endl;
cout << "Cuenta final               --->$"<<(cuenta+precioEstadia-pago_adelantado) << endl;
/// EN ESTE PUNTO SE LE MUESTRAN TODAS LAS COMPRAS QUE HIZO LA HABITACION ///
/// TANTO LAS PAGADAS COMO LAS NO PAGADAS ///
/// Y OBVIO SE LE COBRAN LAS QUE NO PAGO ///
cout << "Pagar (si/no): ";
limpiarBuffer();
cin.getline(pago,3);

if (strcmp(pago,"si")==0){
        if(liberarHabitacion(numeroHab)){
            cout << "Habitación "<< numeroHab << " liberada y en limpieza..."<< endl;
            pausa();
        }
        activa=false;
        return true;
}
if (strcmp(pago,"SI")==0){
        if(liberarHabitacion(numeroHab)){
            cout << "Habitación "<< numeroHab << " liberada y en limpieza..."<< endl;
            pausa();
        }
        activa=false;
        return true;
}

return false;

}

void Habitacion_ocupada::consultar(){
    Tipo_habitacion aux;
cout << "Numero de estadia: "<< numeroDeEstadia << endl;
cout << "Numero de habitación: "<< numeroHab << endl;
datosCliente.mostrar();
int pos=tipoHab-'0';
/// se le resta una unidad para que concuerde con la pos del archivo
aux.leerDeDisco(pos-1);
cout << "Tipo de habitación: "<< aux.getNombre();
cout << endl;
cout << "Servicio contratado: "<< serv_contratado << endl;
cout << "Hora limpieza: "<< hora_limpieza << endl;
cout << "Cuenta actual  ---> $"<< cuenta << endl;
cout << "Pago adelantado---> $"<< pago_adelantado << endl;
cout << "Fecha de entrada: "; entra.mostrarConBarra();
cout << "Fecha de salida:  "; sale.mostrarConBarra();

cout << "El resto esta en mantenimiento :D"<< endl;
pausa();

}

/// FIN HABITACION OCUPADA ///

/// CLASE GASTO ///
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


/// FIN CLASE GASTO ///

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

void mostrarTipo(char tipo){
int pos=tipo-'0';
Tipo_habitacion aux;
aux.leerDeDisco(pos-1);
cout << "Habitación: ";cout << aux.getNombre();cout << endl;

}

bool verificarNumeroHabitacion(char *numHabitacion){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){

    if(strcmp(numHabitacion,aux.getNumero())==0)
        return false;

}

return true;

}



bool Habitacion::cargar_habitacion() /// no esta en uso actualmente
{
  FILE *h;
    h=fopen("habitaciones.dat","ab");
    if(h==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return false;
    }
    fseek(h,0,2);
///    id=((ftell(h)/sizeof(*this))+1);
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
    cin  >>tipo;
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

/*const char* nombreTipoHabitacion(char tipe){

Tipo_habitacion reg;
char nombreHab[30];
int pos=tipe-'0';
reg.leerDeDisco(pos-1);
strcpy(nombreHab,reg.getNombre());

return nombreHab;

}*/



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
///        cout<<"ID:         "<<id<<endl;
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

int contarRegistrosHabitaciones(){

Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos)==1){

    pos++;

}

return pos;
}


void Habitacion::cargar(){

    ///int cant=contarRegistrosHabitaciones();
    ///id=cant+1;
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
    cin  >>tipo;
    estado=true;
    limpio=true; /// se inicializan limpias /// por eso el estado true
    mantenimiento=false; /// se carga en false , si va a mantenimiento se pone en true


}


/// mostrar habitacion mauri
void Habitacion::mostrar(){
Tipo_habitacion aux;
///cout << "Id: "<< id << endl;
cout << "Numero de habitación: "<< numero << endl;
int pos=tipo-'0';
/// se le resta una unidad para que concuerde con la pos del archivo
aux.leerDeDisco(pos-1);
cout << "Tipo de habitación: "<< aux.getNombre();
cout << endl;
cout << "Precio por noche: $ "<< aux.getCosto();
cout << endl;
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
///        cout<<"ID:         "<<id<<endl;
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
///        cout<<"ID: "<<id<<endl;
        cout<<"Habitacion: "<<numero<<endl;
        cout<<"Tipo: "<<nom<<endl;
        cout<<"Costo: $"<<t.get_costo(tipo)<<endl;
        cout<<"Estado: "<<estado<<endl;
        cout<<"-------------------------------"<<endl;
        }
    }
    fclose(h);
}


void mostrarTodasHabitaciones(){
Habitacion aux;
int pos=0;
int cont=0;
while(aux.leerDeDisco(pos)==1){


      aux.mostrar();
        pos++;
        cont++;
  }
if(cont == 0){

   cout << "Aún no hay habitaciones cargadas."<< endl;
    pausa();
   }

}

int contarHabitaciones(char _tipo){ /// cuenta las habitaciones de un tipo
Habitacion aux;
int pos=0;
int cantidad=0;
while(aux.leerDeDisco(pos++)==1){

if(aux.getTipo()==_tipo){

    cantidad++;
    }

}
return cantidad;

}

bool consultarDisponibilidad(Fecha in,Fecha out,char tipo){


int cantReg=contarRegistrosReservas();
if(cantReg==0)return true;
Reserva aux;
int pos=0;
int cantHabitaciones=contarHabitaciones(tipo);
cout << "cant habitaciones"<< cantHabitaciones << endl;
pausa();
int chances=cantHabitaciones;

while(aux.leerDeDisco(pos++)==1){

    if(aux.getTipo()==tipo){

        if((comprobarFecha1(aux,in,out)==false)){chances--;}
        if((comprobarFecha2(aux,in,out)==false)){chances--;}
        if((comprobarFecha3(aux,in,out)==false)){chances--;}
        if((comprobarFecha4(aux,in,out)==false)){chances--;}
        if(chances==0)return false;

            }

        }


return true;

}


void mostrarHabLibres(){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos)==1){


    if(aux.getEstado()==true){
            aux.mostrar();
          }
          pos++;
  }

}


const char* asignarHabitacion(char tipo){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos)==1){

    if((aux.getEstado()==true)&&(aux.getTipo()==tipo)){
        aux.setEstado(false);
        aux.modificarEnDisco(pos);
        return aux.getNumero();
                }
        pos++;
        }


}

void mostrarHabOcupadas(){
Habitacion_ocupada aux;
int pos=0;
bool vacio=true;
while(aux.leerDeDisco(pos)==1){

    if(aux.getActiva()==true){
            vacio=false;
        aux.consultar();
    }
    pos++;
}
if(vacio==true){

    cout << "En este momento no hay habitaciones ocupadas."<< endl;
    pausa();
}

}

void mostrarHabEnLimpieza(){
Habitacion aux;
int pos=0;
int cont=0;
while(aux.leerDeDisco(pos)==1){


    if(aux.getLimpio()==false){
            aux.mostrar();
            cont++;
          }
          pos++;
  }
  if(cont==0){

        cout << "En este momento todas las habitaciones están limpias."<< endl;
        pausa();

  }

}
void mostrarHabEnMantenimiento(){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos)==1){


    if(aux.getMatenimiento()==true){
            aux.mostrar(); /// se deberia mostrar clase habitacion en mantenimiento
          }
          pos++;
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



void realizarCheckOut(){

Habitacion_ocupada aux;
char num[4];
cout << "Ingrese habitación: ";
limpiarBuffer();
cin.getline(num,4);
int pos=buscarHabitacionOcupada(num);
aux.leerDeDisco(pos);
if(aux.desocupar()){
    aux.modificarEnDisco(pos);

    cout << "Check out realizado con éxito"<< endl;
    pausa();
}
 else{
        cout << "No se realizo check out "<< endl;
        cout << "Cuenta pendiente de pago"<< endl;
        pausa();
    }
}


void nuevaVenta(){

Venta reg;
reg.cargar();
if(reg.escribirEnDisco()){

    cout << "Venta cargada con éxito"<< endl;
    pausa();
}
if (reg.getPago()==true){

    cout << "Cagar pago a caja del hotel"<< endl;
}


}

void mostrarVenta(){

Venta aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


    aux.mostrar();
    pausa();
}

}

/// SECTOR LIMPIEZA ///

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
    cout << "Ingrese el número de Habitación: ";
    limpiarBuffer();
    cin.getline(hab,4);
    pos = buscarHabitacion(hab); if(pos==-1){ cout << "no se encontro habitacion" << endl; pausa(); return ;}
    //FILE *p; p = fopen(FILE_HABITACIONES,"rb+");
    //if(p==NULL){ return ;}
    //fseek(p,sizeof aux*pos,0);
    //fread(&aux,sizeof aux,1,p);
    /*if(strcmpi(aux.get_limpiezaMantenimiento(),"En mantenimiento")==0){
        cout << "La habitacion se encuentra en Mantenimiento" << endl;
        pausa();
        fclose(p);
        return ;
    }*/ /// VERIFICA SI LA HABITACION ESTA EN MANTENIMIENTO /// PARA USARLO ANTES INGRESAR HABITACIONES EN MANTENIMIENTO
    aux.leerDeDisco(pos);
    aux.setLimpio(false);
    //fwrite(&aux,sizeof aux,1,p);
    if(aux.modificarEnDisco(pos)){
    cout << "Habitación "<< aux.getNumero();cout << " está ahora en limpieza."<< endl;
    pausa();
    }
    //fclose(p);

}

void mostrarHabitacionesEnLimpieza(){ /// muestra las habitaciones en limpieza actualmente ///
    FILE *p; p = fopen("habitaciones.dat","rb");
    if(p==NULL){ return ;}
    Habitacion aux;
    int cont=0;
    while(fread(&aux,sizeof aux,1,p)==1){
        if(aux.getLimpio()==false){
            aux.mostrar();
            pausa();
            cont ++;
        }
    }
    fclose(p);
    if(cont==0){

        cout << "En este momento todas las habitaciones están limpias."<< endl;
        pausa();
    }
}


void buscarHabitacionEnLimpieza(){ /// busca una habitacion , si esta en limpieza la muestra /// sino dice que esta limpia
    char hab[4];
    int pos;
    Habitacion aux;
    cout << "ingrese el numero de Habitacion: ";
    limpiarBuffer();
    cin.getline(hab,4);
    pos = buscarHabitacion(hab); if(pos==-1){ cout << "no se encontro habitacion" << endl; pausa(); return ;}
    FILE *p; p = fopen(FILE_HABITACIONES,"rb+");
    if(p==NULL){ return ;}
    //fseek(p,sizeof aux*pos,0);
    //fread(p,sizeof aux,1,p);
    aux.leerDeDisco(pos);
    if(aux.getLimpio()==false){
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



int menuLimpieza(){ /// MENU LIMPIEZA ///
    setlocale(LC_ALL,"spanish");
    int opcion;
    while(true){
    system("cls");
    cout << "ELIJA UNA CATEGORIA" <<endl;
    cout << "--------------" <<endl;
    cout << "1)Cargar habitacion para limpieza  " <<endl;
    cout << "2)Sacar habitación de limpieza     " <<endl;
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
 ///FIN SECTOR LIMPIEZA ///

 /// SECTOR MANTENIMIENTO ///

 class Habitacion_mantenimiento{
private:
    char numero[4];
    char tipo;
    bool estado;
    float gasto_total;
    int dias_estimado;
    char descripcion [500];
    char descripcion1[500];
    char descripcion2[500];
    char descripcion3[500];
public:
    void enviar_mantenimiento(); ///Carga una habitacion al sistema de mantenimiento
    void mostrar();
    ///GETS
    const char* getNumero(){return numero; }
    bool getEstado(){return estado;}
    float getGasto(){return gasto_total;}
    int getDias_en_mantenimiento(){return dias_estimado;}
    const char* getDescripcion(){return descripcion;}
    const char* getDescripcion1(){return descripcion1;}
    const char* getDescripcion2(){return descripcion2;}
    const char* getDescripcion3(){return descripcion3;}
    char getTipo(){return tipo;}

    /// SETS
    void setNumero(const char* nuevoNum){strcpy(numero,nuevoNum);}
    void setEstado(bool nuevoEstado){estado=nuevoEstado;}
    void setGasto(float nuevoTotal){gasto_total=nuevoTotal;}
    void setDiasEstimado(int diasNuevo ){dias_estimado=diasNuevo;}
    void setDescripcion(const char* descrip_){strcpy(descripcion,descrip_);}
    void setDescripcion1(const char* descrip1_){strcpy(descripcion1,descrip1_);}
    void setDescripcio2(const char* descrip2_){strcpy(descripcion2,descrip2_);}
    void setDescripcio3(const char* descrip3_){strcpy(descripcion3,descrip3_);}

    /// funciones con archivos
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);

};


int Habitacion_mantenimiento::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_MANTENIMIENTO,"rb");
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



bool Habitacion_mantenimiento::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_MANTENIMIENTO,"rb+");
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

bool Habitacion_mantenimiento::escribirEnDisco(){ /// graba un registro
FILE*P;
P=fopen(FILE_MANTENIMIENTO,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

int buscarHabMantenimiento(const char* numero){ ///devuelve la posicion de la en el archivo
	int pos=0;
	Habitacion_mantenimiento reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if(strcmp(numero,reg.getNumero())==0)
			return pos;
		pos++;
		}
	return -1;
}


void Habitacion_mantenimiento::enviar_mantenimiento(){

    /// cargar ///
    Habitacion aux;
    cout << "Numero de habitación que quiere ingresa a mantenimiento: ";
    limpiarBuffer();
    cin.getline(numero,4);
    while(!verifMantenimiento(numero)){
      borrarPantalla();
      cout << "Habitación "<< numero << " ya se encuentra en mantenimiento"<< endl;
      pausa();
      borrarPantalla();
      if(salir())return;
      cout << "Numero de habitación que quiere ingresa a mantenimiento: ";
      limpiarBuffer();
      cin.getline(numero,4);

    }
    int pos=buscarHabitacion(numero);
    aux.leerDeDisco(pos);
    tipo=aux.getTipo();
    estado=true;
    cout << "Descripcion o motivo: ";
    cin.getline(descripcion,500);
    cout << "Gasto total: ";
    cin  >> gasto_total;
    cout << "Dias estimados de reparación: ";
    cin  >> dias_estimado;
    aux.setMantenimietno(true);
    aux.modificarEnDisco(pos);

}

void Habitacion_mantenimiento::mostrar(){
cout << "Numero: "<< numero << endl;
cout << "Descipción: " << endl;
cout << "Nota 1" << endl;
if (!cadenaVacia(descripcion))
    cout << descripcion << endl;
    cout << endl;
    cout << "Nota 2 "<< endl;
if (!cadenaVacia(descripcion1))
    cout << descripcion << endl;
    cout << endl;
    cout << "Nota 3 "<< endl;
    if (!cadenaVacia(descripcion2))
    cout << descripcion << endl;
    cout << endl;
    cout << "Nota 4 "<< endl;
if (!cadenaVacia(descripcion3))
    cout << descripcion << endl;
    cout << endl;
    cout << "---------------------------"<< endl;
    cout << "Gasto total: $"<< gasto_total << endl;
    cout << "Dias de reparación " << dias_estimado << endl;
    cout << "---------------------------" << endl;
    pausa();

}

bool verifMantenimiento(const char *num){
Habitacion aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


    if (aux.getMatenimiento()==true)
        return false;

}
return true;

}

void cargarParaMantenimiento(){
Habitacion_mantenimiento reg;
reg.enviar_mantenimiento();
if(reg.escribirEnDisco()){

    cout << "Habitación ";cout << reg.getNumero(); cout << " enviada a mantenimiento "<< endl;
    pausa();
}
else {

    cout << "No se pude enviar habitación ";cout << reg.getNumero(); cout << " a mantenimiento "<< endl;
    pausa();
}


}

void sacar_de_mantenimiento(){
char hab[4];
Habitacion_mantenimiento aux;
Habitacion reg;
cout << "Número de habitación a habilitar"<< endl;
limpiarBuffer();
cin.getline(hab,4);
int posi=buscarHabitacion(hab);
int pos=buscarHabMantenimiento(hab);
if(pos==-1){

    cout << "Habitación "<< hab << " no se encuentra en mantenimiento "<< endl;
    pausa();
    return;
}
if(posi==-1){

    cout << "Habitación "<< hab << " no se encuentró"<< endl;
    pausa();
    return;

}
else {


    aux.leerDeDisco(pos);
    aux.setEstado(false);
    aux.modificarEnDisco(pos);

    reg.leerDeDisco(posi);
    reg.setMantenimietno(false);
    reg.modificarEnDisco(posi);
}

}

void copiarArchivoMemoriaMante(Habitacion_mantenimiento *v,int cant){
  FILE *P;
  P=fopen(FILE_MANTENIMIENTO,"rb");
  if(P==NULL){
      mensajes(1);
      return;
      }
    fread(v, sizeof(Habitacion_mantenimiento),cant,P);
  fclose(P);
  }

  void ordenarVectorMante(Habitacion_mantenimiento *v, int cant){
  int i, j, posmin;
  Habitacion_mantenimiento aux;
  for(i=0;i<cant-1;i++){


      posmin=i;
      for(j=i+1;j<cant;j++){
       if(strcmp(v[posmin].getNumero(),v[j].getNumero())>0)
                posmin=j;

      }
      aux=v[i];
      v[i]=v[posmin];
      v[posmin]=aux;


    }
}

void mostrarVectorMante(Habitacion_mantenimiento *v, int cant){
    int i;
    for(i=0; i<cant; i++){
        ///if(v[i].estado==true){
        v[i].mostrar();
        pausa();
        ///}
      }
}

int contarRegistrosMantenimiento(){
    FILE *F;
    F=fopen(FILE_MANTENIMIENTO,"rb");
    if(F==NULL){
        mensajes(1);
        pausa();
        return -1;
    }
    int tam,tamanioreg,cantidad;
    fseek (F,0,SEEK_END);
    tam=ftell(F);
    tamanioreg=sizeof(Cliente);
    cantidad=tam/tamanioreg;
    fclose(F);
    return cantidad;

}

void mostrarTodas_Mantenimiento(){

    int cant;
  cant=contarRegistrosMantenimiento();
  if(cant==0){
    char letra;
    cout << "Para visualizar habitaciones en mantenimiento debe cargar una primero"<<endl;
    cout << "Desea cargar una ahora?(s/n)";
    cin  >> letra;
    if (letra=='s'||letra=='S'){
            cargarParaMantenimiento();
            return;
    }
    else return;

    }
  Habitacion_mantenimiento *vec;
  ///vec=(Cliente*) malloc(cant*sizeof(Cliente));
  vec = new Habitacion_mantenimiento[cant];
  if(vec==NULL) return;

  copiarArchivoMemoriaMante(vec,cant);
  ordenarVectorMante(vec,cant);
  mostrarVectorMante(vec,cant);/// se muestra el vector ordenado
  borrarPantalla();
  delete vec;

}


void listarHabMantenimiento(){
char hab[4];
Habitacion_mantenimiento aux;
cout << "Ingrese número de habitación: ";
limpiarBuffer();
cin.getline(hab,4);
int pos=buscarHabMantenimiento(hab);
if(pos==-1){
    cout << "Habitación " << hab << " no está en mantenimiento"<< endl;
    pausa();
}
else {

    aux.leerDeDisco(pos);
    aux.mostrar();
}


}

void HabitacionesMantenimiento(){
short opcion;
while(true){
    system("cls");
    cout << "BUSQUEDA HABITACIONES EN MANTENIMIENTO" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1)Mostrar Habitaciones en mantenimiento"<< endl;/// mostrarlas ordenadas por numero
    cout << "2)Buscar habitación en mantenimiento   "<< endl;
    cout << "0) Salir "<< endl;
    cout << endl << "Opción: ";
    cin >> opcion;
    system("cls");
    switch(opcion){
      case 1:
    mostrarTodas_Mantenimiento();
      break;
      case 2:
    listarHabMantenimiento();
      break;
      case 0:
        return ;
      break;
      default:

      break;
    }
    cout << endl;

  }




}

void modificarMantenimiento(){


cout << "HoLa AúN EsToY En CoNsTrUcIón :P "<< endl;
pausa();


}

void historialMantenimiento(){
    short op;
short opcion;
while(true){
    system("cls");
    cout << "1)Mostrar todas"<< endl;
    cout << "2)Buscar "<< endl;
    cout << "0) Salir "<< endl;
    cout << endl << "Opción: ";
    cin >> opcion;
    system("cls");
    switch(opcion){
      case 1:
    mostrarHistorialMante();
      break;
      case 2:
    buscarEnHistorialMante();
      break;
      case 0:
        return 0;
      break;
      default:
      mensajes(1);
      break;
    }
    cout << endl;

  }

}

void mostrarHistorialMante(){
Habitacion_mantenimiento aux;
int pos=0;
while(aux.leerDeDisco(pos++)==1){


    if(aux.getEstado()==false){

        aux.mostrar();
    }

}

}

void buscarEnHistorialMante(){
Habitacion_mantenimiento aux;
char num[4];
cout << "Ingrese número de habitación: ";
limpiarBuffer();
cin.getline(num,4);
int pos=0;
int cant=0;
while(aux.leerDeDisco(pos++)==1){

    if ((strcmp(num,aux.getNumero())==0)&&(aux.getEstado()==false)){
        cant++;
        aux.mostrar();
        }
}
if (cant==0){
    printf("No se encontró registros de la habitación en el archivo\n");
    pausa();
}


}

 int sectorMantenimiento(){
 short opcion;
 cout << "En mantenimiento"<< endl;
 pausa();
 return 0;
 while(true){
     borrarPantalla();
     cout << "\t\t ----LIMPIEZA----" << endl;
     cout << "\t\t ----------------" << endl;
     cout << "\t\t1) Cargar habitación para mantenimiento      " << endl;
     cout << "\t\t2) Sacar habitación de mantenimiento         "  << endl;
     cout << "\t\t3) Ver historial de habitaciones en mantenimiento" << endl; /// muestra los registros que ya estan en false ///
     cout << "\t\t4) Ver habitaciones en mantenimiento         " << endl; /// muestra todas juntas o una por numero ///
     cout << "\t\t5) Modificar habitacion en mantenimiento     " << endl; /// modifica lo que se lleva gastado, se agrega una descripcion mas
     cout << "\t\t0) Salir "<< endl;
     cout << endl << "Opción: ";
     cin >> opcion;
     borrarPantalla();
     switch(opcion){
       case 1:
    cargarParaMantenimiento();
       break;
       case 2:
    sacar_de_mantenimiento();
       break;
       case 3:
        historialMantenimiento();
       break;
       case 4:
    HabitacionesMantenimiento();
        break;

       case 0:
       case 5:
        modificarMantenimiento();
        break;
         return 0;
       break;
       default:
           mensajes(1);
        break;
     }
     cout << endl;

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
        cout << "\t\t4) VER HABITACIONES "<< endl; ///LIBRES , OCUPADAS, EN LIMPIEZA, TODAS
        cout << "\t\t5) VENTA DE PRODUCTOS            " << endl;///Cargar modificar y eliminar gastos,
        cout << "\t\t6) MANTENIMIENTO HABITACIÓN (mostrar ventas) " << endl; /// PONE Y SACA UNA HABITACION DE MANTENIMIENTO
        cout << "\t\t7) LIMPIEZA HABITACIÓN      " << endl; /// PONE Y SACA UNA HABITACION DE LIMPIEZA
        cout << "\t\t0) Salir "<< endl;
        cout << endl << "\t\tOpción: ";
        cin >> opcion;
        borrarPantalla();
        switch(opcion){
          case 1:
        cargarEstadia();
          break;
          case 2:
       menuRecepcion();
          break;
          case 3:
       realizarCheckOut();
          break;
          case 4:
            mostrarHabitaciones();
          break;
          case 5:
         nuevaVenta();

          break;
          case 6:
              mostrarVenta(); /// desp esto va en la factura dentro del check out
              cout << "En contruccion..."<<endl;
                pausa();
            break;
          case 7:
          menuLimpieza();
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

