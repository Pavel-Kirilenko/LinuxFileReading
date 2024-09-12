#include "HeaderFR.h"
#include <iostream>
#include <fstream>
#include <filesystem>

namespace fs = std::filesystem;

int main() {
    User user;
    Message message("", "", "");
    string prefix;                           // prefix of file's name to avoid exception when users refer to the same file (may be empty once)
    cout << "Type file's prefix: ";
    getline(cin, prefix);

    ifstream file_User_r(prefix + "User.txt");        // to try to open an existing User file

    if (!file_User_r.is_open())              // if the file is not open
    {
        cout << "Could not open User file!" << '\n';

        ofstream file_User_w(prefix + "User.txt");    // to create a User file
        user.initUser();                     // to initiate a user

        file_User_w << user.getItem('n') << '\n';
        file_User_w << user.getItem('l') << '\n';
        file_User_w << user.getItem('p');

        file_User_w.close();

        setFilePermissions(prefix + "User.txt");

        cout << "New User file is created" << '\n';
    }
    else
    {
        string lnName; string lnLogin; string lnPass;
        getline(file_User_r, lnName);
        getline(file_User_r, lnLogin);
        getline(file_User_r, lnPass);
        user.setUser(lnName, lnLogin, lnPass);
        cout << user.getItem('n') << ", " << user.getItem('l') << ", " << user.getItem('p') << " are written in class User" << endl;
    }

    ifstream file_Message_r(prefix + "Message.txt");      // to try to open an existing Message file

    if (!file_Message_r.is_open())               // if the file is not open
    {
        cout << "Could not open Message file!" << '\n';

        ofstream file_Message_w(prefix + "Message.txt");  // to create a Message file;

        message.sendMessage(user.getItem('n'));  // to create a message with user's name ('getItem' gets the name)

        file_Message_w << message.getItem('t') << '\n';
        file_Message_w << message.getItem('s') << '\n';
        file_Message_w << message.getItem('r');

        file_Message_w.close();

        setFilePermissions(prefix + "Message.txt");

        cout << "New Message file is created" << '\n';
    }
    else
    {
        string lnText; string lnSender; string lnReceiver;
        getline(file_Message_r, lnText);
        getline(file_Message_r, lnSender);
        getline(file_Message_r, lnReceiver);
        Message message(lnText, lnSender, lnReceiver);
        cout << message.getItem('t') << ", " << message.getItem('s') << ", " << message.getItem('r') << " are written in class Message" << endl;
    }

    return 0;
}
