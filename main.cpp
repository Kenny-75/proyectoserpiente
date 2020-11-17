#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
#define ARRIBA 72
#define IZQUIERDA 75
#define ABAJO 80
#define DERECHA 77
#define ESC 27
struct Nodo{
    int dato;
    Nodo *siguiente;
};
char tecla;
int menu;
int cuerpocompleto[118][28];
int n=1;int tam = 2;
int x=10, y=12;
int direccion=3;
int xcomi=30, ycomi=20;
int xob, yob;
int Puntos=0;int por;
float t;
int d;int difi;
float tiempo;
void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
Nodo *lista=NULL;

void gotoxy(int x,int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);

	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;

	SetConsoleCursorPosition(hCon,dwPos);
}
void obstaclos(){
    int a=1;
    if (difi==50){
    if (x==xcomi && y==ycomi) {
    srand((unsigned)time(NULL));
    xob=(rand()% 110)+4;
    srand((unsigned)time(NULL));
    yob=(rand()% 16)+4;
    gotoxy(xob,yob); cout<<"L";
    }
}
}
void dificultad(){
	cin>>d;
	switch(d){
		case 1:
			difi=100;
			break;
		case 2:
		    difi=50;
			break;
		case 3:
		    difi=20;
			break;
        case 4:
		    difi=100;
		    while(tiempo!=20){
            difi-10;
		    }
	}
	system("cls");
}
void pintarescenario(){
	for(int i=2; i<118;i++){
		gotoxy(i,3);cout<<(char)205;
		gotoxy(i,27);cout<<(char)205;
	}
	for(int i=4;i<27;i++){
		gotoxy(2,i); cout<<(char)186;
		gotoxy(117,i); cout<<(char)186;
	}
	gotoxy(2,3);cout<<(char)201;
	gotoxy(2,27);cout<<(char)200;
	gotoxy(117,3);cout<<(char)187;
	gotoxy(117,27);cout<<(char)188;

}
void dibujarcuerpo(){
	for(int i=1; i<tam;i++){
		gotoxy(cuerpocompleto[i][0],cuerpocompleto[i][1]); cout<<"*";
	}
}
void guardarposicion(){
	cuerpocompleto[n][0]=x;
	cuerpocompleto[n][1]=y;
	n++;
	if (n==tam){n=1;}
	dibujarcuerpo();
}
void borrarcuerpo(){
		gotoxy(cuerpocompleto[n][0],cuerpocompleto[n][1]); cout<<" ";
		guardarposicion();
	}
