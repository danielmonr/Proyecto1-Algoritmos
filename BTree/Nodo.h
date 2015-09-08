/*
 * =====================================================================================
 *
 *       Filename:  Nodo.h
 *
 *    Description:  Nodo para el árbol de búsqueda.
 *
 * =====================================================================================
 */

#pragma once
#include <iostream>
#include "Casilla.h"
#include "Ordenamiento.h"

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
		Nodo<T>* buscarLugar(T valor);
		
		bool lleno();
		int libre();
		bool nodoHoja();
		bool insertar(T valor);

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
		std::cout << "error - ubicación invalida" << std::endl;
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
		std::cout << "error - ubicacion invalida" << std::endl;
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
	std::cout << "falta - Nodo.ordenar()" << std::endl;
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

// Funcion para saber si es Nodo Hoja
template <class T>
bool Nodo<T>::nodoHoja(){
	for (int i = 0; i <= t; ++i)
		if(hijos[i] == nullptr)
			return true;

	return false;
}

// Funcion para buscar de forma recursiva el Nodo Hoja de la insercion de un nuevo elemento
template <class T>
Nodo<T>* Nodo<T>::buscarLugar(T valor){
	for (int i = 0; i < t; ++i){
		if(arreglo[i].vacio())
			return this;
		else{
			if (arreglo[i] < valor)
				if(getIzquierdo(i) == nullptr)
					return this;
				else
					return getIzquierdo()->buscarLugar(valor);
			else if(arreglo[i] == valor){
				std::cout << "error - valores iguales" << std::endl;
				return nullptr;
			}
		}
	}
	if (arreglo[t-1].getDerecho() == nullptr)
		return this;
	else 
		return getDerecho(t-1)->buscarLugar(valor);
}

// Funcion para insertar un valor en el Nodo, y luego ordenarlo de nuevo, regresa un booleano de acuerdo al resultado de la operacion
template <class T>
bool Nodo<T>::insertar(T valor){
	int pos = libre();
	if (libre == -1)
		return false;
	if (arreglo[pos].vacio()){
		arreglo[pos].setValor(valor);
		ordenar();
		return true;
	}
	else
		return false;
}
