#include <iostream>
#include <ctime>
#include <cstdlib>
#include "RedBlackTree.h"

using namespace std;

int main()
{

  RedBlackTree<int> * rbtree = new RedBlackTree<int>();

    int v;
    srand (time(NULL));
    for(int i = 0; i < 12; i++)
    {
        v = rand() % 1000;
        rbtree->insertRedBlack(v);
    }

//    rbtree->insertRedBlack(1);
//    rbtree->insertRedBlack(6);
//    rbtree->insertRedBlack(8);
//    rbtree->insertRedBlack(11);
//    rbtree->insertRedBlack(13);
//    rbtree->insertRedBlack(15);
//    rbtree->insertRedBlack(17);
//    rbtree->insertRedBlack(22);
//    rbtree->insertRedBlack(25);
//    rbtree->insertRedBlack(27);

    std::cout << "Imprimiendo en orden ascendente" << std::endl;
    rbtree->inOrder();
    std::cout << "Fin Imprimiendo en orden ascendente" << std::endl << std::endl;

    std::cout << "Imprimiendo en orden descendente" << std::endl;
    rbtree->orderDesc();
    std::cout << "Fin Imprimiendo en orden descendente" << std::endl;

    if(rbtree->search(20))
    {
        cout << "Si" << endl;
    } else {
        cout << "No" << endl;
    }
    if(rbtree->search(15))
    {
        cout << "Si" << endl;
    } else {
        cout << "No" << endl;
    }

//    rbtree->deleteRedBlack(15);
//     rbtree->deleteRedBlack(22);
//      rbtree->deleteRedBlack(11);
//       rbtree->deleteRedBlack(13);
//
    rbtree->isRedBlack(rbtree);

}
