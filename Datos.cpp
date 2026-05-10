#include "Grafo.h"

/* ¿
   INICIALIZACIÓN DE DATOS con 50 DESTINOS 
   Cada destino tiene: id, nombre, altitud, temperatura,
   tipo y satisfacción.
   Luego se definen las conexiones (aristas) con distancias
   reales en km, y el peso se calcula con la fórmula compuesta.
    */

void inicializarDatos(Grafo& grafo) {

    string nombres[] = {
        "Cartagena",        "Santa Marta",      "Medellin",
        "Bogota",           "Cali",             "Barranquilla",
        "Bucaramanga",      "Manizales",        "Pereira",
        "Armenia",          "Leticia",          "San Andres",
        "Villavicencio",    "Cucuta",           "Pasto",
        "Popayan",          "Ibague",           "Neiva",
        "Monteria",         "Valledupar",       "Tunja",
        "Florencia",        "Quibdo",           "Arauca",
        "Mocoa",            "Parque Tayrona",   "Ciudad Perdida",
        "Cano Cristales",   "Desierto Tatacoa", "Laguna de Tota",
        "Cascada Tequendama","Nevado del Ruiz",  "Valle del Cocora",
        "Salento",          "Jardin",           "Guatape",
        "Piedra del Penol", "Barichara",        "Playa Blanca",
        "Isla Baru",        "Los Flamencos",    "Cienaga",
        "Cabo San Juan",    "Termales Santa Rosa","Amacayacu",
        "Canon Chicamocha", "El Cocuy",         "Los Nevados",
        "Chiribiquete",     "Sierra Nevada"
    };

    string tipos[] = {
        "ciudad",  "playa",    "ciudad",   "ciudad",  "ciudad",
        "ciudad",  "ciudad",   "ciudad",   "ciudad",  "ciudad",
        "parque",  "playa",    "ciudad",   "ciudad",  "ciudad",
        "ciudad",  "ciudad",   "ciudad",   "ciudad",  "ciudad",
        "ciudad",  "ciudad",   "ciudad",   "ciudad",  "ciudad",
        "parque",  "montanna", "parque",   "desierto","parque",
        "parque",  "montanna", "parque",   "parque",  "parque",
        "parque",  "parque",   "ciudad",   "playa",   "playa",
        "parque",  "playa",    "playa",    "parque",  "parque",
        "parque",  "montanna", "montanna", "parque",  "montanna"
    };

    int altitudes[] = {
          2,  6, 1495, 2600,  995,  18,  959, 2160, 1411, 1483,
         96,  6,  467,  320, 2527, 1702, 1285,  442,   20,  168,
       2782, 242,   54,  125,  593,   12,  950,  200,  800, 3015,
       2400, 5321, 2400, 1895, 1750, 1887, 1887, 1850,    0,    0,
          5,   5,    0, 2500,  120, 1956, 4000, 3800,  800, 5775
    };

    float temps[] = {
        28, 28, 22, 14, 23, 28, 23, 17, 21, 18,
        27, 27, 25, 24, 12, 18, 20, 25, 28, 25,
        12, 25, 27, 27, 22, 27, 14, 28, 22,  8,
        12,  0, 15, 18, 19, 22, 22, 17, 30, 30,
        28, 28, 25, 12, 27, 18,  4,  5, 25, 20
    };

    float sats[] = {
        4.5f, 4.7f, 4.8f, 4.2f, 4.0f, 3.9f, 4.1f, 4.6f, 4.5f, 4.4f,
        4.8f, 4.9f, 4.0f, 3.5f, 4.2f, 4.3f, 4.0f, 4.1f, 3.8f, 4.0f,
        4.2f, 3.9f, 4.1f, 3.7f, 4.3f, 5.0f, 4.9f, 5.0f, 4.7f, 4.5f,
        4.4f, 4.8f, 4.9f, 4.8f, 4.7f, 4.9f, 4.8f, 4.7f, 4.9f, 4.8f,
        4.3f, 4.2f, 4.8f, 4.5f, 4.8f, 4.6f, 4.9f, 4.8f, 5.0f, 4.9f
    };

    int totalDestinos = MAX_DESTINOS;
    grafo.numDestinos = totalDestinos;
    grafo.destinos.resize(totalDestinos);
    grafo.adyacencia.resize(totalDestinos);

    for (int i = 0; i < totalDestinos; i++) {
        grafo.destinos[i].id           = i;
        grafo.destinos[i].nombre       = nombres[i];
        grafo.destinos[i].altitud      = altitudes[i];
        grafo.destinos[i].temperatura  = temps[i];
        grafo.destinos[i].tipo         = tipos[i];
        grafo.destinos[i].satisfaccion = sats[i];
    }

    /* --- Conexiones (pares de destinos con distancia en km) --- */
    float conexiones[][3] = {
        {0,1,220},  {0,5,120},  {0,18,310}, {0,38,45},  {0,39,50},
        {1,5,80},   {1,25,35},  {1,26,60},  {1,40,60},  {1,41,25},
        {2,8,50},   {2,7,80},   {2,33,170}, {2,34,100}, {2,35,45},
        {2,36,65},  {3,2,415},  {3,6,320},  {3,16,200}, {3,20,150},
        {3,12,86},  {3,29,200}, {3,30,40},  {4,2,440},  {4,14,400},
        {4,15,137}, {4,17,207}, {5,19,200}, {5,6,300},  {6,13,200},
        {6,37,280}, {7,8,50},   {8,9,50},   {9,32,50},  {10,44,100},
        {11,0,900}, {12,3,86},  {14,15,80}, {16,17,100},{17,28,40},
        {18,0,310}, {19,1,200}, {20,3,150}, {21,10,400},{22,8,300},
        {23,6,500}, {24,14,200},{25,1,35},  {26,1,60},  {27,3,600},
        {28,17,40}, {29,20,100},{31,2,200}, {32,9,50},  {33,8,30},
        {34,2,100}, {35,2,45},  {37,6,280}, {38,0,45},  {42,1,80},
        {43,2,150}, {45,6,200}, {46,6,280}, {47,2,200}, {48,3,900},
        {49,1,100}, {40,5,60},  {41,1,25},  {36,2,65},  {30,3,40}
    };

    int numConexiones = sizeof(conexiones) / sizeof(conexiones[0]);
    for (int i = 0; i < numConexiones; i++) {
        int   o    = (int)conexiones[i][0];
        int   d    = (int)conexiones[i][1];
        float dist = conexiones[i][2];
        float peso = grafo.calcularPeso(d, dist);
        grafo.agregarArista(o, d, peso);
    }
}
