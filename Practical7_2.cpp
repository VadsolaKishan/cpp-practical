/*
A data analysis firm is developing a tool to process large text files and extract key statistics, such as
the total number of characters, words, and lines. This tool is essential for tasks like document indexing,
text summarization, and data validation. Given the varying sizes of input files, the system must handle
large datasets efficiently while ensuring error detection when files are missing or inaccessible.
To begin, the program needs to open a specified text file and process its contents line by line. If the
file cannot be found or opened due to permission issues, the system should notify the user with an
appropriate error message and safely terminate execution. Once the file is successfully accessed, the
program will analyze its contents to count the total number of lines, extract words while handling
different delimiters, and compute the total number of characters, including spaces and punctuation.
For handling this data, the team explores two approaches. One approach dynamically stores the lines
in a manually managed array, processing the information without relying on built-in containers. This
requires careful memory allocation and deallocation to avoid leaks. The alternative approach uses a
dynamic structure to hold the lines in memory, allowing for efficient access and further analysis, such
as searching or editing.
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

using namespace std;

const int MAX_LINE_LENGTH = 1024;

// Count words in a line using whitespace and punctuation as delimiters
int countWordsInLine(const char* line) {
    int count = 0;
    bool inWord = false;

    for (int i = 0; line[i]; ++i) {
        if (isalnum(line[i])) {
            if (!inWord) {
                inWord = true;
                count++;
            }
        } else {
            inWord = false;
        }
    }

    return count;
}

// Function to expand dynamic array of lines
void expandLinesArray(char**& lines, int& capacity) {
    int newCapacity = capacity * 2;
    char** newLines = new char*[newCapacity];

    for (int i = 0; i < capacity; ++i) {
        newLines[i] = lines[i];
    }

    delete[] lines;
    lines = newLines;
    capacity = newCapacity;
}

int main() {
    char filename[256];
    cout << "Enter the name of the text file: ";
    cin.getline(filename, 256);

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open the file \"" << filename << "\".\n";
        return 1;
    }

    int capacity = 10;
    int lineCount = 0, wordCount = 0, charCount = 0;

    // Allocate initial array for lines
    char** lines = new char*[capacity];

    char buffer[MAX_LINE_LENGTH];

    while (file.getline(buffer, MAX_LINE_LENGTH)) {
        int len = strlen(buffer);
        charCount += len;         // Count characters in the line
        wordCount += countWordsInLine(buffer);  // Count words

        // Allocate memory for storing the line
        if (lineCount == capacity) {
            expandLinesArray(lines, capacity);
        }

        lines[lineCount] = new char[len + 1];
        strcpy(lines[lineCount], buffer);
        lineCount++;
    }

    // Count newline characters (each line ends with one, except last if EOF)
    charCount += lineCount;

    // Display statistics
    cout << "\nFile Statistics:\n";
    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters (incl. spaces/punctuation): " << charCount << endl;

    // Clean up memory
    for (int i = 0; i < lineCount; ++i) {
        delete[] lines[i];
    }
    delete[] lines;
    file.close();

    
    return 0;
}
