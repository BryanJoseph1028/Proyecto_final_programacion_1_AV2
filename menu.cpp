
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main(){
        char pp;

    do {
        system("cls");
        system("cls");
        system("cls");
        system("color 7E");
        printf("\n\n\n\n\n\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n\t\t\t²          MENU          ²");
        printf("\n\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");
        printf("\t\t    ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
        printf("\t\t    ²²  1. ADIMISTRAR MARCAS          ²²\n");
        printf("\t\t    ²²  2. ADMINISTRAR PRODUCTOS      ²²\n");
        printf("\t\t    ²²  3. IMPRIMIR CODIGO DE BARRAS  ²²\n");
        printf("\t\t    ²²  4. GENERAR FACTURA            ²²\n");
        printf("\t\t    ²²                                ²²\n");
        printf("\t\t    ²²                                ²²\n");
        printf("\t\t    ²²  5. Salir                      ²²\n");
        printf("\t\t    ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²");
        //scanf("%s", &pp);
        pp=getch();
        system("color 7C");
        switch(pp){
            case '1': system("cls");system("start marcas.exe");break;
            case '2': system("cls");system("start productos.exe"); break;
            case '3': system("cls");system("start imprimir.exe"); break;
            case '4': system("cls");system("start FACTURA.exe");break;
            case '5':{
                system("cls");system("color 7C");
              cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²"<<endl;
              cout<<"²²       FINALIZANDO     ²²"<<endl;
              cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²"<<endl;
              cout<<"²²                       ²²"<<endl;
              cout<<"²²                       ²²"<<endl;
              cout<<"²²                       ²²"<<endl;
              cout<<"²²²²²²²²²²²²²²²²²²²²²²²²²²²"<<endl;
                int ter=0;
                for(ter>0;ter<=17;ter++){
                Sleep(90);
                cout<<"²°°"<<endl;
                 }
                 exit(0);
            }
            default: printf("OPCION INVALIDA\n\n\n\n\t\t");Sleep(500);break;
        }
    }while(pp!='5');

    getch();
}
