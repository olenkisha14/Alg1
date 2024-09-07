#include "iostream"
#include "string.h"
using namespace std;
#include "Hoteles.h"
#include "ArrHoteles.h"
/* EJERCICIO 1 

1. Registrar hotel 
2. Mostrar registro de hoteles
3. Modificar un registro de hotel
4. Eliminar un registro de hotel
5. Integrantes del proyecto
6. Reporte de hoteles con desayuno
7. Reporte de hoteles con servicio Aeropuerto 
8. Salir 
Ingrese
*/

/*atributos como :
b) Nombre del hotel
d) Estrellas ( hasta 5 estrellas como max) 
e) Desayuno
f) Teléfono 
g) Servicio
Los métodos que debe tener la clase quedarán bajo su criterio,*/

short Menu()
{
	short op;
	do
	{
		cout << "\tMENU" << endl;
		cout << "1. Registrar hotel" << endl;
		cout << "2. Mostrar registro de hoteles" << endl;
		cout << "3. Modificar un registro de hotel" << endl;
		cout << "4. Eliminar un registro de hotel" << endl;
		cout << "5. Integrantes del proyecto" << endl;
		cout << "6. Reporte de hoteles con desayuno" << endl;
		cout << "7. Reporte de hoteles con servicio Aeropuerto " << endl;
		cout << "8. Salir" << endl;
		cout << "Ingrese la opcion...";
		cin >> op;
		cout << endl;
	} while (op < 1 || op > 8);

	return op;
}

int main()
{
    ArrHoteles reporte;

    while (true) {
        short op = Menu();
        switch (op)
        {
        case 1:
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
                Hoteles* nuevoHoteles = new Hoteles(nombre, estrellas, ofreceDesayuno, telefono, ofreceServicio);
                reporte.agregarHoteles(nuevoHoteles);
                break;
        }
        case 2:
        {
            //Mostrar datos
            reporte.mostrarTodosHoteles();
            break;
                        
        }
        case 3:
        {
            //Modificar un contacto
                int indice;
                cout << "Ingrese el indice del hotel a modificar: ";
                cin >> indice;
                reporte.modificarRegistro(indice - 1);
                break;
        }
        case 4:
        {
            // Eliminar el registro de hotel
            int indice;
            cout << "Ingrese el indice del hotel a eliminar: ";
            cin >> indice;
            reporte.eliminarRegistro(indice - 1);
            break;
        }
        case 5:
        {
            // integrantes
            reporte.integrantes();
            break;
        }
        case 6: {
            // Reporte de hoteles con desayuno
            reporte.reporteServicioDesayuno();
            break;
        }
        case 7:
        {
            //  Reporte de hoteles con servicio
            reporte.reporteservicioAeropuerto();
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
