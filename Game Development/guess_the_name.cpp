#include <iostream>
#include <string>

int main() {
    const std::string secretWord = "apple";
    std::string guessedWord;
    int maxAttempts = 5;
    int attempts = 0;
    bool hasGuessed = false;

    std::cout << "Welcome to the Word Guessing Game!" << std::endl;

    while (attempts < maxAttempts) {
        std::cout << "Guess the secret word: ";
        std::cin >> guessedWord;

        if (guessedWord == secretWord) {
            hasGuessed = true;
            break;
        } else {
            attempts++;
            std::cout << "Incorrect guess. You have " << maxAttempts - attempts << " attempts left." << std::endl;
        }
    }

    if (hasGuessed) {
        std::cout << "Congratulations! You've guessed the word: " << secretWord << std::endl;
    } else {
        std::cout << "Sorry, you've run out of attempts. The secret word was: " << secretWord << std::endl;
    }

    return 0;
}
