#include "Algorithms_Lab_1.h"
#include <iostream>;
using namespace std;

int main()
{
	cout << "Create a new empty List: \n";
	List MyList;
	cout << MyList;

	cout << "Add '2' to the end of List: \n";
	MyList.push_back(2);
	cout << MyList << endl;
	cout << "Try to get second element of List: \n";
	try {
		cout << MyList.at(2) << endl;
	}
	catch (const out_of_range error) {
		cout << error.what() << endl;
	}
	cout << "Add '1' to the begin and '3' to the end of List: \n";
	MyList.push_front(1);
	MyList.push_back(3);
	cout << MyList << endl;
	cout << "Try to get second element of List again: \n";
	try {
		cout << MyList.at(2) << endl << endl;
	}
	catch (const out_of_range error) {
		cout << error.what() << endl << endl;
	}
	cout << "Check the size of List: \n";
	cout << MyList.get_size() << endl << endl;

	cout << "Remove the first and last element of List: \n";
	MyList.pop_back();
	MyList.pop_front();
	cout << MyList << endl;
	cout << "Let's return everything as it was: \n";
	MyList.push_front(1);
	MyList.push_back(3);
	cout << MyList << endl;

	cout << "Insert '5' at first position: \n";
	MyList.insert(5, 1);
	cout << MyList << endl;
	cout << "Set '15' at second position: \n";
	try {
		MyList.set(2, 15);
		cout << MyList << endl;
	}
	catch (const out_of_range error) {
		cout << error.what() << endl << endl;
	}
	cout << "Set '9' at seventh position: \n";
	try {
		MyList.set(7, 9);
		cout << MyList << endl;
	}
	catch (const out_of_range error) {
		cout << error.what() << endl << endl;
	}
	cout << "Remove element at first position: \n";
	MyList.remove(1);
	cout << MyList;

	List Second_List;
	Second_List.push_front(9);
	Second_List.push_back(3);
	cout << "Let's take the second list: \n";
	cout << Second_List << endl;
	cout << "Find the index of the last entry of the second list into the original List: \n";
	try {
		cout << MyList.find_last(Second_List) << endl << endl;
	}
	catch (const invalid_argument error) {
		cout << error.what() << endl << endl;
	}
	MyList.push_back(9);
	MyList.push_back(3);
	cout << "Add '9' and '3' to the end of original List: \n";
	cout << MyList << endl;
	cout << "Find the index of the last entry of the second list into the original List again: \n";
	try {
		cout << MyList.find_last(Second_List) << endl << endl;
	}
	catch (const invalid_argument error) {
		cout << error.what() << endl << endl;
	}

	cout << "Check empty of List: \n0 is not empty \n1 is empty \n";
	cout << MyList.isEmpty() << endl << endl;
	cout << "Clear the List: \n";
	MyList.clear();
	cout << MyList;
	cout << "Check empty of List: \n0 is not empty \n1 is empty \n";
	cout << MyList.isEmpty() << endl;

}