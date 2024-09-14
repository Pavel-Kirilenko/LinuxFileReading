#pragma once
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;

class User {
    string _name;
    string _login;
    string _pass;
public:
    void setUser(string name, string login, string pass); // setter
    void initUser();            // to initiate a user
    string getItem(char item);  // to get name, login or password (depends on value of 'item')
};

class Message {
    string _text;
    string _sender;
    string _receiver;
public:
    Message(string text, string sender, string receiver);  // constructor
    void sendMessage(string sender);  // to create a message
    string getItem(char item) const;  // to get text, sender or receive (depends on value of 'item')
};
void setFilePermissions(const string& filename); // to set file's permissions
