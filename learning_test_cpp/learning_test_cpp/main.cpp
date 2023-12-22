//
//  main.cpp
//  learning_test_cpp
//
//  Created by walle on 21/12/2023.
//

#include "main.hpp"
#include "test_pointers.hpp"
#include "test_generic_templates.tpp"


int main(int argc, const char * argv[]) {
    //stringIsEmpty("");
    changeValOfPointerOfConstantPointerOfConstantInt();
    getSizeOfArrayWithoutTheStdFunction();
    Chou rouge ( "Chou rouge" ) ;
    Chou brux ( "Chou de Bruxelles " );
    //Chou melange = max( rouge , brux );
    //int j = max(4,17);
    //double y = max( 2 , 1. 5 ) ; -> error cannot compare double with int
    double z = maxi((double)2,1.5) ;
    //double x = max(3.5,14.2);
    //double t = max<double>(2,1.5) ;
    // ad - bc
    double matrice2[2][2] = {2.0,3.0,10.0,11.0};
    Matrice m22 ;
    // here just need to give the first adress of array
    doSomethingWithAPointerAdress( matrice2 , m22 );
    std::cout << "Somme=" << m22.detM22 << std::endl;

    return 0;
}


