#pragma once
#include "string.h"
#include "Hoteles.h"

class ArrHoteles
{
public:
	ArrHoteles()
	{
		arrHoteles = nullptr;
		cantidadHoteles = 0;
	}
	~ArrHoteles(){}

	void agregarHoteles(Hoteles* hoteles)
	{
		Hoteles** temp = new Hoteles * [cantidadHoteles + 1];
		for (int i = 0; i < cantidadHoteles; i++)
		{
			temp[i] = arrHoteles[i];
		}
		temp[cantidadHoteles] = hoteles;
		delete[] arrHoteles;
		arrHoteles = temp;
		cantidadHoteles++;
	}

	
	void modificarRegistro(int indice)
	{
		if (&indice >= 0 && indice < cantidadHoteles)
		{
				string nombre, telefono;
				int estrellas;
				bool ofreceDesayuno, ofreceServicio;
			
				cout << "Registre los datos del Hotel:" << endl;
				cout << "Nombre del Hotel: "; cin >> nombre;
				cout << "Estrellas: "; cin >> estrellas;
				cout << "Ofrece Desayuno (1=Si, 0=No): "; cin >> ofreceDesayuno;
				cout << "Telefono: "; cin >> telefono;
				cout << "Ofrece Servicio Aeropuerto (1=Si, 0=No): "; cin >> ofreceServicio;
			
				// Crear un nuevo objeto Hoteles con los nuevos datos
				Hoteles* nuevoHoteles = new Hoteles(nombre, estrellas, ofreceDesayuno,telefono, ofreceServicio);
			
				// Reemplazar el Hoteles existente en el arreglo con el nuevo
				delete arrHoteles[indice];  // Eliminar el antiguo contacto para evitar fugas de memoria
				arrHoteles[indice] = nuevoHoteles;  // Asignar el nuevo contacto
			
			}
			else {
				cout << "Indice no valido." << endl;
			}
			
	}

	void eliminarRegistro(int indice)
	{
		if (indice >= 0 && indice < cantidadHoteles)
		{
			delete arrHoteles[indice];
			for (int i = indice; i < cantidadHoteles - 1; i++)
			{
				arrHoteles[i] = arrHoteles[i + 1];
			}
			cantidadHoteles--;
		}
		else 
		{
			cout << "Indice no valido." << endl;
		}
	}

	void reporteServicioDesayuno() const
	{
		cout << "Los hoteles con servicio de Desayuno son: " << endl;
		for (int i = 0; i < cantidadHoteles; i++)
		{
			if (arrHoteles[i]->ofreceDesayuno())
			{
				cout << "Hotel n" << i + 1 << endl;
				arrHoteles[i]->mostrarDatos();
				cout << endl;
			}
		}
	}

	void reporteservicioAeropuerto()
	{
		cout << "Los hoteles con servicio de Areopuerto son: " << endl;
		for (int i = 0; i < cantidadHoteles; i++)
		{
			if (arrHoteles[i]->ofreceServicio())
			{
				cout << "Hotel n" << i + 1 << endl;
				arrHoteles[i]->mostrarDatos();
				cout << endl;
			}
		}
	}
	
	void mostrarTodosHoteles() const
	{
		cout << "Todos los hoteles: " << endl;
		for (int i = 0; i < cantidadHoteles; i++)
		{
			cout << "Hotel n" << i + 1 << endl;
			arrHoteles[i]->mostrarDatos();
			cout << endl;
		}
	}

	void integrantes()const
	{
		cout << "Olenka Priscilla Del Aguila Del Aguila" << endl;
		cout << "Angela Milagros Espinoza Cruz";
	}

private:

	Hoteles** arrHoteles;
	int cantidadHoteles;
};
