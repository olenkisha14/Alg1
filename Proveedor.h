#pragma once
//Proveedor.h
#include <string>

using namespace std;

class Proveedor {
private:
	string ruc;
	string razonSocial;
	string categoria;
	string direccion;
	string telefono;

public:
	//Constructo que inci l objeto Proveedor con todos atributos indicados
	Proveedor(const string& ruc, const string& razonSocial, const string& categoria, const string& direccion, const string& telefono);

	//Get para obtener el valor de un atributo
	string getRuc() const;
	string getRazonSocial() const;
	string getCategoria() const;
	string getDireccion() const;
	string getTelefono() const;

	//Set para asignar un valor
	void setRuc(const string& ruc);
	void setRazonSocial(const string& razonSocial);
	void setCategoria(const string& categoria);
	void setDireccion(const string& direccion);
	void setTelefono(const string& telefono);


	//Metodo que muestra la info del proveedor
	//El moificar const indica que el metodo NO 
	void mostrarInformacion() const;
};
