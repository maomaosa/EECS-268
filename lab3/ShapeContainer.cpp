/**
*
*@file ShapeContainer.cpp
*@author Yuyang Fan
*Assignment: EECS-268 Lab3
*@brief this progam will contain functions for the ShapeContainer
*@date June.28/2021
*
**/
#include "ShapeContainer.h"

ShapeContainer::ShapeContainer(int size)
{
	m_size=size;
	m_arrayOfShapes = new Shape*[size];
	for(int i =0; i<m_size; i++)
	{
		m_arrayOfShapes[i]=nullptr;
	}
}

ShapeContainer::~ShapeContainer()
{
	for(int i =0; i<m_size; i++)
	{
		if(m_arrayOfShapes[i] != nullptr)
		{
			delete m_arrayOfShapes[i];
		}
		else
		{
		}
	}
	
	delete[] m_arrayOfShapes;
}

double ShapeContainer::area(int index) const
{
	if(index <0 || index >= m_size)
	{
		throw ( std::runtime_error ("INVALID INDEX\n"));
	}
	else if (m_arrayOfShapes[index] == nullptr)
	{
		throw (std::runtime_error ("SHAPE IS NULLPTR\n"));
	}
	else
	{
		return m_arrayOfShapes[index]->area();
	}
}

std::string ShapeContainer::shapeName(int index) const
{
	if(index <0 || index >= m_size)
	{
		throw ( std::runtime_error ("INVALID INDEX\n"));
	}
	else if (m_arrayOfShapes[index] == nullptr)
	{
		throw (std::runtime_error ("SHAPE IS NULLPTR\n"));
	}
	else
	{
		return m_arrayOfShapes[index]->shapeName();
	}
}

void ShapeContainer::add(Shape* shapePtr, int index)
{
	if(index <0 || index >= m_size)
	{
		Shape* temp = shapePtr;
		delete temp;
		throw ( std::runtime_error ("Error: INVALID INDEX TO ADD\n"));
	}
	else if (m_arrayOfShapes[index] != nullptr)
	{
		Shape* temp = shapePtr;
		delete temp;
		throw (std::runtime_error ("Error: SHAPE IS FULL CANNOT ADD\n"));
	}
	else
	{
		m_arrayOfShapes[index] = shapePtr;
	}
}

void ShapeContainer::remove(int index)
{
	if(index <0 || index > m_size-1)
	{
		throw ( std::runtime_error ("Error:INVALID INDEX CANNOT DELETE\n"));
	}
	else if (m_arrayOfShapes[index] == nullptr)
	{
		throw (std::runtime_error ("Error:SHAPE IS NULLPTR CANNOT DELETE\n"));
	}
	else
	{
		delete m_arrayOfShapes[index];
		m_arrayOfShapes[index]=nullptr;
	}
}
	