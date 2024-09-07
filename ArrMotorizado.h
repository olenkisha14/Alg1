#pragma once
#include "string.h"
#include"Motorizado.h"

class ArrMotorizado
{
public:
	ArrMotorizado();
	~ArrMotorizado();

	void agregarMotorizado(Motorizado* motorizado);
	void eliminarMotorizado(int indice);
	void reporteMapi();
	void reporteGlopo();
	void mostrarTotal();


private:
	Motorizado** arr;
	int cantidad;
};

ArrMotorizado::ArrMotorizado()
{
	arr = nullptr;
	cantidad = 0;
}

ArrMotorizado::~ArrMotorizado()
{

}

void ArrMotorizado::agregarMotorizado(Motorizado* motorizado)
{
	Motorizado** temp = new Motorizado * [cantidad + 1];
	for (int i = 0; i < cantidad; i++)
	{
		temp[i] = arr[i];
	}
	temp[cantidad] = motorizado;
	delete[] arr;
	arr = temp;
	cantidad++;
}
void ArrMotorizado::eliminarMotorizado(int indice)
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
		cout << "Indice no valido...." << endl;
	}
}
void ArrMotorizado::reporteMapi()
{
	cout << "Reporte de empresa Mapi: " << endl;
	for (int i = 0; i < cantidad; i++)
	{
		if (arr[i]->getEsMapi())
		{
			cout << "Motorizado n" << i + 1 << endl;
			arr[i]->mostrarDatos();
			cout << endl;
		}
	}
}
void ArrMotorizado::reporteGlopo()
{
	cout << "Reporte de empresa Glopo: " << endl;
	for (int i = 0; i < cantidad; i++)
	{
		if (arr[i]->getEsGlopo())
		{
			cout << "Motorizado n" << i + 1;
			arr[i]->mostrarDatos();
			cout << endl;
		}
	}
}
void ArrMotorizado::mostrarTotal()
{
	cout << "El TOTAL DE MOTORIZADOS ES: " << endl;
	for (int i = 0; i < cantidad; i++)
	{
		cout << "Motorizaddo n" << i + 1 << endl;
		arr[i]->mostrarDatos();
		cout << endl;
	}
}