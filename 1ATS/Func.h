#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
typedef struct Deck
{
    struct Deck *next;
    int number;
    struct Deck *previous;
}Deck;
void CreateEmptyDeck(Deck **head, Deck **tail);
void AskingDeckSize(int **askedSize);
void IsDeckEmpty (Deck **head, Deck **tail);
void AddBegginingElement (Deck **head, Deck **tail,Deck **element, int **sizeCounter);
void AddEndElement (Deck **head, Deck **tail,Deck **element, int **sizeCounter);
void IsDeckFull(int **actualDeckSize, int **askedDeckSize);
void PrintList (Deck **elem, Deck **head, int **sizeCounter);
void RemoveLastElement (Deck **head, Deck **tail, int **elementsData, int **listSize);
void RemoveFirstElement (Deck **head, Deck **tail, int **elementsData, int **listSize);
void DeleteList(Deck** head, Deck **tail, int **sizeCounter);
#endif // FUNC_H_INCLUDED
