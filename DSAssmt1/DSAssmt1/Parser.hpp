//
//  Parser.hpp
//  EDIT
//
//  Created by danielle ryall on 2017-01-26.
//  Copyright © 2017 w0293490. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>

using namespace std;



class Parser
{
public:
    
    //parse 1st number when there is only one number:
    int getNumberWhenOnlyOne(string input, int index)
    {
        int number1;
        int newIndex = 2;
        
        for (int i = 0; i <= index; i++)
        {
            input[i] = input[newIndex];
            input[newIndex] = NULL;
            newIndex++;
        }
        
        number1 = stoi(input);
        return number1;
    }
    
    //parse 1st number from input:
    int getNum1(const char array[])
    {
        int num1;
        int num2;
        int num3;
        int num4;
        
        int number1;
        
        if (array[3] == '-')
        {
            number1 = (array[2] - 48);
        }
        else if (array[4] == '-')
        {
            num1 = (array[2] - 48) * 10;
            num2 = (array[3] - 48);
            
            number1 = num1 + num2;
        }
        else if (array[5] == '-')
        {
            num1 = (array[2] - 48) * 100;
            num2 = (array[3] - 48) * 10;
            num3 = (array[4] - 48);
            
            number1 = num1 + num2 + num3;
        }
        else if (array[6] == '-')
        {
            num1 = (array[2] - 48) * 1000;
            num2 = (array[3] - 48) * 100;
            num3 = (array[4] - 48) * 10;
            num4 = (array[5] - 48);
            
            number1 = num1 + num2 + num3 + num4;
        }
        
        return number1;
    }
    
    //parse 2nd number from input:
    int getNum2(string input, int index)
    {
        int number2;
        int newIndex = index + 1;
        
        for (int i = 0; i < index; i++)
        {
            input[i] = input[newIndex];
            input[newIndex] = NULL;
            newIndex++;
        }
        
        number2 = stoi(input);
        return number2;
    }

    //get number of digits in integer:
    int GetNumberOfDigits (int number)
    {
        int numOfDigits;
        
        if (number > 99)
            {numOfDigits = 3;}
        else if (number > 9)
            {numOfDigits = 2;}
        else
            {numOfDigits = 1;}
        
        return numOfDigits;
    }
    
    //get number of digits in array:
    int getNumDigitsInArray(const char array[])
    {
        int count = 0;
        for (int i = 0 ;i < 10 ;i++){
            if (isdigit(array[i])){
                count++;
            }
        }
        return count;
    }
    
    //get number of numbers in input:
    int numOfNums(const char array[])
    {
        int num;
        int dashes = 0;
        
        for (int i = 0;i < 10 ;i++)
            if (array[i] == '-')
            {
                dashes++;
            }
        num = (dashes == 1 ? 1 : 2);
        
        return num;
    }
};



#endif /* Parser_hpp */
