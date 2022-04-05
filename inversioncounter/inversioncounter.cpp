/*******************************************************************************
 * Name        : inversioncounter.cpp
 * Author      : Rashmika Batra
 * Version     : 1.0
 * Date        : October 27th, 2021 
 * Description : Counts the number of inversions in an array.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System. 
 ******************************************************************************/
#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>

using namespace std;

// Function prototype.
static long mergesort(int array[], int scratch[], int low, int high);

/**
 * Counts the number of inversions in an array in theta(n^2) time.
 */
long count_inversions_slow(int array[], int length) {
    // TODO
    long inversions = 0; 
    for(long g=0; length>g; g++) { 
        for (long r = 1+g; length>r; r++) { 
            if(array[r]<array[g]) { 
                inversions++; 
            }
        }
    }
    return inversions; 
}

/**
 * Counts the number of inversions in an array in theta(n lg n) time.
 */
long count_inversions_fast(int array[], int length) {
    int *scratch = new int[length]; 
    long inversions; 
    inversions = mergesort(array, scratch, 0, length-1); 
    delete [] scratch; 
    return inversions; 

}

static long mergesort(int array[], int scratch[], int low, int high) {
    long inversions = 0; 
    int mid; 
    

    if (low<high) { 
        mid = low + (high-low)/2; 
   inversions+= mergesort(array,scratch, low, mid); 
   inversions+= mergesort(array, scratch, mid+1, high); 

   int L = low; 
   int H = mid+1; 

   for(int k= low; high>= k; k++) { 
       if(L<=mid && (H>high || array[L] <= array[H])) { 
           scratch[k] = array[L]; 
           L= L+1; 
       }
       else { 
           scratch[k]= array[H]; 
           H= H+1; 
           inversions += 1+ (mid-L); 

       }

   }
 for(int k= low; high>= k; k++) { 
     array[k] = scratch[k]; 

}
    }


return inversions; 
} 
int main(int argc, char *argv[]) {
    // TODO: parse command-line argument

    if (argc>2) { 
        cerr << "Usage: " << argv[0] << " [slow]" <<endl; 
        return 1; 
    }

    if(argc==2) { 
        int cmp = strcmp(argv[1], "slow"); 
        if(cmp !=0 ) { 
            cerr << "Error: Unrecognized option '" << argv[1] << "'." << endl; 
            return 1; 
        }
    }
    cout << "Enter sequence of integers, each followed by a space: " << flush;

    istringstream iss;
    int value, index = 0;
    vector<int> values;
    string str;
    str.reserve(11);
    char c;
    while (true) {
        c = getchar();
        const bool eoln = c == '\r' || c == '\n';
        if (isspace(c) || eoln) {
            if (str.length() > 0) {
                iss.str(str);
                if (iss >> value) {
                    values.push_back(value);
                } else {
                    cerr << "Error: Non-integer value '" << str
                         << "' received at index " << index << "." << endl;
                    return 1;
                }
                iss.clear();
                ++index;
            }
            if (eoln) {
                break;
            }
            str.clear();
        } else {
            str += c;
        }
    }

    if (values.size() < 0) { 
        cout << "Error: Sequence of integers not received." << endl; 
       
    }
    if (values.empty()) { 
        cout << "Error: Sequence of integers not received." << endl; 
       
    }
     if (values.size() > 0  && values.size() < 3) { 
         cout << "Number of inversions: " << count_inversions_slow(&values[0], values.size()); 
    }

    if (values.size() > 2) { 
        cout << "Number of inversions: " << count_inversions_fast(&values[0], values.size()); 
    }

    
    // TODO: produce output

    int arr[] = {1,2};
    mergesort(arr, arr, 1, 1);

    return 0;
}
