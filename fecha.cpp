#include <iostream>
#include <stdio.h>
#include<cstdlib>

using namespace std;
class fecha
{
private:
    int anio,mes,dia;
public:
    int get_anio()
    {
        return anio;
    }
    int get_mes()
    {
        return mes;
    }
    int get_dia()
    {
        return dia;
    }
    void set_anio(int a)
    {
        anio=a;
    }
     void set_mes(int m)
    {
        mes=m;
    }
     void set_dia(int d)
    {
        dia=d;
    }
    void cargar_fecha()
    {
        cout<<("Ingrese el dia: ");
        cin>>dia;
        cout<<("Ingrese el mes: ");
        cin>>mes;
        cout<<("Ingrese el anio: ");
        cin>>anio;
    }
};

int cd(fecha fi,fecha ff)
{
    int dias=0, dm;
    int da=fi.get_dia(), ma=fi.get_mes(), aa=fi.get_anio();
    while(true)
    {
        switch(ma)
        {
        case 4:
        case 6:
        case 9:
        case 11:
            dias+=(31-da);
            dm=31;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            dias+=(32-da);
            dm=32;
            break;
        case 2:
            if(aa%400==0||(aa%4==0 && aa%100!=0))
            {
                dias+=(30-da);
                dm=30;
            }
            else
            {
                dias+=(29-da);
                dm=29;
            }
            break;
        }
        if(ma==ff.get_mes() && ff.get_anio()==aa)
        {
            return(dias-(dm-ff.get_dia()));
        }
        if(ma==12)
        {
            ma=1;
            aa++;
        }else{ma++;}
        da=1;
    }
}
int main()
{
    fecha fi,ff;
    cout<<("Ingrese la fecha de inicio:")<<endl;
    fi.cargar_fecha();
    cout<<("Ingrese la fecha de fin:")<<endl;
    ff.cargar_fecha();
    cout<<"La cantidad de dias entre las dos fechas es de: "<<cd(fi,ff)<<" dias";
}
