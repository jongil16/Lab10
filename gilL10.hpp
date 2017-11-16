/*********************************************************************
* Assignment: Lab 10 - Sincgly Linked List implementation            *
* Author: Jonathan Gil                                               *
* Date: Fall 2017                                                    *
* File: LList.hpp                                                    *
*                                                                    *
* Description: This file contains the class for LList and its        *
* components                                                         *
*********************************************************************/

#ifndef LLIST_HPP
#define LLIST_HPP
#include <iostream>

using namespace std;
enum dtype {FORWARD,BACKWARD};
template <class LT> class LList;
template <class LT> ostream & operator << (ostream & outs, const LList <LT> & L);
/*********************************************************************
* Class: LList                                                       *
*                                                                    *
* Description: This class is designed to hold all the member functions
* and parts of the linked list, the LNode struct and its contents.   *
*********************************************************************/
template <class LT>
class LList
{
   private:
      struct LNode
      {
         LNode ();
	 void PrintNode (ostream & output);
         LT data;
         LNode * next;
      };
   public:
      LList ();
      LList (const LList & other);
      ~LList ();
      LList & operator = (const LList & other);
      bool operator == (const LList & other);
      int Size () const;
      void SetDirection (dtype dir);
      dtype GetDirection () const;
      friend ostream & operator << <>
			(ostream & outs, const LList<LT> & L);
     // friend ostream & operator << (ostream & outs, const LList & L);
      bool InsertFirst ( const LT & value);
      bool InsertLast (const LT & value);
      //bool InsertFirst (const int & value);
     // bool InsertLast (const int & value);
      bool DeleteFirst ();
      bool DeleteLast ();
   private:
      LNode * first;
      LNode * last;
      int size;
      dtype direction;
};



/*******************************************************************************
* Function: LList::LNode::LNode()                                              *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will initialize the variables for the LNodes.      *
*******************************************************************************/
template <class LT> 
LList<LT>::LNode::LNode ()
{ 
//	data = 0;
	next = NULL;
}

//
template <class LT>
void LList<LT>::LNode::PrintNode (ostream & output)
{
	if (next != NULL)
		next -> PrintNode (output);
	if (next != NULL)
		output << ' ';
	output << data;
}

/*******************************************************************************
* Function: LList:: LList()                                                    *
*                                                                              *
* Parameters: None                                                             *
* Return value: None                                                           *
* Description: This function will initialize all of the variables of the LList *
* class                                                                        *
*******************************************************************************/
template <class LT>
LList<LT>::LList ()
{ 
	size = 0;
	first = NULL;
	direction = FORWARD;
}

/*********************************************************************
* Function: LList::LList (const LList & other)                       *
*                                                                    *
* Parameters: LList , other                                          *
* Return value: none;                                                     *
* Description: This function will copy the data values of other to
*                                   *
*********************************************************************/
template <class LT> 
LList<LT>::LList (const LList & other)
{ 
	size = 0;
	first = NULL;
	last = NULL;
	LNode * temp= first;
	for (LNode *n = other.first; n != NULL; n = n-> next)
	{
		InsertLast(n -> data);
	}
	direction = other.direction;
}

/*********************************************************************
* Function: LList::~LList()                                          *
*                                                                    *
* Parameters: NONE                                                   *
* Return value: NONE                                                 *
* Description: This function will delete first.                      *
*********************************************************************/
template <class LT>
LList<LT>::~LList ()
{ 
	while (first != NULL)
		DeleteFirst();
}

/*********************************************************************
* Function: LList & LList :: operator = (const LList & other)        *
*                                                                    *
* Parameters: LList, other                                           *
* Return value: this                                                 *
* Description: This function will assign all the elements in the     *
* current list and make it equal to other.                           *
*********************************************************************/
template <class LT>
LList<LT> & LList<LT>::operator = (const LList<LT> & other)
{ 
	if (this == & other)
	{
		return * this;
	}
	while (first != NULL)
		DeleteFirst();
	for (LNode * n = other.first; n!= NULL; n= n-> next)
		InsertLast(n->data);
	direction = other.direction;
	return * this;
}

