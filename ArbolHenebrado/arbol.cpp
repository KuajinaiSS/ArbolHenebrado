#include "arbol.h"
#include <string> // esto permite usar el cout
#include <iostream> // esto permite usar el cout
using namespace std; // esto permite usar el cout

Nodo* arbol::agregar(Nodo* nodo, int dato)
{
	if (nodo->getDato() > dato && nodo->esEnebradoALaIzq()) {
		Nodo* nodoNuevo = new Nodo(dato);
		Nodo* ebraActual = nodo->getHijoIzq();
		nodo->setHijoIzq(nodoNuevo);
		nodo->setEbraIzq(false);
		nodoNuevo->setEbraIzq(true);
		nodoNuevo->setHijoIzq(ebraActual);
		nodoNuevo->setEbraDer(true);
		nodoNuevo->setHijoDer(nodo);
		return nodo;
	}
	else if (nodo->getDato() > dato) {
		nodo->setHijoIzq(agregar(nodo->getHijoIzq(), dato));
	}
	else if (nodo->getDato() < dato && nodo->esEnebradoALaDer()) {
		Nodo* nodoNuevo = new Nodo(dato);
		Nodo* ebraActual = nodo->getHijoDer();
		nodo->setHijoDer(nodoNuevo);
		nodo->setEbraDer(false);
		nodoNuevo->setEbraDer(true);
		nodoNuevo->setHijoDer(ebraActual);
		nodoNuevo->setEbraIzq(true);
		nodoNuevo->setHijoIzq(nodo);
		return nodo;
	}
	else if (nodo->getDato() < dato) {
		nodo->setHijoDer(agregar(nodo->getHijoDer(), dato));

	}
	return nodo;
}







Nodo* arbol::buscar(Nodo* nodo, int dato)
{
	if (nodo->getDato() > dato && !nodo->esEnebradoALaIzq()) {
		return buscar(nodo->getHijoIzq(), dato);
	}
	else if (nodo->getDato() < dato && !nodo->esEnebradoALaDer()) {
		return buscar(nodo->getHijoDer(), dato);
	}
	else if (nodo->getDato() == dato) {
		return nodo;
	}
}








void arbol::borrarNodo(Nodo* nodo, int dato)
{
	if (dato < nodo->getDato() && !nodo->esEnebradoALaIzq()) {
		if (nodo->getHijoIzq()->getDato() == dato) {
			Nodo* ebraActual = nodo->getHijoIzq()->getHijoIzq();
			nodo->getHijoIzq()->~Nodo();
			nodo->setHijoIzq(ebraActual);
			nodo->setEbraIzq(true);
			return;
		}
		else {
			borrarNodo(nodo->getHijoIzq(), dato);
		}
	}
	else if (dato > nodo->getDato() && !nodo->esEnebradoALaDer()) {
		if (nodo->getHijoDer()->getDato() == dato) {
			Nodo* ebraActual = nodo->getHijoDer()->getHijoDer();
			nodo->getHijoDer()->~Nodo();
			nodo->setHijoDer(ebraActual);
			nodo->setEbraDer(true);
			return;

		}
		else {
			borrarNodo(nodo->getHijoDer(),dato);
		}

	}
	return;
}








void arbol::inOrden_inverso(Nodo* nodo, int spaces)
{
	// spaces += SPACE;
	if (!nodo->esEnebradoALaDer()) {
		inOrden_inverso(nodo->getHijoDer(), spaces);
	}
	for (int i = 0; i < spaces; i++)
	{
		cout << " ";
	}
	if (nodo->esEnebradoALaIzq()) {
		cout << "[T]";
	}
	else {
		cout << "[F]";
	}

	cout << "[" << nodo->getDato() << "]";

	if (nodo->esEnebradoALaDer()) {
		cout << "[T] ";
	}
	else {
		cout << "[F] ";
		// cout << "\n\n\n";

	}

	if (!nodo->esEnebradoALaIzq()) {
		inOrden_inverso(nodo->getHijoIzq(), spaces);
	}

}





void arbol::postOrden(Nodo* nodo)
{
	if (!nodo->esEnebradoALaIzq())
	{
		postOrden(nodo->getHijoIzq());
	}
	if (!nodo->esEnebradoALaDer())
	{
		postOrden(nodo->getHijoDer());
	}
	cout << "[" << nodo->getDato() << "] ";
}

void arbol::preOrden(Nodo* nodo)
{
	cout << "[" << nodo->getDato() << "] ";

	if (!nodo->esEnebradoALaIzq())
	{
		postOrden(nodo->getHijoIzq());
	}
	if (!nodo->esEnebradoALaDer())
	{
		postOrden(nodo->getHijoDer());
	}
	
}

void arbol::inOrden(Nodo* nodo)
{
	

	if (!nodo->esEnebradoALaIzq())
	{
		postOrden(nodo->getHijoIzq());
	}

	cout << "[" << nodo->getDato() << "] ";

	if (!nodo->esEnebradoALaDer())
	{
		postOrden(nodo->getHijoDer());
	}
}



arbol::arbol()
{
	this->root = new Nodo(0);
	this->root->setHijoIzq(this->root);
	this->root->setHijoDer(this->root);
	this->root->setEbraIzq(true);
	this->root->setEbraDer(false);
}



void arbol::agregar(int dato)
{
	if (this->root->esEnebradoALaIzq()) {
		this->root->setEbraIzq(false);
		Nodo* nodoNuevo = new Nodo(dato);
		this->root->setHijoIzq(nodoNuevo);
		nodoNuevo->setEbraIzq(true);
		nodoNuevo->setEbraDer(true);
		nodoNuevo->setHijoIzq(this->root);
		nodoNuevo->setHijoDer(this->root);
		return;
	}
	agregar(this->root->getHijoIzq(), dato);
}




void arbol::borrarNodo(int dato)
{
	if (this->root->esEnebradoALaIzq()) return;
	this->borrarNodo(this->root->getHijoIzq(), dato);

}





bool arbol::buscar(int dato)
{
	return this->buscar(this->root->getHijoIzq(), dato);
}

void arbol::imprimirArbol()
{
	this->inOrden_inverso(this->root->getHijoIzq(), -SPACE);
	cout << "\n\n\n\n";
}
