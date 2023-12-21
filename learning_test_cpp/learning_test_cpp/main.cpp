//
//  main.cpp
//  Test pointer
//
//  Created by walle on 19/12/2023.
//

#include <iostream>

#include "main.hpp"

const double mon_pié = 3.14159; // d é f i n i t i o n .
std::string emptys{'z'};
int isemptys= emptys.begin() == emptys.end();
namespace test {int i=2500;}
//using test::i; // 2e définition de i or i a été déjà définie.
int main(int argc, const char * argv[]) {
         std::cout << '\\' << std::endl;
    std::cout << isemptys << std::endl;
    std::cout << "2 * 4 - 6 / 2 = " << 2 * 4 - 6 / 2 << std::endl;
    int réponse { 42 };
      std::cout << "La réponse à la Grande Question est " << réponse << std::endl;
    double weight1 = 122.03;
    int weight2 = static_cast<int>(weight1);
    std::cout << "i  : " << test::i << std::endl;

    int q = 5;
    int *const p = &q;
    int *const q2  = p;
    
    
       //Valid
       *p = 7;
    std::cout << q << std::endl;
    std::cout << *p << std::endl;
    std::cout << p << std::endl;
    std::cout << &q << std::endl;
     
    *q2 = 15;
    
        //Compilation error
    std::cout << &q2 << std::endl;
    std::cout << q2 << std::endl;
    std::cout << *q2 << std::endl;

     int const k  = 24;
    int const * const pk = &k;
    int const * const * pz= &pk;
    
    std::cout << "&pz: " << &pz << std::endl;
    
    std::cout << "pz: " << pz << std::endl;
    std::cout << "&pk: " << &pk << std::endl;
    
    std::cout << "pk: " << pk << std::endl;
    std::cout << "&k : " << &k << std::endl;
    std::cout << "*pz: " << *pz << std::endl;

    std::cout << "*pk: " << *pk << std::endl;
    
    pz = &q2;
    *q2 = 284;
    std::cout << "**pz  : " << **pz << std::endl;

    int t [] = { 5 , 4 , 3 , 2 , 1 } ; // t a b l e a u de 5 e n t i e r s , m o d i f i a bl e , non d é p l a ç a b l e
    std::cout << "t  : " << t << std::endl;
    std::cout << "&t  : " << &t << std::endl;


    return 0;
}

