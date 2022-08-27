// SortCard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "cardlib.h"

#include <string>
#include <iostream>
using namespace std;

const int maxCard = 20;
aCard thePack[maxCard];
int compareCardsCounter;
int swapCardsCounter;

/*string cardToString(aCard c) //cardToString takes a single card of type aCard as an input
{
    string csuit = "HCDS"; //contains all the characters needed to represent cardSuit as a string
    string cval = "A23456789JQK"; //contains all the characters needed to represent cardVal as a string
    string suit = csuit.substr(c.cardSuit, 1); //suit becomes a 1 character substring of csuit equal to character at index cardSuit
    string val = cval.substr(c.cardVal - 1, 1); //val becomes a 1 character substring of cval equal to character at index cardVal - 1
    return val+suit; //outputs val and suit concatenated together
}

void printPack(string mess) //printPack takes a string of text as an input
{
    cout << mess; //prints the input string
    cout << " : "; //prints a colon
    for (int i = 0; i < maxCard; i++) //while integer i is less that maxCard
    {
        cout << cardToString(thePack[i]) << ", "; //print the card at index i in thePack in string form, called cardToString in the process
    }
    cout << endl;
}

int compareCards(aCard c1, aCard c2) //takes an input of 2 cards, c1 and c2, that need to be compared
{
    // compare two cards c1 and c2
    // return -1 (c1 < c2), 0 (c1 == c2), 1 (c1 > c2)
    compareCardsCounter += 1;
    if (c1.cardSuit == c2.cardSuit)
    {
        if (c1.cardVal > c2.cardVal) //if card1 value is greater than card2 value
        {
            return 1; 
        }
        if (c1.cardVal == c2.cardVal) //if card1 value is equal to card2 value
        {
            return 0; 
        }
        if (c1.cardVal < c2.cardVal) //if card1 value is less than to card2 value
        {
            return -1;
        }
    }
    else
    {
        if (c1.cardSuit > c2.cardSuit) //if card1 suit is greater than card2 suit
        {
            return 1; 
        }
        if (c1.cardSuit < c2.cardSuit) //if card1 suit is less than card2 suit
        {
            return -1; 
        }
    }
}

void swapCards(int n1, int n2) //takes the indices of two cards in the pack as inputs
{
    // swap the cards in thePack
    // at indices n1 and n2
    swapCardsCounter += 1; //swapCardsCounter is incremented by 1
    aCard temp = thePack[n1]; //aCard temp is initialised as the card of index n1 in thePack
    thePack[n1] = thePack[n2]; //the value of the card at index n1 of thePack becomes the value of the card at index n2 in thePack
    thePack[n2] = temp; //the value of the card at index n2 of thePack becomes temp
}

void bubblesort()
{
    int i, j; //integers i and j are created
    for (i = 0; i < maxCard; i++) //while i is less than maxCard
    {
        for (j = i+1; j < maxCard; j++) //while j is less than maxCard
        {
            if (compareCards(thePack[i], thePack[j]) == 1) //if the result of comparing the cards in index i and j == 1
            {
                swapCards(i, j); //swap the cards in index i and j of thePack
            }
        }
    }
}

int partition(int left, int right) //inputs are the lowest index of thePack and the highest index of thePack
{
    aCard pivot = thePack[right]; //the pivot is the rightmost card in thePack
    int i = left - 1; //holds the lowest index in thePack minus 1

    for (int j = left; j < right; j++) //while j is less than the highest index of thePack
    {
        if (compareCards(thePack[j], pivot) == -1) //if the result of comparing the card at index j and the pivot is -1 
        {
            i++; //increment i by 1
            swapCards(i, j); //swap the cards at index i and j
        }
    }
    i++; //increment i by 1
    swapCards(i, right); //swap the card at index i and the card at the highest index of thePack
    return(i);
}

void quicksort(int left, int right) //inputs are the lowest index of thePack and the highest index of thePack
{
    if (left < right) //if the lowest index of thePack is less than the highest index of thePack
    {
        int par = partition(left, right); //find the partition between the lowest index and highest index
        quicksort(left, par - 1); //sort the cards lower than the partition by calling quicksort again
        quicksort(par + 1, right); //sort the cards higher than the partition by calling quicksort again
    }
}

int main()
{
    cout << "Card Sorting!\n";

    for (int ct = 0; ct < maxCard; ct++)
        thePack[ct] = getCard("30006150");
    printPack("Unsorted");
    quicksort(0, maxCard - 1);
    printPack("Sorted");
    cout << "Comparasons : " << compareCardsCounter << endl;
    cout << "Swaps : " << swapCardsCounter << endl;
}*/