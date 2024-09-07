#pragma once
class Time
{
public:
	Time()
	{
	
	hour = rand() % 24;
	minute = rand() % 60;
	second = rand() % 60;
	}
	~Time(){}

	int getHour()
	{
		return hour;
	}

	string getCompleteTime()
	{
		//funcion para agreagar al final de una cadena un caracter
		string aux;
		//to_string para hacer una cadena
		//.append  Para añadir al final otra cadena de caracteres
		aux.append(to_string(hour));
		aux.append(":");
		aux.append(to_string(minute));
		aux.append(":");
		aux.append(to_string(second));

		return aux;
	}

private: 
	int hour;
	int minute;
	int second;

};
