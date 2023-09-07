#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "Note Taker Menu:" << endl;
    cout << "1. Create a new note" << endl;
    cout << "2. View all notes" << endl;
    cout << "3. View a specific note" << endl;
    cout << "4. Update a note" << endl;
    cout << "5. Delete a note" << endl;
    cout << "6. Exit" << endl;
}

// Function to create a new note
void createNote() {
    cin.ignore(); // Clear the input buffer
    cout << "Enter the title of the note: ";
    string title;
    getline(cin, title);

    cout << "Enter the content of the note (press Enter followed by Ctrl+D to finish):\n";
    string content;
    cin.clear();
    while (cin >> content) {
        content += '\n';
    }

    ofstream file(title + ".txt");
    if (file.is_open()) {
        file << content;
        file.close();
        cout << "Note created successfully!" << endl;
    } else {
        cout << "Unable to create the note." << endl;
    }
}

// Function to view all notes
void viewAllNotes() {
    cout << "List of notes:" << endl;
    system("ls *.txt"); // List all .txt files in the current directory
}

// Function to view a specific note
void viewNote() {
    cin.ignore(); // Clear the input buffer
    cout << "Enter the title of the note to view: ";
    string title;
    getline(cin, title);

    ifstream file(title + ".txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "Note not found." << endl;
    }
}

// Function to update a note
void updateNote() {
    cin.ignore(); // Clear the input buffer
    cout << "Enter the title of the note to update: ";
    string title;
    getline(cin, title);

    ifstream file(title + ".txt");
    if (file.is_open()) {
        file.close();
        cout << "Enter the new content of the note (press Enter followed by Ctrl+D to finish):\n";
        string content;
        cin.clear();
        while (cin >> content) {
            content += '\n';
        }

        ofstream newFile(title + ".txt");
        if (newFile.is_open()) {
            newFile << content;
            newFile.close();
            cout << "Note updated successfully!" << endl;
        } else {
            cout << "Unable to update the note." << endl;
        }
    } else {
        cout << "Note not found." << endl;
    }
}

// Function to delete a note
void deleteNote() {
    cin.ignore(); // Clear the input buffer
    cout << "Enter the title of the note to delete: ";
    string title;
    getline(cin, title);

    if (remove((title + ".txt").c_str()) == 0) {
        cout << "Note deleted successfully!" << endl;
    } else {
        cout << "Note not found or unable to delete." << endl;
    }
}

int main() {
    while (true) {
        displayMenu();
        int choice;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                createNote();
                break;
            case 2:
                viewAllNotes();
                break;
            case 3:
                viewNote();
                break;
            case 4:
                updateNote();
                break;
            case 5:
                deleteNote();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option (1-6)." << endl;
        }
    }

    return 0;
}
