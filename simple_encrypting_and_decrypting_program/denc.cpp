#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;

int main() {

    cout << "This is a secure encryption and decryption program. Enter E to encrypt a message or enter D to decrypt a message: ";
    char choice;
    cin >> choice;

    cin.ignore(); //This will clear out any unwanted buffer so the next input is taken.


    //This string contains all 91 charachters on the keyboard apart from the backslash character. I made the order of the 
    //characters as random as possible to increase security.
    const string characters = "Kcn!L:svm,./d1Z@#4iop[8`A~Sz]a23?bR 0-=ux5GYVwH9rty$Ejkl;'%^&*UIOP{(+QeWBf)_ghXCq67T>FNM<}|JD";

    //This key is the amount you shift each character by
    const size_t key = 3;
    
    if (choice == 'E' || choice == 'e')
    {   
        cout << "Enter the message you wish to encrypt: ";
        string message;
        getline(cin, message);

        cout << "Encrypting message..." << "\n";

        string encrypted_message;

        for(size_t i = 0; i < message.length(); i++) {

        size_t position = characters.find(message.at(i));
        size_t shift_value;
        if (position + key > characters.length()-1)
        {
            shift_value = (position + key) - characters.length();
            encrypted_message += characters.at(shift_value);
        } else {
            shift_value = position + key;
            encrypted_message += characters.at(shift_value);
        } 
    
    }

        cout << "Encrypted message: " << encrypted_message << "\n";
    }
    else if (choice == 'D' || choice == 'd')
    {   
        cout << "Enter the message you wish to decrypt: ";
        string encrypted_message;
        cin >> encrypted_message;

        cout << "Decrypting message..." << "\n";

        string decrypted_message;
        for (size_t i = 0; i < encrypted_message.length(); i++)
        {
        int position = characters.find(encrypted_message.at(i));
        int unshift_value;

        if (position - key < 0)
        {
            unshift_value = characters.length() + (position-key);
            decrypted_message += characters.at(unshift_value);
        } else {
            unshift_value = position-key;
            decrypted_message += characters.at(unshift_value);
        }
        }
    
    cout << "Decrypted message: " << decrypted_message << "\n";
    }
    else
    {
        cout << "Incorrect input. Please re-run the program and try again." << "\n";
    }
    
    return 0;
}
