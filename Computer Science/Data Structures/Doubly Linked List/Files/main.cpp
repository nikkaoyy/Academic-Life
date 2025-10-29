// Universidad Distrital Francisco José de Caldas
//
// Hecho por: Nicolás Martínez Pineda && Ian Nicolás Sandoval Martínez 
//
//
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "lista_doble.h"
using namespace std;

// -----------------------------------------------------
// Estructura para almacenar datos de Persona
// -----------------------------------------------------
struct Persona {
    string cedula;
    string nombre;
    string codigoEstudiante;
    string carrera;
    int edad;
    
    // Constructor por defecto
    Persona() : cedula(""), nombre(""), codigoEstudiante(""), carrera(""), edad(0) {}
    
    // Constructor con parámetros
    Persona(string ced, string nom, string cod, string car, int ed) 
        : cedula(ced), nombre(nom), codigoEstudiante(cod), carrera(car), edad(ed) {}
};

// Función para imprimir una persona
void imprimirPersona(const Persona& p) {
    cout << "Cédula: " << p.cedula << " | Nombre: " << p.nombre 
         << " | Código: " << p.codigoEstudiante << " | Carrera: " << p.carrera 
         << " | Edad: " << p.edad;
}

// Función para cargar datos desde archivo
void cargar_desde_archivo(ListaDoble<Persona>& lista, const string& nombreArchivo) {
    ifstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo: " << nombreArchivo << endl;
        return;
    }
    
    // IMPORTANTE: Vaciar la lista antes de cargar para evitar duplicados
    lista.vaciar_lista();
    
    string linea;
    // Saltar la primera línea si es un encabezado
    getline(archivo, linea);
    
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string cedula, nombre, codigo, carrera;
        int edad;
        
        // Formato esperado: cedula,nombre,codigo,carrera,edad
        getline(ss, cedula, ',');
        getline(ss, nombre, ',');
        getline(ss, codigo, ',');
        getline(ss, carrera, ',');
        ss >> edad;
        
        Persona p(cedula, nombre, codigo, carrera, edad);
        lista.insertar_final(p);
    }
    
    archivo.close();
    cout << "Datos cargados exitosamente. Total: " << lista.getTam() << " personas.\n";
}

// Función para guardar datos en archivo
void guardar_en_archivo(ListaDoble<Persona>& lista, const string& nombreArchivo) {
    ofstream archivo(nombreArchivo.c_str());
    if (!archivo.is_open()) {
        cout << "No se pudo crear el archivo: " << nombreArchivo << endl;
        return;
    }
    
    // Escribir encabezado
    archivo << "cedula,nombre,codigo,carrera,edad\n";
    
    for (int i = 0; i < lista.getTam(); i++) {
        Persona p = lista.obtenerDato(i);
        archivo << p.cedula << ","
                << p.nombre << ","
                << p.codigoEstudiante << ","
                << p.carrera << ","
                << p.edad << "\n";
    }
    
    archivo.close();
    cout << "Datos guardados exitosamente en: " << nombreArchivo << endl;
}

// Función para buscar por cédula
void buscar_por_cedula(ListaDoble<Persona>& lista, const string& cedula) {
    for (int i = 0; i < lista.getTam(); i++) {
        Persona p = lista.obtenerDato(i);
        if (p.cedula == cedula) {
            cout << "\n=== Persona encontrada en posición " << i << " ===\n";
            imprimirPersona(p);
            cout << endl;
            return;
        }
    }
    cout << "No se encontró ninguna persona con cédula: " << cedula << endl;
}

// Función para buscar por código
void buscar_por_codigo(ListaDoble<Persona>& lista, const string& codigo) {
    for (int i = 0; i < lista.getTam(); i++) {
        Persona p = lista.obtenerDato(i);
        if (p.codigoEstudiante == codigo) {
            cout << "\n=== Estudiante encontrado en posición " << i << " ===\n";
            imprimirPersona(p);
            cout << endl;
            return;
        }
    }
    cout << "No se encontró ningún estudiante con código: " << codigo << endl;
}

// Función para eliminar por cédula
void eliminar_por_cedula(ListaDoble<Persona>& lista, const string& cedula) {
    for (int i = 0; i < lista.getTam(); i++) {
        Persona p = lista.obtenerDato(i);
        if (p.cedula == cedula) {
            lista.eliminar(i);
            cout << "Persona con cédula " << cedula << " eliminada exitosamente.\n";
            return;
        }
    }
    cout << "No se encontró ninguna persona con cédula: " << cedula << endl;
}

