// Universidad Distrital Francisco Jos� de Caldas
//
// Hecho por: Nicol�s Mart�nez Pineda && Ian Nicol�s Sandoval Mart�nez 
//
//
#include <iostream>
#include "lista.h"
using namespace std;

int main() {
	//Creamos las listas con variables int, float y char
    Lista<int> listaEnteros;
    Lista<float> listaReales;
    Lista<char> listaCaracteres;
	
	//Declaramos las variables opcion y pos para lo que desee hacer el usuario con la lista
    int opcion, pos;
    cout << "=== PROGRAMA DE LISTAS GENERICAS ===\n";
	
	//Imprimimos nuestras 3 opciones de lista y una opci�n por si se desea cerrar el programa
    do {
        cout << "\nSeleccione el tipo de lista:\n";
        cout << "1. Enteros\n";
        cout << "2. Reales\n";
        cout << "3. Caracteres\n";
        cout << "0. Salir\n";
        cout << "Opci�n: ";
        cin >> opcion;

        if (opcion == 0) break;

        // Punteros para apuntar a la lista seleccionada
        if (opcion == 1) {
            cout << "\n--- Lista de Enteros ---\n";
        } else if (opcion == 2) {
            cout << "\n--- Lista de Reales ---\n";
        } else if (opcion == 3) {
            cout << "\n--- Lista de Caracteres ---\n";
        } else {
            cout << "Opci�n inv�lida.\n";
            continue;
        }
		
		//definimos acci�n y la leemos creando casos mediante un switch (accion)
        int accion;
        do {
            cout << "\nSeleccione una acci�n:\n";
            cout << "1. Insertar al inicio\n";
            cout << "2. Insertar al final\n";
            cout << "3. Insertar en posicion\n";
            cout << "4. Mostrar lista completa\n";
            cout << "5. Buscar elemento por posicion\n";
            cout << "6. Modificar elemento\n";
            cout << "7. Eliminar elemento\n";
            cout << "8. Tama�o de la lista\n";
            cout << "0. Volver al menu principal\n";
            cout << "Acci�n: ";
            cin >> accion;

            try {
                switch (accion) {
                    case 1: {
                        if (opcion == 1) {
                            int val;
                            cout << "Ingrese un entero: ";
                            cin >> val;
                            listaEnteros.insertar_inicio(val);
                        } else if (opcion == 2) {
                            float val;
                            cout << "Ingrese un real: ";
                            cin >> val;
                            listaReales.insertar_inicio(val);
                        } else {
                            char val;
                            cout << "Ingrese un caracter: ";
                            cin >> val;
                            listaCaracteres.insertar_inicio(val);
                        }
                        break;
                    }

                    case 2: {
                        if (opcion == 1) {
                            int val;
                            cout << "Ingrese un entero: ";
                            cin >> val;
                            listaEnteros.insertar_final(val);
                        } else if (opcion == 2) {
                            float val;
                            cout << "Ingrese un real: ";
                            cin >> val;
                            listaReales.insertar_final(val);
                        } else {
                            char val;
                            cout << "Ingrese un caracter: ";
                            cin >> val;
                            listaCaracteres.insertar_final(val);
                        }
                        break;
                    }

                    case 3: {
                        cout << "Ingrese la posicion: ";
                        cin >> pos;
                        if (opcion == 1) {
                            int val;
                            cout << "Ingrese un entero: ";
                            cin >> val;
                            listaEnteros.insertar_pos(val, pos);
                        } else if (opcion == 2) {
                            float val;
                            cout << "Ingrese un real: ";
                            cin >> val;
                            listaReales.insertar_pos(val, pos);
                        } else {
                            char val;
                            cout << "Ingrese un caracter: ";
                            cin >> val;
                            listaCaracteres.insertar_pos(val, pos);
                        }
                        break;
                    }

                    case 4: {
                        cout << "\nContenido de la lista:\n";
                        if (opcion == 1) {
                            for (int i = 0; i < listaEnteros.getTam(); i++)
                                cout << listaEnteros.obtenerDato(i) << " ";
                        } else if (opcion == 2) {
                            for (int i = 0; i < listaReales.getTam(); i++)
                                cout << listaReales.obtenerDato(i) << " ";
                        } else {
                            for (int i = 0; i < listaCaracteres.getTam(); i++)
                                cout << listaCaracteres.obtenerDato(i) << " ";
                        }
                        cout << endl;
                        break;
                    }

                    case 5: {
                        cout << "Ingrese la posici�n a buscar: ";
                        cin >> pos;
                        if (opcion == 1)
                            cout << "Dato: " << listaEnteros.obtenerDato(pos) << endl;
                        else if (opcion == 2)
                            cout << "Dato: " << listaReales.obtenerDato(pos) << endl;
                        else
                            cout << "Dato: " << listaCaracteres.obtenerDato(pos) << endl;
                        break;
                    }

                    case 6: {
                        cout << "Ingrese la posici�n a modificar: ";
                        cin >> pos;
                        if (opcion == 1) {
                            int val;
                            cout << "Nuevo entero: ";
                            cin >> val;
                            listaEnteros.modificar(pos, val);
                        } else if (opcion == 2) {
                            float val;
                            cout << "Nuevo real: ";
                            cin >> val;
                            listaReales.modificar(pos, val);
                        } else {
                            char val;
                            cout << "Nuevo caracter: ";
                            cin >> val;
                            listaCaracteres.modificar(pos, val);
                        }
                        break;
                    }

                    case 7: {
                        cout << "Ingrese la posicion a eliminar: ";
                        cin >> pos;
                        if (opcion == 1)
                            listaEnteros.eliminar(pos);
                        else if (opcion == 2)
                            listaReales.eliminar(pos);
                        else
                            listaCaracteres.eliminar(pos);
                        cout << "Elemento eliminado.\n";
                        break;
                    }
					
					case 8: {
					    cout << "El tama�o de la lista es: ";
					    if (opcion == 1)
					        cout << listaEnteros.getTam() << endl;
					    else if (opcion == 2)
					        cout << listaReales.getTam() << endl;
					    else
					        cout << listaCaracteres.getTam() << endl;
					    break;		
						}
					
                    case 0:
                        cout << "Volviendo al men� principal...\n";
                        break;

                    default:
                        cout << "Acci�n inv�lida.\n";
                }
            } catch (out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }

        } while (accion != 0);

    } while (opcion != 0);

    cout << "\nPrograma finalizado.\n";
    return 0;
}

