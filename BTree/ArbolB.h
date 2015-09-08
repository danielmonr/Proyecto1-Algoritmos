/*
 * =====================================================================================
 *
 *       Filename:  ArbolB.h
 *
 *    Description:  Arbol B, compuesto por Nodos del archivo Nodo.h
 *
 * =====================================================================================
 */

#pragma once
#include <iostream>
#include "Nodo.h"
#include "Casilla.h"
#include "Ordenamiento.h"

template <class T>
class ArbolB{
	private:
		Nodo<T>* raiz = nullptr;
		int n;
	public:
		ArbolB(int N);

		Nodo<T>* getRaiz();
		void setRaiz(Nodo<T>* nodor);
		
		bool insertarValor(T valor);
		Nodo<T>* getNodoHoja(T valor);

		Nodo<T>* crearNodo();

		Casilla<T> buscar(T info);
		T* ordenarArreglo(T a[]);

		void imprimir();

		bool dividirNodo(Nodo<T>* nododiv, T valor);
};

// Constructor del Arbol
template <class T>
ArbolB<T>::ArbolB(int N){
	n = N;
	Nodo<T>* r = crearNodo();
	raiz = r;
	raiz->setPadre(nullptr);
}

// Funcion para obtener la raiz
template <class T>
Nodo<T>* ArbolB<T>::getRaiz(){
	return raiz;
}

// Funcion para poner una raiz al arbol
template <class T>
void ArbolB<T>::setRaiz(Nodo<T>* nodor){
	raiz = nodor;
	raiz->setPadre(nullptr);
}

// Funcion para insertar un valor en el arbol, debe de ser de forma que este ordenado, regresa un booleano dependendiendo del exito de la operacion
template <class T>
bool ArbolB<T>::insertarValor(T valor){
	Nodo<T>* hoja = getNodoHoja(valor);
	if (hoja == nullptr)
		return false;
	
	if(hoja->libre != -1){
		if(hoja->insertar(valor))
			return true;
		else
			return false;
	}
	else
		return dividirNodo(hoja, valor);
}

// Funcion para buscar el nodo hoja en el que debe de incluirse el nuevo valor.
template <class T>
Nodo<T>* ArbolB<T>::getNodoHoja(T valor){
	return raiz->buscarLugar(valor);
}

// Funcion para buscar un elemento en el ArbolB
template <class T>
Casilla<T> ArbolB<T>::buscar(T info){
	// Vacio, no se como o.o
	std::cout << "falta - ArbolB.buscar()" << std::endl;
	return NULL;
}

// Funcion para imprimir el arbol
template <class T>
void ArbolB<T>::imprimir(){
	// Vacio
	std::cout<< "falta - ArbolB.imprimir()" << std::endl;
}

// Funcion para hacer una inserción con la ayuda de una división de Nodo
template <class T>
bool ArbolB<T>::dividirNodo(Nodo<T>* nododiv, T valor){
	Nodo<T>* izquierdo = crearNodo();
	Nodo<T>* derecho = crearNodo();
	
	int k = (2*n) + 1;
	int med = k/2;
	T* temp = new T[k];
	for (int i = 0; i < k-1; ++i){
		temp[i] = nododiv->getInfo(i);
	}
	temp[k-1] = valor;
	temp = ordenarArreglo(temp);
	T medio = temp[med];

	if(nododiv->getPadre() == nullptr){
		Nodo<T>* nr = crearNodo();
		if(!(nr->insertar(medio)))
			return false;
		raiz = nr;
		nr->setIzquierdo(0, izquierdo);
		nr->setDerecho(0, derecho);
		for(int i = 0; i < med; ++i){
			izquierdo->insertar(temp[i]);
		}
		for(int i = med+1; i < k; ++i){
			derecho->insertar(temp[i]);
		}
	}

	// Vacio
	std::cout << "falta - ArbolB.dividirNodo()" << std::endl;
	return false;
}

// Funcion para la creacion de un Nodo con el numero de casillas 'm' adecuado
template <class T>
Nodo<T>* ArbolB<T>::crearNodo(){
	Nodo<T> * nuevo = new Nodo<T>(2*n);
	return nuevo;
}

// Funcion auxiliar para arreglar arreglos de tipo T
template <class T>
T* ArbolB<T>::ordenarArreglo(T a[]){
	return a;
}
