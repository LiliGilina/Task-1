#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int low_num = 0, high_num = 0, guess = 0, guess_count = 0;
    cout << "Guess My Number Game!\n";
    while (low_num < 1) {
        cout << "Enter number greater than 0:\n";
        cin >> low_num;
    }
    while (high_num < low_num) {
        cout << "Enter number greater than " << low_num << ":\n";
        cin >> high_num;
    }
    srand(time(0)); //seed random number generator
    int num = rand() % (high_num-low_num + 1) + low_num;
    do {
        if (guess_count == 5) {
            int x = num, digit = 0, circles_in_num = 0;
            while (x != 0) {
                digit = x % 10;
                if (digit == 8)
                    circles_in_num = circles_in_num +2;
                else if (digit == 0 || digit == 6 || digit == 9)
                    circles_in_num = circles_in_num +1;
                x = x / 10;
            }
            cout << "Hint: My number has " << circles_in_num << " circles.\n";
        }
        cout << "Enter a guess between " << low_num << " and " << high_num << ":\n";
        cin >> guess;
        guess_count++;
        if (guess == 0) // string input also will make guess = 0
            cout << "My number was " << num << ". You didn't got it after " << guess_count << " guesses!\n";
        else if (guess > num)
            cout << "Your guess " << guess << " is too high!\n";
        else if (guess < num)
            cout << "Your guess " << guess << " is too low!\n";
        else
            cout << "My number was " << num << ". You got it after " << guess_count << " guesses!\n";
    }
    while (guess != num && guess != 0);
    return 0;
}