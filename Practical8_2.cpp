/*
A digital publishing company is developing a tool to analyze text content for word frequency
distribution. This tool aims to help writers and editors understand the prominence of specific words
in an article, enabling them to refine their content for clarity and impact. The system should process
an input sentence, count occurrences of each unique word, and display the results in an organized
manner.
To achieve this, the system utilizes an associative container that maps words to their corresponding
frequencies. As the text is processed, each word is extracted and stored as a key, while its occurrence
count is maintained as the associated value. By leveraging iterators, the system efficiently traverses
the data structure, displaying each word along with its computed frequency.
The use of a dynamic mapping approach ensures that words are stored in an ordered manner, allowing
for fast retrieval and structured output.
*/

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <iterator>

using namespace std;

void countWordFrequency(const string& input) {
    map<string, int> wordCount;  // Associative container to store words and their frequencies
    string word;
    stringstream ss(input);  // Using stringstream to extract words from the input string

    // Extract words from the input sentence
    while (ss >> word) {
        // Normalize the word to lowercase (if case-insensitivity is required)
        for (char& c : word) {
            c = tolower(c);
        }
        // Increment the count for the current word
        wordCount[word]++;
    }

    
    // Display the results
    cout << "\nWord Frequency Distribution:\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    string input;

    // Get input sentence from the user
    cout << "Enter a sentence: ";
    getline(cin, input);

    // Call function to count word frequency
    countWordFrequency(input);

    return 0;
}