void movimiento(){
	if (kbhit()){
		tecla=getch();
		switch(tecla){
			case ARRIBA:
			if (direccion !=2){direccion=1;}
			break;
			case ABAJO:
			if(direccion != 1 ){direccion=2;}
			break;
			case IZQUIERDA:
			if (direccion != 3){direccion=4;}
			break;
			case DERECHA:
			if (direccion != 4){direccion=3;}
			break;
		}
	}
}
void comida(){
    srand(time(NULL));
    por=1+rand()%(100);
    if(por>=0&&por<=40)
    {if (x==xcomi && y==ycomi) {
		srand((unsigned)time(NULL));
		xcomi=(rand()% 110)+4;
		srand((unsigned)time(NULL));
		ycomi=(rand()% 16)+4;
		tam++;
		gotoxy(xcomi,ycomi); cout<<"M";
		Puntos++;
		gotoxy(50,2);cout<<Puntos;
	}}
    else if(por>=41&&por<=65)
    {if (x==xcomi && y==ycomi) {
		srand((unsigned)time(NULL));
		xcomi=(rand()% 110)+4;
		srand((unsigned)time(NULL));
		ycomi=(rand()% 16)+4;
		tam++;
		tam++;
		gotoxy(xcomi,ycomi); cout<<"F";
		Puntos++;
		gotoxy(50,2);cout<<Puntos;
	}}
    else if(por>=66&&por<=85)
    {if (x==xcomi && y==ycomi) {
		srand((unsigned)time(NULL));
		xcomi=(rand()% 110)+4;
		srand((unsigned)time(NULL));
		ycomi=(rand()% 16)+4;
		tam++;
		tam++;
		tam++;
		gotoxy(xcomi,ycomi); cout<<"B";
		Puntos++;
		gotoxy(50,2);cout<<Puntos;
	}}
    else if(por>=86&&por<=95)
    {if (x==xcomi && y==ycomi) {
		srand((unsigned)time(NULL));
		xcomi=(rand()% 110)+4;
		srand((unsigned)time(NULL));
		ycomi=(rand()% 16)+4;
		tam--;
		gotoxy(xcomi,ycomi); cout<<"P";
		Puntos++;
		gotoxy(50,2);cout<<Puntos;
	}}
    else if(por>=96&&por<=100)
    {if (x==xcomi && y==ycomi) {
		srand((unsigned)time(NULL));
		xcomi=(rand()% 110)+4;
		srand((unsigned)time(NULL));
		ycomi=(rand()% 16)+4;
		tam--;tam--;tam--;
		tam--;tam--;
		gotoxy(xcomi,ycomi); cout<<"I";
		Puntos++;
		gotoxy(50,2);cout<<Puntos;
	}}

}
bool gameover(){
	if (y==3 || y== 27 || x==2 || x==117){return false; }
	for (int j=tam-1; j>0;j--){
		if(cuerpocompleto[j][0]==x && cuerpocompleto[j][1]==y) {return false; }
	}
	return true;
}
void totaltiempo(){
    clock_t t;
    t=clock();
	t=clock()-t;
	tiempo=float(t)/CLOCKS_PER_SEC;
}
void procesos(){
	borrarcuerpo();
	//obstaclos();
	comida();
	totaltiempo();
	movimiento();
	movimiento();
	if (direccion==1){y--;}
	if (direccion==2){y++;}
	if (direccion==3){x++;}
	if (direccion==4){x--;}
	Sleep(difi);
}
int main(){
while(menu!=3){
system("cls");
gotoxy(50,3);cout<<"MENU"<<endl;
gotoxy(50,4);cout<<"1. JUGAR"<<endl;
gotoxy(50,5);cout<<"2. PUNTUACIONES"<<endl;
gotoxy(50,6);cout<<"3. SALIR"<<endl;
gotoxy(50,7);cin>>menu;
if(menu==1){
system("cls");
int x=10, y=12;
gotoxy(50,3);cout<<"ELIJJA UNA DIFICULTAD"<<endl;
gotoxy(50,4);cout<<"1. FACIL"<<endl;
gotoxy(50,5);cout<<"2. MEDIA"<<endl;
gotoxy(50,6);cout<<"3. DIFICIL"<<endl;
gotoxy(50,7);cout<<"4. DINAMICA"<<endl;
gotoxy(50,8);dificultad();
pintarescenario();
gotoxy(42,2);cout<<"Puntos: ";
gotoxy(20,1);cout<<"M=1"<<endl;
gotoxy(20,2);cout<<"F=2"<<endl;
gotoxy(24,1);cout<<"B=3"<<endl;
gotoxy(24,2);cout<<"P=-1"<<endl;
gotoxy(29,1);cout<<"I=-5"<<endl;
gotoxy(xcomi,ycomi);cout<<"M";
while(tecla != ESC && gameover() ){procesos();}
if (!gameover()){
	system("cls");
	gotoxy(50,2);cout<<"Has perdido"<<endl;
	gotoxy(50,3);cout<<"puntuacion: "<<Puntos<<endl;
	gotoxy(50,5);system("pause");
	system("cls");
    }
}
if(menu==2){
    system("cls");
    gotoxy(50,3);cout<<"PUNTUACIONES"<<endl;
    gotoxy(50,4);insertarLista(lista,Puntos);
    gotoxy(50,5);mostrarLista(lista);
    return main();
    }
}
    system("cls");
	gotoxy(50,5);system("pause");
	return 0;
}
void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo=new Nodo();
    nuevo_nodo->dato=n;
    Nodo *aux1=lista;
    Nodo *aux2;

    while((aux1!=NULL)&&(aux1->dato < n)){
        aux2=aux1;
        aux1=aux1->siguiente;
    }
    if(lista==aux1){
        lista=nuevo_nodo;
    }
    else{
        aux2->siguiente=nuevo_nodo;
    }
    nuevo_nodo->siguiente=aux1;
}
void mostrarLista(Nodo *lista){
    Nodo *actual= new Nodo();
    actual=lista;
    while(actual!=NULL){
    for (int a=5;a>=1;a--){
        cout<<a<<". "<<actual->dato<<endl;
        actual=actual->siguiente;
    }
    }
}
