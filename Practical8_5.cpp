/*
A software development team requires a lightweight directory management system to efficiently
organize project files. The system should allow users to create folders, add files to specific folders, and
display the directory structure in an organized manner.
Each folder serves as a unique entry, mapping to a list of associated files, ensuring structured storage
and easy retrieval. A hierarchical mapping approach is used, where folder names act as keys, and
dynamically resizable sequences store the corresponding filenames.
The system provides essential functionalities, including adding new folders, appending files to existing
folders, and displaying the complete directory structure. To enhance accessibility, folder names are
sorted alphabetically, allowing users to quickly locate specific folders and their contents. Iterators are
used for efficient traversal and structured display of data. This approach ensures optimized
performance, even for large datasets, while maintaining a logical and organized hierarchy.
*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>


using namespace std;


class DirectoryManager {
private:
    map<string, vector<string>> directory; // folder -> list of files

public:
    // Create a new folder
    void addFolder(const string& folderName) {
        if (directory.find(folderName) == directory.end()) {
            directory[folderName] = vector<string>();
            cout << "Folder '" << folderName << "' created.\n";
        } else {
            cout << "Folder '" << folderName << "' already exists.\n";
        }
    }

    // Add a file to a folder
    void addFileToFolder(const string& folderName, const string& fileName) {
        if (directory.find(folderName) != directory.end()) {
            directory[folderName].push_back(fileName);
            cout << "File '" << fileName << "' added to folder '" << folderName << "'.\n";
        } else {
            cout << "Folder '" << folderName << "' does not exist. Please create it first.\n";
        }
    }

    // Display the directory structure
    void displayDirectory() {
        cout << "\n--- Directory Structure ---\n";
        for (map<string, vector<string>>::iterator it = directory.begin(); it != directory.end(); ++it) {
            cout << "Folder: " << it->first << "\n";
            vector<string>& files = it->second;
            if (files.empty()) {
                cout << "  (Empty)\n";
            } else {
                for (vector<string>::iterator fit = files.begin(); fit != files.end(); ++fit) {
                    cout << "  - " << *fit << "\n";
                }
            }
        }
    }
};

int main() {
    DirectoryManager dm;
    int choice;
    string folder, file;

    do {
        cout << "\n1. Add Folder\n2. Add File to Folder\n3. Display Directory\n0. Exit\nChoose: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter folder name: ";
                getline(cin, folder);
                dm.addFolder(folder);
                break;
            case 2:
                cout << "Enter folder name: ";
                getline(cin, folder);
                cout << "Enter file name: ";
                getline(cin, file);
                dm.addFileToFolder(folder, file);
                break;
            case 3:
                dm.displayDirectory();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}

