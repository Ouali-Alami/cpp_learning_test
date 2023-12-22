//
//  test_generic_templates.tpp
//  learning_test_cpp
//
//  Created by walle on 22/12/2023.
//

#include "test_generic_templates.hpp"

/// compare two object of type T
/// @param t1 object
/// @param t2 object
template <typename T> T maxi( const T& t1 , const T& t2 )
{
return ( t1 < t2 ) ? t2 : t1 ;
};

struct Chou {
Chou( const char * nom ) : mNom(nom) {}
Chou( const Chou & other ) //CopyConstructible
: mNom( other.mNom ) {}
const char * mNom; //but not LessThanComparable
} ;

template <typename SomeObject , typename Fonction>
/// doSomething
/// @param so <#it description#>
/// @param itEnd <#itEnd description#>
/// @param f function to call given by reference
void doSomethingWithAPointerAdress( SomeObject so , Fonction& f )
{
    f( so );
}

struct Matrice {
Matrice() : detM22 ( 0.0 ) {}
// ad - bc
void operator () (  double matriceAddr[2][2] )
{
    // here we manipulate only addresses to get value of m 2,2
    detM22 = (*( *(matriceAddr + 0) + 0)) * (*( *(matriceAddr + 1) + 1)) - (*( *(matriceAddr + 0) + 1)) * (*( *(matriceAddr + 1) + 0));
}

double detM22 ;
};

