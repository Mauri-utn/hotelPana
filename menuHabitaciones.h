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

const char *FILE_TIPO_HABITACION = "tipo_habitacion.dat";


using namespace std;
#include "misFunciones.h"
#include "recepcion.h"
#include "menuReservas.h"
int menuHabitaciones();



/*class Archivos
{
private:
    FILE *p;
    string arch_usar;
    char tipo[4];
public:
    abrir_archivo(string a,string b)
    {
     p=fopen(a,b);
     if(p==NULL)
        {
            cout<<"Error al abrir el archivo";
            return 0;
        }
     }
};*/

class FechaSistema
{
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
class Tipo_habitacion
{
private:
    int cod_tipo;
    char nombre[30];
    float costo;
    char adultos;
    char ninios;
    char vista[50];
    char tecnologias[50];
    char camas[50];
    bool estado;
    bool limpio;



public:
    void cargar();
    void mostrar_todo();

    void get_nombre(int c, char v[30]);/// desp explicame que hacen ambas pana
    float get_costo(int c);

   /// get nombre mauri
   const char* getNombre(){return nombre;}

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

class Habitacion
{
protected:
    char habitacion[4],estado;
    int id,tipo;
public:
    void cargar_habitacion();
    void mostrar_habitacion();
    void mostrar_habitacion_tipo(int t);
    void mostrar_habitacion_estado(char e);
};

class Habitacion_ocupada:public Habitacion
{
private:
    char nom_cliente[50],ape_cliente[50];
    char tarj_cliente[17],cod_tarjeta[5],venc_tarjeta[5],dni_cliente[9],serv_contratado[6],hora_limpieza[5],medio_pago;
    bool reserva;
    int tel_cliente;
    float cuenta,pago_adelantado;
    FechaSistema fec_salida,fec_ingreso;
    // Archivos arc;
public:
    void ocupar(); ///Ocupa una habitacion y carga los datos
    void desocupar(); ///Libera una habitacion
    void consultar(); ///Consulta los datos de la habitacion seleccionada
    void consulta_fecha(); ///Consulta los datos de la habitacion entre 2 fechas
};
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

void Gasto::cargar()
{
    FILE *g;
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

void Gasto::consulta_habitacion()
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

void Gasto::consulta_habitacion_fecha()
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


void Gasto::anular()
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

void Habitacion::cargar_habitacion()
{
  FILE *h;
    h=fopen("habitaciones.dat","ab");
    if(h==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    fseek(h,0,2);
    id=((ftell(h)/sizeof(*this))+1);
    cout<<"Ingrese el numero de la habitacion: ";
    cin>>habitacion;
    cout<<"Ingrese tipo de habitacion: ";
    cin>>tipo;
    estado='0';
    fwrite(this,sizeof(*this),1,h);
    fclose(h);
}
void Tipo_habitacion::cargar()
{
  FILE *t;
  int c;
  bool nome;
  char nom[30];
  Tipo_habitacion p;
    t=fopen("tipo_habitacion.dat","ab+");
    if(t==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    fseek(t,0,2);
    cod_tipo=((ftell(t)/sizeof(*this))+1);
    while(true)
    {
    cout<<"Ingrese el nombre del tipo: ";
    limpiarBuffer();
    cin.getline(nombre,30);
    strcpy(nom,nombre);
    nome=false;
    fseek(t,0,0);
    c=1;
    while(fread(this,sizeof(*this),1,t)==1)
    {
        c++;

        if(nombre==nom)
        {
            cout<<"Tipo de habitacion ya ingresada"<<endl;
            nome=true;
            cout<<nombre<<endl;
            cout<<nom<<endl;
            break;
        }
        cout<<nome;
    }
    if(nome==false)
    {
        break;
    }
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
    cin.getline(camas,50);
    cout << "Ingrese tecnologías disponibles: ";
    limpiarBuffer();
    cin.getline(tecnologias,50);
    cout << "Ingrese vistas desde a habitación: ";
    limpiarBuffer();
    cin.getline(vista,50);
    estado=true;
    limpio=true;
    fwrite(this,sizeof(*this),1,t);
    fclose(t);

}
void Tipo_habitacion::mostrar_todo()
{
   FILE *t;
    t=fopen("tipo_habitacion.dat","rb");
    if(t==NULL)
    {
        cout<<"Fallo al abrir el archivo";
        return;
    }
    while(fread(this,sizeof(*this),1,t)==1)
    {

        cout <<"\t\tCodigo de tipo: "<<cod_tipo<<endl;
        cout <<"\t\tNombre: "<<nombre<<endl;
        cout <<"\t\tcosto: "<<costo<<endl;
        cout <<"\t\tCapacidad máxima: "<< adultos << " Adulto/s + "<< ninios << " niño/s"<< endl;
        cout <<"\t\tCARACTERISTICAS: "<< endl;
        cout <<"\t\t*"<<camas << endl;
        cout <<"\t\t*"<<tecnologias << endl;
        cout <<"\t\t*"<<vista << endl;
        if(limpio==true){
                cout << "\t\tLimpio:";
                system("color 2");
                cout <<"\t\t*"<<endl;
        }
        else{
            cout << "\t\tLimpio:";
            system("color 1");
            cout <<"\t\t*"<<endl;

        }
        if(estado==true){
            cout << "\t\tEstado:";
            system("color 2");
            cout <<"DISPONIBLE"<<endl;
        }
        else{

           cout << "\t\tEstado:";
            system("color 1");
            cout <<"OCUPADO"<<endl;

        }
        cout<<"\t\t---------------------------"<<endl;
        pausa();

    }
    fclose(t);
}

/// cuanta las habitacion del tipo que le mandes
int contarHabitacionesTipo(char tipo){
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
        cout<<"ID: "<<id<<endl;
        cout<<"Habitacion: "<<habitacion<<endl;
        cout<<"Tipo: "<<nom<<endl;
        cout<<"Costo: $"<<t.get_costo(tipo)<<endl;
        cout<<"Estado: "<<estado<<endl;
        cout<<"-------------------------------"<<endl;

    }
    fclose(h);
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
        cout<<"ID: "<<id<<endl;
        cout<<"Habitacion: "<<habitacion<<endl;
        cout<<"Tipo: "<<nom<<endl;
        cout<<"Costo: $"<<t.get_costo(tipo)<<endl;
        cout<<"Estado: "<<estado<<endl;
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
        cout<<"Habitacion: "<<habitacion<<endl;
        cout<<"Tipo: "<<nom<<endl;
        cout<<"Costo: $"<<t.get_costo(tipo)<<endl;
        cout<<"Estado: "<<estado<<endl;
        cout<<"-------------------------------"<<endl;
        }
    }
    fclose(h);
}
/// FUNCIONES

void nuevaHabitacion();
void consultarHabitaciones();

void nuevaHabitacion(){

Tipo_habitacion reg;
reg.cargar();
pausa();
cout << "prueba finalizada "<< endl;
pausa();



}

void consultarHabitaciones(){
Tipo_habitacion reg;
reg.mostrar_todo();
pausa();
cout << "prueba finalizada "<< endl;
pausa();



}


int menuHabitaciones()
{

    short opcion;
    while(true){
        borrarPantalla();
        cout << "\t\tMENÚ HABITACIONES    " << endl;
        cout << "\t\t-------------------- " << endl;
        cout << "\t\t1) CREAR NUEVA HABITACIÓN       " << endl; /// crea una nueva habitacion
        cout << "\t\t2) MOSTRAR HABITACIONES CREADAS (esto desp se va)" << endl; /// consulta habitaciones disponibles
        /// si hay habitacion disponible cargar el cliente y le asigna la habitacion seleccionada
        /// sin necesidad de que haya reservado
        cout << "\t\t2) CONSULTAR HABITACIONES"<< endl;
        cout << "\t\t3) GASTOS            " << endl;///Cargar modificar y eliminar gastos,
        cout << "\t\t4) CARGAR HABITACION PARA MANTENIMIENTO" << endl;
        cout << "\t\t5) RECEPCIÓN          "<< endl;
        cout << "\t\t6) CHECK OUT          "<< endl;
        cout << "\t\t0) Salir "<< endl;
        cout << endl << "\t\tOpción: ";
        cin >> opcion;
        borrarPantalla();
        switch(opcion){
          case 1:
       nuevaHabitacion();
          break;
          case 2:
        consultarHabitaciones();
          break;
          case 3:
            cout << "En contruccion..."<<endl;
        pausa();
          break;
          case 4:
            cout << "En contruccion..."<<endl;
        pausa();
          break;
          case 5:
           menuRecepcion();
          break;
          case 0:
            return 0;
          break;
        }
        cout << endl;

      }
}


#endif // MENUHABITACIONES_H_INCLUDED
