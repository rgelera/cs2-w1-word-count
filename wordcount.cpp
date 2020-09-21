#include <iostream>
#include <string>

using namespace std;

// Are we assuming input is gramatically correct? (spaces after appropriate punctuation)

// word count
// word is separated by spaces and punctuation unless the punctation is part of the word (conjugated words)
// is something like "log.txt" one word
// numbers (1, 2, etc) count as words?

// longest word
// is punctuation part of the count?
// I'm counting it.

// largest num vowels
// A/a = 65/97
// E/e = 69/101
// I/i = 73/105
// O/o = 79/111
// U/u = 85/117
// not counting Y
 
// ASCII:
// numbers are from 48-71
// letters are from 65-90, 97-122
// space is 32
// apostrophe is 39, 
// \n is 10?

int main(int argc, char** argv) {
  int input;
  
  int word_count = 0; // assuming grammatically correct and only separating one space for now.
  
  int longest_word = 0;
  int longest_running_word = 0;
  
  int largest_num_vowels = 0;
  int largest_running_vowels = 0;
  int vowels[] = { 65, 69, 73, 79, 85, 97, 101, 105, 111, 117 };

  while(input != 10) {
    input = cin.get();
    if (input == 32) {  // if space
      if (longest_running_word != 0) { // make sure to start if started a word (accounts for multiple spaces)
        word_count++;
      }
      if (longest_running_word > longest_word) {
        longest_word = longest_running_word;
      }
      if (largest_running_vowels > largest_num_vowels) {
        largest_num_vowels = largest_running_vowels;
      }
      longest_running_word = 0;
      largest_running_vowels = 0;
    }

    if (input >= 65 && input <= 90) { // letter uppercase
      for (int i = 0; i <= 4; i++) {
        if (input == vowels[i]) {
          largest_running_vowels++;
        }
      }
      longest_running_word++;
    } else if (input >= 97 && input <= 122) { // letter lowercase
      for (int j = 5; j <= 9; j++) {
        if (input == vowels[j]) {
          largest_running_vowels++;
        }
      }
      longest_running_word++;
    } else if (input == 39) { // apostrophe. only punctuation im counting as part of a word
      longest_running_word++;
    }
  }

  // counts last "word"
  if (longest_running_word > longest_word) {
    longest_word = longest_running_word;
  }
  if (largest_running_vowels > largest_num_vowels) {
    largest_num_vowels = largest_running_vowels;
  }
  if (longest_running_word != 0) { // accounts for if enter pressed right away
    word_count++;
  }

  cout << "Number of words: " << word_count << "\n";

  cout << "Number of letters in longest word: " << longest_word << "\n";

  cout << "Largest vowels of letters in one word: " << largest_num_vowels << "\n";
}