/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Rashmika Batra
 * Date        : October 2nd, 2021
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {

    // Define vectors ways and results
    vector<vector<int>> ways = {}; 

    vector<vector<int>> result = {}; 

    // Check if number of stairs is less than 0
    if (num_stairs<=0) { 

        ways.push_back(vector<int>()); 

    }
   

    else { 
        
        for (unsigned int i=1; i<4; i++) { 

            if(num_stairs >=i) { 

                result = get_ways(num_stairs-i); 

                //prepending i to all the solutions in result 
                for(unsigned int j=0; j<result.size(); j++) { 

                   result[j].insert(result[j].begin(), i); 
                }
                ways.insert(ways.end(), result.begin(), result.end()); 
            }

        }
    }
   
    return ways; 

}

void display_ways(const vector< vector<int> > &ways) {

    //function to display ways 
    //max variable set to ways vector 

    int max= ways.size(), 
    
    c = 0; 

    //setting counter variable to zero 

    while (max != 0) { 
        
        max=max/10; 
       //incrementing c for digits 
        c++; 
    }

    for (unsigned int i=0; i<ways.size(); i++) { 
      
        cout << setw(c) << i+1 << ". ["; 

        int r = 0; 

        for (int j=0; j<ways[i].size()-1; j++) { 
            cout<< ways[i][j] << ", "; 
            r++; 
        }

        cout << ways[i][r] << "]" << endl; 


    }
}



int main(int argc, char * const argv[]) {

    istringstream iss; 
    int a; 


    if (argc == 1 || 2<argc) { 
		cerr << "Usage: " << argv[0] << " <number of stairs>" << endl;
		return 1;
	}

    

    iss.str(argv[1]); 

    //Error Statement, if input is not positive integer 

    if (!(iss>>a) || (a<=0)) { 
        cerr << "Error: Number of stairs must be a positive integer." << endl; 
        return 1; 
    }

    vector<vector<int>> myvec = get_ways(a); 
    int length= myvec.size(); 

    //if only one way to climb, different statement 
    if (length==1) { 
        cout << myvec.size() << " way to climb " << a << " stair." << endl; 
    
    }
    //if multiple ways to climb, different statement
    else { 
        cout << myvec.size() << " ways to climb " << a << " stairs." << endl; 

    }

    display_ways(myvec); 

    return 0; 


}

