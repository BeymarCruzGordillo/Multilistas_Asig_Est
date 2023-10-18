#pragma once
#include "NodoAsignatura.h"
#include <iostream>
using namespace std;
class Multilista_A_E
{
public:
    NodoAsignatura* primero, * ultimo;
    Multilista_A_E();
    ~Multilista_A_E();

    void iniciar();
    int AsigVacia();
    void insertAsignatura(string cod, string desc);
    void EliminarAsignatura(string cod);
    void MostrarAsignaturas();

    NodoAsignatura* buscarAsignatura(string cod);
    NodoEstudiante* buscarEstudiante(string codAsig, string codEst);

    void CantidadAsignaturas();
    void mostrarAsignatura(string cod);
    void MostrarEstudiantesMasculinos();
    void MostrarEstudiantesFemeninos();

    void insertarEstudiante(string codAsig, string codEst, string nombreEst, string _apellidoEst,int _edad,string _sexo);
    void eliminarEstudiante(string codAsig, string codEst);
    void mostrarEstudiantes(string codAsig);

    void mostrarTodo();

};

