#pragma once
#pragma once
#include "Eclipse.h"

class ArrEclipse {
private:
	int n; //almacena el # actual de objetos Eclisp en el arreglo
	Eclipse** arr; // arreglo dinamico

public:

	ArrEclipse() {
		//Inciar el contador
		n = 0;
		//Iniciamos el arreglo con Punteros a Eclipse con tamaño 0
		arr = new Eclipse * [n];
	}

	~ArrEclipse() {}

	void addEclipse() {
		//Creamos un objeto Eclipse
		Eclipse* e = new Eclipse();
		//Crear un arreglo con espacio para un elemento adicional
		Eclipse** aux = new Eclipse * [n + 1];

		//Copiamos los punteros del arreglo
		for (int i = 0; i < n; i++) {
			aux[i] = arr[i];
		}


		//Agregamos un nuevo objeto Eclipse
		aux[n] = e;

		n++; 
		arr = aux;//Asignamos un nuevo arreglo
	}

	//Editar
	void editEclipseType(int position, string newType) {
		arr[position]->setType(newType);
	}

	//Eliminar
	void deleteEclipse() {
		Eclipse** aux = new Eclipse * [n - 1];

		for (int i = 0; i < n - 1; i++) {
			aux[i] = arr[i];
		}

		n--;
		arr = aux;
	}

	void eclipsesVisiblesEurope() {
		for (int i = 0; i < n; i++) {
			if (arr[i]->getVisibility() == "Europe") {
				arr[i]->printData();
			}
		}
	}

	void eclipsesEarthquakes() {
		for (int i = 0; i < n; i++) {
			if (arr[i]->getEarthquake() == "Yes") {
				arr[i]->printData();
			}
		}
	}

	void eclipsesInTheNight() {
		for (int i = 0; i < n; i++) {
			if (arr[i]->getHour() >= 18) {
				arr[i]->printData();
			}
		}
	}

	void printArray() {
		for (int i = 0; i < n; i++) {
			cout << endl;
			cout << "Eclipse " << i << endl;
			arr[i]->printData();
		}
	}
};
