//
//  main.cpp
//  DSAssmt1
//
//  Created by danielle ryall on 2017-01-20.
//  Copyright © 2017 w0293490. All rights reserved.
//

//#include <iostream>
//#include <fstream>
//#include <cstdio>
////#include "LinkedList.hpp"
//
//
//using namespace std;
//
//
//struct Node
//{
//public:
//    string data;
//    Node *next;
//    
//    Node() : next(NULL), data("") {}
//};
//
//class LinkedList
//{
//private:
//    Node *first;
//    
//public:
//    LinkedList() : first(NULL) {}
//    
//    virtual ~LinkedList()
//    {
//        Node *node = first;
//        
//        while (node != NULL)
//        {
//            Node *temp = node;
//            
//            node = node->next;
//            
//            delete temp;
//        }
//    }
//    
//    void Add(string num)
//    {
//        Node *node = new Node();
//        node->data = num;
//        
//        if (first == NULL)
//        {
//            first = node;
//        }
//        else
//        {
//            Node *currNode = first;
//            Node *prevNode = NULL;
//            
//            while (currNode != NULL)
//            {
//                prevNode = currNode;
//                currNode = currNode->next;
//            }
//            
//            if (prevNode != NULL)
//            {
//                prevNode->next = node;
//            }
//        }
//    }
//    
//    void DeleteValue(string value)
//    {
//        Node *node = first;
//        Node *prev = NULL;
//        
//        while (node != NULL)
//        {
//            if (node->data == value)
//            {
//                break;
//            }
//            
//            prev = node;
//            node = node->next;
//        }
//        
//        if (node != NULL)
//        {
//            if (node == first)
//            {
//                first = node->next;
//            }
//            else
//            {
//                prev->next = node->next;
//            }
//            
//            delete node;
//        }
//    }
//    
//    void DeleteNode(int nodenum)
//    {
//        int index = -1;
//        
//        Node *node = first;
//        Node *prev = NULL;
//        
//        while (node != NULL)
//        {
//            index++;
//            
//            if (index == nodenum)
//            {
//                break;
//            }
//            
//            prev = node;
//            node = node->next;
//        }
//        
//        if (index >= 0)
//        {
//            if (node == first)
//            {
//                first = node->next;
//            }
//            else
//            {
//                prev->next = node->next;
//            }
//            
//            delete node;
//        }
//    }
//    
//    void InsertAfterValue(string value, string num)
//    {
//        Node *node = new Node();
//        node->data = num;
//        
//        // search for node to insert after
//        Node *prev = first;
//        
//        while (prev != NULL)
//        {
//            if (prev->data == value)
//            {
//                break;
//            }
//            
//            prev = prev->next;
//        }
//        
//        // insert node into list
//        if (first == NULL)
//        {
//            first = node;
//        }
//        else
//        {
//            if (prev != NULL)
//            {
//                node->next = prev->next;
//                prev->next = node;
//            }
//            else
//            {
//                // could not find the node to insert after
//                // so defaulting to Add function
//                Add("");
//            }
//        }
//    }
//    
//    friend ostream& operator<<(ostream& output, LinkedList& list);
//};
//
//ostream& operator<<(ostream& output, LinkedList& list)
//{
//    Node *currNode = list.first;
//    
//    while (currNode != NULL)
//    {
//        output << currNode->data << endl;
//        
//        currNode = currNode->next;
//    }
//    
//    return output;
//}
