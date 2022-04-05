/*******************************************************************************
 * Name        : unique.cpp
 * Author      : Rashmika Batra
 * Date        : September 27th, 2021
 * Description : Determining uniqueness of chars with int as bit vector.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System. 
 ******************************************************************************/
#include <iostream>
#include <cctype>
#include <sstream>

using namespace std;

bool is_all_lowercase(const string &s) {

    for (unsigned int i = 0; i < s.length(); i++)
    {
        if(!islower(s[i])) 
        { 
            return false; 
        }
    }
    return true;
    // TODO: returns true if all characters in string are lowercase
    // letters in the English alphabet; false otherwise.
}

bool all_unique_letters(const string &s) {

    int track_var = 0;
    for(unsigned int i = 0; i < s.length(); i++)
    {
        char current = s[i];
        int lower_case_a = 'a';
        int c = current;
        
        int num_shifts = c - lower_case_a;
        
        int representation = 1 << num_shifts;
        int test = track_var & representation;
        
        if(test != 0)//there is duplicate
        {
            return false;
        }
        
        
        track_var = track_var | representation;
        
        
    }
    return true;
}

int main(int argc, char * const argv[]) {
    istringstream stream;
    
    if(argc != 2)
    {
        cerr << "Usage: ./unique <string>" << endl;
        return 1;
    }
    
    string str;
    
    stream.str(argv[1]);
    
    stream >> str;
    
    if(!is_all_lowercase(str))
    {
        cerr << "Error: String must contain only lowercase letters." << endl;
        return 1;
    }

    else if(all_unique_letters(str))
    {
        cerr << "All letters are unique." << endl;
        return 0;
    }

    else
    {
        cerr << "Duplicate letters found." << endl;
        return 0;
    }
    
    return 0;
}


