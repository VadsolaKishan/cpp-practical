/*
A data analytics firm is developing a tool to process numerical sequences efficiently. One of the key
requirements is to reverse a given sequence of integers while ensuring optimized performance using
modern C++ techniques. The system should allow users to input a sequence of numbers, process the
reversal using iterators, and display the transformed output.
To accomplish this, two approaches are explored. The first method leverages the built-in std::reverse()
function, which efficiently reverses elements within a dynamically managed sequence. The second
approach involves manually implementing the reversal using iterators, providing deeper insight into
how iterators navigate and modify data structures.
The system uses a dynamic storage mechanism to handle sequences of varying sizes efficiently.
Iterators facilitate traversal and modification, ensuring that elements are manipulated without direct
indexing.
*/

#include <iostream>
#include <vector>
#include <algorithm>  // For std::reverse
#include <iterator>   // For iterators

using namespace std;

// Approach 1: Reverse using std::reverse() function
void reverseWithStd(vector<int>& seq) {
    std::reverse(seq.begin(), seq.end());
}

// Approach 2: Reverse manually using iterators
void reverseManually(vector<int>& seq) {
    auto start = seq.begin();
    auto end = seq.end() - 1;

    while (start < end) {
        // Swap the values using iterators
        swap(*start, *end);
        ++start;
        --end;
    }
}


int main() {
    int n;

    // Input: Size of the sequence
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> seq(n);

    // Read the sequence of integers from user
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    // Approach 1: Using std::reverse()
    cout << "\nOriginal sequence: ";
    for (const auto& num : seq) {
        cout << num << " ";
    }

    reverseWithStd(seq);
    cout << "\nReversed sequence using std::reverse(): ";
    for (const auto& num : seq) {
        cout << num << " ";
    }

    // Input new sequence for manual reversal
    cout << "\n\nEnter the elements again for manual reversal: ";
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    // Approach 2: Using manual iteration
    cout << "\nOriginal sequence: ";
    for (const auto& num : seq) {
        cout << num << " ";
    }

    reverseManually(seq);
    cout << "\nReversed sequence using iterators: ";
    for (const auto& num : seq) {
        cout << num << " ";
    }

    return 0;
}

