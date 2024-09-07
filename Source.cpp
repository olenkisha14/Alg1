#include "iostream"
using namespace std;
#include "ArrMotorizado.h"

short Menu()
{
	short op;
	do
	{
		cout << "\tMENU" << endl;
		cout << "1. Registrar motorizado" << endl;
		cout << "2. Eliminar un registro de motorizado" << endl;
		cout << "3. Mostrar registro de hoteles" << endl;
		cout << "4. Motorizado Mapi" << endl;
		cout << "5. Motorizado Glopo" << endl;
		cout << "6. Salir" << endl;
		cout << "Ingrese la opcion: ";
		cin >> op;

	} while (op < 1 || op > 7);
	return op; 
}



int main()
{
	ArrMotorizado reporte;
	while (true)
	{
		short op = Menu();
		switch (op)
		{
		case 1:
		{
			string nombre;
			string apellido;
			int placa;
			float kilometraje;
			bool esMapi;
			bool esGlopo;

			cout << "Nombre: "; cin >> nombre ;
			cout << "Apellido: "; cin >> apellido;
			cout << "Placa: "; cin >> placa ;
			cout << "Kilometraje: "; cin >> kilometraje ;
			cout << "Es Mapi(1=Si, 0=No): "; cin >> esMapi;
			cout << "Es Glopo(1=Si, 0=No): "; cin >> esGlopo ;

			Motorizado* nuevoMotorizado = new Motorizado(nombre, apellido, placa, kilometraje, esMapi, esGlopo);
			reporte.agregarMotorizado(nuevoMotorizado);
			break;
		}
		case 2:
		{
			int indice;
			cout << "Ingrese el indice a eliminar: "; cin >> indice;
			reporte.eliminarMotorizado(indice - 1);
			break;
		}
		case 3:
		{
			reporte.mostrarTotal();
			break;
		}
		case 4:
		{
			reporte.reporteMapi();
			break;
		}
		case 5:
		{
			reporte.reporteGlopo();
			break;
		}
		case 6:
		{
			cout << "Saliendo del programa...." << endl;
			return 0;
		}
		}

		system("pause>0");
		system("cls");
	}

	system("pause>0");
	return 0;
}