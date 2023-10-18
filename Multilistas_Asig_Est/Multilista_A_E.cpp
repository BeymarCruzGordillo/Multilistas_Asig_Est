#include "Multilista_A_E.h"
#include "NodoAsignatura.h"
#include "NodoEstudiante.h"

Multilista_A_E::Multilista_A_E() {
    primero = NULL;
    ultimo = NULL;
}

Multilista_A_E::~Multilista_A_E() {}

void Multilista_A_E::iniciar() {
    primero = NULL;
    ultimo = NULL;
}

int Multilista_A_E::AsigVacia() {
    if (primero==NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void Multilista_A_E::insertAsignatura(string cod, string desc) {
    NodoAsignatura* nodoAsig = new NodoAsignatura();

    nodoAsig->setCodigo(cod);
    nodoAsig->setDescripcion(desc);

    if (AsigVacia()) {
        primero = nodoAsig;
        ultimo = nodoAsig;
        ultimo->setSiguiente(primero);
    }
    else {
        nodoAsig->setSiguiente(primero);
        primero = nodoAsig;
        ultimo->setSiguiente(primero);
    }
}

NodoAsignatura* Multilista_A_E::buscarAsignatura(string cod) {
    NodoAsignatura* p;
    p = primero;

    if (AsigVacia()) {
        return NULL;
    }

    do {
        if (p->getCodigo() == cod) {
            return p;
        }
        p = p->getSiguiente();
    } while (p != primero);

    return NULL;
}

void Multilista_A_E::EliminarAsignatura(string cod) {
    if (AsigVacia()) {
        cout << "Lista vacia de asignaturas" << endl;
        return;
    }

    NodoAsignatura* p = primero;
    NodoAsignatura* q = NULL;
    if (primero == ultimo) {
        primero = NULL;
        ultimo = NULL;
    }
    else {
        while (p->getCodigo() != cod) {
            q = p;
            p = p->getSiguiente();
            if (p == primero) {
                cout << "No se encontró la asignatura con el codigo: " << cod << endl;
                break;
            }
        }
        if (p == primero) {
            primero = primero->getSiguiente();
            ultimo->setSiguiente(primero);

            p->~NodoAsignatura();
        }
        else {
            if (p == ultimo) {
                q->setSiguiente(primero); 
                ultimo = q; 

                p->~NodoAsignatura();
            }
            else {
                q->setSiguiente(p->getSiguiente());
                p->~NodoAsignatura();
            }
        }
    }
    
}

void Multilista_A_E::MostrarAsignaturas() {
    NodoAsignatura* p= new NodoAsignatura ;
    p = primero;
    if (AsigVacia()) {
        cout << "Lista vacia de asignaturas" << endl;
    }
    else {
        do {
            cout << endl << "----------<<<<>>>>>-----------" << endl;
            cout << "Codigo  " << endl;
            cout << p->getCodigo() << endl;;
            cout << "Descripcion " << endl;
            cout << p->getDescripcion() << endl;
            cout << "Cantidad Estudiantes" << endl;
            cout << p->getCantidadEstudiantes() << endl;
            p = p->getSiguiente();
        } while (p != primero);
    }
}

void Multilista_A_E::insertarEstudiante(string codAsig, string codEst, string nombreEst,string apellidoEst, int _edad,string _sexo) {
    NodoAsignatura* p;
    if (AsigVacia()) {
        cout << "Lista vacia de asignaturas" << endl;
    }
    else {
        p = buscarAsignatura(codAsig);
        if (p == NULL) {
            cout << "No se encontro ninguna asignatura  con ese codido de asignatura" << endl;
        }
        else {
            NodoEstudiante* nodoEstudiante = new NodoEstudiante();
            nodoEstudiante->setId(codAsig);
            nodoEstudiante->setNombre(nombreEst);
            nodoEstudiante->setApellido(apellidoEst);
            nodoEstudiante->setEdad(_edad);
            nodoEstudiante->setSexo(_sexo);
            if (p->getPEstudiante()==NULL) {
                nodoEstudiante->setSiguiente(p->getPEstudiante());
                p->setPEstudiante(nodoEstudiante);
            }
            else {
                NodoEstudiante* auxi ;

                nodoEstudiante->setSiguiente(p->getPEstudiante());
                auxi = nodoEstudiante->getSiguiente();
                p->setPEstudiante(nodoEstudiante);
                auxi->setAnterior(nodoEstudiante);
            }
            p->setCantidadEstudiantes();
        }
    }
    
}


NodoEstudiante* Multilista_A_E::buscarEstudiante(string codAsig, string codEst) {
    if (AsigVacia()) {
        cout << "Lista de Asignaturas vacia" << endl;
        return NULL;
    }
    else {
        NodoAsignatura* p;

        p = buscarAsignatura(codAsig);
        if (p == NULL) {
            cout << "No se encontro ninguna asignatura con el codigo " << codAsig << endl;
        }
        else {
            NodoEstudiante* q;
            q= p->getPEstudiante();
            while (q != NULL && q->getId() != codEst) {
                q = q->getSiguiente();
            }
            return q;
        }
    }
}

void Multilista_A_E::mostrarEstudiantes(string codAsig) {
    NodoAsignatura* p;
    if (AsigVacia()) {
        cout << "Lista de Asignaturas vacia" << endl;
    }
    else {
        p = buscarAsignatura(codAsig);
        if (p == NULL) {
            cout << "No existe ninguna asignatura" << endl;
        }
        else {
            NodoEstudiante* q=new NodoEstudiante;
            q = p->getPEstudiante();
            cout << "\n Nombre de la Asignatura: " << p->getDescripcion() << endl;

            while (q != NULL) {
                cout << "\n----------<<<<<<>>>>>>--------" << endl;
                cout << "Codigo: ";
                cout << q->getId() << endl;
                cout << "Nombre: ";
                cout << q->getNombre() << endl;
                cout << "Apellido: ";
                cout << q->getApellido() << endl;
                cout << "Edad: ";
                cout << q->getEdad() << endl;
                cout << "sexo: ";
                cout << q->getSexo() << endl;

                q = q->getSiguiente();
            }
        }
    }
}

void Multilista_A_E::eliminarEstudiante(string codAsig, string codEst) {
    NodoAsignatura* p;
    NodoEstudiante* nodoEstudiante();

    if (AsigVacia()) {
        cout << "\nLista de Asignaturas vacia" << endl;
    }
    else {
        p = buscarAsignatura(codAsig);
        if (p == NULL) {
            cout << "\nNo existe La asignatura con codigo " <<codAsig<< endl;
        }
        else {
            if (p->getPEstudiante()==NULL) {
                cout << "\nAsignatura sin estudiantes" << endl;
            }
            else {
                NodoEstudiante* nodoEstudiante;
                nodoEstudiante = buscarEstudiante(codAsig,codEst);
                if (nodoEstudiante==NULL) {
                    cout << "No se encontro ninguna estudiante con el codigo de " << codEst << endl;
                }
                else {
                    NodoEstudiante* auxi,*auxi2;
                    auxi = p->getPEstudiante();
                    if (auxi->getSiguiente()==NULL) {
                        p->setPEstudiante(NULL);
                    }
                    else {
                        if (nodoEstudiante == p->getPEstudiante()) {
                            p->setPEstudiante(auxi->getSiguiente());
                        }
                        else {
                            auxi = nodoEstudiante->getAnterior();
                            auxi->setSiguiente(nodoEstudiante->getSiguiente());
                            if (auxi->getSiguiente() != NULL) {

                                auxi2 = nodoEstudiante->getSiguiente();
                                auxi2->setAnterior(auxi);

                            }                            
                        }
                    }
                    nodoEstudiante->~NodoEstudiante();

                }
              
            }
        }
    }
}

void Multilista_A_E::CantidadAsignaturas() {
    int contador = 0;
    NodoAsignatura* p = primero;
    if (AsigVacia()) {
        cout << "\nCantidad de asignaturas: " << contador << endl;
    }
    else {
        do {
            contador++;
            p = p->getSiguiente();
        } while (p != primero);
        cout << "Cantidad de asignaturas: " << contador << endl;
    }
}


void Multilista_A_E::MostrarEstudiantesMasculinos() {
    NodoAsignatura* nodoAsig;
    NodoEstudiante* nodoEst=new NodoEstudiante;
    if (AsigVacia()) {
        cout << "Lista de asignaturas vacia" << endl;
    }
    else {
        nodoAsig = primero;
        do {
            nodoEst = nodoAsig->getPEstudiante();
            while (nodoEst!=NULL) {
                if (nodoEst->getSexo()== "Masculino" || nodoEst->getSexo() == "masculino" || nodoEst->getSexo() == "M" || nodoEst->getSexo() == "m") {
                    cout << "\n----------<<<<<<>>>>>>--------" << endl;
                    cout << "Asignatura :";
                        cout << nodoAsig->getDescripcion() << endl;
                        cout << "Codigo: ";
                        cout << nodoEst->getId() << endl;
                        cout << "Nombre: ";
                        cout << nodoEst->getNombre() << endl;
                        cout << "Apellido: ";
                        cout << nodoEst->getApellido() << endl;
                        cout << "Edad: ";
                        cout << nodoEst->getEdad() << endl;
                        cout << "sexo: ";
                        cout << nodoEst->getSexo() << endl;
                }
                nodoEst=nodoEst->getSiguiente();
            }
            nodoAsig = nodoAsig->getSiguiente();
        } while (nodoAsig!=primero);
    }
}

void Multilista_A_E::MostrarEstudiantesFemeninos() {
    NodoAsignatura* nodoAsig;
    NodoEstudiante* nodoEst = new NodoEstudiante;
    if (AsigVacia()) {
        cout << "Lista de asignaturas vacia" << endl;
    }
    else {
        nodoAsig = primero;
        do {
            nodoEst = nodoAsig->getPEstudiante();
            while (nodoEst != NULL) {
                if (nodoEst->getSexo() == "Femenino" || nodoEst->getSexo() == "femenino" || nodoEst->getSexo() == "F" || nodoEst->getSexo() == "f") {
                    cout << "\n----------<<<<<<>>>>>>--------" << endl;
                    cout << "Asignatura :";
                    cout << nodoAsig->getDescripcion() << endl;
                    cout << "Codigo: ";
                    cout << nodoEst->getId() << endl;
                    cout << "Nombre: ";
                    cout << nodoEst->getNombre() << endl;
                    cout << "Apellido: ";
                    cout << nodoEst->getApellido() << endl;
                    cout << "Edad: ";
                    cout << nodoEst->getEdad() << endl;
                    cout << "sexo: ";
                    cout << nodoEst->getSexo() << endl;
                }
                nodoEst = nodoEst->getSiguiente();
            }
            nodoAsig = nodoAsig->getSiguiente();
        } while (nodoAsig != primero);
    }
}

void Multilista_A_E::mostrarTodo() {
    NodoAsignatura *nodoAsig= new NodoAsignatura;
    NodoEstudiante *nodoEst=new NodoEstudiante;
    nodoAsig = primero;
    if (AsigVacia()) {
        cout << "Lista de Estudiantes vacia" << endl;
    }
    else {
        do {
            nodoEst = nodoAsig->getPEstudiante();
            cout << "\n<<<<<<<<<<<<<<>>>>>>>>>>>>>>--------" << endl;
            cout << "Asignatura :";
            cout << nodoAsig->getDescripcion() << endl;
            cout << "Codigo de Asignatutra:  ";
            cout << nodoAsig->getCodigo() << endl;
            cout << "Cantidad de estudiantes";
            cout << nodoAsig->getCantidadEstudiantes() << endl;
            cout << "Los estudiantes de la Asignatura  " << nodoAsig->getDescripcion() << " son los siguientes: " << endl;
            while (nodoEst != NULL) {
                cout << "---------------" << endl;
                    cout << "Codigo: ";
                    cout << nodoEst->getId() << endl;
                    cout << "Nombre: ";
                    cout << nodoEst->getNombre() << endl;
                    cout << "Apellido: ";
                    cout << nodoEst->getApellido() << endl;
                    cout << "Edad: ";
                    cout << nodoEst->getEdad() << endl;
                    cout << "sexo: ";
                    cout << nodoEst->getSexo() << endl;

                nodoEst = nodoEst->getSiguiente();
            }
            nodoAsig = nodoAsig->getSiguiente();
        } while (nodoAsig != primero);
    }
}

void Multilista_A_E::mostrarAsignatura(string cod) {
    NodoAsignatura* p = new NodoAsignatura;
    p = primero;
    if (AsigVacia()) {
        cout << "Lista vacia de asignaturas" << endl;
    }
    else {
        p = buscarAsignatura(cod);
        if (p==NULL) {
            cout << "No se encontro ninguna Asignatura con el codigo de " << cod << endl;
        }
        else {
            cout << endl << "----------<<<<>>>>>-----------" << endl;
            cout << "Codigo  " << endl;
            cout << p->getCodigo() << endl;;
            cout << "Descripcion " << endl;
            cout << p->getDescripcion() << endl;
            cout << "Cantidad Estudiantes" << endl;
            cout << p->getCantidadEstudiantes() << endl;
            p = p->getSiguiente();
        }
    }
}




