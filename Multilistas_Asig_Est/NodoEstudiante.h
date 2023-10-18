#pragma once
#include <iostream>
using namespace std;
class NodoEstudiante
{
private:
	string id;
	string nombre;
	string apellido;
	int edad;
	string sexo;

	NodoEstudiante* siguiente;
	NodoEstudiante* anterior;

public:
	NodoEstudiante();
	NodoEstudiante(string _id, string _nombre, string _apellido, int _edad,string _sexo);
	~NodoEstudiante();

public:
	//metodos get y set
		
	string getId() { return id; }
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	int getEdad() { return edad; }
	string getSexo() { return sexo; }

	void setId(string _id) { id = _id; }
	void setNombre(string _nombre) { nombre = _nombre; }
	void setApellido(string _apellido) { apellido = _apellido; }
	void setEdad(int _edad) { edad = _edad; }
	void setSexo(string _sexo) { sexo = _sexo; }

	void setSiguiente(NodoEstudiante* _siguiente) { siguiente = _siguiente; }
	void setAnterior(NodoEstudiante* _anterior) { anterior = _anterior; }
	//void setSiguienteEstudiante(NodoEstudiante* _pEstudiante) { pEstudiante = _pEstudiante; };
	NodoEstudiante* getSiguiente() { return siguiente; }
	NodoEstudiante* getAnterior() { return anterior; }
};

