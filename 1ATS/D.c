#include <stdio.h>
#include <stdlib.h>
#include "Func.h"
int main ()
{
    int sizeCounter = 0;
    int wantedDeckSize = 0;
    int gotData = 0;
    int i = 0;
    int *pWantedDeckSize = &wantedDeckSize;
    int *pSizeCounter = &sizeCounter;
    int *pGotData = &gotData;

    Deck *head, *tail, *element;

//-------------------------------------------------------------------------
    CreateEmptyDeck(&head, &tail);
    IsDeckEmpty(&head, &tail);
    //AskingDeckSize(&pWantedDeckSize);
    AddEndElement(&head, &tail,&element, &pSizeCounter);
    AddEndElement(&head, &tail,&element, &pSizeCounter);
    //AddEndElement(&head, &tail,&element, &pSizeCounter);
    //AddBegginingElement(&head, &tail,&element, &pSizeCounter);
    //AddEndElement(&head, &tail,&element, &pSizeCounter);
    //IsDeckFull(&pSizeCounter,&pWantedDeckSize);
    //RemoveLastElement(&head, &tail,&pGotData, &pSizeCounter);
    //printf("Gauta reiksme is paskutinio elemento: %d\n",(*pGotData));
    //RemoveFirstElement(&head,&tail,&pGotData,&pSizeCounter);
    printf("\n");
    //DeleteList(&head,&tail,&pSizeCounter);
    printf("Deko dydis: %d\n",sizeCounter);
    //AddEndElement(&head, &tail,&element, &pSizeCounter);
    //AddBegginingElement(&head, &tail,&element, &pSizeCounter);

    //RemoveLastElement(&head, &tail,&pGotData, &pSizeCounter);
    //DeleteList(&head,&tail,&pSizeCounter);
    //PrintList(&element,&head,&pSizeCounter);
    //printf("%d %d", head -> number, tail -> number);
    //RemoveLastElement(&head, &tail,&pGotData, &pSizeCounter);
    //AddBegginingElement(&head, &tail,&element, &pSizeCounter);
    //AddBegginingElement(&head, &tail,&element, &pSizeCounter);
    PrintList(&element,&head,&pSizeCounter);
    RemoveFirstElement(&head,&tail,&pGotData,&pSizeCounter);
    PrintList(&element,&head,&pSizeCounter);
    //RemoveLastElement(&head, &tail,&pGotData, &pSizeCounter);
    //AddEndElement(&head, &tail,&element, &pSizeCounter);
    //PrintList(&element,&head,&pSizeCounter);
    IsDeckEmpty(&head, &tail);
    return 0;
}
