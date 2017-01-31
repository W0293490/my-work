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
#include <string.h>
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
    regex help("-h");
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
    char fileExt[] = ".txt";
    
    //this wil append '.txt' to any save name.
    char str1[16];
    char str2[16];
    strcpy(str1, argv[2]);
    strcpy(str2, fileExt);
    strcat(str1, str2);
    string newStr1 = string(str1);
    
    
    //validate args, read and write file to list:
    if (regex_match(argv[1], help))
    {
        cout << endl;
        cout << "DATA STRUCTURES - ASSMT 1 - EDIT v1.0 (2017 Jan 20, compiled Jan 30 2017)\n" << endl;
        cout << "usage: EDIT [file... (file to read from)] [file... (file to save to]" << endl;
        cout << "       The second argument will be a text file, automatically saved in the root directory" << endl;
        cout << "or: EDIT -h (for the man page)\n" << endl;
        cout << "THIS IS A LIST OF COMMAND LETTERS AND THEIR MEANINGS:" << endl;
        cout << "      They are to be typed as a command letter (upper or lower case), then " << endl;
        cout << "      optionally (as required) a number, followed by, optionally (as required)" << endl;
        cout << "      a second number. The letter and number must be separated by a dash, with" << endl;
        cout << "      no spaces, Examples are: 'd', or 'd-2', or 'd-2-5'. No other formation " << endl;
        cout << "      will be accepted. The commands are:" << endl;
        cout << "'I' - will insert a line (provided by the user) in the specified position, or at " << endl;
        cout << "      the current position of the cursor." << endl;
        cout << "'D' - will delete the line, or lines of a given number or numbers, or delete the " << endl;
        cout << "      line at the position of the cursor if no number is given." << endl;
        cout << "'V' - will display all lines." << endl;
        cout << "'G' - will move the cursor to the line of the number provided, or set the cursor " << endl;
        cout << "      to the first line of no number is provided." << endl;
        cout << "'L' - will list the lines of the buffer using the same numbering system as the 'D' " << endl;
        cout << "      command" << endl;
        cout << "'S' - will substitute a line (provided by the user) with the line in the specified " << endl;
        cout << "      position, or at the current position of the cursor." << endl;
        cout << "'E' - will exit the program, and save the updated text file in the root directory, " << endl;
        cout << "      with the name provided as the second argument." << endl;
        cout << "'S' - will exit the program without saving.\n" << endl;
    
        
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
            ofstream myFile = fileHandler.writeFile(newStr1);
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
//            cout << "the number is " << firstNum << endl;
        }
        else if (numberOfNumbers == 2)
        {
            firstNum = parser.getNum1(input);
            int ind = parser.GetNumberOfDigits(firstNum) + 2;
            secondNum = parser.getNum2(input, ind);
//            cout << "the numbers are " << firstNum << " and " << secondNum << endl << endl;
        }
        
        //validation for numbers input:
        
        
        if (numberOfNumbers != 1 && numberOfNumbers != 0)
            {
                if (firstNum > secondNum)
                {
                    parser.swap(firstNum, secondNum);
                }
                
                if (firstNum == 0 || firstNum > numberOfLines || secondNum == 0 || secondNum > numberOfLines)
                {
                    cout << "Please keep the numbers within bounds..." << endl;
                    continue;
                }
            }
        
        if (numberOfNumbers == 1)
        {
            if (firstNum == 0 || firstNum > numberOfLines)
            {
                cout << "Please keep the numbers within bounds..." << endl;
                continue;
            }
        }
        
//        cout << "the numbers are " << firstNum << " and " << secondNum << endl << endl;
        
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


