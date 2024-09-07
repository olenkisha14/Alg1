#pragma once
#include "string.h"

class Motorizado
{
public:
	Motorizado();
	Motorizado(string nombre, string apellido, int placa,float kilometraje, bool esMapi, bool esGlopo);
	~Motorizado();

	string getNombre();
	string getApellido();
	int getPlaca();
	float getKilometraje();
	bool getEsMapi();
	bool getEsGlopo();

	void obtenerPrecio();
	void mostrarDatos();


private:
	string nombre;
	string apellido;
	int placa;
	float kilometraje;
	bool esMapi;
	bool esGlopo;
	float precio;
};

Motorizado::Motorizado()
{
	this->precio = 0;
	this->esMapi = rand() % 2;
	this->esGlopo = rand() % 2;
}
Motorizado::Motorizado(string nombre, string apellido, int placa, float kilometraje, bool esMapi, bool esGlopo)
{
	this->nombre= nombre;
	this->apellido= apellido;
	this->placa= placa;
	this->kilometraje= kilometraje;
	
	
}
Motorizado::~Motorizado()
{
}

string Motorizado::getNombre()
{
	return this->nombre;
}
string Motorizado::getApellido() 
{
	return this->apellido;
}
int Motorizado::getPlaca() 
{
	return this->placa;
}
float Motorizado::getKilometraje()
{
	return this->kilometraje;
}

bool Motorizado::getEsMapi()
{
	return this->esMapi;
}
bool Motorizado::getEsGlopo()
{
	return this->esGlopo;
}

void Motorizado::obtenerPrecio() 
{
	precio = kilometraje * 1.5;
}
void Motorizado::mostrarDatos()
{
	cout << "Nombre: " << nombre << endl;
	cout << "Apellido: " << apellido << endl;
	cout << "Placa: " << placa << endl;
	cout << "Kilometraje: " << kilometraje << endl;
	cout << "Precio: " << precio << "soles" << endl;
	cout << "Es Mapi: " << (esMapi? "Si" : "No") << endl;
	cout << "Es Glopo: " << (esGlopo ? "Si" : "No") << endl;
}
