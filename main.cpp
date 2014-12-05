//Program 4 redux with templates
//Dallas Johnson
//I put program 4 on hault for a while. ONce I finish this assignment, I'll use the code from this to finish the fourth program.
//I hope I can do this at least, program 4's command parser is extremely broken as it is, and I wan to to try to nail this program down and kill two stones with one bird.

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "LL.h" //since I'm not original in any way... (totally joking, just needed to get the template written)
#include "LLN.h"

using namespace std;

//Some advice I was told: code around your main method.

int main(int argc, char** argv) {
//AnyList<string> newList(new AnyNode<string>("Our Head",NULL));
//So now we must figure out how to write a command parser. Awesome...
//Since the vector method isn't working for some reason (I hate templates so much) I'll try an array method.
string command = "";
string * commandSplit = new string[3];
commandSplit[0] = commandSplit[1] = commandSplit[2] = "";
cout << "Please enter a command: ";

getline(cin, command);
splitString(command);

//here's our super advanced command checker.
/*
------
Commands
------
ADD
REMOVE
PRINT
EXIT
*/
if (commandSplit[0] == "ADD") {
	if (commandSplit[1] != NULL && commandSplit[2] != NULL) {
		//see above for this.
		//newList.head = new AnyNode<currentCommand[1]>(currentCommand[2], NULL);
		cout << "ADD WAS CALLED WITH : " << commandSplit[1] << " AND " << commandSplit[2] << " AS ARGS.";
	}
}
}

//Now we know we'll need to split the strings. We'll use our delimiter as the space character.

//This will be kind of strange. It'll take in the string as a full string, then split it and put the parsed string into the command array. Different than I wanted to do it, but I want to get this done ASAP. Templates are awful.

//;-;
void splitString(string parseMe, string *& commandArray) {
	//these three variables basically run the show. Space is obviuosly the space char, pos is our position in the word, and the current word is actually what we'll push onto the array. Ticker is the word we're currently on.
	char space = " ";
	int pos = 0;
	string currentWord = "";
	int ticker = 0;

	while (pos < parseMe.length() && ticker != 3) { //While the position counter is less than the length, and the ticker is less than 3 (there shouldn't be more than three parameters to this anyhow) do everything below.
	   if ((char)parseMe[pos] != space) {
	      currentWord = currentWord + parseMe[pos];
	   } else {
		commandArray[ticker] = currentWord;
		currentWord = ""; //clear the word once we push it.
		ticker++; //Increment the ticker.
	}
	pos++;
}





/*vector<string> splitString(string parseMe) {
	char spc = ' ';
	string word = "";
	vector<string> parsedString;
	//Loop through each word. If it hits the space, cut the word off.
	
	int pos = 0;
	while(pos != parseMe.length()) {
	
	if ((char)parseMe[pos] == spc) {
	
	parsedString.push_back(word);
	//once we push the word into the vector we need to clear the word again.
	word = "";
	} else {
	word = word + parseMe[pos];
	}
    }
	//returns a vector with the string split up.
	return parsedString;
}*/
