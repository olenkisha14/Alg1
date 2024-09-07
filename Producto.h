#pragma once
#include <string>
#include "Proveedor.h"

using namespace std;

class Producto {
private:
	int idProducto;
	string nombre;
	string tipo;
	int cantidad;
	string categoria;
	int anio;
	double precio;
	Proveedor* proveedor;
	//Puntero a un objeto de la clase provedor
	//(asocia l prod con su proveedor)
	//Toma todos los datos de la clase povedor

public:
	Producto(int IdProducto, const string& nombre, const string& tipo, int cantidad, const string& categoria, int anio, double precio, Proveedor* proveedor);

	//Get
	int getIdProducto() const;
	string getNombre() const;
	string getTipo() const;
	int getCantidad() const;
	string getCategoria() const;
	int getanio() const;
	double getPrecio() const;
	Proveedor* getProveedor() const;

	//Set
	void setIdProducto(int idProducto);
	void setNombre(const string& nombre);
	void setTipo(const string& tipo);
	void setCantidad(int cantidad);
	void setCategoria(const string& categoria);
	void setanio(int anio);
	void setPrecio(double precio);
	void setProveedor(Proveedor* proveedor);

	void mostrarInformacion() const;
};
