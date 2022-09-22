#ifndef POKEMON_H
#define POKEMON_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

class pokemon
{
    private:
    string USName;
    string JPName;
    int index;


    public:
    pokemon();

    pokemon(string name1, int num , string name2);
    //@pre - it must include the USAName, JPName and the index of pokemon
    //@post - initialzie the name for the USName, JPName and index

    ~pokemon();


    void print();
    //@post - print the USName, JPNanme and the idnex of pokemon

    static void static_print(pokemon poke);
    //@post - static type of print function, use for the BST cpp

    bool operator == (const pokemon& anotherone);
    //@post - overloading the operator '==';
    //@return - renturn true if their USName, JPName, index are same

    bool operator > (const pokemon& anotherone);
    //@post - overloading the operator '>'
    //@return - return true if the index is ibgger than the object's index
    
    bool operator < (const pokemon& anotherone);
    //@post - overloading the operator '<'
    //@return - return true if the index is smaller than the object's index


    bool operator == (int num);
    //@post - overloading the operator '==' with nums;
    //@return - return true if the num is euqal the object's index

    bool operator > (int num);
    //@post - overloading the operator '>' with nums;
    //@return - return true if the num is bigger than the object's index

    bool operator < (int num);
    //@post - overloading the operator '<' with nums;
    //@return - return true if the num is less than the object's index




};

#endif