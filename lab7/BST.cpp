/**
*
*@file BST.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab7
*@brief cpp file of the BinarySearchTree
*@date July.25/2021
*
*/

using namespace std;

template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::BST()
{
    m_root = nullptr;
    jumper = nullptr;
}


template <typename ItemType, typename KeyType>
BST<ItemType, KeyType>::~BST()
{
    clear();
}


template <typename ItemType, typename KeyType>
BinaryNode<ItemType>* BST<ItemType, KeyType>::getroot()
{
    return (m_root);
}

/****************************************************************
 * 
 * add part
 * add part
 * add part
 *
 ***************************************************************/


template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::add(ItemType entry)
{

    if ( m_root == nullptr)
    {
        BinaryNode<ItemType>* temp = new BinaryNode<ItemType>(entry);
        m_root = temp;
    }
    else
    {       
        recadd(entry, m_root); 
    }

   

}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recadd(ItemType entry, BinaryNode<ItemType>* subtree)
{
    
    if (entry == subtree->getEntry())
    {
        throw(std::runtime_error("Error:Cannot do duplicate add\n"));
    }
    else if (entry < subtree->getEntry())
    {
        if (subtree -> getLeft() == nullptr)
        {
            BinaryNode<ItemType>* temp = new BinaryNode<ItemType>(entry);
            subtree ->setLeft(temp);
        }
        else
        {
            recadd(entry, subtree->getLeft());
        }

    }
    else if (entry > subtree->getEntry())
    {
        if (subtree -> getRight() == nullptr)
        {
            BinaryNode<ItemType>* temp = new BinaryNode<ItemType>(entry);
            subtree ->setRight(temp);
        }
        else
        {
            recadd(entry, subtree->getRight());
        }

    }


}


/****************************************************************
 * 
 * search part
 * search part
 * search part
 *
 ***************************************************************/

template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>::search(KeyType key) const
{

    if (m_root == nullptr)
    {
        throw (runtime_error("Error:Empty store, nothing to find\n" ));
    }
    else
    {
        return (recsearch(key,m_root));
    }
    
    

    
}

template <typename ItemType, typename KeyType>
ItemType BST<ItemType, KeyType>:: recsearch(KeyType key,BinaryNode<ItemType>* subtree) const
{
    
    if (subtree->getEntry() > key )
    {
        if (subtree -> getLeft() == nullptr)
        {
            throw (runtime_error("Error:Cannot find the object\n" ));
        }
        else 
        {
            return recsearch (key, subtree -> getLeft());
        }
    }
    else if (subtree->getEntry() < key)
    {
        if (subtree ->getRight() == nullptr)
        {
            throw (runtime_error("Error:Cannot find the object\n" ));
        }
        else
        {
            return recsearch (key, subtree -> getRight());
        }
    }
    else // (subtree->getEntry() == key)
    {
        return (subtree->getEntry());
    }


}


/****************************************************************
 * 
 * clear part
 * clear part
 * clear part
 *
 ***************************************************************/
template <typename ItemType, typename KeyType> 
void BST<ItemType, KeyType>:: clear()
{
    if (m_root == nullptr)
    {

    }
    else
    {
        recclear(m_root);
    }
}


template <typename ItemType, typename KeyType> 
void BST<ItemType, KeyType>:: recclear(BinaryNode<ItemType>* subtree)
{
    if(subtree->getLeft() != nullptr)
    {
        recclear(subtree->getLeft());
    }

    if(subtree->getRight() != nullptr)
    {
        recclear(subtree->getRight());
    }

    delete subtree;
}




/****************************************************************
 * 
 * remove part
 * remove part
 * remove part
 *
 ***************************************************************/

