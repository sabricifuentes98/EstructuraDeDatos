// Lista.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#define NULL 0
using namespace std;

struct NodoLista {
	int dato;
	NodoLista *siguiente;
};

struct Tlista {
	NodoLista *inicio; 
	NodoLista *fin; 
};

void inicializa(struct Tlista *L) {
	L-> inicio = NULL;
	L-> fin = NULL; 
}

bool vacia(struct Tlista *L) {
	return (L->inicio == NULL);
}

NodoLista* inicio(struct Tlista *L) {
	return L->inicio; 
}

NodoLista* fin(struct Tlista *L) {
	return L->fin; 
}

void insertaInicio(struct Tlista *L, int v) {
	NodoLista *tmp = new NodoLista;
	tmp->dato = v; 

	if (vacia(L)) {
		tmp->siguiente = NULL;
		L->inicio = tmp;
		L->fin = tmp;
	}
	else {
		tmp->siguiente = L->inicio; 
		L->inicio = tmp;
	}
}

void insertaFin(struct Tlista *L, int v) {
	NodoLista* tmp = new NodoLista;
	tmp->dato = v;

	if (vacia(L)) { 
		tmp->siguiente = NULL; 
		L->inicio = tmp;
		L->fin = tmp; 
	}
	else {
		tmp->siguiente = NULL;
		L->fin->siguiente = tmp; 
		L->fin = tmp;	
	}
}

void imprime(struct Tlista *L) {
	NodoLista *p = L->inicio; 

	if (p == NULL)
		cout << "Lista vacia " << endl; 
	else {
		cout << endl << "Lista {";
		while (p != NULL) {
			cout << p->dato << ",";
			p = p->siguiente; 
		}
		cout << "}" << endl; 
	}
}

NodoLista*busca(struct Tlista*L, int v) {
	NodoLista*p = L->inicio; 
	if (p != NULL)
		while (p != NULL) {
			if (p->dato == v)
				break;

			p = p->siguiente;
		}
	
	return p;
		
}

void insertaDespues(struct Tlista *L, int v, NodoLista *p) {
	if (p != NULL)
		if (p == L->fin)
			insertaFin(L, v);
		else {
			NodoLista*tmp = new NodoLista;
			tmp->dato = v; 
			tmp->siguiente = p->siguiente;
			p->siguiente = tmp; 
		}
}

void insertaAntes(struct Tlista*L, int v, NodoLista*p) {
	if (p != NULL)
		if (p == L->inicio)
			insertaInicio(L, v);
		else {
			NodoLista*q = L->inicio; 
			while (q->siguiente != p)
				q = q->siguiente; 
			if (q -> siguiente == p) {

				NodoLista *tmp = new NodoLista; 
				tmp->dato = v;
				tmp->siguiente = p; 
				q->siguiente = tmp;
		}
		}
}

void eliminar(struct Tlista *L, NodoLista *p) {
	if (p != NULL) {
		if (p == L->inicio) {
			L->inicio = p->siguiente;
		}
		else if (p == L->fin) {
			NodoLista *q = L->inicio;
			while (q->siguiente != p) {
				q = q->siguiente;
			}
			q->siguiente = NULL;
			L->fin = q;
		}
		else {
			NodoLista *q = L->inicio;
			while (q->siguiente != p) {
				q = q->siguiente;
			}
			q->siguiente = q->siguiente->siguiente;
		}
		delete (p);
	}
	else
		cout << "La lista esta vacia " << endl;
}

void eliminaNum(struct Tlista *L, int n) {

	eliminar(L, busca(L, n));
}


void insertaOrd(struct Tlista *L, int v) {
	NodoLista *q = L->inicio;
	if (vacia(L))
		insertaInicio(L, v);
	else {
		while (q != NULL)
			if (q->dato < v)
				q = q->siguiente;
			else
				break;
		if (q == NULL)
			insertaFin(L, v);
		else
			insertaAntes(L, v ,q);
	}
}


void concatenar(struct Tlista *L1, struct Tlista *L2, struct Tlista *L) {
	if (!(vacia(L1)) && !(vacia(L2))) {
		NodoLista *q;
		q = L1->inicio;
		do {
			insertaFin(L, q->dato);
			q = q->siguiente;
		} while (q != NULL);
		q = L2->inicio;
		do {
			insertaFin(L, q->dato);
			q = q->siguiente;
		} while (q != NULL);
		
	}
}


int main()
{
	int menu;
	struct Tlista L1; 
	inicializa(&L1);
	struct Tlista L2;
	inicializa(&L2);
	struct Tlista L3;
	inicializa(&L3);
	

	do
	{
		struct Tlista *L=NULL;
		int v, n;
		int p;
		do {
			cout<< "Elija en que lista quiere realizar las operaciones:" <<endl << "<1> Lista 1" << "\t"<< "<2> Lista 2" << " < Lista 3 >" <<endl;
			cin >> p;
		} while (!(p > 0 && p < 4));
		if (p == 1) {
			L = &L1;
		}
		else if(p==2){
			L = &L2;
		}
		else if (p == 3) {
			concatenar(&L1,&L2,&L3);
			imprime(&L3);
			system("pause>null");
			continue;
		}

		cout << "<1> Inserta Inicio" << endl << "<2> Inserta Fin" << endl << "<3> Inserta Despues" << endl << "<4> Inserta antes " << endl<< "<5> Eliminar" << endl << "<6> Visualizar lista" << endl<< "<7>Inserta ordenado " << endl << "<8>  Salir" << endl;
		cin >> menu; 
		system("cls");
		switch (menu) {
		case 1:
			cout << "Introduce un numero" << endl;
			cin >> v;
			insertaInicio(L, v);
		
			break;

		case 2:
			cout << "Introduce un numero" << endl;
			cin >> v;
			insertaFin(L, v);
			break;
		case 3:
			cout << "Introduce un numero" << endl;
			cin >> v;
			cout << "Despues de que numero lo quieres insertar" << endl; 
			cin >> n;
			insertaDespues(L, v, busca(L, n));
			
			break;
		case 4:
			cout << "Introduce un numero" << endl;
			cin >> v;
			cout << "Antes de que numero quieres insertar" << endl;
			cin >> n;
			insertaAntes(L, v, busca(L, n));
			
			break;
		case 5:
			cout << "introduce el valor que quieres eliminar" << endl;
			cin >> n;
			eliminaNum(L,n);
			cout << "Valor eliminado correctamente " << endl << endl; 
			break;
		case 6:
			imprime(L);
			break;
		case 7:
			cout << "introduce el valor que quieres insertar ordenadamente " << endl;
			cin >> n;
			insertaOrd(L, n);
			break;
		case 8:
			break;
		default:
			cout << "introduza una opcion correcta " << endl;
			break;
		}

		
	} while (menu!=8);

    return 0;
}

