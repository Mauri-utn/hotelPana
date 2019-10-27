#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <time.h>
#include <clocale>
#include <conio.h>
using namespace std;
#include "menuPrincipal.h"
#include "menuClientes.h"
#include "misFunciones.h"
#include "menuHabitaciones.h"
#include "login_pass.h"
#include "menuReservas.h"



///PROTOTIPO DE FUNCIONES
void abrirArchivos();
void cClientes();
void cHabitaciones();
void cEmpleados();
void cMenores();
void cConsumos();
void cGastos();
void cReservas();
bool validarLogin(string);
bool validarContrasenia(string);
int ingresar();
    /// ARCHIVOS
    ///const char *FILE_LOGIN = "usuarios.dat"; LOS LOGIN Y CONTRA SE AGREGARAN A LA CLASE EMPLEADOS PARA DIFERENCIARLOS


    const char *FILE_EMPLEADOS    = "empleados.dat";
    const char *FILE_CONSUMOS     = "consumos.dat";
    const char *FILE_RESERVAS     = "reservas.dat";
    const char Usuario[6] = "admin";
    const char contrasenia[5] = "7705";

void abrirArchivos(){


 cClientes();
 cHabitaciones();
 cEmpleados();
 cMenores();
 cConsumos();
 cGastos();
 cReservas();
}
void cClientes(){
    FILE*C;
    C=fopen(FILE_CLIENTES,"ab");
    if(C==NULL)return;
    fclose(C);
    return;
}
void cHabitaciones(){
    FILE*H;
    H=fopen(FILE_HABITACIONES,"ab");
    if(H==NULL)return;
    fclose(H);
    return;
}
void cEmpleados(){
    FILE*E;
    E=fopen(FILE_EMPLEADOS,"ab");
    if(E==NULL)return;
    fclose(E);
    return;
}
void cMenores(){
    FILE*M;
    M=fopen(FILE_MENORES,"ab");
    if(M==NULL)return;
    fclose(M);
    return;
}
void cConsumos(){
    FILE*C;
    C=fopen(FILE_CONSUMOS,"ab");
    if(C==NULL)return;
    fclose(C);
    return;
}
void cGastos(){

    FILE*G;
    G=fopen(FILE_GASTOS,"ab");
    if(G==NULL)return;
    fclose(G);
    return;
}
void cReservas(){

    FILE*R;
    R=fopen(FILE_RESERVAS,"ab");
    if(R==NULL)return;
    fclose(R);
    return;

}


/*class Login{
private:
    char login[20];
    char contrasenia[20];
public:
    void cargar();
    void mostrar();
    ///GETS()
    const char* getLogin(){return login;}
    const char* getContrasenia (){return contrasenia;}
    ///SETS
    void setLogin(char*);
    void setContrasenia(char*);

};*/


int main(){
abrirArchivos();
setlocale (LC_ALL, "spanish");
int login;
char cerrar[2];
 while(true){
    borrarPantalla();
    char opc;
    cout << "\t\t1)INGRESAR                     --->"<<endl;
    cout << "\t\t2)SALIR                        --->"<<endl;
    cout << "\t\t3)RECUPERAR CONTRASEÑA         --->"<<endl;
    cout << "\t\t4)CAMBIAR CONTRASEÑA           --->"<<endl;
    cout << "\t\tOPCIÓN: ";
    cin  >> opc;
    switch(opc){
      case '1':
      case 'a':
      case 'A':

    login=ingresar();
    if(login>=1)menuPrincipal(login);

            break;

      case '2':
      case 'b':
      case 'B':
            cout << "\t\t¿Seguro que quiere cerrar el programa?"<< endl;
            cout << "\t\tsi-no: ";
            cin  >>  cerrar;
            if (strcmp(cerrar,"si")==0){
                return 0;
            }
        break;

      case '3':
      case 'c':
      case 'C':
          menuLogins(opc);
        break;
      case '4':
      case 'd':
      case 'D':
          menuLogins(opc);
        break;
      default:
        break;
    }

 }

pausa();
return 0;
}

int ingresar(){
char user[20];
char pass[20];
int contador = 0;
bool ingresa=false;
do {
borrarPantalla();
if(contador==0){
    cin.ignore();
}
 string user,pass;
cout << "\t\t\tLOGIN DE USUARIO"<<endl;
cout << "\t\t\t-----------------"<<endl;
cout << "\n\tUsuario: ";
getline(cin,user);
cout << "\tContraseña: ";
//getline(cin,pass);
char caracter;
caracter = getch();
pass = "";
while (caracter!=13){
        if (caracter != 8){
     pass.push_back(caracter);
    cout << "*";
        }
        else{

            if(pass.length() > 0){
                cout << "\b \b";
                pass = pass.substr(0,pass.length() - 1);
            }
        }

    caracter = getch();

}

if ((Usuario==user)&&(contrasenia==pass)||(validarContrasenia(pass))&&(validarLogin(user))){

    ingresa = true;
}
else{

    cout << "\n\tEl usuario y/o password son incorrectos "<< endl;
    pausa();
    contador ++;
}


} while( ingresa==false && contador < 3 ); /// FIN DO WHILE

if ( ingresa==false ){

    cout << "\n\tUsted no pudo ingresar al sistema "<< endl;
    pausa();

    }
else {

    cout << "\n\tBienvenido al sistema "<<endl;
    pausa();
    return 1;
}

}

bool validarContrasenia(string pasw){
/*FILE *P;
P=fopen(FILE_EMPLEADOS,"rb");
if(P==NULL)return false;
Empleado aux;
while(fread(&aux,sizeof(Empleado),1,P)==1){
    if(pasw==aux.getContra())
        fclose(P);
    return true;

}
fclose(P);*/
return true;

}

bool validarLogin(string log){
/*FILE *P;
P=fopen(FILE_EMPLEADOS,"rb");
if(P==NULL)return false;
Empleado aux;
while(fread(&aux,sizeof(Empleado),1,P)==1){
    if(log==aux.getLegajo())
        fclose(P);
    return true;

}
fclose(P);*/
return true;



}
