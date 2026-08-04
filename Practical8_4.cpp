/*
An educational institution is developing a system to rank students based on their scores in an
examination. The goal is to efficiently store student names along with their respective scores, sort the
records in descending order based on scores, and display the ranked list. The system should be flexible
enough to handle varying numbers of students dynamically.
To achieve this, the system associates each student�s name with their score using a structured data
representation. A dynamically resizable sequence is chosen to store student records, allowing efficient
insertion and retrieval of entries. Each entry consists of a name-score pair, ensuring logical grouping
of related information.
Once the data is collected, a sorting operation is performed using a custom comparison function. By
leveraging an efficient sorting algorithm, the system ensures that students with the highest scores
appear at the top of the list. Iterators are then used to traverse and display the sorted data in a
structured format, highlighting rank-based ordering.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

// Structure to hold student record
struct Student {
    string name;
    int score;
};

// Custom comparison function for sorting in descending order of score
bool compareByScore(const Student& a, const Student& b) {
    return a.score > b.score;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    vector<Student> students;

    // Input student records
    for (int i = 0; i < n; ++i) {
        Student s;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> ws; // flush newline
        getline(cin, s.name);

        cout << "Enter score of " << s.name << ": ";
        cin >> s.score;

        students.push_back(s);
    }

    
    // Sort students based on scores in descending order
    sort(students.begin(), students.end(), compareByScore);

    // Display ranked list
    cout << "\n--- Student Rankings ---\n";
    cout << left << setw(5) << "Rank" << setw(20) << "Name" << "Score" << endl;
    cout << "------------------------------\n";

    int rank = 1;
    for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        cout << left << setw(5) << rank++ << setw(20) << it->name << it->score << endl;
    }

    return 0;
}

