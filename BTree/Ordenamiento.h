//
//  Ordenamiento.h
//  Ordenamiento
//
//  Created by Daniel on 01/09/14.
//  Copyright (c) 2014 Gotomo. All rights reserved.
//

#ifndef __Ordenamiento__Ordenamiento__
#define __Ordenamiento__Ordenamiento__

#include <iostream>
#include <algorithm>

using namespace std;

template <class T>
class Ordenamiento{
public:
    static void ordenamientoBurbuja(T [], int , bool(*)(T,T));
    static void ordenamientoinsercion(T [], int, bool(*)(T,T));
    static void ordenamientoSeleccion(T [], int , bool(*) (T,T));
    
    static void ordenamientoQuickSort(T [], bool(*)(T,T), int, int);
    static void ordenamientoMergeSort(T [], bool(*)(T,T), int, int, int);
    static void merge(T [], int, int, int, bool(*)(T,T), int);
    
	static void ordenamientoCounting(T [], int, bool(*)(T,T));
	static void ordenamientoCocktail(T [], int, bool(*)(T,T));
	static void ordenamientoBucket(T [], int, bool(*)(T,T));
	static void ordenamientoHeapSort(T [], int, bool(*)(T,T));
	static void ordenamientoRadixSort(T [], int, bool(*)(T,T));
    static void ordenamientoShellSort(T [], int, bool(*)(T,T));

	static void swap(T&, T&);
	static void siftDown(T*, int, int);
	static void countSort(T [], int, int);
    static bool asc(T, T);
    static bool desc(T,T);
};


template <class T>
bool Ordenamiento<T>::asc(T a, T b){
    return a>b;
}
template <class T>
bool Ordenamiento<T>::desc(T a, T b){
    return a<b;
}

template <class T>
void Ordenamiento<T>::ordenamientoBurbuja(T v[], int n, bool compara (T,T)){
    T temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > i; j--)
        {
            //if (v[j-1] > v[j])
            if(compara(v[j-1], v[j]))
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            } }
    }
}
template <class T>
void Ordenamiento<T>::ordenamientoinsercion(T v[], int n, bool compara (T,T)){
    T index;
    for (int i=1; i < n; i++)
    {
        index = v[i];
        int j = i-1;
        while (j >= 0 && compara(v[j], index))
        {
            v[j + 1] = v[j];
            j--; }
        v[j+1] = index;
    }
}
template <class T>
void Ordenamiento<T>::ordenamientoSeleccion(T v[], int n, bool compara (T,T)){
    int minimo = 0;
    T temp;
    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < n; j++)
        {
            //if (v[minimo] > v[j])
            if(compara(v[minimo], v[j])){
                minimo = j;
            }
        }
        temp = v[minimo];
        v[minimo] = v[i];
        v[i] = temp;
    }
}

template <class T>
void Ordenamiento<T>::ordenamientoCounting(T v[], int n, bool compara(T,T)){
	T min = *min_element(v, v+n);
	T max = *max_element(v, v+n);

	int repeticiones[max-min+1];
	for(int i = 0; i < (max-min+1); ++i){
		repeticiones[i]=0;
	}
	for(int i = 0; i < n; ++i){
		repeticiones[v[i]-min] += 1;
	}
	int punt = 0;
	for (int i = 0; i < (max-min+1); ++i){
		for(int j = 0; j < repeticiones[i]; ++j){
			v[punt] = i+min;
			punt++;
		}
	}
}

template <class T>
void Ordenamiento<T>::ordenamientoCocktail(T data[], int N, bool compara(T,T)){
    bool notSorted = true;
    while(notSorted)
    {
        notSorted = false;
        for(int i = 0; i < N; i++)
            if( compara(data[i], data[i+1]) )
            {
                int aux = data[i];
                data[i] = data[i+1];
                data[i+1] = aux;
                notSorted = true;
            }
        if( !notSorted ) break;
        notSorted = false;
        for(int i = N - 1; i > 0; i--)
            if(compara(data[i-1], data[i]) )
            {
                int aux = data[i];
                data[i] = data[i-1];
                data[i-1] = aux;
                notSorted = true;
            }
    }
}

