//
//  main.cpp
//  DSAssmt1
//
//  Created by danielle ryall on 2017-01-20.
//  Copyright © 2017 w0293490. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <regex>
#include <math.h>
#include <array>
#include "LinkedList.hpp"
//#include <cstdio>

using namespace std;







//regex will be ^[a-zA-Z](-[0-9]+)+$
//better yet, ^[idvlgseqIDVLGSEQ](-[0-9]+)+$


int main(int argc, const char * argv[])
{
    regex r("^[idvlgseqIDVLGSEQ](-[0-9]+)+$");
    int firstNum = 0;
    int secondNum = 0;
    string STRING;
    char input[20];
    LinkedList list;
    bool quit = false;
    
    
    //read file
    if (argc != 3)
    {
        cout << "You must provide two arguments (an input file and an output file)." << endl;
        return -1;
    }
    try
    {
        ifstream f(argv[1]);
        
        if(!f)
        {
            cout << "ERROR: Cannot open file!" << endl;
            exit(1);
        }
        string line;
        
        
        while (getline(f,line))
        {
            list.Add(line);
        }
    }
    catch(const exception& ex)
    {
        cout << "Exception: '" << ex.what() << "'!" << endl;
        exit(1);
    }
    
    while (!quit)
    {
    
    cout << list << endl;
//    list.outputWithNums(list);
//    list.GetNth(list, 3);
    
    
    cout << "Currently at line number 1: " << endl;
    cin >> input;
        if (input[0] == 'Q' || input[0] == 'q')
        {
            return 0;
        }
        
        if (input[0] == 'E' || input[0] == 'e')
        {
            //writing list to new text file
            ofstream myfile;
            myfile.open (argv[2]);
            myfile << list;
            myfile.close();
            
            return 0;
        }
        
    while(!regex_match(input, r)){
        cout << "Please key in a proper sequence: \n" << endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> input;
        cout << "\n";
    }
    
    
    //methods to get numbers from input
    int numberOfNumbers = list.numOfNums(input);
    
    if (numberOfNumbers == 1)
    {
        int ind2 = list.getNumDigits(input);
        firstNum = list.oneNum(input, ind2);
        cout << "the number is " << firstNum << endl;
        
        
    }
    else
    {
        firstNum = list.getNum1(input);
        int ind = list.GetNumberOfDigits(firstNum) + 2;
        secondNum = list.getNum2(input, ind);
        cout << "the numbers are " << firstNum << " and " << secondNum << endl << endl;
    }
    
    
    
    if (input[0] == 'i' || input[0] == 'I')
    {
        string userLine;
        
        cout << "Please key in the line you would like to insert: " << endl;
        cin.clear();
        cin.ignore(256, '\n');
        getline(cin, userLine);
        
        if (numberOfNumbers == 1)
        {
            list.addNodeAtPos(userLine, firstNum-1);
            
            cout << endl;
            
//            cout << list << endl;
        }
    }
    
    if (input[0] == 'd' || input[0] == 'D')
    {
        if (firstNum == 0)
        {
            list.DeleteNode(0);
        }
        else if (secondNum == 0)
        {
            list.DeleteNode(firstNum);
        }
        else
        {
            int range = secondNum - firstNum;
            for (int i = 0; i <= range; i++)
            {
                list.DeleteNode(firstNum);
            }
                
        }
    }
    
    if (input[0] == 'v' || input[0] == 'V')
    {
        cout << list << endl;
        
    }
    
    if (input[0] == 'g' || input[0] == 'G')
    {
        cout << list << endl;
        
    }
        
        
        
    
        
    
    
        
    cout << "This is the original text file printed:\n" << endl;
    
    ifstream infile1;
    infile1.open (argv[1]);
    while(!infile1.eof())
    {
        getline(infile1,STRING);
        cout<<STRING<<endl;
    }
    infile1.close();
    
    cout << "This is the new text file printed:\n" << endl;

    ifstream infile2;
    infile2.open (argv[2]);
    while(!infile2.eof())
    {
        getline(infile2,STRING);
        cout<<STRING<<endl;
    }
    infile2.close();
        
        
    }

    
    return 0;
}

