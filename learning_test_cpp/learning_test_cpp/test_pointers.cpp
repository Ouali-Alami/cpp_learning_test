//
//  test_pointers.cpp
//  learning_test_cpp
//
//  Created by walle on 22/12/2023.
//

#include "test_pointers.hpp"
#include <string>


void getSizeOfArrayWithoutTheStdFunction(){
    int tbl[] = {10, 12, 221};
    int size = *(&tbl + 1) - tbl;
    //tbl  = &tbl[0] => adress of first element
    //&tbl = &tbl[2] => adress of last element
    // so 3+1 -1
    std::cout << "size of array" << size << " \n";
}

void changeValOfPointerOfConstantPointerOfConstantInt(){
    int const k  = 24;
    int const * const pk = &k;
    int const * const * pz= &pk;
    
    std::cout << "&pz: " << &pz << std::endl;
    
    std::cout << "pz == &pk" << std::endl;
    std::cout << "pz: " << pz << std::endl;
    std::cout << "&pk: " << &pk << std::endl;

    std::cout << " pk == &k == $pz  " << std::endl;
    std::cout << "pk: " << pk << std::endl;
    std::cout << "&k : " << &k << std::endl;
    std::cout << "*pz: " << *pz << std::endl;
    
    std::cout << "*pk: " << *pk << std::endl;
    std::cout << "**pz: " << *pz << std::endl;
    
    // **pz = 2 -> error because int is const
    
    // then if you want to hack the int const * const * pz variable
    // here we create a new pointer q2 of type int * const q2 this replace the type int const *const of pointer pk pointed by pz
    int q = 0;
    int * const q2 = &q;
    // here u can change the value of pz by giving him the address of int * const p that replace the old address of int const * const pk variable
    pz =  &q2;
    // now we can change the value of  int const * const * pz even if the the int is declared const by changing the value of q2 we can't modifie directly pz so **pz is forbidden but *q2 = is ok
    *q2 = 284;
    // and we check the value of ** pz
    std::cout << "**pz  : " << **pz << std::endl;
    
}

void  stringIsEmpty (std::string& chaine ){

    std::cout
    << "get size of the string : " << chaine.size() << ""
    << " then test first char [" << *chaine.begin() << "]"
    << "equals to last  char [" << *chaine.end()
    << "] result : "
    << (chaine.begin() == chaine.end())
    << std::endl;
}