template <class T>
void Ordenamiento<T>::ordenamientoBucket(T a[], int n, bool compara(T,T)){
	int buckets[1001];
	for (int i = 0; i < 1001; ++i){
		buckets[i] = 0;
	}
	for (int i = 0; i < n; ++i){
		++buckets[a[i]];
	}
	for (int i = 0, j = 0; j < 1001; ++j){
		for (int k = buckets[j]; k > 0; --k){
			a[i++] = j;
		}
	}
}

template <class T>
void Ordenamiento<T>::ordenamientoHeapSort(T a[], int n, bool compara(T,T)){
	for (int k = n/2; k >= 0; --k){
		siftDown(a, k, n);
	}

	while(n-1 > 0){
		swap(a[n-1], a[0]);
		siftDown(a,0,n-1);
		n--;
	}
}

template <class T>
void Ordenamiento<T>::swap(T& m, T& n){
    int tmp;
    tmp = m;
    m = n;
    n = tmp;
} 

template <class T>
void Ordenamiento<T>::siftDown(T a[], int k, int N){
	 while ( k*2 + 1 < N ) {
        /* For zero-based arrays, the children are 2*i+1 and 2*i+2 */
        int child = 2*k + 1;

        /* get bigger child if there are two children */
        if ((child + 1 < N) && (a[child] < a[child+1])) child++;

        if (a[k] < a[child]) {   /* out of max-heap order */
            swap( a[child], a[k] );
            /* repeat to continue sifting down the child now */
            k = child;
        }
        else
            return;
    }
}

template <class T>
void Ordenamiento<T>::countSort(T arr[], int n, int exp){
	T output[n];
	int i, count[10] = {0};
	for(i = 0; i<n; ++i)
		count[(arr[i]/exp)% 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	 for (i = n - 1; i >= 0; i--){
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	 }
	 for (i = 0; i < n; i++)
	    arr[i] = output[i];
}

template <class T>
void Ordenamiento<T>::ordenamientoRadixSort(T a[], int n, bool compara(T,T)){
	int max = *max_element(a, a+n);
	for(int i = 1; max / i > 0; i *=10){
		countSort(a, n, i);
	}
}

template <class T>
void Ordenamiento<T>::ordenamientoShellSort(T v[], int n, bool compara(T,T)){

    int gap, i, j;
    T temp;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

template <class T>
void Ordenamiento<T>::ordenamientoQuickSort(T a[], bool compara (T,T), int primero, int ultimo){
    int izquierdo = primero;
    int derecho = ultimo;
    int temp;
    //Se selecciona pivote
    int pivote = a[primero];
    if ( primero < ultimo) // Paso base
    {
        // particion
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && (!compara(a[izquierdo], pivote ))) izquierdo++;
            while ( compara(a[derecho], pivote )) derecho--;
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                temp = a[derecho];
                a[derecho] = a[izquierdo];
                a[izquierdo] = temp;
            }
        }
        
        // Se intercambia el pivote con el elemento de la posición derecha
        temp = a[derecho];
        a[derecho] = a[primero];
        a[primero] = temp;
        // Paso recursivo
        ordenamientoQuickSort ( a,compara, primero, derecho-1);
        ordenamientoQuickSort ( a, compara, izquierdo, ultimo);
    }
}

template <class T>
void Ordenamiento<T>::ordenamientoMergeSort(T v[], bool compara (T,T), int l, int n, int N){
    int m = (n+l)/2;
    if (n > l)
    {
        ordenamientoMergeSort (v, compara, l, m, N);
        ordenamientoMergeSort (v, compara, m+1, n, N);
        merge (v, l, m, n, compara, N);
    }
    
}

template <class T>
void Ordenamiento<T>::merge(T v[], int l, int m, int n, bool compara(T,T), int N){
    int i, j, k;
    T aux[N]; //Vectorauxiliar
    for(i=m+1;i>l;i--)
        aux[i-1] = v[i-1];
    
    for (j=m; j<n; j++)
            aux[n+m-j] = v[j+1];
    
    for(k=l;k<=n;k++) //Mezcla
        if (!compara(aux[i], aux[j]))
            v[k] = aux[i++];
        else
            v[k] = aux[j--];
    
}
#endif /* defined(__Ordenamiento__Ordenamiento__) */
