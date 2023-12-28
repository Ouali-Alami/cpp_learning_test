//
//  test_generic_templates.tpp
//  learning_test_cpp
//
//  Created by walle on 22/12/2023.
//

#include "test_generic_templates.hpp"
#include <cxxabi.h>



/// compare two object of type T work with std type
/// @param t1 object
/// @param t2 object
template <typename T> T maxi( const T& t1 , const T& t2 )
{
    return ( t1 < t2 ) ? t2 : t1 ;
};
// i try to do some weird ugly mix between template and abstract and derivate class :/
// i know there is a easier way to do it, then we talk about it
// this code show lot of things
template <typename T>
struct ComparableThings {
//struct is by default public so here public is useless
public:
virtual const T&  operator<( const T  & things){
    const char * CPerson = "Person";
    int     status;
    //here i wanna cast this object to the T type for so that can compare class name
    // here i can cast with dynamic because is  polymorphic function(virtual) otherwise i would use static_cast
    const T & me = dynamic_cast< const T & >( *this );
    // i do the same things in the other object
    // but here we can use dynamic because its not this current object
    const T & otherobject = dynamic_cast< const T & >( things );
    // then we can compare the class name
   
    bool isNotEqualToPerson = strcmp(abi::__cxa_demangle(typeid(me).name(), 0, 0, &status) , CPerson);
    // we check if the comparable things are  two persons
    if (! isNotEqualToPerson){
       std::cout << "cool we can compare two person" << std::endl;
       // we create a new object Person from object things
       std::cout << "otherperson age =" << otherobject.mAge << std::endl;
       // he have access of the class member because we cast the object
       // it's ugly because you have a new class to compare
      // u need to modify this method instead of redined it in this new class
       return me.mAge < otherobject.mAge ? otherobject :  me;
    }
    // then you can add the other type test comparaison but its very ugly and complex
    // here we can say why is better to not over generalized code
    // it's better to do generic based on defined needs and able to accommodate future needs in a simple way
    // the solution here its just to redefined the operator< in the child(derived) class of this parent class
   return me;
}
};
// i try to do some weird ugly mix between template and abstract and derivate class :/ hahaha Person : ComparableThings<Person>
struct Person: public ComparableThings<Person>{
public:
    const char * mNom;
    const int  mAge;
public:
    Person( const char * nom, const int  age ) : mNom(nom) , mAge(age) {}
    //CopyConstructible
    Person( const Person & other )
    : mNom( other.mNom )  , mAge( other.mAge ) {}
} ;

template <typename SomeObject , typename Fonction>
/// doSomethingWithAPointerAdress
/// @param so it description
/// @param f function to call given by reference
void doSomethingWithAPointerAdress( SomeObject so , Fonction& f )
{
    f( so );
}
    
    /// Description
struct Matrice {
Matrice() : detM22 ( 0.0 ) {}
// ad - bc
void operator () (  double matriceAddr[2][2])
{
    // here we manipulate only addresses
    //to get value of m 2,2
    detM22 = (*( *(matriceAddr + 0) + 0)) * (*( *(matriceAddr + 1) + 1)) - (*( *(matriceAddr + 0) + 1)) * (*( *(matriceAddr + 1) + 0));
}

double detM22 ;
};