/*********************************************************************
* Function:bool LList::operator == (const LList & other)             *
*                                                                    *
* Parameters: LList, other                                           *
* Return value: bool                                                 *
* Description: This function will copy the data from other into the  *
* LList.                                                             *
*********************************************************************/
template <class LT>
bool LList<LT>::operator == (const LList & other)
{ 
	if (size != other.size)
		return false;
	LNode * n = first;
	LNode * m = other.first;
	while (n!= NULL)
	{
		if (n->data != m -> data)
			return false;
		n = n-> next;
		m = m->next;
	}
	return true;
}

/*********************************************************************
* Function: int LList::Size()                                        *
*                                                                    *
* Parameters: None                                                   *
* Return value: size                                                 *
* Description: This function will return the value of size           *
*********************************************************************/
template <class LT>
int LList<LT>::Size () const
{ 
	return size;
}

template <class LT>
void LList<LT>::SetDirection (dtype dir)
{
	direction = dir;
}

template <class LT>
dtype LList<LT>::GetDirection () const
{
	return direction;
}

/*********************************************************************
* Function: ostream & operator << (ostream & outs, const LList & L   *
*                                                                    *
* Parameters: LList, L, ostream, outs                                *
* Return value: outs                                                 *
* Description: This function will display the data values followed by*
* spaces.                                                            *
*********************************************************************/
template <class LT>
ostream & operator << (ostream & outs, const LList<LT> & L)
{ 
	if (L.first == NULL)
		return outs;
	if  (L.direction == FORWARD)
	{//print the lsit from beginning (first) to end
		outs << L.first -> data;
		typename LList<LT>::LNode * n;
		for (n = L.first -> next; n != NULL; n = n->next)
			outs << ' ' << n-> data;
	}
	else //L.direction == Backward
	{	//print the list from end to beginning
		L.first->PrintNode(outs);
	}
	return outs;
	
/*	LList::LNode * n = L.first;
	while (n!=NULL)
	{
		outs << n->data << ' ';
		n= n-> next;
	}	
	return outs;
*/
}

/*********************************************************************
* Function: bool LList::InsertFirst (const int & value)              *
*                                                                    *
* Parameters: value                                                  *
* Return value: True or False                                        *
* Description: This function will insert a new LNode at the beginning 
* of the linked list and increment size.                                   *
*********************************************************************/
template <class LT>
bool LList<LT>::InsertFirst (const LT & value)
{ 
	LNode * nn = new LNode;
	if (nn==NULL)
		return false;
	nn->data = value;
	nn -> next = first;
	first = nn;
	if (size ==0)
	{
		last = nn;
	}
	size++;
	return true;
}

/*********************************************************************
* Function: bool LList::InsertLast(const int & value)                *
*                                                                    *
* Parameters: value                                                  *
* Return value: bool                                                 *
* Description: This function will check whether the linked list is   *
* empty and and insert a node as the first and last, if it is not    *
* empty it will insert a LNode at the end and update the size.       *
*********************************************************************/
template <class LT>
bool LList<LT>::InsertLast (const LT & value)
{
	if (size == 0)
		return InsertFirst(value);
	LNode * nn = new LNode;
	if (nn == NULL)
		return false;
	nn -> data = value;
	last -> next = nn;
	last = nn;
	size++;
	return true;
}

/*********************************************************************
* Function:bool LList::DeleteFirst()                                 *
*                                                                    *
* Parameters: NONE                                                   *
* Return value: bool                                                 *
* Description: This function will delete the first data object in the*
* linked list and decrement size.                                    *
*********************************************************************/
template <class LT>
bool LList<LT>::DeleteFirst ()
{ 
	if (first == NULL )
		return false;
	LNode * n = first;
	first = n -> next;
	delete n;
	size--;
	if (size == 0)
		last = NULL;	
	return true;
}

/*********************************************************************
* Function: bool LList::DeleteLast()                                 *
*                                                                    *
* Parameters: None                                                   *
* Return value: bool                                                 *
* Description: This function will delete that last data object in the*
* linked list and decrement size.                                    *
*********************************************************************/
template <class LT>
bool LList<LT>::DeleteLast ()
{ 
	if (size == 0 )
		return false;
	if (size ==1)
		return DeleteFirst();
	LNode *p = first;
	while (p-> next != last)
		p = p->next;
	p->next = NULL;
	delete last;
	last = p;
	size--;
	return false;
}

#endif
