#include "NodoAsignatura.h"

NodoAsignatura::NodoAsignatura() {
	codigo = "";
	descripcion = "";
	cantidadEstudiantes = 0;
	siguiente = NULL;
	pEstudiante = NULL;
}

NodoAsignatura::NodoAsignatura(string _codigo, string _descripcion, int _cantidad) {
	codigo = _codigo;
	descripcion = _descripcion;
	cantidadEstudiantes = _cantidad;
	siguiente = NULL;
}

NodoAsignatura::~NodoAsignatura() {

}