#pragma once
#include "string.h"
class Platos
{
public:
	Platos();
	Platos(string nombre, bool esFrio, bool esPicante, float calorias, float precioPromedio);
	~Platos();

	//Set y Get
	void setNombre(string nombre);
	void setEsFrio(bool esFrio);
	void setEsPicante(bool esPicante);
	void setCalorias(float calorias);
	void setPromedio(float precioPromedio);

	bool getEsPicante();
	float getPrecioPromedio();


	void mostrarDatos();

private:
	string nombre;
	bool esFrio, esPicante;
	float calorias, precioPromedio;
};

Platos::Platos()
{
	this->nombre = "std";
	this->esFrio = rand() % 2;
	this->esPicante = rand() % 2;
	this->calorias = (rand() % 10000) / 10.0;
	this->precioPromedio = (rand() % 3000) / 10.0;
}

Platos::Platos(string nombre, bool esFrio, bool esPicante, float calorias, float precioPromedio)
{
	this->nombre = nombre;
	this->esFrio = esFrio;
	this->esPicante = esPicante;
	this->calorias = calorias;
	this->precioPromedio = precioPromedio;
}

Platos::~Platos()
{

}

void Platos::setNombre(string nombre)
{
	this->nombre = nombre;
}
void Platos::setEsFrio(bool esFrio)
{
	this->esFrio = esFrio;
}
void Platos::setEsPicante(bool esPicante)
{
	this->esPicante = esPicante;
}
void Platos::setCalorias(float calorias)
{
	this->calorias = calorias;
}
void Platos::setPromedio(float precioPromedio)
{
	this->precioPromedio = precioPromedio;
}

bool Platos::getEsPicante()
{
	return this->esPicante;
}
float Platos::getPrecioPromedio()
{
	return this->precioPromedio;
}

void Platos::mostrarDatos()
{
	cout << "Nombre del Plato: " << nombre << endl;
	cout << "Es Frio: " << (esFrio ? "Si" : "No") << endl;
	cout << "Es Picante: " << (esPicante ? "Si" : "No") << endl;
	cout << "Cantidad de Calorias: " << calorias << endl;
	cout << "Precio Promedio: " << precioPromedio << endl;
}

