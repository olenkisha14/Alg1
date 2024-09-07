#pragma once
#include "Nacimiento.h"
class Contacto
{
public:
	Contacto(){}

	Contacto(const string& nombre, const string& telefono, const string& sexo, const string& facultad, Fecha fechaNacimiento, const string& email, bool fb, bool ws)
	{
		this->nombre = nombre;
		this->telefono = telefono;
		this->sexo = sexo;
		this->facultad = facultad;
		this->fechaNacimiento = fechaNacimiento;
		this->email = email;
		tieneFacebook = fb;
		tieneWhatsApp = ws;
	}
	~Contacto() {}

	string getNombre() const 
	{
		return nombre;
	}
	string getTelefono() const
	{ 
		return telefono; 
	}
	string getSexo() const 
	{ 
		return sexo;
	}
	string getFacultad() const 
	{ 
		return facultad;
	}
	Fecha* getNacimiento() 
	{ 
		return &fechaNacimiento; 
	}
	string getEmail() const 
	{
		return email;
	}
	bool tieneFacebookActivo() const 
	{ 
		return tieneFacebook;
	}
	bool tieneWhatsAppActivo() const 
	{ 
		return tieneWhatsApp;
	}

	void mostrarDatos() const
	{
		cout << "Nombre: " << nombre << endl;
		cout << "Telefono: " << telefono << endl;
		cout << "Sexo(F: femenino, M: masculino): " << sexo << endl;
		cout << "Facultad: " << facultad << endl;
		cout << "Fecha de Nacimiento: ";
		fechaNacimiento.mostrarFecha();
		cout << "Email: " << email << endl;
		cout << "Tiene Facebook: " << (tieneFacebook ? "Si" : "No") << endl;
		cout << "Tiene WhatsApp: " << (tieneWhatsApp ? "Si" : "No") << endl;

		cout << endl;
	}

private:

	string nombre;
	string telefono;
	string sexo;
	string facultad;
	Fecha fechaNacimiento;
	string email;
	bool tieneFacebook;
	bool tieneWhatsApp;


};

