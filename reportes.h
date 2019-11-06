

#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


int menuReportes();


int menuReportes(){

short opcion;
while(true){
    borrarPantalla();
    cout << "\t\t-------MENÚ REPORTES--------  " << endl;
    cout << "\t\t----------------------------- " << endl;
    cout << "\t\t1) REPORTE DIARIO             " << endl;
    cout << "\t\t2) REPORTE MENSUAL            " << endl;
    cout << "\t\t3) REPORTE ANUAL              " << endl;
    cout << "\t\t4) REPOTE POR FECHA           " << endl;
    cout << "\t\t0) Salir "<< endl;
    cin >> opcion;
    borrarPantalla();
    switch(opcion){
      case 1:
          cout << "En contruccion..."<<endl;
        pausa();
      break;
      case 2:
          cout << "En contruccion..."<<endl;
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


#endif // REPORTES_H_INCLUDED


