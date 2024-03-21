#include<iostream>
#include <bits/stdc++.h>
#include<map>
using namespace std;
void encryptAffineCipher(const string& text) {
    map<char, int> affine_map = {
            {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4},
            {'f', 5}, {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9},
            {'k', 10}, {'l', 11}, {'m', 12}, {'n', 13}, {'o', 14},
            {'p', 15}, {'q', 16}, {'r', 17}, {'s', 18}, {'t', 19},
            {'u', 20}, {'v', 21}, {'w', 22}, {'x', 23}, {'y', 24},
            {'z', 25}
    };

    map<int, char> reverse_affine_map;
    for (const auto& pair : affine_map) {
        reverse_affine_map[pair.second] = pair.first;
    }

    string clear_text, cipher_text;
    int a, b, result;

    while (true) {
        cout << "Enter (a, b): ";
        cin >> a >> b;

        // Check if both a and b are positive integers
        if (a > 0 && b > 0) {
            break; // Exit the loop if both are valid
        } else {
            cout << "Please enter positive numbers only." << endl;
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        }
    }

    // Process the input text
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            clear_text += tolower(text[i]); // Convert to lowercase
        }
    }

    // Apply the affine cipher and build the cipher text
    for (int i = 0; i < clear_text.length(); i++) {
        result = (a * affine_map[clear_text[i]] + b) % 26;
        cipher_text += toupper(reverse_affine_map[result]); // Convert to uppercase
    }

    cout << "Cipher text: " << cipher_text;
}

int modulo(int a, int b) {
    return (a % b + b) % b;
}

void decryptAffineCipher(const string& text) {
    map<char, int> affine_map = {
            {'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}, {'e', 4},
            {'f', 5}, {'g', 6}, {'h', 7}, {'i', 8}, {'j', 9},
            {'k', 10}, {'l', 11}, {'m', 12}, {'n', 13}, {'o', 14},
            {'p', 15}, {'q', 16}, {'r', 17}, {'s', 18}, {'t', 19},
            {'u', 20}, {'v', 21}, {'w', 22}, {'x', 23}, {'y', 24},
            {'z', 25}
    };

    map<int, char> reverse_affine_map;
    for (const auto& pair : affine_map) {
        reverse_affine_map[pair.second] = pair.first;
    }

    string clear_text, decipher_text;
    int b, c, result;

    cout << "Enter (b, c): ";
    cin >> b >> c;

    // Process the input text
    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            clear_text += tolower(text[i]); // Convert to lowercase
        }
    }
    // Apply the affine cipher and build the deciphered text
    for (int i = 0; i < clear_text.length(); i++) {
        result = modulo(c * (affine_map[clear_text[i]] - b) ,26) ;
        decipher_text += toupper(reverse_affine_map[result]); // Convert to uppercase
    }

    cout << "Deciphered text: " << decipher_text;
}
int main() {
   
    return 0;
}
