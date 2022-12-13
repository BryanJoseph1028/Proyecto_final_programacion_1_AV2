#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>

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

void ingresar();
void crearusuario();
void verificacion();

string usuariod="admin", passwordd="admin";


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
	gotoxy(16,7);cout<<"::º          1. INGRESAR             º::";
	gotoxy(16,8);cout<<"::º                                  º::";
	gotoxy(16,9);cout<<"::º          2. CREAR                º::";
	gotoxy(16,10);cout<<"::º                                  º::";
	gotoxy(16,11);cout<<"::º          3. SALIR                º::";
	gotoxy(16,12);cout<<"::º                                  º::";
	gotoxy(16,13);cout<<"::º                                  º::";
	gotoxy(16,14);cout<<"::ºßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßßº::";
	gotoxy(16,15);cout<<"::::::::::::::::::::::::::::::::::::::::";
	gotoxy(30,17);cin>>opcion;
	system("cls");
	
	switch(opcion){
		case 1: ingresar(); break;
		case 2: verificacion(); break;
		case 3: exit(1); break;
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
	cin>>cadena2;
	
	if(!archivo.is_open()){
		archivo.open("usuarios.txt", ios::in);
	}	
	
	while(getline(archivo, linea)){
		if(linea.find(cadena)!=string::npos){
			getline(archivo, linea2);
			if(linea2.find(cadena2)!=string::npos && linea2==cadena2){
				getline(archivo, linea3); 
				
				if(linea3=="Administrador"){
					gotoxy(20,9);	cout<<"Administrador";
					system("start main.exe");
				}
				
				else if(linea3=="Empleado"){
					gotoxy(20,9);	cout<<"Empleado";
					system("start main.exe");
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
	}
	
	archivo.close();
	
}

void verificacion(){
	string usuarioa, passworda;
	
	system("cls");
		gotoxy(15,2); cout<<"VERIFICACION:";
		gotoxy(10,4);cout<<"Ingrese el usuario administrador: ";
			cin>>usuarioa;
			gotoxy(10,5); cout<<"Ingrese el password: ";
			cin>>passworda;
			
			if(usuarioa==usuariod && passworda==passwordd){
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
				 		gotoxy(25,12); cout<<"password: ";	cin>>nuevop;
						
						archivo<<nuevou<<endl;
						archivo<<nuevop<<endl;
						archivo<<"Administrador"<<endl<<endl;
					break;
					
					case 2: 
						system("cls");
						gotoxy(30,5); cout<<"CREAR USUARIO";
						gotoxy(23,10); cout<<"TIPO DE USUARIO: Empleado";
						gotoxy(25,11);cout<<"usuario: ";	cin>>nuevou;
						gotoxy(25,12);cout<<"password: ";		cin>>nuevop;
						
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
					
			archivo.close();
				
				main();
			
		}
	}


