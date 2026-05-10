#include "Grafo.h"

/* ============================================================
   CONSTRUCTOR — Inicializa el grafo vacío
   ============================================================ */

Grafo::Grafo() : numDestinos(0) {}

/* ============================================================
   CÁLCULO DEL PESO DE UNA ARISTA
   Fórmula:  peso = distancia*0.5 + costo*0.3 + (5.0-sat)*20.0
   - distancia: penaliza rutas largas
   - costo (distancia*1.2): penaliza rutas costosas
   - (5.0 - satisfaccion): penaliza destinos poco valorados
   ============================================================ */

float Grafo::calcularPeso(int idDest, float distancia) {
    float costo = distancia * 1.2f;
    float sat   = destinos[idDest].satisfaccion;
    return distancia * 0.5f + costo * 0.3f + (5.0f - sat) * 20.0f;
}

/* ============================================================
   AGREGAR ARISTA BIDIRECCIONAL
   Grafo no dirigido: se agrega en ambas direcciones.
   ============================================================ */

void Grafo::agregarArista(int origen, int dest, float peso) {
    Arista a1;
    a1.destino = dest;
    a1.peso    = peso;
    adyacencia[origen].push_back(a1);

    Arista a2;
    a2.destino = origen;
    a2.peso    = peso;
    adyacencia[dest].push_back(a2);
}
