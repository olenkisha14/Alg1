#include "iostream"
#include "string"
using namespace std;
#include "ArrContacto.h"

short Menu() 
{
	short opc;
	do
	{
		cout << "\tMENU" << endl;
		cout << "1. Agregar contacto" << endl;
		cout << "2. Modificar datos de un contacto" << endl;
		cout << "3. Eliminar un contacto" << endl;
		cout << "4. Reporte de contactos que cumplen anios en mayo" << endl;
		cout << "5. Reporte de contactos que son varones" << endl;
        cout << "6. Reporte de contactos con redes sociales" << endl;
		cout << "7. Mostrar todos los contactos" << endl;
		cout << "8. Salir" << endl;
		cout << "Ingrese la opcion...";
		cin >> opc;
        cout << endl;
	} while (opc < 1 || opc > 8);
	return opc;
}

int main() 
{
    ArrContacto agenda; 

    while (true) {
        short opc = Menu(); 
        switch (opc)
        {
        case 1: 
        {
            // Agregar un contacto
            string nombre, telefono, sexo, facultad, email;
            bool tieneFacebook, tieneWhatsApp;
            Fecha fechaNacimiento;

            cout << "Ingrese los datos del nuevo contacto:" << endl;
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

            // Crear y agregar el nuevo contacto a la agenda
            Contacto* nuevoContacto = new Contacto(nombre, telefono, sexo, facultad, fechaNacimiento, email, tieneFacebook, tieneWhatsApp);
            agenda.agregarContacto(nuevoContacto);
            break;
        }
        case 2: 
        {
            // Modificar un contacto
            int indice;
            cout << "Ingrese el indice del contacto a modificar: ";
            cin >> indice;
            agenda.modificarContacto(indice - 1);  // Indices son base 0 en el arreglo
            break;
        }
        case 3: 
        {
            // Eliminar un contacto
            int indice;
            cout << "Ingrese el indice del contacto a eliminar: ";
            cin >> indice;
            agenda.eliminarContacto(indice - 1);  // Indices son base 0 en el arreglo
            break;
        }
        case 4:
        {
            // Reporte de contactos que cumplen años en mayo
            agenda.mostrarContactosCumpleanosMayo();
            break;
        }
        case 5: 
        {
            // Reporte de contactos que son varones
            agenda.reporteVarones();
            break;
        }
        case 6: {
            // Reporte de contactos que tienen red social Facebook y WhatsApp
            agenda.mostrarContactosConRedesSociales();
            break;
        }
        case 7: 
        {
            // Mostrar todos los contactos
            agenda.mostrarTodosContactos();
            break;
        }
        case 8: 
        {
            // Salir del programa
            cout << "Saliendo..." << endl;
            return 0;
        }
        default: 
        {
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
        }
        system("pause>0");
        system("cls");
    }
	system("pause>0");
	return 0;
}