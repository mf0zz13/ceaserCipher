#include <iostream>
#include <format>

using namespace std;

string encoder(string message, int shift);
string decooder(string message, int shift);

int main() {
    bool exit = false;

    while(!exit) {
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

        if(decision == 1) {
            cout << "Enter message to encode: ";
            getline(cin, messageToEncode);

            cout << "Enter the shift value: ";
            cin >> shift;
            cin.ignore();

            shift = shift % 26;

            encodedMessage = encoder(messageToEncode, shift);

            cout << format("Encoded message: {}", encodedMessage) << endl;
        }

        cout << "Would you like to exit? (y/n) ";
        cin >> continueOrExit;
        cin.ignore();

        if(continueOrExit == 'y') {exit = true;}
    }
}

string encoder(string message, int shift) {
    int asciiValue;

    for(int i=0; i < message.size(); i++) {
        asciiValue = int(message[i]);
        asciiValue += shift;

        asciiValue = asciiValue > 122? (asciiValue - 26) : asciiValue;
        asciiValue = asciiValue < 97? (asciiValue + 26) : adciiValue;

        message[i] = char(asciiValue);
    }
    return message;
}

string decoder(string message, int shift) {

    //TODO: add decode method.
    return "FIXME: implememnt method";
}