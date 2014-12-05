//Linked List Template Class
//Should be able to accept any type of class
//Downside: Slow Code! :D
#ifdef __LINKTEMPLATE__
#define __LINKTEMPLATE__

#include <iostream>
#include <string>
#include <cstdlib>
#include "LLN.h"

using namespace std;

//Fitting name
template <class t> class AnyList {

//what variables should this hold?
private:
	t head;
	//The size method may be obselete at this point.
	//int size;
public:
//constructor	
	AnyList(t * newHead);
//destructor
	~AnyList();
	void insert(int i, t * node); //Inserts an item before position i, preferrably a 'node'.
	t get(int i); //Gets the info at the i'th node.
	int length(); //Returns the length of our list. We could possibly do this recursively (and with templates... Shudder)

	T & operator[] (int i);//Overloaded operator. This will essentially act like an array, even though t's a linked list.

};

template <class t> AnyList<t>::Anylist (t * newHead) {
	//Our head must be a new node. These nodes can exist in many forms, so they'll be templated as well.

	head = newHead;
	size = 1;
}

template <class t> AnyList<t>::~Anylist() {
	
	delete[] head;
}

template <class t> void AnyList<t>::insert(int i, t * node) {

	//Now we use the length method we defined to make sure that we actually can do this.
	if (length() < i) {
	head->insertAfter(node, length()-1);
	} else {
	//If we can, we'll insert the node after the selected position.
	head->insertAfter(node, i);
	}
}

//I'm assuming that the instructions are to return the node at a position. This will do just that.
template <class t> t AnyList<t>::get(int i) {

	return head->get(0, i); //Zero as the first position always, i is the max.
	//I did something a bit dirty with this, at least in my opinion.
	//The node returns itself, so the operator overload just may do something a bit interesting hopefully with this idea.
}

template <class t> int length() {

	//We'll have to increment this counter somehow. We could do it either from this list, or we could do it from the nodes. I'd prefer the list personally, but we'll see how life takes us.
	return head->findLength();
}

template <class t> t & AnyList::operator[] (int i) {

	//Since we're not dealing with an array, we need to also iterate the list to determine this.
	//We could technically use the get method for this. Since I've not yet actually run this code at all to see if it truly works like I'm hoping, I'm going to assume that my little tricks I've used thusfar actually DO work and get all meta with this template.
	t &x = head->get(0, i);
	return x;
}

#endif

