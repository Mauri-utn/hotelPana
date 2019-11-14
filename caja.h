#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED

void abrirCaja();
void cerrarCaja();

///relacionar con reporte diarion mensual y anual
/// para facturar siempre tiene que haber una caja abierta
/// agregar "menu" agresos para realizar y se resten de lo que tiene la caja abierta al momento del egreso



class Caja{ /// relacionar con venta sumandole las que van pagando, el pago anticipado , y el check out
    private:
        bool estadoCaja;
        float aperturaCaja;
        float cierreCaja;
        int codigoCaja;
    public:
        /// GETS
        bool getEstadoCaja(){ return estadoCaja;}
        float getAperturaCaja(){ return aperturaCaja;}
        float getCierreCaja(){ return cierreCaja;}
        int getCodigoCaja(){ return codigoCaja;}
        /// SETS
        void setEstadoCaja(bool e){estadoCaja=e;}
        void setAperturaCaja(float a){aperturaCaja=a;}
        void setCierreCaja(float c){cierreCaja=c;}
        void setCodigoCaja(int c){estadoCaja=c;}

        bool EscribirEnDisco(void);
        bool LeerDeDisco(int);

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
        pausa();
      break;
      case 2:
          cerrarCaja();
        pausa();
      break;
      case 3:
          cout << "En contruccion..."<<endl;
        pausa();
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

bool Caja::EscribirEnDisco(){
    FILE *p;
    p = fopen("caja,dat","ab");
    if(p==NULL){return false;}
    fwrite(this,sizeof (Empleados),1,p);
    fclose(p);
}

bool Caja::LeerDeDisco(int posicion){
    FILE *p;
    p = fopen("caja.dat","rb");
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
        if(aux.getEstadoCaja()==true){
            return -1;
        }
    }
}
int buscarIdCaja(){
    Caja reg;
    int aux;
    FILE *p;
    p = fopen("","rb");
    if(p==NULL){ return false;}
    fseek(p,0,2);
    aux = (ftell(p)/sizeof reg)+1;
    fclose(p);
    return aux;
}

void abrirCaja(){
    int estado;
    estado = comprobarEstadoCaja();
    if(estado==-1){cout << "Ya hay una caja activa" << endl; return ;}
    Caja aux;
    float monto;
    cout << "Ingrese el monto con el que va a abrir la caja" << endl;
    cin >> monto;
    aux.setEstadoCaja(true);
    aux.setAperturaCaja(monto);
    aux.setCierreCaja(0);
    aux.setCodigoCaja(buscarIdCaja());
}

void cerrarCaja(){
    Caja aux;
    char opcion[5];
    cout << "DESEA CERRAR LA CAJA?" << endl;
    if(strcmpi(opcion,"No")){
        return ;
    }
    else{
        aux.setCierreCaja(2000);
        aux.EscribirEnDisco();
    }
}

#endif // CAJA_H_INCLUDED

