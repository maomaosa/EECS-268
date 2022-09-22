/**
*
*@file BST.h
*@author Yuyang Fan
*Assignment: EECS-268 Lab7
*@brief header file of the BinarySearchTree
*@date July.25/2021
*
*/

#ifndef BST_H
#define BST_H

#include <iostream>
#include <exception>
#include "BinarySearchTreeInterface.h"
#include "BinaryNode.h"
#include "pokemon.h"

template <typename ItemType, typename KeyType>

class BST : public BinarySearchTreeInterface<ItemType,KeyType>
{
    private:
    BinaryNode<ItemType>* m_root;
    BinaryNode<ItemType>* jumper;
    

    void recadd(ItemType entry, BinaryNode<ItemType>* subtree);
    //@pre - it must include the ItemType entry and m_root starter
    //@post - recursive fucntion of the add function, recutsive until add the item to the correct position
    //@post - runtime_error if dupilcate added


    ItemType recsearch(KeyType key, BinaryNode<ItemType>* subtree) const;
    //@pre - it must include the key (num) to find the loaction
    //@post - recursive the recsearch function until find the object
    //@post - throws std::runtime_error if not in tree
    //@return - return the findding object


    void recclear(BinaryNode<ItemType>* subtree);
    //@post - delete the heap stored BinaryNode 
	
	
	void recremove(KeyType key, BinaryNode<ItemType>* subtree);
	//@pre - it must include the key (num) to find the loaction
	//@post - recursive the recsearch function until find the object that need to delete
	//@post - if the object have one or more childs, exchange the object with childs
	//@post - throws std::runtime_error if not in tree


    void doremove(KeyType key, BinaryNode<ItemType>* subtree);
    //@pre - it must include the key (num) to find the loaction
    //@post - the function helping remove the nodes

    void recPre(void visit(ItemType),BinaryNode<ItemType>* subtree) const;
    //@pre - it must include the function and subtree
    //@post - using the Pre order to working the input function


    void recIn(void visit(ItemType),BinaryNode<ItemType>* subtree) const;
    //@pre - it must include the function and subtree
    //@post - using the In order to working the input function


    void recPost(void visit(ItemType),BinaryNode<ItemType>* subtree) const;
    //@pre - it must include the function and subtree
    //@post - using the Post order to working the input function


    void reccopy(BST<ItemType,KeyType>*& copytree,BinaryNode<ItemType>* subtree) const ;
    //@post - deep copy the tree of m_root


    public:
    BST();
    ~BST();

    BinaryNode<ItemType>* getroot();
    //@pre - return the m_root
    //@return - return the m_root


    void add(ItemType entry); //throws std::runtime_error if duplicate added
    //@pre - it must include the ItemType entry
    //@post - running the recursion function "recadd"


    ItemType search(KeyType key) const ; //throws std::runtime_error if not in tree
    //@pre - it must include the key (num) to find the loaction
    //@post - running the recursion function "recsearch"
	

    void clear();
    //@post - running the recursion funtion "recclear"

	
	void remove(KeyType key) ;//throws std::runtime_error if not in tree
	//@pre - it must include the key (num) to find the loaction
	//@Post - running the recursion function "recremove"


    //For the following methods, each method will take a function as a parameter
    //These function then call the provided function on every entry in the tree in the appropriate order (i.e. pre, in, post)
    //The function you pass in will need to a static method

    void visitPreOrder(void visit(ItemType)) const; //Visits each node in pre order
    //@pre - it must include the input function
    //@post - running the recursion function "recPre"

    void visitInOrder(void visit(ItemType)) const; //Visits each node in in order
    //@pre - it must include the input function
    //@post - running the recursion function "recIn"

    void visitPostOrder(void visit(ItemType)) const ; //Visits each node in post order
    //@pre - it must include the input function
    //@post - running the recursion function "recPost"

    void copy(BST<ItemType,KeyType>*& copytree) const;
    //@post - running the recursion function "reccopy"


 
};

#include "BST.cpp"

#endif