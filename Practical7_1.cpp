/* A media research team is developing a tool to analyze word frequency in large textual datasets, such 
as news articles and research papers. The goal is to process a given paragraph, identify individual 
words, and count their occurrences while ensuring case-insensitive matching. Since the tool is 
intended for both constrained environments and high-performance systems, two different 
approaches are considered—one utilizing dynamic memory management and another relying on 
manually structured arrays. 
The first challenge is reading an entire paragraph from the console as a single unformatted string. 
Once acquired, the text must be split into individual words, ensuring that uppercase and lowercase 
variations are treated as the same. To store and process words dynamically, the team designs a 
mechanism using raw pointers and dynamic memory allocation, allowing the program to handle 
variable input sizes effectively. 
In one approach, a dynamically allocated array is used to store words, with additional logic to count 
occurrences efficiently. The array expands as needed, ensuring that new words can be 
accommodated. The frequency counting is implemented manually by searching for existing words in 
the array and updating counts accordingly. */

#include <iostream>
#include <vector>
#include <cstring>
#include <cctype>
using namespace std;

class Word 
{
public:
    string text;
    int count;

    Word(string t) : text(t), count(1) {}
};

class WordFrequency 
{
    vector<Word> words;

    void toLowerCase(string& str) 
    {
        for (char& c : str) 
        {
            c = tolower(c);
        }
    }

    int findWord(const string& word) 
    {
        for (int i = 0; i < words.size(); i++) 
        {
            if (words[i].text == word) 
            {
                return i;
            }
        }
        return -1;
    }

public:
    void processParagraph(const string& paragraph) 
    {
        string temp = paragraph;
        toLowerCase(temp);
        char* token = strtok(&temp[0], " ,.!?;:\n");
        while (token != nullptr) 
        {
            string word(token);
            int index = findWord(word);
            if (index != -1) 
            {
                words[index].count++;
            } else 
            {
                words.push_back(Word(word));
            }
            token = strtok(nullptr, " ,.!?;:\n");
        }
    }

    void displayFrequencies() 
    {
        cout << "Word Frequencies:" << endl;
        for (const auto& word : words) 
        {
            cout << word.text << ": " << word.count << endl;
        }
    }
};

int main() 
{
    string paragraph;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);

    WordFrequency wf;
    wf.processParagraph(paragraph);
    wf.displayFrequencies();

    return 0;
}
