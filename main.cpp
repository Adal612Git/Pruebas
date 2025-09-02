#include <iostream>
using namespace std;

void menu();
void ingreso();
void consultar();

struct Estudiante {
    string nombre;
    int edad;
    string matricula;
    float promedio;
};

Estudiante estudiantes[10];
bool ocupado[10] = {false}; // Para saber si hay datos en la posición

void ingreso() {
    int posicion = 0;
    while (true) {
        cout << "--------------------------------------" << endl;
        cout << "La tabla admite 10 estudiantes." << endl;
        cout << "Ingrese la posición para registrar (1-10): ";
        cout << "\nEscriba 11 para volver al menú: ";
        cin >> posicion;

        if (posicion == 11) break;

        if (posicion < 1 || posicion > 10) {
            cout << "❌ Posición inválida. Intente de nuevo." << endl;
            continue;
        }

        int idx = posicion - 1;
        cout << "Ingrese el nombre: ";
        cin.ignore(); // para limpiar buffer
        getline(cin, estudiantes[idx].nombre);

        cout << "Ingrese la edad: ";
        cin >> estudiantes[idx].edad;

        cout << "Ingrese la matrícula: ";
        cin.ignore();
        getline(cin, estudiantes[idx].matricula);

        cout << "Ingrese el promedio: ";
        cin >> estudiantes[idx].promedio;

        ocupado[idx] = true;

        cout << "✅ Estudiante registrado en posición " << posicion << "." << endl;
    }
}

void consultar() {
    cout << "\n--- Consulta de Estudiantes ---" << endl;
    for (int i = 0; i < 10; i++) {
        if (ocupado[i]) {
            cout << "Posición " << (i + 1) << ": ";
            cout << "Nombre: " << estudiantes[i].nombre << ", ";
            cout << "Edad: " << estudiantes[i].edad << ", ";
            cout << "Matrícula: " << estudiantes[i].matricula << ", ";
            cout << "Promedio: " << estudiantes[i].promedio << endl;
        }
    }
    cout << "-----------------------------\n";
}

void menu() {
    int opcion = 0;
    do {
        cout << "\n______________________________________" << endl;
        cout << "Bienvenido, seleccione una opción:" << endl;
        cout << "1. Ingresar estudiantes" << endl;
        cout << "2. Consultar estudiantes" << endl;
        cout << "3. Salir del programa" << endl;
        cout << "--------------------------------------" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1: ingreso(); break;
            case 2: consultar(); break;
            case 3: cout << "Saliendo del programa." << endl; break;
            default: cout << "Opción inválida, intente de nuevo." << endl;
        }
    } while (opcion != 3);
}

int main() {
    menu();
    return 0;
}
