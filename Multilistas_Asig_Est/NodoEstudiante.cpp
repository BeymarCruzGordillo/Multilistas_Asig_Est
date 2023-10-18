#include "NodoEstudiante.h"

NodoEstudiante::NodoEstudiante() {
	id = "";
	nombre = "";
	apellido = "";
	edad = 0;
	sexo = "";

	siguiente = nullptr;
	anterior = nullptr;
}

NodoEstudiante::NodoEstudiante(string _id, string _nombre, string _apellido, int _edad,string _sexo)
{
	id = _id;
	nombre = _nombre;
	apellido = _apellido;
	edad = _edad;
	sexo = _sexo;
}

NodoEstudiante::~NodoEstudiante() {

}

