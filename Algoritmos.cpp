#include "Grafo.h"

/* ============================================================
   ALGORITMO DE DIJKSTRA
   Paso 1: Inicializar distancias en infinito y previo en -1.
   Paso 2: Encontrar nodo no visitado con menor distancia (u).
   Paso 3: Relajar aristas de u hacia sus vecinos.
   ============================================================ */

void dijkstra(Grafo& grafo, int inicio,
              vector<float>& distancias, vector<int>& previo) {

    int n = grafo.numDestinos;
    vector<bool> visitado(n, false);

    distancias.assign(n, INF);
    previo.assign(n, -1);
    distancias[inicio] = 0.0f;

    for (int iter = 0; iter < n; iter++) {
        // Encontrar nodo no visitado con menor distancia
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!visitado[i] && (u == -1 || distancias[i] < distancias[u]))
                u = i;
        }
        if (u == -1 || distancias[u] == INF) break;
        visitado[u] = true;

        for (int j = 0; j < (int)grafo.adyacencia[u].size(); j++) {
            int   v         = grafo.adyacencia[u][j].destino;
            float nuevaDist = distancias[u] + grafo.adyacencia[u][j].peso;
            if (nuevaDist < distancias[v]) {
                distancias[v] = nuevaDist;
                previo[v]     = u;
            }
        }
    }
}

/* 
   RECONSTRUCCIÓN DE RUTA
   Recorre recursivamente previo[] para imprimir el camino
   desde el origen hasta el destino indicado.
 */

void imprimirRuta(Grafo& grafo, vector<int>& previo, int destino) {
    if (previo[destino] == -1) {
        cout << grafo.destinos[destino].nombre;
        return;
    }
    imprimirRuta(grafo, previo, previo[destino]);
    cout << " -> " << grafo.destinos[destino].nombre;
}

/*
   RECOMENDACIÓN DE TOUR (paso a paso el algoritmo)
   1. Ejecutar Dijkstra desde el favorito.
   2. Calcular ratio satisfaccion / peso_minimo.
   3. Ordenar por ratio descendente.
   4. Seleccionar 5 con variedad de tipo (max 2 iguales).
   5. Reconstruir y mostrar la ruta de cada uno.
 */

void recomendarTour(Grafo& grafo, int idFavorito) {
    int n = grafo.numDestinos;
    vector<float> distancias;
    vector<int>   previo;

    dijkstra(grafo, idFavorito, distancias, previo);

    // Calcular ratio satisfaccion / distancia
    vector<float> ratio(n);
    for (int i = 0; i < n; i++) {
        if (i == idFavorito || distancias[i] == INF || distancias[i] == 0)
            ratio[i] = -1.0f;
        else
            ratio[i] = grafo.destinos[i].satisfaccion / distancias[i];
    }

    vector<int> indices(n);
    for (int i = 0; i < n; i++) indices[i] = i;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[indices[j]] > ratio[indices[i]]) {
                int tmp    = indices[i];
                indices[i] = indices[j];
                indices[j] = tmp;
            }
        }
    }

    cout << "\n=== TOUR RECOMENDADO DESDE "
         << grafo.destinos[idFavorito].nombre << " ===" << endl;

    vector<string> tiposUsados;
    int mostrados = 0;

    for (int i = 0; i < n && mostrados < 5; i++) {
        int idx = indices[i];
        if (ratio[idx] <= 0) continue;


        int cuentaTipo = 0;
        for (int t = 0; t < (int)tiposUsados.size(); t++) {
            if (tiposUsados[t] == grafo.destinos[idx].tipo)
                cuentaTipo++;
        }
        if (cuentaTipo >= 2) continue;

        tiposUsados.push_back(grafo.destinos[idx].tipo);
        mostrados++;

        string nombre = grafo.destinos[idx].nombre;
        cout << "\n" << mostrados << ". " << nombre;
        for (int p = (int)nombre.size(); p < 22; p++) cout << " ";
        cout << "(tipo: " << grafo.destinos[idx].tipo;
        for (int p = (int)grafo.destinos[idx].tipo.size(); p < 8; p++) cout << " ";
        cout << " | satisf: " << grafo.destinos[idx].satisfaccion
             << " | peso ruta: " << distancias[idx] << ")" << endl;
        cout << "   Ruta: ";
        imprimirRuta(grafo, previo, idx);
        cout << endl;
    }

    if (mostrados == 0)
        cout << "No se encontraron destinos recomendados desde este punto." << endl;
}



void mostrarDestinos(Grafo& grafo) {
    cout << endl;
    cout << left  << setw(4)  << "ID"
         << left  << setw(24) << "Nombre"
         << left  << setw(10) << "Tipo"
         << right << setw(5)  << "Temp"
         << right << setw(7)  << "Alt(m)"
         << right << setw(7)  << "Satisf" << endl;
    cout << "--------------------------------------------------------------" << endl;

    for (int i = 0; i < grafo.numDestinos; i++) {
        cout << left  << setw(4)  << i
             << left  << setw(24) << grafo.destinos[i].nombre
             << left  << setw(10) << grafo.destinos[i].tipo
             << right << setw(4)  << fixed << setprecision(0)
                                  << grafo.destinos[i].temperatura
             << right << setw(7)  << grafo.destinos[i].altitud
             << right << setw(6)  << fixed << setprecision(1)
                                  << grafo.destinos[i].satisfaccion
             << endl;
    }
}

/* 
   RUTA ÓPTIMA ENTRE DOS PUNTOS
   Solicita los ids, ejecuta Dijkstra, muestra camino y peso.
 */

void rutaOptima(Grafo& grafo) {
    int origen, dest;
    cout << "Ingrese ID de origen  (0-" << grafo.numDestinos - 1 << "): ";
    cin >> origen;
    cout << "Ingrese ID de destino (0-" << grafo.numDestinos - 1 << "): ";
    cin >> dest;

    if (origen < 0 || origen >= grafo.numDestinos ||
        dest   < 0 || dest   >= grafo.numDestinos) {
        cout << "ID invalido." << endl;
        return;
    }

    vector<float> distancias;
    vector<int>   previo;
    dijkstra(grafo, origen, distancias, previo);

    if (distancias[dest] == INF) {
        cout << "No existe ruta entre " << grafo.destinos[origen].nombre
             << " y " << grafo.destinos[dest].nombre << "." << endl;
    } else {
        cout << "\nRuta optima de " << grafo.destinos[origen].nombre
             << " a " << grafo.destinos[dest].nombre << ":" << endl;
        cout << "  Camino: ";
        imprimirRuta(grafo, previo, dest);
        cout << "\n  Peso total: " << fixed << setprecision(2)
             << distancias[dest] << endl;
    }
}
