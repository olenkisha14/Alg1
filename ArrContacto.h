#pragma once
#include "Contacto.h"

class ArrContacto
{
public:
	ArrContacto()
	{
		arrContacto = nullptr;
		cantidadContactos = 0;
	}
	~ArrContacto() {}

	void agregarContacto(Contacto* contacto)
	{
		Contacto** temp = new Contacto * [cantidadContactos + 1];
		for (int i = 0; i < cantidadContactos; ++i) {
			temp[i] = arrContacto[i];
		}
		temp[cantidadContactos] = contacto;
		delete[] arrContacto;
		arrContacto = temp;
		cantidadContactos++;
	}

	void modificarContacto(int indice) {
		if (indice >= 0 && indice < cantidadContactos) {
			string nombre, telefono, sexo, facultad, email;
			bool tieneFacebook, tieneWhatsApp;
			Fecha fechaNacimiento;

			cout << "Ingrese los nuevos datos del contacto:" << endl;
			cout << "Nombre: "; cin >> nombre;
			cout << "Telefono: "; cin >> telefono;
			cout << "Sexo(F: femenino, M: masculino): "; cin >> sexo;
			cout << "Facultad: "; cin >> facultad;
			cout << "Fecha de Nacimiento (dd/mm/yyyy): ";
			int dia, mes, anio;
			cin >> dia >> mes >> anio;
			fechaNacimiento.setDia(dia);
			fechaNacimiento.setMes(mes);
			fechaNacimiento.setAnio(anio);
			cout << "Email: "; cin >> email;
			cout << "Tiene Facebook (1=Si, 0=No): "; cin >> tieneFacebook;
			cout << "Tiene WhatsApp (1=Si, 0=No): "; cin >> tieneWhatsApp;

			// Crear un nuevo objeto Contacto con los nuevos datos
			Contacto* nuevoContacto = new Contacto(nombre, telefono, sexo, facultad, fechaNacimiento, email, tieneFacebook, tieneWhatsApp);

			// Reemplazar el contacto existente en el arreglo con el nuevo
			delete arrContacto[indice];  // Eliminar el antiguo contacto para evitar fugas de memoria
			arrContacto[indice] = nuevoContacto;  // Asignar el nuevo contacto

		}
		else {
			cout << "Indice no valido." << endl;
		}
	}

	void eliminarContacto(int indice)
	{
		if (indice >= 0 && indice < cantidadContactos) {
			delete arrContacto[indice];
			for (int i = indice; i < cantidadContactos - 1; ++i) {
				arrContacto[i] = arrContacto[i + 1];
			}
			cantidadContactos--;
		}
		else {
			cout << "Indice no valido." << endl;
		}
	}

	void mostrarContactosCumpleanosMayo() const
	{
		cout << "-->Los contactos que cumplen anios en mayo son:" << endl;
		for (int i = 0; i < cantidadContactos; i++)
		{
			// Mayo es el mes 5
			if (arrContacto[i]->getNacimiento()->getMes() == 5) 
			{
				cout << "Contacto n" << i + 1 << endl;
				arrContacto[i]->mostrarDatos();
				cout << endl;
			}
		}
	}

	void reporteVarones() const {
		cout << "Contactos que son varones:" << endl;
		for (int i = 0; i < cantidadContactos; ++i)
		{
			if (arrContacto[i]->getSexo() == "M" || arrContacto[i]->getSexo() == "m") {
				arrContacto[i]->mostrarDatos();
			}
		}
	}

	void mostrarContactosConRedesSociales()
	{
		cout << "--> Los contactos que tienen Facebook y WhatsApp son:\n";
		for (int i = 0; i < cantidadContactos; i++) 
		{
			if (arrContacto[i]->tieneFacebookActivo() && arrContacto[i]->tieneWhatsAppActivo()) 
			{
				cout << "Contacto n" << i + 1 << endl;
				arrContacto[i]->mostrarDatos(); 
				cout << endl;
			}
		}
	}
	void mostrarTodosContactos() const 
	{
		cout << "Todos los contactos:" << endl;
		for (int i = 0; i < cantidadContactos; ++i) {
			cout << "Contacto n" << i + 1 << endl;
			arrContacto[i]->mostrarDatos();
		}
	}

private:
	Contacto** arrContacto;
	int cantidadContactos;
};
