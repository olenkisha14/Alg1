//Producto.cpp

#include "Producto.h"
#include <iostream>

using namespace std;
//Consuctor q inicializa 
Producto::Producto(int idProducto, const string& nombre, const string& tipo, int cantidad, const string& categoria, int anio, double precio, Proveedor* proveedor)
	: idProducto(idProducto), nombre(nombre), tipo(tipo), cantidad(cantidad), categoria(categoria), anio(anio), precio(precio), proveedor(proveedor) {}

int Producto::getIdProducto() const {
	return idProducto;
}

string Producto::getNombre() const {
	return nombre;
}

string Producto::getTipo() const {
	return tipo;
}

int Producto::getCantidad() const {
	return cantidad;
}

string Producto::getCategoria() const {
	return categoria;
}

int Producto::getanio() const {
	return anio;
}
double Producto::getPrecio() const {
	return precio;
}

Proveedor* Producto::getProveedor() const {
	return proveedor;
}

void Producto::setIdProducto(int newIdProducto) {
	idProducto = newIdProducto;
}

void Producto::setNombre(const string& newNombre) {
	nombre = newNombre;
}

void Producto::setTipo(const string& newTipo) {
	tipo = newTipo;
}

void Producto::setCantidad(int newCantidad) {
	cantidad = newCantidad;
}

void Producto::setCategoria(const string& newCategoria) {
	categoria = newCategoria;
}

void Producto::setanio(int newanio) {
	anio = newanio;
}

void Producto::setPrecio(double newPrecio) {
	precio = newPrecio;
}

void Producto::setProveedor(Proveedor* newProveedor) {
	proveedor = newProveedor;
}

//Mostrar la info en la consola
void Producto::mostrarInformacion() const {
	cout << "ID Producto: " << idProducto << "\nNombre: " << nombre << "\n Tipo: " << tipo << "\nCantidad: " << cantidad << "\nCategoria: " << categoria << "\nanio: " << anio << "\nPrecio: " << precio << endl;
	proveedor->mostrarInformacion();
}
