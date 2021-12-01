#pragma once
#include <iostream>
#include <stdexcept> 

using namespace std;

class List {

private:

    class Node {
    public:
        int date; // date of element
        Node* next; // pointer to the next element
    };
    Node* head; // pointer to the begin of List
    Node* tail; // pointer to the end of List

public:
    // Constructor with date
    List(int date) {

        Node* temp = new Node; // Create temporary node
        temp->date = date;
        temp->next = tail;
        head = temp;
        tail = temp;
    }

    // Constructor without date
    List() {
        head = tail = NULL;
        Node* temp = new Node; // Create temporary node
        temp->next = NULL;
        temp->date = NULL;
    }

    // Destructor
    ~List() {
        clear();
    }

    // getting list size
    int get_size() {
        int list_size = 0;
        Node* temp = head;
        while (temp != NULL) {
            list_size++;
            temp = temp->next;
        }
        return list_size;
    }

    // checking if the list is empty
    bool isEmpty() {
        return head == NULL;
    }

    // adding to the end of the list
    void push_back(int date) {
        Node* temp = new Node;
        if (isEmpty() == 1) { // If List is empty  
            temp->date = date;
            temp->next = NULL;
            head = temp;
            tail = temp;
        }
        else { // If List isn't empty
            temp->date = date;
            temp->next = NULL;          
            tail->next = temp;
            tail = temp;
        }

    }

    // adding to the beginning of the list
    void push_front(int date) {
        Node* temp = new Node; // Create temporary node
        if (isEmpty() == 1) { // If List is empty
            temp->date = date;
            temp->next = NULL;
            head = temp;
            tail = temp;
        }
        else {  // If List isn't empty
            temp->date = date;           
            temp->next = head;
            head = temp;
            temp = temp->next;         
        }
    }

    // removing the last item
    void pop_back() {
        if (isEmpty() == 0) // If List isn't empty
        {
            Node* temp = head; // Create temporary node
            if (head->next == NULL) {
                pop_front();
            }
            else {
                while (temp->next != NULL) {
                    tail = temp;
                    temp = temp->next;
                }
                tail->next = NULL;
                delete temp;
            }
        }
        else {
            throw invalid_argument("List is empty. Last element cannot be deleted"); // Error message 
        }
    }

    // deleting the first element deleting an element
    void pop_front() {

        if (isEmpty() == 0) // If List isn't empty
        {
            Node* temp = head; // Create temporary node
            head = head->next;
            delete temp;
            if (head == NULL) tail = head;
        }
        else {
            throw invalid_argument("List is empty. First element cannot be deleted"); // Error message 
        }
    }

    // adding an item at index (insertion before an item that was previously accessible at that index)
    void insert(int date, size_t index) {
        if (index < get_size())
        {
            if (index == 0) { // If insert before the first element
                return push_front(date);
            }
            else // If List is empty
            {
                Node* temp = head; // Create temporary node
                Node* insert = new Node;
                insert->date = date;              
                for (int i = 0; i < index - 1; i++) {
                    temp = temp->next;
                }
                insert->next = temp->next;
                temp->next = insert;
                temp = insert;
            }
        }
        else {
            throw out_of_range("The position of the element is greater than the maximum index of the List"); // Error message 
        }
    }

    // getting an element by index
    int at(size_t index) {
        if (index < get_size()) // If index is in List range
        {
            Node* temp = head; // Create temporary node
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            return temp->date;
        }
        else {
            throw out_of_range("The position of the element is out of range List index\n"); // Error message
        }
    }

    // deleting an element by index
    void remove(size_t index) {
        if (index < get_size()) { // If index is in List range

            if (index == 0)
            {
                return pop_front();
            }
            else if (index == get_size() - 1)
            {
                return pop_back();
            }
            else {
                Node* temp = head; // Create temporary node
                for (int i = 0; i < index - 1; i++) {
                    temp = temp->next;
                }
                Node* remove = temp->next;
                temp->next = remove->next;
                delete remove;
                

            }
        }
        else {
            throw out_of_range("The position of the element is out of range List index"); // Error message
        }
    }

    // removing all list items
    void clear() {
        Node* temp = head; // Create temporary node
        while (head != NULL) {
            temp = head->next;
            delete head;
            head = temp;
        }
        tail = NULL;
    }

    // replacing the element by index with the passed element
    void set(size_t index, int date) {
        if (index < get_size()) { // If index is in List range
            Node* temp = head; // Create temporary node
            for (int i = 0; i < index; i++) {
                temp = temp->next;
            }
            temp->date = date;
        }
        else {
            throw out_of_range("The position of the element is out of range List index"); // Error message
        }
    }

    //	Overloading the output operator <<
    friend ostream& operator << (ostream& stream, const List& list);

    // поиск последнего вхождения другого списка в список
    int find_last(List& const list) {
        bool flag_entry = false;
        int last_entry_index = -1;
        int counter = -1;
        int chekcounter = 0;
        Node* temp = head; // Create temporary node
        Node* doptemp = list.head;
        Node* chektemp;  // Create temporary node
        Node* chekdoptemp;
        while (temp != NULL) {
            if (temp->date == doptemp->date) {
                flag_entry = true;
                chektemp = temp ->next;  // Create temporary node
                chekdoptemp = doptemp->next;
                chekcounter = 1;
                for (; (chekdoptemp != NULL) && (chektemp != NULL);) // Checking that the entire list is included in the original List
                {
                    if (chektemp->date != chekdoptemp->date) {
                        flag_entry = false;
                    }
                    chektemp = chektemp->next;
                    chekdoptemp = chekdoptemp->next;
                    chekcounter = chekcounter + 1;
                }
                if ((chekdoptemp != NULL) && (chektemp == NULL))  flag_entry = false;
                if (flag_entry) last_entry_index = counter + 1;
                temp = chektemp;
                counter = counter + chekcounter;
            }
            else {
                temp = temp->next;
                counter = counter + 1;
            }
        }
        if (last_entry_index != -1) return last_entry_index;
        else {
            throw invalid_argument("Lists are not included in each other"); // Error message
        }
    };
};

//	Overloading the output operator <<
ostream& operator << (ostream& stream, const List& list)
{
    List::Node* current = list.head;
    while (current != NULL) {
        stream << current->date << " ";
        current = current->next;
    }
    stream << endl;
    return stream;
}

