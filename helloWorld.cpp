#include <iostream>
#include <map>

using namespace std;

string MessageEncoder(string message, map<char, int> characters, int shift);

int main() {

    map<char, int> characters = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}, {'e', 5}, {'f', 6}, {'g', 7}, {'h', 8}, {'i', 9}, {'j', 10}, {'k', 11}, {'l', 12}, {'m', 13}, {'n', 14}, {'o', 15}, {'p', 16}, {'q', 17}, {'r', 18}, {'s', 19}, {'t', 20}, {'u', 21}, {'v', 22}, {'w', 23}, {'x', 24}, {'y', 25}, {'z', 26}};
    string message;
    string exit;
    int shift;
    string newMessage;

    cout << "Cesar Cipher\nEnter your message: ";
    getline(cin, message);
    cout << "Enter shift value: ";
    cin >> shift;

    newMessage = MessageEncoder(message, characters, shift);

    cout << newMessage << endl;

    cout << "Press any key to exit" << endl;
    cin >> exit;

    return 0;
}

string MessageEncoder(string message, map<char,int> characters, int shift) {
    for(int i=0; i<message.size(); i++) {
        int tempVal = characters.at(message[i]);
        tempVal += shift;
        
        char tempChar;

        for(const auto& [key, value] : characters) {
            if (value == tempVal) {
                tempChar = key;
            }
        }

        message[i] = tempChar;
    }
}