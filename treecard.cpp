#include "cardlib.h"

#include <string>
#include <iostream>
using namespace std;

struct treeNode
{
    aCard data;
    treeNode* less;
    treeNode* more;
};
treeNode* treeTop;

treeNode* newNode(aCard c) //card of type aCard is now the input
{
    treeNode* p = new treeNode; //new node p is created
    p->data = c; //p data value is then set to the input card
    p->less = NULL;
    p->more = NULL; //less and more pointers now point to NULL
    return p;
}

string cardToString(aCard c)
{
    string csuit = "HCDS";
    string cval = "A23456789JQK";
    string suit = csuit.substr(c.cardSuit, 1);
    string val = cval.substr(c.cardVal - 1, 1);
    return val + suit;
}

void printTree(treeNode* p)
{   // print the tree from node p
    if (p != NULL)
    {
        printTree(p->less);             // print any nodes in less sub tree
        cout << cardToString(p->data) << ", ";        // print this node after calling cardToString
        printTree(p->more);             // print any nodes in more sub tree
    }
}

int compareCards(aCard c1, aCard c2)
{
    // compare two cards c1 and c2
    // return -1 (c1 < c2), 1 (c1 == c2) or (c1 > c2)
    if (c1.cardSuit == c2.cardSuit)
    {
        if (c1.cardVal > c2.cardVal) //if card1 value is greater than card2 value
        {
            return 1;
        }
        if (c1.cardVal == c2.cardVal) //if card1 value is equal to card2 value
        {
            return 1;
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

treeNode* insertTree(treeNode* p, aCard c) 
{
    // insert aCard c searching from node p, returns pointer to this node (normally unchanged)
    treeNode* ans = p;
    if (p == NULL) ans = newNode(c);    // if found NULL pointer, create new node and this is returned connecting to node above
    else if (compareCards(p->data, c) > 0) p->less = insertTree(p->less, c);    // insert in less subtree
    else if (compareCards(p->data, c) < 0) p->more = insertTree(p->more, c);    // insert in more subtree
        // change above line if want repeat items in tree
    return ans;         // return pointer to new node, or to this node, as appropriate
}

int main()
{
    cout << "RJM's Tree Program!\n";
    const int maxCard = 7;
    treeTop = NULL;                             
    for (int ct = 0; ct < maxCard; ct++)
    {
        treeTop = insertTree(treeTop, getCard("30006150"));
    }

    printTree(treeTop);                       
    cout << "\n";
}