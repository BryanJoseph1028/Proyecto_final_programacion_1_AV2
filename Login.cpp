#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
#include<stdlib.h>


#define ENTER 13
#define BACKSPACE 
#define PASSWOR "admin"
#define USUARIO "admin"

void menu(); 
using namespace std;
const char *nombre_archivo="usuarios.txt";

struct datos{
	string usuario, clave;
}informacion;

void gotoxy(int x, int y){
	HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hcon, dwPos);
	
}

string Convertir(char caracter){
    return string(1,caracter);
}


string Convertir2(char passworda){
    return string(1,passworda);
}

void ingresar();
void crearusuario();
void verificacion();

//tring usuariod="admin", passwordd="admin";
//#una maquina quizin 

int main(){
	system("color 0b");
	system("cls");
	
	int opcion;
	gotoxy(16,1);cout<<"::::::::::::::::::::::::::::::::::::::::";
	gotoxy(16,2);cout<<"::ºßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßº::";
	gotoxy(16,3);cout<<"::º                                  º::";
	gotoxy(16,4);cout<<"::º              LOGIN               º::";
	gotoxy(16,5);cout<<"::º                                  º::";
	gotoxy(16,6);cout<<"::º                                  º::";
	gotoxy(16,7);cout<<"::º   1. INGRESAR                    º::";
	gotoxy(16,8);cout<<"::º                                  º::";
	gotoxy(16,9);cout<<"::º   2. SALIR                       º::";
	gotoxy(16,10);cout<<"::º                                  º::";
	gotoxy(16,11);cout<<"::º                                  º::";
	gotoxy(16,12);cout<<"::º                                  º::";
	gotoxy(16,13);cout<<"::º                                  º::";
	gotoxy(16,14);cout<<"::ºßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßº::";
	gotoxy(16,15);cout<<"::::::::::::::::::::::::::::::::::::::::";
	gotoxy(30,17);cin>>opcion;
	system("cls");
	
	switch(opcion){
		case 1: ingresar(); break;
		case 2: exit(1); break;
		default: main(); break;
	}
	
	

}



void ingresar(){
	fstream archivo;
	string cadena,cadena2, linea, linea2, linea3;
	int res=0;
	
	gotoxy(24,2); cout<<"INICIO DE SESSION";
	
	gotoxy(16,4); cout<<"Usuario: ";
	cin>>cadena;
	gotoxy(16,5); cout<<"password: ";


	//cin>>cadena2;
	
char  caracter;
caracter = getch();
while (caracter!=ENTER){
	
   cadena2.push_back(caracter);
	cout<<"*";
	caracter=getch();

	//Convertir(caracter);
		
    }


	if(!archivo.is_open()){
		archivo.open("usuarios.txt", ios::in);
	}	
	
	while(getline(archivo, linea)){
		if(linea.find(cadena)!=string::npos){
			getline(archivo, linea2);
			if(linea2.find(cadena2)!=string::npos && linea2==cadena2)
				getline(archivo, linea3); 
				
				if(linea3=="Administrador"){
					gotoxy(20,9);	cout<<"Hola Administrador";
				//	system("cls");system("start menu.exe");
				menu();
				
				}
				
				else if(linea3=="Empleado"){
					gotoxy(20,9);	cout<<"Hola Empleado";
				//	system("cls");system("start menu.exe");
				menu();
				}
				
				gotoxy(20,10); cout<<"BIENVENIDO\n\n\n\n\n";
				res=1;
				
			}else{
				gotoxy(20,10); cout<<"EL USUARIO NO EXISTE...";
				getch();
				system("cls");
				ingresar();
			}
		
		}	
		system("cls"); system("start menu.exe");
	}
	


