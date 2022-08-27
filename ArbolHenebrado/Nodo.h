#pragma once
class Nodo
{
	bool ebraIzq;
	Nodo* hijoIzq;
	bool ebraDer;
	Nodo* hijoDer;
	int dato;

public:
	Nodo(int dato);
	~Nodo();

	bool esEnebradoALaIzq();
	bool esEnebradoALaDer();
	Nodo* getHijoIzq();
	Nodo* getHijoDer();
	int getDato();

	void setEbraIzq(bool ebraIzq);
	void setEbraDer(bool ebraDer);
	void setHijoIzq(Nodo* hijoIzq);
	void setHijoDer(Nodo* hijoDer);
	void setDato(int dato);




};

