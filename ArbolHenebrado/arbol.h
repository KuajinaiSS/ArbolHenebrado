#pragma once
#include "Nodo.h"
#include "arbol.h"
#include <string> // esto permite usar el cout
#include <iostream> // esto permite usar el cout
using namespace std; // esto permite usar el cout

#define SPACE 15 // ?

class arbol
{
	Nodo* root;
	Nodo* agregar(Nodo* nodo, int dato);
	Nodo* buscar(Nodo* nodo, int dato);
	void borrarNodo(Nodo* nodo, int dato);
	void inOrden_inverso(Nodo* node, int spaces);



public:
	// constructores destructores
	arbol();
	void agregar(int dato);
	void borrarNodo(int dato);
	bool buscar(int dato);
	void imprimirArbol();
	void postOrden(Nodo* nodo);
	void preOrden(Nodo* nodo);
	void inOrden(Nodo* nodo);



};

