//
//  FileHandler.hpp
//  EDIT
//
//  Created by danielle ryall on 2017-01-26.
//  Copyright © 2017 w0293490. All rights reserved.
//

#ifndef FileHandler_hpp
#define FileHandler_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;

class FileHandler
{
public:
    
    ifstream readFile(string file)
    {
        ifstream ifstrm;
        ifstrm.open(file);
    
        try
        {
            if(!ifstrm)
            {
                cout << "ERROR: Cannot open file!" << endl;
                exit(1);
            }
        }
        catch(const exception& ex)
        {
            cout << "Exception: '" << ex.what() << "'!" << endl;
            exit(1);
        }
        return ifstrm;
    }
    
    ofstream writeFile(string file)
    {
        //writing list to new text file
        ofstream myfile;
        myfile.open (file);
        return myfile;
        myfile.close();
        
    }
    
};



#endif /* FileHandler_hpp */
