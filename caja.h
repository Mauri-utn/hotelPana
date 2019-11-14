#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
#include "menuHabitaciones.h"

void abrirCaja();
void cerrarCaja();
void mostrarCaja();


class Caja{
    private:
        int estadoCaja;
        float aperturaCaja;
        float sumaCaja;
        float cierreCaja;
        int codigoCaja;
    public:

        /// GETS
        int getEstadoCaja(){ return estadoCaja;}
        float getAperturaCaja(){ return aperturaCaja;}
        float getSumaCaja(){ return sumaCaja;}
        float getCierreCaja(){ return cierreCaja;}
        int getCodigoCaja(){ return codigoCaja;}
        /// SETS
        void setEstadoCaja(int e){estadoCaja=e;}
        void setAperturaCaja(float a){aperturaCaja=a;}
        void setSumaCaja(float s){sumaCaja=s;}
        void setCierreCaja(float c){cierreCaja=c;}
        void setCodigoCaja(int c){codigoCaja=c;}

        void mostrar();
        bool EscribirEnDisco(void);
        bool LeerDeDisco(int);
        void EscribirPosicionEnDisco(int);


};

int menuCaja(){

short opcion;
while(true){
    borrarPantalla();
    cout << "\t\t-------MENÚ REPORTES--------  " << endl;
    cout << "\t\t----------------------------- " << endl;
    cout << "\t\t1) ABRIR CAJA             " << endl;
    cout << "\t\t2) CERRAR CAJA            " << endl;
    cout << "\t\t3) MOSTRAR CAJA              " << endl;
    cout << "\t\t0) Salir "<< endl;
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case 1:
          abrirCaja();
      break;
      case 2:
          cerrarCaja();
      break;
      case 3:
          mostrarCaja();
      break;
      case 4:
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
    }
}


void Caja::mostrar(){
    cout << "Codigo de Caja: " << codigoCaja << endl;
    cout << "Dinero de apertura de caja: " << aperturaCaja << endl;
    cout << "Dinero de cierre de caja: " << cierreCaja << endl;
    cout << "estado caja " << estadoCaja << endl;
    cout << endl;
    pausa();
}

void Caja::EscribirPosicionEnDisco(int pos){
  FILE *p;
  p=fopen("caja.dat","rb+");
      if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        system("pause");
        return;
      }
  fseek(p, sizeof *this*pos, 0);
  fwrite(this, sizeof *this, 1, p);
  fclose(p);
}

bool Caja::EscribirEnDisco(){
    FILE *p;
    p = fopen("caja.dat","ab");
    if(p==NULL){return false;}
    fwrite(this,sizeof *this,1,p);
    fclose(p);
}

bool Caja::LeerDeDisco(int posicion){
    FILE *p;
    p = fopen("caja.dat","rb+");
    if(p==NULL){ return false;}
    fseek(p,sizeof *this*posicion,0);

    bool leyo=fread(this,sizeof *this,1,p);
    fclose(p);
    return leyo;
}

int comprobarEstadoCaja(){
    Caja aux;
    int pos=0;
    while(aux.LeerDeDisco(pos++)){
        if(aux.getEstadoCaja()==1){
            return -1;
        }
    }
}
int buscarIdCaja(){
    Caja reg;
    int aux;
    FILE *p;
    p = fopen("caja.dat","rb");
    if(p==NULL){ return false;}
    fseek(p,0,2);
    aux = (ftell(p)/sizeof reg)+1;
    fclose(p);
    system("pause");
    return aux;
}

int contarRegistrosCaja(){
    Caja reg;
    int pos=0;
    while(reg.LeerDeDisco(pos)){
        pos++;
    }
    pausa();
    return pos-1;
}

void abrirCaja(){
    Caja aux;
    int estado;
    estado = comprobarEstadoCaja();
    if(estado==-1){cout << "Ya hay una caja activa" << endl; pausa(); return ;}
    float monto;
    cout << "Ingrese el monto con el que va a abrir la caja" << endl;
    cin >> monto;
    aux.setEstadoCaja(1);
    aux.setAperturaCaja(monto);
    aux.setCierreCaja(0);
    aux.setCodigoCaja(buscarIdCaja());
    aux.EscribirEnDisco();
    return ;
}

float CierreCaja(){
    Caja aux;
    float aux2;
    aux2 = aux.getSumaCaja();
    cout << "VALOR DE CIERRE DE CAJA " << endl;
    system("pause");

    return aux2;
}

void cerrarCaja(){
    char opcion[5];
    cout << "DESEA CERRAR LA CAJA?" << endl;
    cin >> opcion;
    if(strcmpi(opcion,"No")==0){
        cout << "ingreso la opcion NO" << endl; pausa();
        return ;
    }
    else{
        int pos = contarRegistrosCaja();
        cout << "pos " << pos;
        pausa();
        Caja aux;
        aux.LeerDeDisco(pos);
        aux.setCierreCaja(CierreCaja());
        aux.setEstadoCaja(0);
        aux.EscribirPosicionEnDisco(pos);
    }
}

void mostrarCaja(){
    Caja aux;
    int i=0;
    while(aux.LeerDeDisco(i++)){
        aux.mostrar();
    }
}

#endif // CAJA_H_INCLUDED
