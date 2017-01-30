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

void printUpperBanner()
{
    cout << endl << string(67,'*') << endl;
    cout << "'I'= Insert | 'D' = Delete | 'G'= Goto Line | 'L' = Display Line(s)" << endl;
    cout << string(67,'*') << endl << endl;
}

void printLowerBanner()
{
    cout << endl << string(67,'*') << endl;
    cout << "'V'= Display All | 'S'= Substitute | 'E'= Save and Exit |'Q'= Exit" << endl;
    cout << string(67,'*') << endl << endl;
}

int main(int argc, const char * argv[])
{
    //regex variables:
    regex r("^[idvlgseqIDVLGSEQ]((-[0-9]+)+)?$");
    regex man("-man");
    regex i("[Ii](-[0-9]+)?");
    regex d("[Dd](-[0-9]+)?(-[0-9]+)?");
    regex v("[Vv]$");
    regex g("[Gg](-[0-9]+)?");
    regex l("[Ll](-[0-9]+)?(-[0-9]+)?");
    regex s("[Ss](-[0-9]+)?");
    regex e("[Ee]$");
    regex q("[Qq]$");
    regex gOnly("[Gg]$");
    
    //misc. variables:
    int firstNum = 0;
    int secondNum = 0;
    int numberOfNumbers = 0;
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
    
    ClearScreen();
    
    //display all lines:
    printUpperBanner();
    list.displayAllLines(numberOfLines, bufferLine);
    printLowerBanner();
    
    
    
    //enter program loop:
    while (!quit)
    {
        //clear input:
        memset(input, 0, sizeof(input));
        //get number of lines to feed displayAllLines method:
        numberOfLines = (list.lineCounter(list));
        
        //initialize numbers to zero for next input:
        firstNum = 0;
        secondNum = 0;
        
        //display the lines, prompt with line number, validate input:
        cout << ">> ";
        cin.getline(input, 10);
        
        //for input for quit:
        if (regex_match(input, q))
        {
            return 0;
        }
        
        //for input for quit and save file:
        if (regex_match(input, e))
        {
            ofstream myFile = fileHandler.writeFile(argv[2]);
            myFile << list;
            return 0;
        }
        
        //for input for display all:
        if (regex_match(input, v))
        {
            ClearScreen();
            
            //display all lines:
            printUpperBanner();
            list.displayAllLines(numberOfLines, bufferLine);
            printLowerBanner();
            
        }
        
        while(!regex_match(input, r))
        {
            cout << "Please key in a proper sequence: \n" << endl;
            cin.clear();
            cin.ignore(256, '\n');
//                  cin >> input;
            cin.getline(input, 10);
            cout << "\n";
        }
        
        
        //methods to get numbers from input
        numberOfNumbers = parser.numOfNums(input);
        
        if (numberOfNumbers == 1)
        {
            int numOfDigits = parser.getNumDigitsInArray(input);
            firstNum = parser.getNumberWhenOnlyOne(input, numOfDigits);
            cout << "the number is " << firstNum << endl;
        }
        else if (numberOfNumbers == 2)
        {
            firstNum = parser.getNum1(input);
            int ind = parser.GetNumberOfDigits(firstNum) + 2;
            secondNum = parser.getNum2(input, ind);
            cout << "the numbers are " << firstNum << " and " << secondNum << endl << endl;
        }
        
        //for input for insert:
        if (regex_match(input, i))
        {
            string userLine;
            
            cout << "Please key in the line you would like to insert: " << endl;
            getline(cin, userLine);
            
            if (numberOfNumbers == 1)
            {
                list.addNodeAtPos(userLine, firstNum);
                
                cout << endl;
            }
            if (numberOfNumbers == 0)
            {
                list.addNodeAtPos(userLine, bufferLine);
                
                cout << endl;
            }
            
            //get number of lines to feed displayAllLines method:
            numberOfLines = (list.lineCounter(list));
            
            ClearScreen();
            
            //display all lines:
            printUpperBanner();
            list.displayAllLines(numberOfLines, bufferLine);
            printLowerBanner();
        }
        
        //for input for delete:
        if (regex_match(input, d))
        {
            if (firstNum == 0 && secondNum == 0)
            {
                list.DeleteNode2(bufferLine);
            }
            else if (firstNum != 0 && secondNum == 0)
            {
                list.DeleteNode2(firstNum);
            }
            
            else
            {
                int range = secondNum - firstNum;
                for (int i = 0; i <= range; i++)
                {
                    list.DeleteNode2(firstNum);
                }
            }
            
            //get number of lines to feed displayAllLines method:
            numberOfLines = (list.lineCounter(list));
            
            ClearScreen();
            
            //display all lines:
            printUpperBanner();
            list.displayAllLines(numberOfLines, bufferLine);
            printLowerBanner();
        }
        
        //for input for display line:
        if (regex_match(input, l))
        {
            ClearScreen();
            
            printUpperBanner();
            list.displayLines(firstNum, secondNum);
            printLowerBanner();
        }
        
        //for input for goto line:
        if (regex_match(input, g))
        {
            if (numberOfNumbers == 0)
            {
                bufferLine = 1;
            }
            else
            {
                bufferLine = firstNum;
            }
            
            ClearScreen();
            
            //display all lines:
            printUpperBanner();
            list.displayAllLines(numberOfLines, bufferLine);
            printLowerBanner();
        }
        
        //for input for substitute:
        if (regex_match(input, s))
        {
            string userLine;
            
            cout << "Please key in the line you would like to replace the deleted line with: " << endl;
            getline(cin, userLine);
            
            if (numberOfNumbers == 1)
            {
                list.DeleteNode2(firstNum);
                list.addNodeAtPos(userLine, firstNum);
                
                cout << endl;
            }
            if (numberOfNumbers == 0)
            {
                list.DeleteNode2(bufferLine);
                list.addNodeAtPos(userLine, bufferLine);
                
                cout << endl;
            }
            
            ClearScreen();
            
            //display all lines:
            printUpperBanner();
            list.displayAllLines(numberOfLines, bufferLine);
            printLowerBanner();
        }
    }
    
    return 0;
}


