#include "pokemon.h"
using namespace std;

pokemon::pokemon()
{
    USName = "";
    JPName = "";
    index  = 0;

}

pokemon::pokemon(string name1, int num , string name2)
{
    USName = name1;
    JPName = name2;
    index = num;
}


pokemon::~pokemon()
{

}


void pokemon::print()
{
    cout << USName << "  ";
    cout << index << "  ";
    cout << JPName << endl;
}

void pokemon::static_print(pokemon poke)
{
    cout << poke.USName << "  ";
    cout << poke.index << "  ";
    cout << poke.JPName << endl;
}


bool pokemon::operator == (const pokemon& anotherone)
{
    return (index == anotherone.index);

}


bool pokemon::operator > (const pokemon& anotherone)
{
    return (index > anotherone.index);
}


bool pokemon::operator < (const pokemon& anotherone)
{
    return (index < anotherone.index);
}


bool pokemon::operator == (int num)
{
    return (index == num);
}

bool pokemon::operator > (int num)
{
    return (index > num);
}

bool pokemon::operator < (int num)
{
    return (index < num);
}