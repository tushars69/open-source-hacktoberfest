#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

std::vector<std::string> words = {"programming", "computer", "hangman", "game", "developer", "openai", "language"};
const int maxAttempts = 6;

std::string selectRandomWord() {
    int randomIndex = std::rand() % words.size();
    return words[randomIndex];
}

bool contains(char guess, const std::string& word) {
    return word.find(guess) != std::string::npos;
}

std::string displayWord(const std::string& word, const std::string& guessed) {
    std::string result = "";
    for (char letter : word) {
        if (guessed.find(letter) != std::string::npos) {
            result += letter;
        } else {
            result += '_';
        }
    }
    return result;
}

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr));
    std::string wordToGuess = selectRandomWord();
    std::string guessedLetters = "";
    int attempts = 0;

    std::cout << "Welcome to Hangman!" << std::endl;

    while (attempts < maxAttempts) {
        std::cout << "Word: " << displayWord(wordToGuess, guessedLetters) << std::endl;
        std::cout << "Guessed letters: " << guessedLetters << std::endl;
        std::cout << "Attempts left: " << maxAttempts - attempts << std::endl;

        char guess;
        std::cout << "Enter a letter: ";
        std::cin >> guess;

        if (contains(guess, wordToGuess)) {
            guessedLetters += guess;
            std::cout << "Good guess!" << std::endl;

            if (displayWord(wordToGuess, guessedLetters) == wordToGuess) {
                std::cout << "Congratulations! You guessed the word: " << wordToGuess << std::endl;
                break;
            }
        } else {
            guessedLetters += guess;
            attempts++;
            std::cout << "Incorrect guess." << std::endl;
        }
    }

    if (attempts == maxAttempts) {
        std::cout << "You ran out of attempts! The word was: " << wordToGuess << std::endl;
    }

    return 0;
}
