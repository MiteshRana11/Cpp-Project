#include <iostream>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

class Dictionary {
private:
    unordered_map<string, string> words;
    const string filename = "dictionary.txt";

    void loadFromFile() {
        ifstream file(filename);
        string line;

        while (getline(file, line)) {
            stringstream ss(line);
            string word, meaning;

            getline(ss, word, ':');
            getline(ss, meaning);

            words[word] = meaning;
        }

        file.close();
    }

    void saveToFile() {
        ofstream file(filename);

        for (const auto &pair : words) {
            file << pair.first << ":" << pair.second << endl;
        }

        file.close();
    }

public:

    Dictionary() {
        loadFromFile();
    }

    void addWord() {
        string word, meaning;

        cout << "Enter word: ";
        cin >> word;
        cin.ignore();

        cout << "Enter meaning: ";
        getline(cin, meaning);

        words[word] = meaning;

        saveToFile();

        cout << "Word added successfully\n";
    }

    void searchWord() {
        string word;

        cout << "Enter word to search: ";
        cin >> word;

        auto it = words.find(word);

        if (it != words.end())
            cout << "Meaning: " << it->second << endl;
        else
            cout << "Word not found\n";
    }

    void deleteWord() {
        string word;

        cout << "Enter word to delete: ";
        cin >> word;

        if (words.erase(word)) {
            saveToFile();
            cout << "Word deleted successfully\n";
        } else {
            cout << "Word not found\n";
        }
    }

    void displayDictionary() {
        cout << "\n--- Dictionary ---\n";

        for (const auto &pair : words) {
            cout << pair.first << " : " << pair.second << endl;
        }
    }
};

int main() {

    Dictionary dict;
    int choice;

    while (true) {

        cout << "\n===== DICTIONARY APP =====\n";
        cout << "1. Add Word\n";
        cout << "2. Search Word\n";
        cout << "3. Delete Word\n";
        cout << "4. Display Dictionary\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {

            case 1:
                dict.addWord();
                break;

            case 2:
                dict.searchWord();
                break;

            case 3:
                dict.deleteWord();
                break;

            case 4:
                dict.displayDictionary();
                break;

            case 5:
                return 0;

            default:
                cout << "Invalid option\n";
        }
    }
}