template <typename ItemType, typename KeyType> 
void BST<ItemType, KeyType>:: remove(KeyType key)
{

    jumper = nullptr ;// the jummper to store the last BNode

	if (m_root == nullptr)
	{
        throw(std::runtime_error("Error: Empty store, nothing to remove\n"));
    }
    else if (m_root->getEntry() == key)
    {
        if(m_root->getLeft() == nullptr && m_root->getRight() == nullptr)
        {
            delete m_root;
            m_root = nullptr;
        }
        else if (m_root -> getLeft() != nullptr && m_root->getRight() == nullptr)
        {
            BinaryNode<ItemType>* temp = m_root;
            m_root = m_root -> getLeft();
            delete temp;
        }
        else if (m_root -> getLeft() == nullptr && m_root->getRight() != nullptr)
        {
            BinaryNode<ItemType>* temp = m_root;
            m_root = m_root -> getRight();
            delete temp;
        }
        else
        {

            BinaryNode<ItemType>* finder = m_root->getLeft(); //The target point
            BinaryNode<ItemType>* before = m_root->getLeft(); //pointer before finder
            int move_time = 0;
            while(finder->getRight() != nullptr)
            {
                finder = finder->getRight();
                move_time ++;
            }

            if(move_time == 0)  //set left node and nullptr
            {
                
            }
            else //(movetime >= 1)
            {
                for (int i =0 ; i<move_time-1; i++)
                {
                    before = before->getRight();
                }
				if(finder->getLeft() == nullptr)
				{				
					before->setRight(nullptr);
				}
				else
				{
					before->setRight(finder->getLeft());
				}
                finder->setLeft(m_root->getLeft());
            }


            finder->setRight(m_root->getRight()) ;//set right node
            delete m_root;
            m_root = finder;
        }

        
    }
    else
    {
        recremove(key, m_root);
    }
}
		

template <typename ItemType, typename KeyType> 
void BST<ItemType, KeyType>::recremove(KeyType key, BinaryNode<ItemType>* subtree)
{

    
    if (subtree->getEntry() > key)
    {
        jumper = subtree;
        if(subtree->getLeft() == nullptr)
        {
            throw(std::runtime_error("Error:The object is not in the tree\n"));
        }
        else
        {
            recremove(key, subtree->getLeft());
        }
    }
    else if (subtree->getEntry() < key)
    {
        jumper = subtree;
        if(subtree->getRight() == nullptr)
        {
            throw(std::runtime_error("Error:The object is not in the tree\n"));
        }
        else
        {
            recremove(key, subtree->getRight());
        }
    }

    
    else if(subtree -> getEntry() == key)
    {
        doremove(key,subtree);
    }

}


template <typename ItemType, typename KeyType> 
void BST<ItemType, KeyType>::doremove(KeyType key, BinaryNode<ItemType>* subtree)
{ 
    if(subtree->getLeft() == nullptr && subtree->getRight() == nullptr) // with two nullptr below
    {
        //BinaryNode<ItemType>* temp = subtree;  //DONT FORGET to add nullptr!!!!!!!!!!!!
        //subtree->setEntry(nullptr);                 // Or the clear() cannot read anymore!!!!!!!!!!!!!
        if(subtree->getEntry() < jumper->getEntry() )
        {
            jumper->setLeft(nullptr);
        }
        else //(subtree->getEntry() > jumper->getEntry() )
        {
            jumper->setRight(nullptr);
        }
        delete subtree;
    }


    else if (subtree -> getLeft() != nullptr && subtree->getRight() == nullptr) //with one nullptr below
    {
        if(jumper->getEntry() > subtree->getEntry())
        {
            jumper->setLeft(subtree->getLeft());
        }
        else //(jumper->getEntry() < subtree->getEntry())
        {
            jumper->setRight(subtree->getLeft());
        }
        delete subtree;
    }
    else if (subtree -> getLeft() == nullptr && subtree->getRight() != nullptr)
    {
        if(jumper->getEntry() > subtree->getEntry())
        {
            jumper->setLeft(subtree->getRight());
        }
        else //(jumper->getEntry() < subtree->getEntry())
        {
            jumper->setRight(subtree->getRight());
        }
        delete subtree;
    }


    else // (subtree->getLeft() != nullptr && subtree->getRight() != nullptr)
    {
        BinaryNode<ItemType>* finder = subtree->getLeft(); //The target point
        BinaryNode<ItemType>* before = subtree->getLeft(); //pointer before finder
        int move_time = 0;
        while(finder->getRight() != nullptr)
        {
            finder = finder->getRight();
            move_time ++;
        }

        if(move_time == 0)  //set left node and nullptr
        {
            
        }
        else //(movetime > 1)
        {
            for (int i =0 ; i<move_time-1; i++)
            {
                before = before->getRight();
            }
			if(finder->getLeft() == nullptr)
			{				
				before->setRight(nullptr);
			}
			else
			{
				before->setRight(finder->getLeft());
			}
            finder->setLeft(subtree->getLeft());
        }


        finder->setRight(subtree->getRight()) ;//set right node

        if (finder->getEntry() > jumper->getEntry()) //set upper node
        {
                jumper->setRight(finder);
        }
        if (finder->getEntry() < jumper->getEntry())
        {
                jumper->setLeft(finder);
        }

        

        delete subtree;
    }

}


