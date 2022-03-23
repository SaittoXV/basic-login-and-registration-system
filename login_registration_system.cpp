#include <iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using std::string;
using std::cout;
using std::cin;
using std::ofstream;
using std::ifstream;

int main();
void userInterface();
void userInput();
void userRegister();
void userLogin();
void userForgot();
void userExit();

string username;
string password;
string temp_username;
string temp_password;

void userInterface() {

    cout << "\n\n\n-------------------------------------------------------------\n";
    cout << "                         Welcome                             \n";
    cout << "----------------------              -------------------------\n";

    cout << "|  Press 1 to Register           |\n";
    cout << "|  Press 2 to Login              |\n";
    cout << "|  Press 3 to Forgot Password    |\n";
    cout << "|  Press 4 to Exit               |\n";
}

void userRegister() {

    cout << "Select a username: ";
    cin.ignore();
    getline(cin,username);

    ifstream user_file;
    user_file.open(username + ".txt");
    getline(user_file,temp_username);
    getline(user_file,temp_password);

    if (temp_username == username) {
        cout << "\nThis username is already being used!\n";
    }
    else {

        cout << "Select a password: ";
        cin >> password;

        ofstream user_file;
        user_file.open(username + ".txt");
        user_file << username << "\n";
        user_file << password << "\n";
        user_file.close();

        cout << "Your username is " << username << " and your password is " << password << "\n";
    }
    
    return;
}

void userLogin() {

    cout << "Enter your username: ";
    cin.ignore();
    getline(cin, username);

    ifstream user_file;
    user_file.open(username + ".txt");
    getline(user_file, temp_username);
    getline(user_file, temp_password);


    if (temp_username == username ) {
        cout << "Enter your password: ";
        cin >> password;

        if (temp_password == password) {
            cout << "\nWelcome to the world!!\n";
            return;
        }
        else {
            cout << "\nWrong credentials..Pleas try again.\n";
            return;

        }
    }
    else {
        cout << "\nWrong credentials..Pleas try again.\n";
        return;
    }

}

void userForgot() {
    cout << "Enter your username: ";
    cin >> username;

    ifstream user_file;
    user_file.open(username + ".txt");
    getline(user_file,temp_username);

    if (temp_username == username) {

        cout << "Change your password: ";
        cin >> password;

        ofstream user_file;
        user_file.open(username + ".txt");
        user_file<<username<<"\n";
        user_file << password<<"\n";
    }
    else {
        cout << "\nWrong credentials..Pleas try again.\n";
        return;
    }

}

void userExit() {
    exit(0);
}

void userInput() {

    int choice;

    cout << "Enter your choice: ";
    cin >> choice;
    
    switch (choice) {
    case 1:
        userRegister();
        main();
    case 2:
        userLogin();
        main();
    case 3:
        userForgot();
        main();
    case 4:
        userExit();
    default:
        cout << "Try again..\n";
        main();
    }
}

int main() {
    userInterface();
    userInput();
    return 0;
}
