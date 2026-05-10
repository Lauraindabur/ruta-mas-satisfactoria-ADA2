# Sistema de Rutas Turisticas - Colombia

Este proyecto es una aplicacion de consola desarrollada en C++ que permite gestionar y optimizar rutas entre 50 destinos turisticos de Colombia. Utiliza algoritmos de grafos para encontrar caminos optimos y generar recomendaciones personalizadas basadas en la satisfaccion del usuario y la eficiencia del viaje.

## Descripcion de la Solucion

El sistema modela los destinos como nodos en un grafo, donde las conexiones (aristas) representan rutas reales. El peso de estas rutas se calcula mediante una formula compuesta que considera:
- Distancia fisica en kilometros.
- Costo estimado de transporte.
- Puntaje de satisfaccion del destino de llegada.

## Caracteristicas Principales

1. Catalogo de Destinos: Visualizacion de 50 destinos con informacion sobre altitud, temperatura, tipo y satisfaccion.
2. Ruta Optima: Implementacion del Algoritmo de Dijkstra para encontrar el camino mas corto (de menor peso) entre cualquier par de destinos.
3. Recomendacion de Tour: Generacion automatica de un itinerario de 5 destinos basado en un ratio de satisfaccion/esfuerzo, garantizando variedad en los tipos de destinos visitados.

## Estructura del Proyecto

El codigo esta organizado de forma modular:

- main.cpp: Contiene el punto de entrada y la logica del menu principal interactivo.
- Grafo.h: Define las estructuras de datos (Destino, Arista) y la interfaz de la clase Grafo.
- Grafo.cpp: Implementa los metodos base de la clase Grafo (constructor, calculo de peso, insercion de aristas).
- Algoritmos.cpp: Contiene la logica compleja (Dijkstra, recomendacion de tour y funciones de visualizacion).
- Datos.cpp: Encargado de la inicializacion de los 50 destinos y sus conexiones iniciales.

## Requisitos

- Compilador de C++ (como GCC/MinGW o Clang).
- Terminal o consola de comandos.

## Compilacion

Para compilar el proyecto y generar el ejecutable, ejecute el siguiente comando en la carpeta del proyecto:

```bash
g++ -o rutas_turisticas.exe main.cpp Grafo.cpp Algoritmos.cpp Datos.cpp
```

## Ejecucion

Una vez compilado, puede iniciar el programa con el siguiente comando:

```powershell
.\rutas_turisticas.exe
```

## Manual de Uso

Al iniciar el programa, se presentara un menu con las siguientes opciones:

1. Ver todos los destinos: Muestra una tabla con los IDs y detalles de cada lugar. Use esta opcion para identificar los IDs de origen y destino.
2. Ruta optima entre dos destinos: Solicita el ID de origen y destino para mostrar el camino exacto y el peso total del viaje.
3. Tour de 5 destinos recomendados: Solicita el ID de un destino que le haya gustado para generar una recomendacion automatica de 5 lugares similares o cercanos con alta satisfaccion.
4. Salir: Finaliza la ejecucion de la aplicacion.
