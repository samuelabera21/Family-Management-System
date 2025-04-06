#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // for system("cls")
using namespace std;

// Structure to store family member details
struct FamilyMember {
    string name;
    int age;
    string relationship;
};

// Vector to store family members
vector<FamilyMember> family;

// Function to pause and clear the screen
void pauseAndClear() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
    system("cls"); // Clears the screen (Windows-specific)
}

// Function to add a new family member
void addMember() {
    system("cls");
    FamilyMember member;
    cin.ignore(); // Clear the input buffer
    cout << "?? Enter full name: ";
    getline(cin, member.name); // Accept full name with spaces
    cout << "?? Enter age: ";
    cin >> member.age;
    cin.ignore();
    cout << "?? Enter relationship (e.g., Father, Younger Brother): ";
    getline(cin, member.relationship); // Accept full relationship with spaces

    int position;
    cout << "\n?? Where do you want to add the member?\n";
    cout << "1. At the beginning\n";
    cout << "2. At the middle\n";
    cout << "3. At the end\n";
    cout << "?? Enter your choice: ";
    cin >> position;

    // Insert the new member at the chosen position
    switch (position) {
        case 1:
            family.insert(family.begin(), member); // Add at the beginning
            break;
        case 2:
            family.insert(family.begin() + family.size() / 2, member); // Add at the middle
            break;
        case 3:
            family.push_back(member); // Add at the end
            break;
        default:
            cout << "? Invalid option! Adding at the end by default.\n";
            family.push_back(member);
    }

    cout << "? Member added successfully!\n";
    pauseAndClear(); // Pause and clear the screen
}

// Function to display all family members
void displayFamily() {
    system("cls");
    if (family.empty()) {
        cout << "\n?? No family members to display.\n"; // No members in the list
    } else {
        cout << "\n?? --- Family Members ---\n";
        for (int i = 0; i < family.size(); ++i) {
            cout << i + 1 << ". Name: " << family[i].name
                 << ", Age: " << family[i].age
                 << ", Relationship: " << family[i].relationship << endl;
        }
    }
    pauseAndClear(); // Pause and clear the screen
}

// Function to delete a family member
void deleteMember() {
    system("cls");
    if (family.empty()) {
        cout << "\n?? No members to delete.\n"; // No members to delete
        pauseAndClear();
        return;
    }

    int position;
    cout << "\n?? Where do you want to delete the member from?\n";
    cout << "1. From the beginning\n";
    cout << "2. From the middle\n";
    cout << "3. From the end\n";
    cout << "?? Enter your choice: ";
    cin >> position;

    // Delete the member from the chosen position
    switch (position) {
        case 1:
            family.erase(family.begin()); // Delete from the beginning
            break;
        case 2:
            if (!family.empty()) {
                family.erase(family.begin() + family.size() / 2); // Delete from the middle
            } else {
                cout << "? No middle element to delete.\n";
            }
            break;
        case 3:
            family.pop_back(); // Delete from the end
            break;
        default:
            cout << "? Invalid option! Deleting from the end by default.\n";
            family.pop_back();
    }

    cout << "? Member deleted successfully.\n";
    pauseAndClear(); // Pause and clear the screen
}

// Function to update a family member's details
void updateMember() {
    system("cls");
    if (family.empty()) {
        cout << "\n?? No members to update.\n"; // No members to update
        pauseAndClear();
        return;
    }

    displayFamily(); // Display all family members
    int index;
    cout << "?? Enter the number of the member to update: ";
    cin >> index;

    // Validate the input and update the member details
    if (index > 0 && index <= family.size()) {
        cin.ignore(); // Clear input buffer
        cout << "?? Enter new full name: ";
        getline(cin, family[index - 1].name);
        cout << "?? Enter new age: ";
        cin >> family[index - 1].age;
        cin.ignore();
        cout << "?? Enter new relationship: ";
        getline(cin, family[index - 1].relationship);
        cout << "? Member updated successfully.\n";
    } else {
        cout << "? Invalid number!\n";
    }
    pauseAndClear(); // Pause and clear the screen
}

// Function to search for a family member by name
void searchMember() {
    system("cls");
    if (family.empty()) {
        cout << "\n?? No members to search.\n"; // No members to search
        pauseAndClear();
        return;
    }

    string searchName;
    bool found = false;
    cin.ignore();
    cout << "?? Enter full name to search: ";
    getline(cin, searchName); // Accept full name with spaces

    // Search through the family vector
    for (int i = 0; i < family.size(); i++) {
        if (family[i].name == searchName) {
            cout << "? Found: Name: " << family[i].name
                 << ", Age: " << family[i].age
                 << ", Relationship: " << family[i].relationship << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "? No member found with that name.\n"; // No member found
    }
    pauseAndClear(); // Pause and clear the screen
}

// Function to show the main menu
void showMenu() {
    cout << "\n???? Family Management System ????\n";
    cout << "1. Add Member\n";
    cout << "2. Display All Members\n";
    cout << "3. Delete Member\n";
    cout << "4. Update Member\n";
    cout << "5. Search Member by Full Name\n";
    cout << "6. Exit\n";
    cout << "?? Enter your choice: ";
}

int main() {
    int choice;

    // Main loop for the menu
    do {
        system("cls");
        showMenu(); // Show the main menu
        cin >> choice;

        // Switch to call the respective function based on user input
        switch (choice) {
            case 1: addMember(); break; // Add a new member
            case 2: displayFamily(); break; // Display all family members
            case 3: deleteMember(); break; // Delete a member
            case 4: updateMember(); break; // Update a member's information
            case 5: searchMember(); break; // Search for a member
            case 6:
                system("cls");
                cout << "?? Exiting program... Goodbye!\n"; // Exit message
                break;
            default:
                cout << "? Invalid choice. Please try again.\n"; // Invalid choice
                pauseAndClear();
        }
    } while (choice != 6); // Continue the loop until the user chooses to exit

    return 0;
}
