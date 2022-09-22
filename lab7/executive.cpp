/**
*
*@file executive.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab7
*@brief cpp file of the executive
*@date July.27/2021
*
*/


#include "executive.h"

using namespace std;

executive::executive(std::string name)
{
    filename = name;
    infile.open(filename);
    if (infile.is_open())
    {
        run();
    }
    else
    {
        throw(std::runtime_error("Error:Failed to open the file\n"));
    }
}


executive::~executive()
{
    if (tree != nullptr)
    {
        delete tree;
    }
    if (copytree != nullptr)
    {
        delete copytree;
    }

}


void executive::run()
{
    string USName, JPName;
    int ID;
    int choice = 0;

    tree = new BST<pokemon, int>;
    copytree = new BST<pokemon, int>;

    try
    {

        while (infile >>USName >> ID >> JPName)
        {
            pokemon temp(USName, ID, JPName);
            tree->add(temp);
        }
        

        while(choice != 6)
        {
            try
            {
                printmenu();
                cout <<"what is the choice: \n";
                cin >> choice;
                if (choice == 1)
                {
                    search();
                }
                else if (choice == 2)
                {
                    add();
                }
                else if (choice == 3)
                {
                    copy();
                }
                else if (choice == 4)
                {
                    remove();
                }
                else if (choice == 5)
                {
                    print();
                }
                else
                {

                }

            }
            catch(const std::exception& e)
            {
                std::cout << e.what() << '\n';
            }
        
            
            
            
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    

}


void executive::printmenu()
{
    cout << "************\n";
    cout << "    MENU    \n";
    cout << "1.Search\n";
    cout << "2. Add\n";
    cout << "3. Copy\n";
    cout << "4. Remove\n";
    cout << "5. Print\n";
    cout << "6. Quit\n";
    cout << "************\n\n";

}


bool executive::choose_copy_one()
{
    int choice = 0;
    do
    {
        cout <<"Which one do you want to interact with?\n";
        cout << "1. original one\n";
        cout << "2. copy one\n";
        cin >> choice;
    }while (choice != 1 && choice != 2);

    if (choice == 2)
    {
        return true;
    }
    else //(choice == 1 )
    {
        return false;
    }

}

void executive::search()
{
    int num;
    if(copytree->getroot() == nullptr)
    {
        if(tree->getroot() == nullptr)
        {
            throw(std::runtime_error("Error: Empty, Nothing to search!\n"));
        }
        cout << "what is the pokedex number (id)?\n";
        cin >> num;
        tree->search(num).print();
    }
    else //(copytree != nullptr)
    {
        if(choose_copy_one())
        {
            cout << "what is the pokedex number (id)?\n";
            cin >> num;
            copytree->search(num).print();
        }
        else
        {
            cout << "what is the pokedex number (id)?\n";
            cin >> num;
            tree->search(num).print();
            if(tree->getroot() == nullptr)
            {
                throw(std::runtime_error("Error: Empty, Nothing to search!\n"));
            }
        }
    }
}


void executive::add()
{
    string USName, JPName;
    int num;
    
    if(copytree->getroot() == nullptr)
    {
        cout << "What is the US name?\n";
        cin >> USName;
        cout << "What is the pokedex number? \n";
        cin >> num;
        cout << "What is the Japanese name? \n";
        cin >> JPName;

        pokemon temp(USName, num, JPName);
        tree->add(temp);
    }
    else
    {
        if(choose_copy_one())
        {
            cout << "What is the US name?\n";
            cin >> USName;
            cout << "What is the pokedex number? \n";
            cin >> num;
            cout << "What is the Japanese name? \n";
            cin >> JPName;

            pokemon temp(USName, num, JPName);
            copytree->add(temp);
        }
        else
        {
            cout << "What is the US name?\n";
            cin >> USName;
            cout << "What is the pokedex number? \n";
            cin >> num;
            cout << "What is the Japanese name? \n";
            cin >> JPName;

            pokemon temp(USName, num, JPName);
            tree->add(temp);

        }


    }
}


void executive::copy()
{
    if (copytree->getroot() != nullptr)
    {
        throw(std::runtime_error("Error: You can only have 2 BST at one time\n"));
    }
    else
    {
        if(tree == nullptr)
        {

        }
        else
        {
            tree->copy(copytree);
        }
        cout <<"copy successfully\n";
    }


}


void executive::remove()
{
    int num;
    if(copytree->getroot() == nullptr)
    {
        if(tree->getroot() == nullptr)
        {
            throw(std::runtime_error("Error: Empty, Nothing to remove!\n"));
        }
        cout << "What is the pokedex number do you want to remove\n";
        cin >> num;
        tree->remove(num);

    }
    else
    {
        if(choose_copy_one())
        {
            cout << "What is the pokedex number do you want to remove\n";
            cin >> num;
            copytree->remove(num);

        }
        else
        {
            if(tree->getroot() == nullptr)
            {
                throw(std::runtime_error("Error: Empty, Nothing to remove!\n"));
            }
            cout << "What is the pokedex number do you want to remove\n";
            cin >> num;
            tree->remove(num);

        }

    }
}


void executive::print()
{
    int choice=0;
    if(copytree->getroot() == nullptr)
    {
        if(tree->getroot() == nullptr)
        {
            throw(std::runtime_error("Error: Empty, Nothing to print!\n"));
        }
        do
        {
            cout << "************\n";
            cout << "Which way do you want to print?\n";
            cout << "1.PreOrder\n";
            cout << "2.InOrder\n";
            cout << "3.PostOrder\n";
            cout << "************\n\n";
            cin >> choice;
        }while (choice != 1 && choice != 2 && choice !=3 );
        
        if (choice == 1)
        {
            tree->visitPreOrder(pokemon::static_print);
        }
        else if (choice == 2)
        {
            tree->visitInOrder(pokemon::static_print);
        }
        else //(choice == 3)
        {
            tree->visitPostOrder(pokemon::static_print);
        }
    }
    else
    {
        if(choose_copy_one())
        {
            do
            {
                cout << "************\n";
                cout << "Which way do you want to print?\n";
                cout << "1.PreOrder\n";
                cout << "2.InOrder\n";
                cout << "3.PostOrder\n";
                cout << "************\n\n";
                cin >> choice;
            }while (choice != 1 && choice != 2 && choice !=3 );
        
            if (choice == 1)
            {
                copytree->visitPreOrder(pokemon::static_print);
            }
            else if (choice == 2)
            {
                copytree->visitInOrder(pokemon::static_print);
            }
            else //(choice == 3)
            {
                copytree->visitPostOrder(pokemon::static_print);
            }
        }
        else
        {
            if(tree->getroot() == nullptr)
            {
                throw(std::runtime_error("Error: Empty, Nothing to print!\n"));
            }
            do
            {
                cout << "************\n";
                cout << "Which way do you want to print?\n";
                cout << "1.PreOrder\n";
                cout << "2.InOrder\n";
                cout << "3.PostOrder\n";
                cout << "************\n\n";
                cin >> choice;
            }while (choice != 1 && choice != 2 && choice !=3 );
            
            if (choice == 1)
            {
                tree->visitPreOrder(pokemon::static_print);
            }
            else if (choice == 2)
            {
                tree->visitInOrder(pokemon::static_print);
            }
            else //(choice == 3)
            {
                tree->visitPostOrder(pokemon::static_print);
            }
        }
    }

}