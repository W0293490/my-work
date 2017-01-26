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
    
    //    void insertNode(double num)
    //    {
    //        Node *nodePtr;
    //        Node *newNode;
    //        Node *previousNode = 0;
    //
    //        //create and store data to new node
    //        newNode = new Node;
    //        newNode->data = num;
    //        //if there are no nodes in the list - make it the first node
    //        if (!first)
    //        {
    //            first = newNode;
    //            newNode->next = 0;
    //        }
    //        else //insertnode
    //        {
    //            //nodePtr to head of list
    //            nodePtr = first;
    //            //set previous to null
    //            previousNode = 0;
    //            //skip nodes valued less than num
    //            while (nodePtr !=0 && nodePtr->value < num)
    //            {
    //                previousNode = nodePtr;
    //                nodePtr = nodePtr->next;
    //            }
    //            //If the new node is the be the first in the list,
    //            //insert it before all the other nodes
    //            if(previousNode == 0)
    //            {
    //                first = newNode;
    //                newNode->next = nodePtr;
    //            }
    //            else//insert after previousNode (ORDER MATTERS!!!)
    //            {
    //                previousNode->next = newNode;
    //                newNode->next = nodePtr;
    //            }
    //
    //        }
    //    }
    
    
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
    
    void DeleteValue(string value)
    {
        Node *node = first;
        Node *prev = NULL;
        
        while (node != NULL)
        {
            if (node->data == value)
            {
                break;
            }
            
            prev = node;
            node = node->next;
        }
        
        if (node != NULL)
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
    
    //    void DeleteSelectedValue(int num)
    //    {
    //        Node *node = first;
    //        Node *prev = NULL;
    //
    ////        while (node != NULL)
    ////        {
    ////            if (node->data == value)
    ////            {
    ////                break;
    ////            }
    ////
    ////            prev = node;
    ////            node = node->next;
    ////        }
    //        for (int i = 0; i == num; i++)
    //        {
    //            prev = node;
    //            node = node->next;
    //            delete node;
    //        }
    //
    //        if (node != NULL)
    //        {
    //            prev->next = node->next;
    //
    //            delete node;
    //        }
    //    }
    
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
    
    void InsertAfterValue(string value, string num)
    {
        Node *node = new Node();
        node->data = num;
        
        // search for node to insert after
        Node *prev = first;
        
        while (prev != NULL)
        {
            if (prev->data == value)
            {
                break;
            }
            
            prev = prev->next;
        }
        
        // insert node into list
        if (first == NULL)
        {
            first = node;
        }
        else
        {
            if (prev != NULL)
            {
                node->next = prev->next;
                prev->next = node;
            }
            else
            {
                // could not find the node to insert after
                // so defaulting to Add function
                Add("");
            }
        }
    }
    
//    void outputWithNums(LinkedList list)
//    {
//        Node* p = list.first;
//        int i = 1;
//        while(p != NULL) {
//            cout << i << " - " << p->data << "\n";
//            p = p->next;
//            i++;
//        }
//    }
    
    //    void outputSingleNode(LinkedList list, int num)
    //    {
    //        Node* p = list.first;
    //        int i = 1;
    //        while(p != NULL) {
    //            cout << i << " - " << p->data << "\n";
    //            p = p->next;
    //            i++;
    //        }
    //    }
    //
    //    string GetNth(LinkedList list, int index)
    //    {
    //        string s;
    //        Node* p = list.first;
    //        int count = 0; /* the index of the node we're currently
    //                        looking at */
    //        while (p != NULL)
    //        {
    //            if (count == index)
    //                return(p->data);
    //            count++;
    //            p = p->next;
    //        }
    //        return s;
    //    }
    
    
    
    friend ostream& operator<<(ostream& output, LinkedList& list);
    
    
    
    
    int getNum1(const char stAr[])
    {
        int n1;
        int n2;
        int n3;
        int n4;
        
        int num1;
        
        if (stAr[3] == '-')
        {
            num1 = (stAr[2] - 48);
        }
        else if (stAr[4] == '-')
        {
            n1 = (stAr[2] - 48) * 10;
            n2 = (stAr[3] - 48);
            
            num1 = n1 + n2;
            
        }
        else if (stAr[5] == '-')
        {
            n1 = (stAr[2] - 48) * 100;
            n2 = (stAr[3] - 48) * 10;
            n3 = (stAr[4] - 48);
            
            num1 = n1 + n2 + n3;
            
        }
        else if (stAr[6] == '-')
        {
            n1 = (stAr[2] - 48) * 1000;
            n2 = (stAr[3] - 48) * 100;
            n3 = (stAr[4] - 48) * 10;
            n4 = (stAr[5] - 48);
            
            num1 = n1 + n2 + n3 + n4;
            
            
        }
        
        return num1;
    }
    
    int getNum2(string input, int ind)
    {
        int num2;
        int in = ind + 1;
        
        for (int i = 0; i < ind; i++)
        {
            input[i] = input[in];
            input[in] = NULL;
            in++;
        }
        
        num2 = stoi(input);
        return num2;
        
    }
    
    int oneNum(string input, int ind)
    {
        int num2;
        int in = 2;
        
        for (int i = 0; i <= ind; i++)
        {
            input[i] = input[in];
            input[in] = NULL;
            in++;
        }
        
        num2 = stoi(input);
        return num2;
    }
    
    
    
    
    unsigned GetNumberOfDigits (int n)
    {
        int num;
        if (n > 99)
        {num = 3;}
        else if (n > 9)
        {num = 2;}
        else
        {num = 1;}
        
        return num;
    }
    
    int getNumDigits(const char stAr[])
    {
        int cnt = 0;
        for (int i=0;i<10;i++){
            if (isdigit(stAr[i])){
                cnt++;
            }
        }
        return cnt;
        
    }
    
    //    int getNumOfChars(const char stAr[])
    //    {
    //        int cnt = 0;
    //        for (int i=0;i<10;i++){
    //            if (stAr[i] != ' '){
    //                cnt++;
    //            }
    //        }
    //        return cnt;
    //    }
    
    int numOfNums(const char stAr[])
    {
        int num;
        
        int dashes = 0;
        
        for (int i=0;i<10;i++)
            if (stAr[i] == '-')
            {
                dashes++;
            }
        num = (dashes == 1 ? 1 : 2);
        
        return num;
    }
    
    
    
    
    
    
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