#include "HeaderFR.h"
#include <iostream>

void User::setUser(string name, string login, string pass)  // setter
{
    this->_name = name; this->_login = login; this->_pass = pass;
}

void User::initUser()  // to initiate a user
{
    cout << "Type your name: ";
    getline(cin, this->_name);
    cout << "Type you login: ";
    getline(cin, this->_login);
    cout << "Type your password: ";
    getline(cin, this->_pass);
}

string User::getItem(char item)  // to get name, login or password of User class (depends on value 'item')
{
    switch (item)
    {
    case 'n': return this->_name;     // to get a name
    case 'l': return this->_login;    // to get a login
    case 'p': return this->_pass;     // to get a password
    }
    return "";
}

Message::Message(string text, string sender, string receiver)  // setter
{
    this->_text = text; this->_sender = sender; this->_receiver = receiver;
}

void Message::sendMessage(string sender)  // to send a message
{
    cout << "Type a receiver: ";
    getline(cin, this->_receiver);
    cout << "Type a message: ";
    getline(cin, this->_text);
    this->_sender = sender;
}

string Message::getItem(char item) const  // to get text, sender or receive of Message class (depends on value 'item')
{
    switch (item)
    {
    case 't': return this->_text;         // to get a text
    case 's': return this->_sender;       // to get a sender
    case 'r': return this->_receiver;     // to get a receiver
    }
    return "";
}
void setFilePermissions(const string& filename)  // to set file's permissions
{
    fs::permissions(filename,
        fs::perms::group_write | fs::perms::group_read | fs::perms::group_exec |
        fs::perms::others_write | fs::perms::others_read | fs::perms::others_exec,
        fs::perm_options::remove);
}