//Dallas Johnson
//Template Code for the link list node
//This will be interesting to write...

#ifdef __LINKNODETEMPLATE__
#define __LINKNODETEMPLATE__

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

template <class t> class AnyNode {

private:
//our variables that only the nodes will know about.
	t next;
	t info;
public:
//everything else the nodes should know about.
//This also includes recursive methods that will be defined for the higher functions of the list itself.

//constructor
	AnyNode(t data, t nextNode);
//Destructor
	~AnyNode();
	void insertAfter(t * nodePointer, int position, int currentPosition = 0); //We're inserting a node after the bracket number
	int findLength(); //This will be the method that finds the length of the whole list recursively
	t get(int currentPosition);
};

//Constructor fleshed out
template <class t> AnyNode::AnyNode(t data, t * nextNode) {
	info = data;
	next = nextNode;
}

//I have a feeling this will blow up in my face.
template <class t> ~AnyNode::AnyNode() {
	if (next != NULL) {
		delete[] next;
	}
}

//This is where things get a bit fuzzy.
template <class t> void AnyNode::insertAfter(t * nodePointer, int position, int currentPosition = 0) {
//Hell yeah! Variable declaration in the method signature! This is important as well!
	if (currentPosition == position) {
		//Sliding into yo lists like (vine / twitter joke)
		//Essentially adding that node into the list after the position. This is our base case.
		nodePointer -> next = this.next;
		this.next = nodePointer;
		return;
	}
	else {
		//I'm really hoping this will work. At this point I'm writing this without
		//Even testing the program at all once.
		next->insertAfter(nodePointer, position, currentPosition++);
	}
}

//The recursive method that will return the lenght of the list to the list template.
template <class t> int AnyNode::findLength() {
	//start it at one, because we're counting this node.
	int count = 1;
	if (this.next == NULL) {
	   return count;
	} else {
	   count++;
	   next -> findLength();
	}
}

//I forgot the get method
template <class t> t AnyNode::get(int currentPosition, int max) {
	pos = currentPosition;
	//this is a rather meta way of doing it, since the user never interacts with the param. Just for recusrion's sake. currentPosition should always start at 0
	if (currentPosition == max) {
		return this;
	} else {
	//Here's the recursion.
	next->get(pos++, max); 
}

#endif

