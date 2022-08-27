#include "Nodo.h"
#include <string> // esto permite usar el cout
#include <iostream> // esto permite usar el cout
using namespace std; // esto permite usar el cout

Nodo::Nodo(int dato)
{
	this->dato = dato;
	this->hijoDer = nullptr;
	this->hijoIzq = nullptr;
	this->ebraDer = false;
	this->ebraIzq = false;
}

Nodo::~Nodo()
{
}

bool Nodo::esEnebradoALaIzq()
{
	return this->ebraIzq;
}

bool Nodo::esEnebradoALaDer()
{
	return this->ebraDer;
}

Nodo* Nodo::getHijoIzq()
{
	return this->hijoIzq;
}

Nodo* Nodo::getHijoDer()
{
	return this->hijoDer;
}

int Nodo::getDato()
{
	return this->dato;
}

void Nodo::setEbraIzq(bool ebraIzq)
{
	this->ebraIzq = ebraIzq;
}

void Nodo::setEbraDer(bool ebraDer)
{
	this->ebraDer = ebraDer;
}

void Nodo::setHijoIzq(Nodo* hijoIzq)
{
	this->hijoIzq = hijoIzq;
}

void Nodo::setHijoDer(Nodo* hijoDer)
{
	this->hijoDer = hijoDer;
}

void Nodo::setDato(int dato)
{
	this->dato = dato;
}
