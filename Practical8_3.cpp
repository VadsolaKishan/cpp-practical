/*
A financial analytics firm is designing a data processing system to filter out duplicate transaction IDs
from large datasets. The system must take an input list of integers, efficiently remove duplicates, and
display the unique values in an ordered manner. Given the need for high performance in handling
large datasets, the implementation must leverage efficient data structures that automatically
eliminate redundancy.
To achieve this, the system employs an associative container that inherently ensures uniqueness while
maintaining a sorted order. As integers are added, duplicate entries are automatically discarded,
eliminating the need for explicit duplicate-checking logic. Once the unique values are identified, they
are either displayed directly using iterators or converted back into a dynamically managed sequence
for further processing.
By utilizing iterators, the system efficiently traverses the filtered dataset, ensuring that unique
elements are accessed and displayed without additional computational overhead.
*/

#include <iostream>
#include <set>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    int n, id;

    // Associative container (set) to store unique and sorted transaction IDs
    set<int> transactionIDs;

    cout << "Enter number of transaction IDs: ";
    cin >> n;

    cout << "Enter transaction IDs:\n";
    for (int i = 0; i < n; ++i) {
        cin >> id;
        transactionIDs.insert(id);  // Duplicates will be ignored automatically
    }

    
    // Display unique and sorted transaction IDs
    cout << "\nUnique and Sorted Transaction IDs:\n";
    for (set<int>::iterator it = transactionIDs.begin(); it != transactionIDs.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Optionally, convert to a dynamically managed sequence (e.g., vector) for further use
    vector<int> uniqueIDs(transactionIDs.begin(), transactionIDs.end());

    return 0;
}

