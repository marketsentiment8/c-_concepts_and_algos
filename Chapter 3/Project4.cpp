#include <iostream>

int main() {
    char play_again = 'y';

    while (play_again == 'y' || play_again == 'Y') {
        int amount_cards;
        std::cout << "Enter the amount of cards that you have: ";
        std::cin >> amount_cards;

        char card_val;
        int hand_val = 0;
        int num_aces = 0; // Keep track of the number of Aces 

        for (int i = 0; i < amount_cards; i++) {
            std::cout << "Enter the card value (2, 3, 4, 5, 6, 7, 8, 9, t, j, q, k, a): ";
            std::cin >> card_val;

            switch (card_val) {
                case '2':
                    hand_val += 2;
                    break;
                case '3':
                    hand_val += 3;
                    break;
                case '4':
                    hand_val += 4;
                    break;
                case '5':
                    hand_val += 5;
                    break;
                case '6':
                    hand_val += 6;
                    break;
                case '7':
                    hand_val += 7;
                    break;
                case '8':
                    hand_val += 8;
                    break;
                case '9':
                    hand_val += 9;
                    break;
                case 't':
                case 'j':
                case 'q':
                case 'k':
                    hand_val += 10;
                    break;
                case 'a':
                    // Count the Ace and make a decision
                    num_aces++;
                    hand_val += 11;
                    break;
                default:
                    std::cout << "Invalid card entered: " << card_val << std::endl;
                    break;
            }
        }

        // Avoid busting
        while (num_aces > 0 && hand_val > 21) {
            hand_val -= 10; // Treat an Ace as 1 instead of 11
            num_aces--;
        }

        if (hand_val > 21) {
            std::cout << "Total hand value: BUSTED (" << hand_val << ")" << std::endl;
        } else {
            std::cout << "Total hand value: INCONCLUSIVE (" << hand_val << ")" << std::endl;
        }

        std::cout << "Play again? (y/n): ";
        std::cin >> play_again;
    }

    return 0;
}
