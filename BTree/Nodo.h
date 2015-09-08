/*
 * =====================================================================================
 *
 *       Filename:  Nodo.h
 *
 *    Description:  Nodo para el árbol de búsqueda.
 *
 * =====================================================================================
 */

#include <iostream>
#include "Casilla.h"

template <class T>
class Nodo{
	public:
		Nodo(int tamano, int level);
		T getInfo(int posicion);
		void setInfo(int posicion, T nueva);
		Nodo<T>* getIzquierdo(int posicion);
		void setIzquierdo(int posicion, Nodo<T>* hijo);
		Nodo<T>* getDerecho(int posicion);
		void setDerecho(int posicion, Nodo<T>* hijo);

		int getNivel();
		void setNivel(int level);

		void ordenar();
		
		bool lleno();
		int libre();

	private:
		Casilla<T>* arreglo;
		Nodo<T>** hijos;
		int t, nivel;
		
};

// Crea un Nodo con un tamaño de arreglo predefinido en la clase Árbol, Va a poder tener Tamano +1 hijos.
template <class T>
Nodo<T>::Nodo(int tamano, int level){
	t = tamano;
	nivel = level;
	Casilla<T>* arreglo = new Casilla<T>[t];
	hijos = new Nodo<T>* [t+1];
	for (int i = 0; i <= t; ++i){
		hijos[i] = nullptr;
	}
}

// Inicio de bloque de configuración de los hijos, o pedido, según su posición de acuerdo a los elementos del arreglo
template <class T>
Nodo<T>* Nodo<T>::getIzquierdo(int posicion){
	if (posicion < t)
		return hijos[posicion];
	else
		return nullptr;
}

template <class T>
void Nodo<T>::setIzquierdo(int posicion, Nodo<T>* hijo){
	if(posicion < t)
		hijos[posicion] = hijo;
	else
		std::cout << "error de ubicación" << std::endl;
}


template <class T>
Nodo<T>* Nodo<T>::getDerecho(int posicion){
	if (posicion < t)
		return hijos[posicion + 1];
	else
		return nullptr;
}

template <class T>
void Nodo<T>::setDerecho(int posicion, Nodo<T>* hijo){
	if (posicion < t)
		hijos[posicion + 1] = hijo;
	else
		std::cout << "error de ubicacion" << std::endl;
}
// Fin de bloque

// Bloque para utilidades del nivel del Nodo
template <class T>
int Nodo<T>::getNivel(){
	return nivel;
}

template <class T>
void Nodo<T>::setNivel(int level){
	nivel = level;
}
// Fin de bloque


// Regresa la informacion del nodo en la posicion señalada en el parametro
template <class T>
T Nodo<T>::getInfo(int posicion){
	return arreglo[posicion].getValor();
}

// Le da valor a algun elemento del nodo en la posicion deseada
template <class T>
void Nodo<T>::setInfo(int posicion, T nueva){
	arreglo[posicion].setValor(nueva);
}

// Encargado de ordenar los elementos dentro del Nodo
template < class T>
void Nodo<T>::ordenar(){
	// Falta el algoritmo
	std::cout << "Faltante - Nodo.ordenar()" << std::endl;
}

// Funcion para ver si el Nodo cumple con la capacidad minima
template <class T>
bool Nodo<T>::lleno(){
	for (int i = 0; i < t/2; ++i){
		if(arreglo[i].vacio())
			return false;
	}
	return true;
}


// Funcion para regresar el primer lugar libre en el Nodo, si no existe regresa -1
template <class T>
int Nodo<T>::libre(){
	for (int i = 0; i <t ;++i){
		if(arreglo[i].vacio())
			return i;
	}
	return -1;
}