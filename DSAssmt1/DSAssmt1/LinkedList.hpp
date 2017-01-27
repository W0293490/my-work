//
//  LinkedList.hpp
//  EDIT
//
//  Created by danielle ryall on 2017-01-22.
//  Copyright © 2017 w0293490. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

using namespace std;

struct Node
{
public:
    string data;
    Node *next;
    
    Node() : next(NULL), data("") {}
};

class LinkedList
{
private:
    Node *first;
    
public:
    LinkedList() : first(NULL) {}
    
    virtual ~LinkedList()
    {
        Node *node = first;
        
        while (node != NULL)
        {
            Node *temp = node;
            
            node = node->next;
            
            delete temp;
        }
    }

    
    
    void addNodeAtPos(string data, int pos)
    {
        Node* prev = new Node();
        Node* curr = new Node();
        Node* newNode = new Node();
        newNode->data = data;
        
        int tempPos = 0;   // Traverses through the list
        
        curr = first;      // Initialize current to head;
        if(first != NULL)
        {
            while(curr->next != NULL && tempPos != pos)
            {
                prev = curr;
                curr = curr->next;
                tempPos++;
            }
            if(pos==0)
            {
                cout << "Adding at Head! " << endl;
                // Call function to addNode from head;
            }
            else if(curr->next == NULL && pos == tempPos+1)
            {
                cout << "Adding at Tail! " << endl;
                // Call function to addNode at tail;
            }
            else if(pos > tempPos+1)
                cout << " Position is out of bounds " << endl;
            //Position not valid
            
            else
            {
                prev->next = newNode;
                newNode->next = curr;
                cout << "Node added at position: " << pos << endl;
            }
        }
        else
        {
            first = newNode;
            newNode->next=NULL;
            cout << "Added at head as list is empty! " << endl;
        }
    }
    
    void Add(string num)
    {
        Node *node = new Node();
        node->data = num;
        
        if (first == NULL)
        {
            first = node;
        }
        else
        {
            Node *currNode = first;
            Node *prevNode = NULL;
            
            while (currNode != NULL)
            {
                prevNode = currNode;
                currNode = currNode->next;
            }
            
            if (prevNode != NULL)
            {
                prevNode->next = node;
            }
        }
    }

    
    void DeleteNode(int nodenum)
    {
        int index = 0;
        
        Node *node = first;
        Node *prev = NULL;
        
        while (node != NULL)
        {
            index++;
            
            if (index == nodenum)
            {
                break;
            }
            
            prev = node;
            node = node->next;
        }
        
        if (index >= 0)
        {
            if (node == first)
            {
                first = node->next;
            }
            else
            {
                prev->next = node->next;
            }
            
            delete node;
        }
    }
    
    
    friend ostream& operator<<(ostream& output, LinkedList& list);

    
};

ostream& operator<<(ostream& output, LinkedList& list)
{
    Node *currNode = list.first;
    
    while (currNode != NULL)
    {
        output << currNode->data << endl;
        
        currNode = currNode->next;
    }
    
    return output;
}


#endif /* LinkedList_hpp */
