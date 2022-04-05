/*******************************************************************************
 * Name    : student.cpp
 * Author  : Rashmika Batra
 * Date    : September 9, 2021
 * Description : Creating a student class. 
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <vector> 

using namespace std; 
class Student { 
    private: 
        string first_; 
        string last_; 
        float gpa_; 
        int id_;  

    public: 
        Student(string first, string last, float gpa, int id): first_{first}, last_{last}, gpa_{gpa}, id_{id} {} 

    string const full_name() { 
        return first_ + " "  + last_; 

    }
    int const id () {
        return id_; 

    } 

    float const gpa() { 
        return gpa_; 
    }

    void print_info() {
        cout << full_name() << ", " << "GPA: " << fixed << setprecision(2) << gpa() << ", " << "ID: " << id() << endl;
    } 
};

vector<Student> find_failing_students(const vector<Student> &students) { 
    vector<Student> failing_students; 
    for (Student name: students) { 
        if (name.gpa() < 1.0) { 
            failing_students.push_back(name);
        }
    }
        return failing_students; 
}

void print_students(const vector<Student> &students) { 
    for (Student name: students) { 
        name.print_info(); 
        }
    }


int main() { 
    string first_name, last_name; 
    float gpa; 
    int id; 
    char repeat; 
    vector<Student> students; 

    do { 
        cout << "Enter student's first name: ";
        cin >> first_name; 
        cout << "Enter student's last name: ";
        cin >> last_name; 
        gpa = -1; 
        while (gpa<0 || gpa>4 ) { 
            cout << "Enter student's GPA (0.0-4.0): " ; 
            cin >> gpa; 
        }
        cout << "Enter student's ID: "; 
        cin>>id; 
        students.push_back(Student(first_name, last_name, gpa, id)); 
        cout << "Add another student to database (Y/N)? " ; 
        cin >> repeat; 
    } while (repeat == 'Y' || repeat == 'y'); 

    cout <<endl << "All students:" << endl; 
    print_students(students); 

    cout << endl << "Failing students:"; 

    vector<Student> failures = find_failing_students(students);  

    if(failures.empty()) { 
        cout <<" None" <<endl; 
    }
    else {
    	cout << endl;
        print_students(failures); 
    }

    
    //TODO
    //Print a space and the word 'None' on the same line if no stuents are failing 
    //Otherwise, print each failing student on a seperate line. 

    return 0; 
}
