
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
        printf("\n\n\n\n\n\t\t\t��������������������������");
        printf("\n\t\t\t�          MENU          �");
        printf("\n\t\t\t��������������������������\n\n\n");
        printf("\t\t    ������������������������������������\n");
        printf("\t\t    ��  1. ADIMISTRAR MARCAS          ��\n");
        printf("\t\t    ��  2. ADMINISTRAR PRODUCTOS      ��\n");
        printf("\t\t    ��  3. IMPRIMIR CODIGO DE BARRAS  ��\n");
        printf("\t\t    ��  4. GENERAR FACTURA            ��\n");
        printf("\t\t    ��                                ��\n");
        printf("\t\t    ��                                ��\n");
        printf("\t\t    ��  5. Salir                      ��\n");
        printf("\t\t    ������������������������������������");
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
              cout<<"���������������������������"<<endl;
              cout<<"��       FINALIZANDO     ��"<<endl;
              cout<<"���������������������������"<<endl;
              cout<<"��                       ��"<<endl;
              cout<<"��                       ��"<<endl;
              cout<<"��                       ��"<<endl;
              cout<<"���������������������������"<<endl;
                int ter=0;
                for(ter>0;ter<=17;ter++){
                Sleep(90);
                cout<<"���"<<endl;
                 }
                 exit(0);
            }
            default: printf("OPCION INVALIDA\n\n\n\n\t\t");Sleep(500);break;
        }
    }while(pp!='5');

    getch();
}