void verificacion(){
	string usuarioa, passworda;
	
	system("cls");
		gotoxy(15,2); cout<<"VERIFICACION:";
		gotoxy(10,4);cout<<"Ingrese el usuario administrador: ";
			cin>>usuarioa;
			gotoxy(10,5); cout<<"Ingrese el password: ";
		//cin>>passworda;
char cadena;		
cadena = getch();
while (cadena!=ENTER){
	passworda.push_back(cadena);
	cout<<"*";
	cadena=getch();
}
//Convertir2(passworda);
	
			if(usuarioa==USUARIO && passworda==PASSWOR){
				crearusuario();	
			}else{
				gotoxy(20,10);cout<<"EL USUARIO NO ES CORRECTO...";
				getch();
				verificacion();
			}
			
	
}

void crearusuario(){
	ofstream archivo;
	informacion;
	int tipo=0;
	string nuevou,nuevop,nuevoad;
	string r;
	
	archivo.open(nombre_archivo,ios::app);
		if (archivo.fail()){
			cout<<"no se puede abrir el archivo";
			exit(1);
		}else{
			
			do{
				
				system("cls");
				fflush(stdin);
				
				gotoxy(30,5); cout<<"CREAR USUARIO";
				gotoxy(23,10); cout<<"1. Administrador / 2. Empleado: ";
				cin>>tipo;
				
				switch(tipo){
				
					case 1: 
						system("cls");
						gotoxy(30,5); cout<<"CREAR USUARIO";
						gotoxy(23,10); cout<<"TIPO DE USUARIO: Administrador";
						gotoxy(25,11);cout<<"usuario: ";	cin>>nuevou;
				 		gotoxy(25,12); cout<<"password: ";	//cin>>nuevop;
					char  caracter;
                   caracter = getch();
                   while (caracter!=ENTER){
                   nuevop.push_back(caracter);
                       	cout<<"*";
                   	caracter=getch();
	
    }

						archivo<<nuevou<<endl;
						archivo<<nuevop<<endl;
						archivo<<"Administrador"<<endl<<endl;
					break;
					
					case 2: 
						system("cls");
						gotoxy(30,5); cout<<"CREAR USUARIO";
						gotoxy(23,10); cout<<"TIPO DE USUARIO: Empleado";
						gotoxy(25,11);cout<<"usuario: ";	cin>>nuevou;
						gotoxy(25,12);cout<<"password: ";	//	cin>>nuevop;
					char  caracter1;
                   caracter = getch();
                   while (caracter!=ENTER){
                   nuevop.push_back(caracter);
                       	cout<<"*";
                   	caracter=getch();
	
    }
	
						archivo<<nuevou<<endl;
						archivo<<nuevop<<endl;
						archivo<<"Empleado"<<endl<<endl; 
					break;
					
					default:
						system("cls");
						return crearusuario();
					break;
				}
							     
			
			fflush(stdin);
			     
			 gotoxy(25,14); cout<<"Desea ingresar crear otro 1.Si/2.No: "; getline(cin,r);	
		
			}while((r=="1")||(r=="S")||(r=="s"));	
					
			//close
				
				main();
			
		}
	}
	
	
	void menu(){
	
	 char pp;

    do {
        system("cls");
        system("cls");
        system("cls");
        system("color 7C");
        printf("\n\n\n\n\n\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²");
        printf("\n\t\t\t²          MENU          ²");
        printf("\n\t\t\t²²²²²²²²²²²²²²²²²²²²²²²²²²\n\n\n");
        printf("\t\t    ²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²²\n");
        printf("\t\t    ²²  1. ADIMISTRAR MARCAS          ²²\n");
        printf("\t\t    ²²  2. ADMINISTRAR PRODUCTOS      ²²\n");
        printf("\t\t    ²²  3. IMPRIMIR CODIGO DE BARRAS  ²²\n");
        printf("\t\t    ²²  4. GENERAR FACTURA            ²²\n");
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
                 break;
            }
            default: printf("OPCION INVALIDA\n\n\n\n\t\t");Sleep(1000000);break;
        }
    }while(pp!='5');

    getch();
	
	
	}
	
