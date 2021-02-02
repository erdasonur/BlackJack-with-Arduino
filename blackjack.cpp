#include "Blackjack.h"
#include <conio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

Blackjack::Blackjack()
{
    srand(time(NULL));
    dhandSize = 0;
    phandSize = 0;
    dhandSum = 0;
    phandSum = 0;
    playerDone = false;
    dealerDone = false;
}

void Blackjack::playGame()
{
    std::cout << "Welcome to Blackjack!\n";

    // Start the player and dealer with two cards
    addPlayerCard();
    addPlayerCard();
    addDealerCard();
    addDealerCard();
    sumHands();
    printHand();

    if (dhandSum == 21)
    {
        cout << "Dealer has blackjack. Dealer wins.\n";
        return;
    }
    else if (phandSum == 21)
    {
        cout << "Player has blackjack. Player wins.\n";
        return;
    }

    while (dealerDone == false || playerDone == false)
    {
        if (playerDone == false)
        {
            cout << "Would you like to hit? (1 - Yes, 2 - No)\n";
            cin >> phit;

            if (phit == 1)
            {
                addPlayerCard();
                printHand();
                sumHands();

                if (phandSum > 21)
                {
                    cout << "Player's hand exceeded 21. Player loses.\n";
                    return;
                }
            }
        }

        if (playerDone == false)
        {
            cout << "Would you like to stand? (1 - Yes, 2 - No)\n";
            cin >> pstand;
        }

        if (pstand == 1)
        {
            playerDone = true;
        }

        if (dhandSum < 17 && dealerDone != true)
        {
            addDealerCard();
            printHand();
            sumHands();

            if (dhandSum > 21)
            {
                cout << "Dealer hand exceeded 21. Dealer loses.\n";
                return;
            }
        }
        else if (dhandSum >= 17)
        {
            dealerDone = true;
        }

        if (phandSum == 21 && dhandSum == 21)
        {
            cout << "Push, player and dealer reached 21.\n";
            return;
        }
        else if (phandSum == 21)
        {
            cout << "Player reached 21. Player wins.\n";
            return;
        }
        else if (dhandSum == 21)
        {
            cout << "Dealer reached 21. Dealer wins.\n";
            return;
        }

        if ((playerDone == true && dealerDone == true) || (phandSize == 5 && phandSize == 5))
        {
            if (dhandSum < phandSum)
            {
                cout << "Sum of your hand exceeds the dealer's sum of " << dhandSum << "! You win!";
                return;
            }
            else if (phandSum == dhandSum)
            {
                cout << "Dealer sum of " << dhandSum << " is equal to the sum of your hand. Tie game.";
                return;
            }
            else if (dhandSum > phandSum)
            {
                std::cout << "Sum of your hand is lower than the dealer's sum of " << dhandSum << ". You lose!";
                return;
            }
        }
    }
}

int dhand[5];
int phand[5];
int dhandSize;
int phandSize;
int dhandSum;
int phandSum;
int phit;
int pstand;
bool playerDone;
bool dealerDone;

void Blackjack::addPlayerCard()
{
    if (phandSize <= 5)
    {
        phand[phandSize] = 1 + (rand() % 11);
        phandSize++;
    }
    else
    {
        cout << "Sorry. You have reached the maximum number of cards (5)." << endl;
        playerDone = true;
    }
}

void Blackjack::addDealerCard()
{
    if (dhandSize <= 5)
    {
        dhand[dhandSize] = 1 + (rand() % 11);
        dhandSize++;
    }
    else
    {
        dealerDone = true;
    }
}

void Blackjack::printHand()
{
    cout << "Your current hand is...\n";

    for (int i = 0; i < phandSize; i++)
    {
        cout << "    -" << phand[i] << "-    \n\n";
    }

    cout << "Dealer's current hand is...\n";

    for (int j = 0; j < dhandSize; j++)
    {
        cout << "    -" << dhand[j] << "-    \n\n";
    }
}

void Blackjack::sumHands()
{
    dhandSum = 0;
    phandSum = 0;
    for (int i = 0; i < dhandSize; i++)
    {
        dhandSum += dhand[i];
    }

    for (int j = 0; j < phandSize; j++)
    {
        phandSum += phand[j];
    }

    cout << "Current player hand sum is: " << phandSum << endl;
}
