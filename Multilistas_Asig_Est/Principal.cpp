#include <iostream>
#include "Multilista_A_E.h"


using namespace std;
int main() {
		Multilista_A_E* MList=new Multilista_A_E;
		MList->iniciar();

		string codA, descripcion, cantidadEstudiantes;
		string codE, nombre, apellido, sexo;
		int edad;
		int opc;
		
		do
		{
			system("cls");
			cout << " LISTA DE BRIGADAS" << endl;
			cout << " Seleccione la opcion a realizar\n\n";
			cout << " 1.- Insertar una Asignatura\n";
			cout << " 2.- Insertar Estudiante\n";
			cout << " 3.- Buscar Asignatura \n";
			cout << " 4.- Cantidad de Asignaturas\n";
			cout << " 5.- Mostrar todos los estudiantes del sexo masculino\n";
			cout << " 6.- Mostrar todos los estudiantes de sexo femenino\n";
			cout << " 7.- Mostrar toda la multilista\n";
			cout << " 8.- Mostrar todas las Asignaturas\n";
			cout << " 9.- Mostrar Estudiantes de una asignatura\n";
			cout << " 8.- Salir";
			cout << "Opcion(1-8)=> ";


			cin >> opc;
			switch (opc)
			{
			case 1:
				cout << "Codigo Asignatura: "<<endl;
				cin >> codA;
				cout << "Nombre de la asignatura: "<<endl;
				cin >> descripcion;
				MList->insertAsignatura(codA,descripcion);
				cout << "\nPresiones un atecla para continuar";
				(void)getchar();
				(void)getchar();
				break;
			case 2:
				cout << "Codigo De la Asignatura" << endl;
				cin >> codA;
				cout << "Codigo Estudiante: "<<endl;
				cin >> codE;
				cout << "Nombre: " << endl;
				cin >> nombre;
				cout << "Apellido: "<<endl;
				cin >> apellido;
				cout << "Edad: ";
				cin >> edad;
				cout << "sexo: ";
				cin >> sexo;
				MList->insertarEstudiante(codA,codE,nombre,apellido,edad,sexo);
				cout << "\nPresiones un atecla para continuar";
				(void)getchar();
				(void)getchar();
				break;
			case 3:
				cout << "\n Codigo de Asignatura" << endl;
				cin >> codA;
				MList->mostrarAsignatura(codA);
				cout << "\nPresiones un atecla para continuar";;
				(void)getchar();
				(void)getchar();
				break;
			case 4:
				MList->CantidadAsignaturas();
				
				cout << "\nPresiones un atecla para continuar";
				(void)getchar();
				(void)getchar();
				break;
			case 5:
				MList->MostrarEstudiantesMasculinos();
				cout << "\nPresiones un atecla para continuar";
				(void)getchar();
				(void)getchar();
				break;
			case 6:
				MList->MostrarEstudiantesFemeninos();
				cout << "\nPresiones un atecla para continuar";
				(void)getchar();
				(void)getchar();
				break;
			case 7:
				MList->mostrarTodo();
				cout << "\nPresiones un atecla para continuar";
				(void)getchar();
				(void)getchar();
				break;
				break;
			case 8:
				MList->MostrarAsignaturas();
				cout << "\nPresiones un atecla para continuar";
				(void)getchar();
				(void)getchar();
				break;
				break;
			case 9:
				cout << "Codigo de la Asignatura: " << endl;
				cin >> codA;
				MList->mostrarEstudiantes(codA);
				cout << "\nPresiones un atecla para continuar";
				(void)getchar();
				(void)getchar();
				break;
			case 10:
				
				break;

			default:
				cout << "Opcion no valida" << endl;
				cout << "\nPresiones un atecla para continuar";
				(void)getchar();
				(void)getchar();
				break;
			}
		} while ((opc != 10));


	return 0;
}