/****************************************************************
 * 
 * traversing part
 * traversing part
 * traversing part
 *
 ***************************************************************/
template <typename ItemType, typename KeyType>
 void BST<ItemType, KeyType>::visitPreOrder(void visit(ItemType)) const ////Pre order
 {
     if (m_root == nullptr)
     {
        throw(std::runtime_error("Error: Empty, nothing to do\n"));
     }
     else
     {
        recPre(visit, m_root);
     }
 }


 template <typename ItemType, typename KeyType>
 void BST<ItemType, KeyType>::recPre(void visit(ItemType),BinaryNode<ItemType>* subtree) const ////Pre order
 {
     if (subtree == nullptr)
     {
         return;
     }
     visit(subtree->getEntry());
     recPre(visit,subtree->getLeft());
     recPre(visit,subtree->getRight());

 }

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitInOrder(void visit(ItemType)) const ////In order
{
    if(m_root == nullptr)
    {
        throw(std::runtime_error("Error: Empty, nothing to do\n"));
    }
    else
    {
        recIn(visit, m_root);
    }
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recIn(void visit(ItemType),BinaryNode<ItemType>* subtree) const////In order
{
    if(subtree == nullptr)
    {
        return;
    }
    recIn(visit, subtree->getLeft());
    visit(subtree->getEntry());
    recIn(visit, subtree->getRight());
}   

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::visitPostOrder(void visit(ItemType)) const ////Post order
{
    if(m_root == nullptr)
    {
        throw(std::runtime_error("Error: Empty, nothing to do\n"));
    }
    else
    {
        recPost(visit, m_root);
    }
}

template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::recPost(void visit(ItemType),BinaryNode<ItemType>* subtree) const ////Post order
{
    if(subtree == nullptr)
    {
        return;
    }
    recPost(visit,subtree->getLeft());
    recPost(visit, subtree->getRight());
    visit(subtree->getEntry());
}




/****************************************************************
 * 
 * copy part
 * copy part
 * copy part
 *
 ***************************************************************/
template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::copy(BST<ItemType,KeyType>*& copytree) const //by reference the copy tree
{

    reccopy(copytree,m_root);                                            //change the copy tree in the executive.cpp by reference
}


template <typename ItemType, typename KeyType>
void BST<ItemType, KeyType>::reccopy(BST<ItemType,KeyType>*& copytree, BinaryNode<ItemType>* subtree) const
{
    if(subtree == nullptr)
    {
        return;
    }
    
    copytree->add(subtree->getEntry());    //[copytree] -> add the [subtree->getEntry()] (pokemon type)
    reccopy(copytree, subtree->getLeft()); //use the pre order
    reccopy(copytree, subtree->getRight());


}