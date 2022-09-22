/**
*
*@file executive.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab7
*@brief header file of the executive
*@date July.27/2021
*
*/

#ifndef EXECUTIVE_h
#define EXECUTIVE_h

#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include "BST.h"
#include "BinarySearchTreeInterface.h"

using namespace std;

class executive
{
    private:
    BST<pokemon, int>* tree = nullptr ;
    BST<pokemon, int>* copytree = nullptr;
    std::string filename;
    ifstream infile;


    public:
    executive(std::string name);
    //@pre - filename must be included
    //@post - initialzie the filename, check if open the file successfully 

    ~executive();

    void run();
    //@post - running the printmenu(), int the choice and running the correct function


    void printmenu();
    //@psot - print the menu

    bool choose_copy_one();
    //@post - check if the user want to use the copy one
    //@return - return true if uset choose the copy one 

    void search();
    //@psot - search function while the choice == 1

    void add();
    //@post - add funtion while the choice == 2

    void copy();
    //@post - deep copy the tree to the copy tree while the choice ==3

    void remove();
    //@post - remove certain pokemon while the choice == 4

    void print();
    //@post - print in certain order choosen by the user while the choice == 5
};



#endif