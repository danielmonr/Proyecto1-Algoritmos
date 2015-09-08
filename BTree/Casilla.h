/*
 * =====================================================================================
 *
 *       Filename:  Casilla.h
 *
 *    Description:  Cassila de uno de los Nodos
 *
 * =====================================================================================
 */

#include <iostream>

template <class T>
class Casilla{
	private:
		T valor;
		bool empty;
	public:
		Casilla();
		Casilla(T value);

		T getValor();
		void setValor(T nueva);

		bool vacio();
		void vaciar();

		bool operator <(T b);
		bool operator >(T b);

};

template <class T>
Casilla<T>::Casilla(){
	valor = NULL;
	empty = true;
}

template <class T>
Casilla<T>::Casilla(T value){
	valor = value;
	empty = false;
}

template <class T>
bool Casilla<T>::operator< (T b){
	return valor < b;
}

template <class T>
bool Casilla<T>::operator> (T b){
	return valor > b;
}

template <class T>
T Casilla<T>::getValor(){
	if (!empty)
		return valor;
	else
		return NULL;
}

template <class T>
void Casilla<T>::setValor(T nueva){
	valor = nueva;
	empty = false;
}

template <class T>
bool Casilla<T>::vacio(){
	return empty;
}

template <class T>
void Casilla<T>::vaciar(){
	empty = true;
	valor = NULL;
}
