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
#include "LinkedList.hpp"
#include "Parser.hpp"
#include "FileHandler.hpp"

using namespace std;

void ClearScreen()
{
    cout << string( 100, '\n' );
}

//regex will be ^[a-zA-Z](-[0-9]+)+$
//better yet, ^[idvlgseqIDVLGSEQ](-[0-9]+)+$


int main(int argc, const char * argv[])
{
    regex r("^[idvlgseqIDVLGSEQ](-[0-9]+)+$");
    regex man("-man");
    int firstNum = 0;
    int secondNum = 0;
    string STRING;
    char input[20];
    LinkedList list;
    Parser parser;
    FileHandler fileHandler;
    bool quit = false;
    int bufferLine = 1;
    int numberOfLines;
    
    //validate args, read and write file to list:
    if (regex_match(argv[1],man))
    {
        cout << "This is where the manual will go." << endl;
        cout << "it will guide you with rules and stuff." << endl;
        return 0;
    }
    
    else if (argc != 3)
    {
        cout << "You must provide two arguments (an input file and an output file)." << endl;
        return -1;
    }

    ifstream stream = fileHandler.readFile(argv[1]);
    
    string line;
    while (getline(stream,line))
    {
        list.Add(line);
    }
    
    //get number of lines to feed displayAllLines method:
    numberOfLines = (list.lineCounter(list));
    
    //enter program loop:
    while (!quit)
    {
        
        ClearScreen();
        
        //display all lines:
        list.displayAllLines(numberOfLines, bufferLine);
        
        //initialize numbers to zero for next input:
        firstNum = 0;
        secondNum = 0;
        
        //display the lines, prompt with line number, validate input:
//        cout << list << endl;
        
        cout << ">> ";
        cin >> input;
        
        //quit:
        if (input[0] == 'Q' || input[0] == 'q')
        {
            return 0;
        }
        
        //quit and save file:
        if (input[0] == 'E' || input[0] == 'e')
        {
            ofstream myFile = fileHandler.writeFile(argv[2]);
            
            myFile << list;
            
            return 0;
        }
        
        
        
        //show list:
//        if (input[0] == 'v' || input[0] == 'V')
//        {
//            cout << list << endl;
//        }
        
        
        while(!regex_match(input, r)){
            
            cout << "Please key in a proper sequence: \n" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> input;
            cout << "\n";
        }
        
    
    //methods to get numbers from input
        int numberOfNumbers = parser.numOfNums(input);
        
        if (numberOfNumbers == 1)
        {
            int ind2 = parser.getNumDigitsInArray(input);
            firstNum = parser.getNumberWhenOnlyOne(input, ind2);
            cout << "the number is " << firstNum << endl;
        }
        else
        {
            firstNum = parser.getNum1(input);
            int ind = parser.GetNumberOfDigits(firstNum) + 2;
            secondNum = parser.getNum2(input, ind);
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
            }
            if (numberOfNumbers == 0)
            {
                list.addNodeAtPos(userLine, bufferLine);
                
                cout << endl;
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
        
        
        if (input[0] == 'l' || input[0] == 'L')
        {
            list.displayLines(firstNum, secondNum);
            cout << endl;
        }
        
        if (input[0] == 'g' || input[0] == 'G')
        {
            bufferLine = firstNum;
        }
        
        if (input[0] == 's' || input[0] == 'S')
        {
            string userLine;
            
            cout << "Please key in the line you would like to replace the deleted line with: " << endl;
            cin.clear();
            cin.ignore(256, '\n');
            getline(cin, userLine);
            
            if (numberOfNumbers == 1)
            {
                list.DeleteNode(firstNum);
                list.addNodeAtPos(userLine, firstNum-1);
                
                cout << endl;
            }
            if (numberOfNumbers == 0)
            {
                list.DeleteNode(firstNum);
                list.addNodeAtPos(userLine, bufferLine);
                
                cout << endl;
            }
        }
        
        
    }
    
    return 0;
}

