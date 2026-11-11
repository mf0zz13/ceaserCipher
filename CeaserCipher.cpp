#include <iostream>
#include <format>
#include <string>
#include <format>

using namespace std;

enum class Operation {
    Encode,
    Decode,
    Exit
};

string Cipher(string message, int shift, Operation op);

int main() {
    bool exit = false;
    Operation op;

    while (!exit) {
        string messageToEncode;
        string messageToDecode;
        string encodedMessage;

        int decision = 0;
        int shift;

        char continueOrExit;

        cout << "Ceaser Cipher" << endl;
        cout << "Enter 1 to encode, or 2 to decode: ";

        cin >> decision;
        cin.ignore();
        
        cout << "Enter message to encode: ";
        getline(cin, messageToEncode);

        cout << "Enter the shift value: ";
        cin >> shift;
        cin.ignore();

        shift = shift % 26;

        switch (decision) {
        case 1:
            op = Operation::Encode;
            break;
        case 2:
            op = Operation::Decode;
            break;
        }

        encodedMessage = Cipher(messageToEncode, shift, op);

        cout << format("Encoded message: {}", encodedMessage) << endl;
        

        cout << "Would you like to exit? (y/n) ";
        cin >> continueOrExit;
        cin.ignore();

        if (continueOrExit == 'y') { exit = true; }
    }
}

string Cipher(string message, int shift, Operation op) {
    
    int asciiValue;
    if (op == Operation::Exit) {
        return "Exit is not valid option";
    }

    if (op == Operation::Decode) {
        shift *= -1;
    }
        
    for(int i=0; i < message.size(); i++) {
        asciiValue = int(message[i]);
        asciiValue += shift;

        asciiValue = asciiValue > 122 ? (asciiValue - 26) : asciiValue;
        asciiValue = asciiValue < 97 ? (asciiValue + 26) : asciiValue;
        

        message[i] = char(asciiValue);
    }
    return message;
}