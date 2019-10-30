#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED


#include "misfunciones.h"
#include "menuPrincipal.h"
const char *FILE_PRODUCTOS = "productos.dat";

int menuProductos();
void nuevoProducto();
void bajarProducto();
void mostrarProductos();
void sumarStock();


class Producto{
    private:
        char id[5];
        char nombre[30];
        char descripcion[100];
        float precioUnidad;
        int stock;
        bool estado;

    public:

        void cargar();
        void mostrar();
        ///GETS
        const char* getId(){return id;}
        const char* getNombre(){return nombre;}
        const char* getDescripcion(){return descripcion;}
        float getPrecio(){return precioUnidad;}
        bool getEstado(){return estado;}
        int getStock(){return stock;}
        ///SETS
        void setId(const char*);
        void setNombre(const char*);
        void setDescripcion(const char*);
        void setPrecio(float);
        void setEstado(bool);
        void setStock(int);
        /// funciones con archivos
        bool escribirEnDisco();
		int leerDeDisco(int);
		bool modificarEnDisco(int);


};

int Producto::leerDeDisco(int pos) /// lee el disco hasta encontrar el registro
	{
	int x;
	FILE *p;
	p=fopen(FILE_PRODUCTOS,"rb");
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



bool Producto::modificarEnDisco(int pos){ /// graba una modificacion
	FILE *p;
	p=fopen(FILE_PRODUCTOS,"rb+");
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

bool Producto::escribirEnDisco(){ /// graba un registro de reservas
FILE*P;
P=fopen(FILE_PRODUCTOS,"ab");
if(P==NULL){
        fclose(P);
        return false;
}
fwrite(this,sizeof(*this),1,P);
fclose(P);
return true;
}

int buscarProducto(char* id){ ///devuelve la posicion de la reserva en el archivo
	int pos=0;
	Producto reg;
	while(reg.leerDeDisco(pos)==1)
		{
		if((strcmp(id,reg.getId())==0)&& reg.getEstado()==true)
			return pos;
		pos++;
		}
	return -1;
}

///SETS
void Producto::setId(const char*codigo){
    strcpy(id,codigo);
}
void Producto::setNombre(const char*nuevoNom){
        strcpy(nombre,nuevoNom);
}
void Producto::setDescripcion(const char*nuevaDesc){
    strcpy(descripcion,nuevaDesc);
}
void Producto::setPrecio(float nuevoPrecio){
precioUnidad=nuevoPrecio;
}
void Producto::setEstado(bool variable){
estado=variable;
}
void Producto::setStock(int nuevoStock){

stock=nuevoStock;
}
/// FIN SETS PRODCUTO
void Producto::cargar(){
cout << "Codigo de producto: ";
limpiarBuffer();
cin.getline(id,5);
cout << "Noubre del producto: ";
limpiarBuffer();
cin.getline(nombre,30);
cout << "Descripcion: ";
limpiarBuffer();
cin.getline(descripcion,100);
cout << "Precio unitario: ";
cin  >> precioUnidad;
cout << "Stock inicial: ";
cin  >> stock;
estado=true;

}

void Producto::mostrar(){

cout << "Codigo de producto:  "<< id << endl;
cout << "Nombre del producto: "<< nombre << endl;
cout << "Descripción:         "<< descripcion <<endl;
cout << "Precio unitario:    $"<< precioUnidad<<endl;
cout << "Stock actual:        "<< stock << endl;
cout << "----------------------"<< endl;
pausa();

}

void nuevoProducto(){
Producto reg;
reg.cargar();
if(reg.escribirEnDisco()){
        cout << "PRODUCTO CARGADO CON ÉXITO!"<< endl;
        pausa();
}

}
void bajarProducto(){
Producto reg;
char ide[5];
cout << "Ingrese ID de producto: "<< endl;
limpiarBuffer();
cin.getline(ide,5);
int pos=buscarProducto(ide);
if(pos==-1){

    cout << "El producto no esta registrado o fue dado de baja"<< endl;
    pausa();
    return;
}
else{


    reg.leerDeDisco(pos);
    reg.setEstado(false);
    if(reg.modificarEnDisco(pos)){

        cout << "Producto dado de baja con éxito"<< endl;
        pausa();
        return;
    }

}



}




void mostrarProductos(){
Producto aux;
int pos=0;
while(aux.leerDeDisco(pos++)==true){

    if(aux.getEstado()==true){
            aux.mostrar();
            cout << endl;
    }
}

}

void sumarStock(){

Producto aux;
char cod[5];
int cant;
cout << "Ingrese el ID del producto y el stock que ingresa"<< endl;
cout << "ID: ";
limpiarBuffer();
cin.getline(cod,5);
cout << "Stock ingresante: ";
cin  >> cant;
int pos=buscarProducto(cod);
if(pos==-1){

    cout << "El producto no esta registrado o fue dado de baja"<< endl;
    pausa();
    return;
}
else{


    aux.leerDeDisco(pos);
    int stockNuevo=aux.getStock()+cant;
    aux.setStock(stockNuevo);
    if(aux.modificarEnDisco(pos)){

        cout << "Se agrego stock a producto con éxito"<< endl;
        pausa();
        return;
    }

}

}

int menuProductos(){
short opcion;
while(true){
    borrarPantalla();
    cout << "\t\t-------MENÚ PRODUCTOS-------- " << endl;
    cout << "\t\t----------------------------- " << endl;
    cout << "\t\t1) AÑADIR PRODUCTOS           " << endl;
    cout << "\t\t2) DAR DE BAJA PRODUCTOS      " << endl;
    cout << "\t\t3) AÑADIR STOCK A PRODUCTOS   " << endl;
    cout << "\t\t4) MOSTRAR TODOS LOS PRODUCTOS" << endl;
    cout << "\t\t5) PUNTO DE VENTA." << endl;
    cout << "\t\t0) Salir "<< endl;
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case 1:
    nuevoProducto();
      break;
      case 2:
    bajarProducto();
      break;
      case 3:
    sumarStock();
      break;
      case 4:
    mostrarProductos();
        break;

      case 0:
        return 0;
      break;
    }
    cout << endl;

  }

}




#endif // PRODUCTOS_H_INCLUDED
