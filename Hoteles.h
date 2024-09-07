#pragma once
#include "string.h"

class Hoteles
{
public:
	Hoteles() {}
	Hoteles(const string & nombre, const int estrellas, bool desayuno, const string & telefono, bool servicio)
	{
		this->nombre = nombre;
		this->estrellas = estrellas;
		this->desayuno = desayuno;
		this->telefono = telefono;
		this->servicio = servicio;
	}

	~Hoteles(){}

	string getNombre() const
	{
		return nombre;
	}

	int getEstrellas() const
	{
		return estrellas;
	}

	bool ofreceDesayuno() const
	{
		return desayuno;
	}

	string getTelefono()const
	{
		return telefono;
	}

	bool ofreceServicio()const
	{
		return servicio;
	}


	void mostrarDatos() const
	{
		cout << "Nombre del Hotel: " << nombre << endl;
		cout << "Num estrellas: " << estrellas << endl;
		cout << "Ofrece desayuno: " << (desayuno ? "Si" : "No") << endl;
		cout << "Telefono: " << telefono << endl;
		cout << "Ofrece servicio Aeropuerto: "<< (servicio ?"Si" : "No") << endl;
	}

private:
	string nombre;
	int estrellas;
	bool desayuno;
	string telefono;
	bool servicio;
};