int main() {
    // Creamos la lista de personas
    ListaDoble<Persona> listaPersonas;
    
    // Variables para el menú
    int opcion, pos;
    string nombreArchivo = "personas.txt";
    
    cout << "=== PROGRAMA DE LISTA DOBLEMENTE ENLAZADA - PERSONAS ===\n";
    
    do {
        cout << "\nSeleccione una acción:\n";
        cout << "1. Cargar datos desde archivo\n";
        cout << "2. Agregar persona al inicio\n";
        cout << "3. Agregar persona al final\n";
        cout << "4. Insertar persona en posición\n";
        cout << "5. Mostrar todas las personas\n";
        cout << "6. Buscar persona por posición\n";
        cout << "7. Buscar por cédula\n";
        cout << "8. Buscar por código de estudiante\n";
        cout << "9. Modificar persona\n";
        cout << "10. Eliminar persona por posición\n";
        cout << "11. Eliminar persona por cédula\n";
        cout << "12. Guardar datos en archivo\n";
        cout << "13. Tamaño de la lista\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;
        cin.ignore(); // Limpiar buffer

        try {
            switch (opcion) {
                case 1: {
                    cargar_desde_archivo(listaPersonas, nombreArchivo);
                    break;
                }

                case 2: {
                    string cedula, nombre, codigo, carrera;
                    int edad;
                    
                    cout << "Ingrese cédula: ";
                    getline(cin, cedula);
                    cout << "Ingrese nombre: ";
                    getline(cin, nombre);
                    cout << "Ingrese código de estudiante: ";
                    getline(cin, codigo);
                    cout << "Ingrese carrera: ";
                    getline(cin, carrera);
                    cout << "Ingrese edad: ";
                    cin >> edad;
                    cin.ignore();
                    
                    Persona p(cedula, nombre, codigo, carrera, edad);
                    listaPersonas.insertar_inicio(p);
                    cout << "Persona agregada al inicio.\n";
                    break;
                }

                case 3: {
                    string cedula, nombre, codigo, carrera;
                    int edad;
                    
                    cout << "Ingrese cédula: ";
                    getline(cin, cedula);
                    cout << "Ingrese nombre: ";
                    getline(cin, nombre);
                    cout << "Ingrese código de estudiante: ";
                    getline(cin, codigo);
                    cout << "Ingrese carrera: ";
                    getline(cin, carrera);
                    cout << "Ingrese edad: ";
                    cin >> edad;
                    cin.ignore();
                    
                    Persona p(cedula, nombre, codigo, carrera, edad);
                    listaPersonas.insertar_final(p);
                    cout << "Persona agregada al final.\n";
                    break;
                }

                case 4: {
                    cout << "Ingrese la posición: ";
                    cin >> pos;
                    cin.ignore();
                    
                    string cedula, nombre, codigo, carrera;
                    int edad;
                    
                    cout << "Ingrese cédula: ";
                    getline(cin, cedula);
                    cout << "Ingrese nombre: ";
                    getline(cin, nombre);
                    cout << "Ingrese código de estudiante: ";
                    getline(cin, codigo);
                    cout << "Ingrese carrera: ";
                    getline(cin, carrera);
                    cout << "Ingrese edad: ";
                    cin >> edad;
                    cin.ignore();
                    
                    Persona p(cedula, nombre, codigo, carrera, edad);
                    listaPersonas.insertar_pos(p, pos);
                    cout << "Persona insertada en posición " << pos << ".\n";
                    break;
                }

                case 5: {
                    if (listaPersonas.lista_vacia()) {
                        cout << "La lista está vacía.\n";
                    } else {
                        cout << "\n=== LISTA COMPLETA DE PERSONAS ===\n";
                        for (int i = 0; i < listaPersonas.getTam(); i++) {
                            cout << "Posición " << i << ": ";
                            imprimirPersona(listaPersonas.obtenerDato(i));
                            cout << endl;
                        }
                    }
                    break;
                }

                case 6: {
                    cout << "Ingrese la posición a buscar: ";
                    cin >> pos;
                    cin.ignore();
                    cout << "\n=== Persona en posición " << pos << " ===\n";
                    imprimirPersona(listaPersonas.obtenerDato(pos));
                    cout << endl;
                    break;
                }

                case 7: {
                    string cedula;
                    cout << "Ingrese cédula a buscar: ";
                    getline(cin, cedula);
                    buscar_por_cedula(listaPersonas, cedula);
                    break;
                }

                case 8: {
                    string codigo;
                    cout << "Ingrese código de estudiante: ";
                    getline(cin, codigo);
                    buscar_por_codigo(listaPersonas, codigo);
                    break;
                }

                case 9: {
                    cout << "Ingrese la posición a modificar: ";
                    cin >> pos;
                    cin.ignore();
                    
                    string cedula, nombre, codigo, carrera;
                    int edad;
                    
                    cout << "Ingrese nueva cédula: ";
                    getline(cin, cedula);
                    cout << "Ingrese nuevo nombre: ";
                    getline(cin, nombre);
                    cout << "Ingrese nuevo código: ";
                    getline(cin, codigo);
                    cout << "Ingrese nueva carrera: ";
                    getline(cin, carrera);
                    cout << "Ingrese nueva edad: ";
                    cin >> edad;
                    cin.ignore();
                    
                    Persona p(cedula, nombre, codigo, carrera, edad);
                    listaPersonas.modificar(pos, p);
                    cout << "Persona modificada exitosamente.\n";
                    break;
                }

                case 10: {
                    cout << "Ingrese la posición a eliminar: ";
                    cin >> pos;
                    cin.ignore();
                    listaPersonas.eliminar(pos);
                    cout << "Persona eliminada.\n";
                    break;
                }

                case 11: {
                    string cedula;
                    cout << "Ingrese cédula a eliminar: ";
                    getline(cin, cedula);
                    eliminar_por_cedula(listaPersonas, cedula);
                    break;
                }

                case 12: {
                    guardar_en_archivo(listaPersonas, nombreArchivo);
                    break;
                }

                case 13: {
                    cout << "El tamaño de la lista es: " << listaPersonas.getTam() << " personas.\n";
                    break;
                }

                case 0:
                    cout << "\nPrograma finalizado.\n";
                    break;

                default:
                    cout << "Opción inválida.\n";
            }
        } catch (out_of_range& e) {
            cout << "Error: " << e.what() << endl;
        } catch (exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (opcion != 0);

    return 0;
}
