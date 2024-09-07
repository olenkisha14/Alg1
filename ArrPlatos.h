#pragma once
#include "string.h"
#include "Platos.h"

class ArrPlatos
{
public:
	ArrPlatos();
	~ArrPlatos();

	void agregarPlato(Platos* platos);
	void modificarPlato(int indice);
	void eliminarPlato(int indice);
	void mostrarTodosPlatos();
	void reportePlatoPicantes();
	void reportePlatoCaros();


private:
	Platos** arr;
	int cantidad;
};

ArrPlatos::ArrPlatos()
{
	arr = nullptr;
	cantidad = 0;
}

ArrPlatos::~ArrPlatos()
{
}

void ArrPlatos::agregarPlato(Platos* platos)
{
	Platos** temp = new Platos * [cantidad + 1];
	for (int i = 0; i < cantidad; i++)
	{
		temp[i] = arr[i];
	}
	temp[cantidad] = platos;
	delete[] arr;
	arr = temp;
	cantidad++;
}
void ArrPlatos::modificarPlato(int indice)
{
	if (&indice >= 0 && indice < cantidad)
	{
		string nombre;
		bool esFrio, esPicante;
		float calorias, precioPromedio;
		cout << "Nombre del Plato: "; cin >> nombre;
		cout << "Es Frio (1=Si, 0=No): "; cin >> esFrio;
		cout << "Es Picante (1=Si, 0=No): "; cin >> esPicante;
		cout << "Cantidad de Calorias: "; cin >> calorias ;
		cout << "Precio Promedio: "; cin >> precioPromedio ;
		
		//Crear un nuevo plato
		Platos* nuevosPlatos = new Platos(nombre,esFrio,esPicante,calorias,precioPromedio);

		delete arr[indice];//Eliminar antigua plato
		arr[indice] = nuevosPlatos; //Asignar nuevo plato
	}
	else 
	{
		cout << "Indice no valido." << endl;
	}
}
void ArrPlatos::eliminarPlato(int indice)
{
	if (&indice >= 0 && indice < cantidad)
	{
		delete arr[indice];
		for (int i = 0; i < cantidad - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
		cantidad--;
	}
	else
	{
		cout << "Indice no valido" << endl;
	}
}

void ArrPlatos::mostrarTodosPlatos()
{
	cout << "Los platos registrados son: " << endl;
	for (int i = 0; i < cantidad; i++)
	{
		cout << "Plato n" << i + 1 << endl;
		arr[i]->mostrarDatos();
		cout << endl;
	}
}

void ArrPlatos::reportePlatoPicantes()
{
	cout << "Los platos picantes son: " << endl;
	for (int i = 0; i < cantidad; i++)
	{
		if (arr[i]->getEsPicante())
		{
			cout << "Plato n" << i + 1 << endl;
			arr[i]->mostrarDatos();
			cout << endl;
		}
	}
}
void ArrPlatos::reportePlatoCaros()
{
	cout << "Los platos caros son: " << endl;
	for (int i = 0; i < cantidad; i++)
	{
		if (arr[i]->getPrecioPromedio() > 100)
		{
			cout << "Plato n" << i + 1 << endl;
			arr[i]->mostrarDatos();
			cout << endl;
		}
	}
}