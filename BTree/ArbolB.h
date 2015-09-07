/*
 * =====================================================================================
 *
 *       Filename:  ArbolB.h
 *
 *    Description:  Arbol B, compuesto por Nodos del archivo Nodo.h
 *
 * =====================================================================================
 */


#include <iostream>
#include "Nodo.h"

template <class T>
class ArbolB{
	private:
		Nodo<T>* raiz = nullptr;
		int n;
	public:
		ArbolB(int N);

		Nodo<T>* getRaiz();
		void setRaiz(Nodo<T>* nodor);
		
		void insertarValor(T valor);
		Nodo<T>* getNodoHoja(T valor);

		void buscar(T info);
		// void ordenar();

		void imprimir();

		void dividirNodo(Nodo<T>* nododiv);
};

// Constructor del Arbol
template <class T>
ArbolB<T>::ArbolB(int N){
	n = N;
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
}

// Funcion para insertar un valor en el arbol, debe de ser de forma que este ordenado
template <class T>
void ArbolB<T>::insertarValor(T valor){
	// Vacio
	std::cout << "falta - ArbolB.insertarValor()" << std::endl;
}

// Funcion para buscar el nodo hoja en el que debe de incluirse el nuevo valor.
template <class T>
Nodo<T>* ArbolB<T>::getNodoHoja(T valor){
	// Vacio
	std::cout << "falta - ArbolB.getNodoHoja()" << std::endl;
	return nullptr;
}

template <class T>
void ArbolB<T>::buscar(T info){
	// Vacio, no se como o.o
	std::cout << "falta - ArbolB.buscar()" << std::endl;
}

template <class T>
void ArbolB<T>::imprimir(){
	// Vacio
	std::cout<< "falta - ArbolB.imprimir()" << std::endl;
}

template <class T>
void ArbolB<T>::dividirNodo(Nodo<T>* nododiv){
	// Vacio
	std::cout << "falta - ArbolB.dividirNodo()" << std::endl;
}
