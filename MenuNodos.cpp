#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo*der;
	Nodo*izq;
	Nodo*padre;
	
};

//prototipos
void menu();
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo *&,int,Nodo *);
void mostrarArbol(Nodo *,int);
Nodo *arbol = NULL;

int main() {	
	menu();
}

void menu(){

int dato, opcion, contador=0;

	do{
		cout<<"\t      MENU      "<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Lista de Nodos"<<endl;
		cout<<"3. Salir"<<endl;
		cout<<"Opcion: "; 
		cin>>opcion;
		
		switch(opcion){
			case 1: cout<<"\nInsertar nodo: ";
					cin>>dato;
					insertarNodo(arbol,dato,NULL);
					cout<<"\n";
					system("pause");
					break;
			case 2: cout<<"\nLista de nodos:\n\n";
					//cin>>dato;
					mostrarArbol(arbol,contador);			
					system("pause");
					break;
				}
				system("cls");
				}
				while (opcion!=3);
				
}

//Funcion para crear un nuevo nodo
Nodo *crearNodo(int n,Nodo *padre){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n,Nodo *padre){
	if(arbol == NULL){ //Si el arbol esta vacio
		Nodo *nuevo_nodo = crearNodo(n,padre);
		arbol = nuevo_nodo;
	}
	else{ //Si el arbol tiene un nodo o mas
		int valorRaiz = arbol->dato; //Obtenemos el valor de la raiz
		if(n < valorRaiz){ //Si el elemento es menor a la raiz, insertamos en izq
			insertarNodo(arbol->izq,n,arbol);
		}
		else{//Si el elemento es mayor a la raiz, insertamos en der
			insertarNodo(arbol->der,n,arbol);
		}	
	}
}

//Funcion para mostrar el arbol completo
void mostrarArbol(Nodo *arbol,int cont){
	if(arbol == NULL){ //Si el arbol esta vacio
		return;
	}
	else{
		mostrarArbol(arbol->der, cont+1);
		cout<<"Valor del nodo: "<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}
