#ifndef CHECKOUT_H_INCLUDED
#define CHECKOUT_H_INCLUDED

int menuCheckOut();




int menuCheckOut(){

    borrarPantalla();

    char habitacion_[4];
    cout << "\t\t-----REALIZAR CHECK OUT-------" << endl;
    cout << "\t\t------------------------------" << endl;
    cout << "Ingrese habitación: ";
    limpiarBuffer();
    cin.getline(habitacion_,4);


    cout << "realizando check out habitacion "<< habitacion_ << endl;
    pausa();

}





#endif // CHECKOUT_H_INCLUDED
