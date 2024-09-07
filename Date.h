#pragma once
class Date
{
public:
	Date()
	{
		//%30 limitada de 0 a 29 y +1 aumentada
		day = rand() % 30 + 1;
		month = rand() % 12 + 1;
		//Generar un numero aleaorio del 0 al 10 y sumarle 2014
		year = rand() % 22 + 2000;
	}
	~Date(){}

	string getCompleteDate()
	{
		//funcion para agreagar al final de una cadena un caracter
		string aux;
		//to_string para hacer una cadena
		//.append  Para añadir al final otra cadena de caracteres
		aux.append(to_string(day));
		aux.append("/");
		aux.append(to_string(month));
		aux.append("/");
		aux.append(to_string(year));
		// dd / mm / yyyy
		return aux;
	}

private:

	int day;
	int month;
	int year;

};

