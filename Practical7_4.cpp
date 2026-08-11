/*
An educational institution requires a system to generate well-structured student performance reports
from raw data stored in a file. The system should read student records, including their name, marks,
and grade, and present the information in a neatly formatted tabular format. Since the institution
handles large datasets, the report generation must be efficient, ensuring clear alignment and
readability while allowing for future enhancements such as sorting and filtering.
To achieve this, the system must first handle file input operations, reading student data while ensuring
error handling if the file is missing or inaccessible. The program should then format and display the
information in a structured manner, making use of a user-defined manipulator to align columns
properly. This ensures that names, marks, and grades are clearly visible in the report, regardless of
data length variations.
For implementation, two approaches are explored. The first method processes the data directly from
the file, formatting and displaying each entry without storing it in memory. This minimizes memory
usage but limits additional processing, such as sorting or filtering. The alternative approach
dynamically stores student records using a manually managed data structure, allowing further
modifications, such as sorting by marks or filtering based on grades, before presenting the final
formatted report.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

void printFormattedHeader() {
    cout << left << setw(20) << "Student Name"
         << setw(10) << "Marks"
         << setw(10) << "Grade" << endl;
    cout << string(40, '-') << endl;
}

void generateReport(const string& filename) {
    ifstream file(filename);

    if (!file) {
        cout << "Error: File could not be opened." << endl;
        return;
    }

    string name;
    int marks;
    char grade;

    printFormattedHeader();

    while (file >> name >> marks >> grade) {
        cout << left << setw(20) << name
             << setw(10) << marks
             << setw(10) << grade << endl;
    }

    file.close();
}

int main() {
    string filename = "students.txt";
    generateReport(filename);

    return 0;
}

