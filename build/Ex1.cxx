#include <iostream>
using namespace std;

class Teacher {
public:
    string toString();
    static Teacher& getTeacher();

    // Constructor
    Teacher(const string& name)
        : theName(name) {
    }

    Teacher(const Teacher& other)
        : theName(other.theName) {
    }

    // Move constructor
    Teacher(Teacher&& other) 
        : theName(move(other.theName)) {
            other.theName = "DefaultName";
    }

    // Destructor defined within the class
    ~Teacher() {
    }

private:
    string theName;

    static Teacher teacher; // Define and initialize the teacher object.
};

Teacher Teacher::teacher("Prof1"); // Initialize the static teacher object.

string Teacher::toString() {
    return "Name: " + theName;
}

Teacher& Teacher::getTeacher() {
    return teacher;
}

int main() {
    Teacher& teacher1 = Teacher::getTeacher();
    Teacher teacher2 = move(teacher1); // Using the move constructor to transfer resources
    cout << teacher1.toString() << endl; // Note: After the move, teacher1 might be in a valid but unspecified state.
    cout << teacher2.toString() << endl;

    return 0;
}
