#pragma once
#include "NodoEstudiante.h"
#include <iostream>
using namespace std;

class NodoAsignatura
{
private:
	string codigo;
	string descripcion;
	int cantidadEstudiantes;

	NodoAsignatura* siguiente;
	NodoEstudiante* pEstudiante;

public:
	NodoAsignatura();
	NodoAsignatura(string _codigo, string _descripcion, int _cantidad);
	~NodoAsignatura();

public:
	//geters y seters

	string getCodigo() { return codigo; }
	string getDescripcion() { return descripcion; }
	int getCantidadEstudiantes() { return cantidadEstudiantes; }


	void setCodigo(string _codigo) { codigo = _codigo; }
	void setDescripcion(string _descripcion) { descripcion = _descripcion; }
	void setCantidadEstudiantes() { cantidadEstudiantes += 1; }

	void setSiguiente(NodoAsignatura* _siguiente) { siguiente = _siguiente; }
	NodoAsignatura* getSiguiente() { return siguiente; }

	void setPEstudiante(NodoEstudiante* _pEstudiante) { pEstudiante = _pEstudiante; }
	NodoEstudiante* getPEstudiante() { return pEstudiante; };
};

