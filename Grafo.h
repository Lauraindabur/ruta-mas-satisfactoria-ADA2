#ifndef GRAFO_H
#define GRAFO_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cfloat>

using namespace std;

#define MAX_DESTINOS 50
#define INF FLT_MAX

/* ============================================================
   ESTRUCTURA DE DATOS — DESTINO TURÍSTICO
   Cada destino se almacena con 6 atributos: id, nombre,
   altitud, temperatura, tipo y satisfacción.
   ============================================================ */

struct Destino {
    int    id;
    string nombre;
    int    altitud;       // metros sobre el nivel del mar
    float  temperatura;   // °C promedio anual
    string tipo;          // playa, montanna, ciudad, parque, desierto
    float  satisfaccion;  // escala 1.0 a 5.0
};

/* ============================================================
   ESTRUCTURA DE ARISTA
   Almacena el índice del destino vecino y el peso calculado
   con la fórmula compuesta.
   ============================================================ */

struct Arista {
    int   destino;
    float peso;
};

/* ============================================================
   CLASE GRAFO — LISTA DE ADYACENCIA
   Usa un vector de vectores para representar las conexiones.
   Cada posición i contiene la lista de aristas del destino i.
   ============================================================ */

class Grafo {
public:
    vector<Destino>         destinos;
    vector<vector<Arista>>  adyacencia;
    int                     numDestinos;

    Grafo();

    // Calcula el peso de una arista hacia idDest con distancia dada
    float calcularPeso(int idDest, float distancia);

    // Agrega arista bidireccional (grafo no dirigido)
    void agregarArista(int origen, int dest, float peso);
};

/* ============================================================
   FUNCIONES DE ALGORITMOS Y PRESENTACIÓN
   ============================================================ */

// Dijkstra: caminos mínimos desde un nodo inicio
void dijkstra(Grafo& grafo, int inicio,
              vector<float>& distancias, vector<int>& previo);

// Reconstruye e imprime la ruta usando el arreglo previo[]
void imprimirRuta(Grafo& grafo, vector<int>& previo, int destino);

// Genera tour de 5 destinos recomendados desde un favorito
void recomendarTour(Grafo& grafo, int idFavorito);

// Muestra tabla de todos los destinos
void mostrarDestinos(Grafo& grafo);

// Encuentra y muestra la ruta óptima entre dos puntos
void rutaOptima(Grafo& grafo);

// Inicializa los 50 destinos y conexiones
void inicializarDatos(Grafo& grafo);

#endif
