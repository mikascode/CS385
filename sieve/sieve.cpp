/*******************************************************************************
 * Name        : sieve.cpp
 * Author      : Rashmika Batra
 * Date        : September 14th, 2021 
 * Description : Sieve of Eratosthenes
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

using namespace std;

class PrimesSieve {
public:
    PrimesSieve(int limit);

    ~PrimesSieve() {
        delete [] is_prime_;
    }

    int num_primes() const {
        return num_primes_;
    }

    void display_primes() const;
    

private:
    // Instance variables
    bool * const is_prime_;
    const int limit_;
    int num_primes_, max_prime_;

    // Method declarations
    int count_num_primes() const;
    void sieve();
    static int num_digits(int num);
    
};

PrimesSieve::PrimesSieve(int limit) :
        is_prime_{new bool[limit + 1]}, limit_{limit} {
    sieve();
}

void PrimesSieve::display_primes() const {
    
    const int max_prime_width = num_digits(max_prime_), primes_per_row = 80 / (max_prime_width + 1);
    
     int remaining = primes_per_row;
     
    if (primes_per_row < count_num_primes()){
        
         for (int i = 0; limit_ >= i; i++) {
             
            if (max_prime_ == i ) {
                
                cout << setw(max_prime_width) << i;
                
                break;
                
            } 
            
            else if(is_prime_[i]) {
                
                
                if (remaining == 0) {
                    
                    remaining = primes_per_row;
                    
                    cout << endl;
                }
                
                cout << setw(max_prime_width) << i;
                
                if (1!= remaining ) {
                    
                    cout << " ";
                }
                
                remaining--;
            }
        }
    }
        
        
        
        else {
            
            for (int i = 0; i <= limit_; i++) {
                
            if (i == max_prime_) {
                
                cout << setw(max_prime_width) << i;
                
            } else if(is_prime_[i]) {
                
                if (0 == remaining) {
                    
                    cout << endl;
                    
                    remaining = primes_per_row ;
                }
                cout << i;
                if (1 != remaining) {
                    cout << " ";
                }
                remaining--;
            }
        }
    } 
}
    




int PrimesSieve::count_num_primes() const {
    return num_primes_;
}

void PrimesSieve::sieve() {
    
    num_primes_ = 0;
    
    for (int i=0; i<=limit_; i++) { 
        
         if (i<2) { is_prime_[i] = false;}
         
         else{is_prime_[i] = true;} 
         
    } 

    for (int x = 0; x <= limit_; x++) { 
        
        if (is_prime_[x]) { 
            
            for (int y = x* 2; y<= limit_; y+=x) { 
                
                    is_prime_[y] = false; 
            }
            
            num_primes_++;
            
            max_prime_ = x;
        }
    }
}

int PrimesSieve::num_digits(int num) {
    
    int count = 0;
    
    while (num > 0) {
        
        num = num/10;
        
        count++;
    }
    return count;
}

int main() {
    cout << "**************************** " <<  "Sieve of Eratosthenes" <<
            " ****************************" << endl;
    cout << "Search for primes up to: ";
    string limit_str;
    cin >> limit_str;
    int limit;

    // Use stringstream for conversion. Don't forget to #include <sstream>
    istringstream iss(limit_str);

    // Check for error.
    if ( !(iss >> limit) ) {
        cerr << "Error: Input is not an integer." << endl;
        return 1;
    }
    if (limit < 2) {
        cerr << "Error: Input must be an integer >= 2." << endl;
        return 1;
    }

    PrimesSieve test(limit);
    cout << endl;
    
    cout << "Number of primes found: " << test.num_primes() << endl;
    
    cout << "Primes up to " << limit << ":" << endl;
    
    test.display_primes();

    return 0;
}