#pragma once
class Fecha
{
public:
	Fecha()
	{
		dia = 0;
		mes = 0;
		anio = 0;
	}
	~Fecha() {}

	void mostrarFecha()const
	{
		cout << dia << "/" << mes << "/" << anio << endl;
	}

	void setDia(int dia)
	{
		this->dia = dia;
	}
	void setMes(int mes)
	{
		this->mes = mes;
	}
	void setAnio(int anio)
	{
		this->anio = anio;
	}
	int getDia()const
	{
		return this->dia;
	}
	int getMes()const
	{
		return this->mes;
	}
	int getAnio()const
	{
		return this->anio;
	}

private:
	int dia, mes, anio;
};

