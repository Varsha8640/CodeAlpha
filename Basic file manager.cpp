#include <iostream>
#include <string>
#include <filesystem>
#include <vector>

using namespace std;
using namespace std::filesystem;

// Function to display the contents of a directory
void list_directory(const path& dir) {
    cout << "Contents of " << dir.string() << ":" << endl;
    for (const auto& entry : directory_iterator(dir)) {
        if (is_regular_file(entry)) {
            cout << "File: " << entry.path().filename().string() << endl;
        } else if (is_directory(entry)) {
            cout << "Directory: " << entry.path().filename().string() << endl;
        }
    }
}

// Function to create a new directory
void create_directory(const path& dir) {
    if (create_directory(dir)) {
        cout << "Directory " << dir.string() << " created successfully." << endl;
    } else {
        cout << "Error creating directory " << dir.string() << endl;
    }
}

// Function to copy a file
void copy_file(const path& source, const path& destination) {
    if (copy_file(source, destination)) {
        cout << "File " << source.string() << " copied to " << destination.string() << " successfully." << endl;
    } else {
        cout << "Error copying file " << source.string() << " to " << destination.string() << endl;
    }
}

// Function to move a file
void move_file(const path& source, const path& destination) {
    if (rename(source, destination)) {
        cout << "File " << source.string() << " moved to " << destination.string() << " successfully." << endl;
    } else {
        cout << "Error moving file " << source.string() << " to " << destination.string() << endl;
    }
}

int main() {
    // Get the current working directory
    path current_dir = current_path();
    cout << "Current directory: " << current_dir.string() << endl;

    // Main loop for the file manager
    while (true) {
        string command;
        cout << "Enter command (ls, cd, mkdir, cp, mv, exit): ";
        cin >> command;

        if (command == "ls") {
            list_directory(current_dir);
        } else if (command == "cd") {
            string dir_name;
            cin >> dir_name;
            path new_dir = current_dir / dir_name;
            if (exists(new_dir) && is_directory(new_dir)) {
                current_dir = new_dir;
                cout << "Current directory: " << current_dir.string() << endl;
            } else {
                cout << "Invalid directory." << endl;
            }
        } else if (command == "mkdir") {
            string dir_name;
            cin >> dir_name;
            path new_dir = current_dir / dir_name;
            create_directory(new_dir);
        } else if (command == "cp") {
            string source_file, destination_file;
            cin >> source_file >> destination_file;
            path source = current_dir / source_file;
            path destination = current_dir / destination_file;
            copy_file(source, destination);
        } else if (command == "mv") {
            string source_file, destination_file;
            cin >> source_file >> destination_file;
            path source = current_dir / source_file;
            path destination = current_dir / destination_file;
            move_file(source, destination);
        } else if (command == "exit") {
            break;
        } else {
            cout << "Invalid command." << endl;
        }
    }

    return 0;
}