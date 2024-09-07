#include "iostream"
using namespace std;
#include "ArrPlatos.h"

short Menu()
{
	short op;
	do
	{
		cout << "*****MENU******" << endl;
		cout << "1.Agregar plato" << endl;
		cout << "2.Modificar datos de un plato" << endl;
		cout << "3.Eliminar un plato" << endl;
		cout << "4.Reporte de platos picantes" << endl;
		cout << "5.Reporte de platos caros" << endl;
		cout << "6.Mostrar todos los platos" << endl;
		cout << "7.Salir\n";
		cout << "Ingrese la opcion..."; cin >> op;
	} while (op < 1 || op > 8);
	return op;
}

int main()
{
	srand(time(nullptr));
	ArrPlatos reporte;

	while (true)
	{
		short op = Menu();
		switch (op)
		{
		case 1:
		{
			string nombre;
			bool esFrio, esPicante;
			float calorias, precioPromedio;
			cout << "Nombre del Plato: "; cin >> nombre;
			cout << "Es Frio (1=Si, 0=No): "; cin >> esFrio;
			cout << "Es Picante (1=Si, 0=No): "; cin >> esPicante;
			cout << "Cantidad de Calorias: "; cin >> calorias;
			cout << "Precio Promedio: "; cin >> precioPromedio;

			//Crear un nuevo plato
			Platos* nuevosPlatos = new Platos(nombre, esFrio, esPicante, calorias, precioPromedio);
			reporte.agregarPlato(nuevosPlatos);
			break;
		}
		case 2:
		{
			int indice;
			cout << "Ingrese indice del plato a modificar: "; cin >> indice;
			reporte.modificarPlato(indice - 1);
			break;
		}
		case 3:
		{
			int indice;
			cout << "Ingrese indice del plato a modificar"; cin >> indice;
			reporte.eliminarPlato(indice - 1);
			break;
		}
		case 4:
		{
			reporte.reportePlatoPicantes();
			break;
		}
		case 5:
		{
			reporte.reportePlatoCaros();
			break;
		}
		case 6:
		{
			reporte.mostrarTodosPlatos();
			break;
		}
		case 7:
		{
			cout << "Saliendo del programa....";
			return 0;
		}

		default:
			break;
		}


		system("pause>0");
		system("cls");
	}
	system("pause>0");
	return 0;
}

