#include "Grafo.h"

/* 
   PUNTO DE ENTRADA — MENÚ PRINCIPAL
   Crea el grafo, carga los datos y ejecuta el bucle del menú.
*/

int main() {
    Grafo grafo;
    inicializarDatos(grafo);

    int opcion;

    do {
        cout << "\n========================================" << endl;
        cout << "   SISTEMA DE RUTAS TURISTICAS" << endl;
        cout << "   Colombia - Destinos Satisfactorios" << endl;
        cout << "========================================" << endl;
        cout << "1. Ver todos los destinos" << endl;
        cout << "2. Ruta optima entre dos destinos" << endl;
        cout << "3. Tour de 5 destinos recomendados" << endl;
        cout << "4. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarDestinos(grafo);
                break;
            case 2:
                rutaOptima(grafo);
                break;
            case 3: {
                mostrarDestinos(grafo);
                int fav;
                cout << "\nIngrese ID del destino que le gusto: ";
                cin >> fav;
                if (fav >= 0 && fav < grafo.numDestinos)
                    recomendarTour(grafo, fav);
                else
                    cout << "ID invalido." << endl;
                break;
            }
            case 4:
                cout << "Hasta luego!" << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}
