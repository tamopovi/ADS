#include <stdlib.h>
#include <stdio.h>
#include "Func.h"
void CreateEmptyDeck(Deck **head, Deck **tail)
{
    (*head) = NULL;
    (*tail) = NULL;
    printf("Sukurtas tuscias dekas.\n");
}
void AskingDeckSize(int **askedSize)
{
    printf("Koks bus deko dydis ?");
    scanf("%d",&(*(*askedSize)));
}
void IsDeckEmpty (Deck **head, Deck **tail)
{
    if ((*head) == NULL && (*tail) == NULL)
        printf("Dekas tuscias.\n");
        else
            printf("Dekas nera tuscias.\n");
}
void AddBegginingElement (Deck **head, Deck **tail,Deck **element, int **sizeCounter)
{
    if ((*head) == NULL && (*tail) == NULL)
    {
        int n;
        (*element) = (Deck *) malloc (sizeof(Deck));
        printf("Iveskite naujo pradzios elemento reiksme: ");
        scanf("%d",&n);
        (*element) -> number = n;
        (*element) -> previous =  NULL;
        (*element) -> next = NULL;
        *head = *element;
        *tail = *element;
        (*(*sizeCounter))++;
    }
    else
    {
        int n;
        (*element) = (Deck *) malloc (sizeof(Deck));
        printf("Iveskite naujo elemento reiksme: ");
        scanf("%d",&n);
        (*element) -> number = n;
        (*element) -> previous =  NULL;
        (*element) -> next = *head;
        (*head) -> previous = *element;
        *head = *element;
        (*(*sizeCounter))++;
    }
}
void AddEndElement (Deck **head, Deck **tail,Deck **element, int **sizeCounter)
{
    if ((*head) == NULL && (*tail) == NULL)
    {
        int n;
        (*element) = (Deck *) malloc (sizeof(Deck));
        printf("Iveskite naujo elemento reiksme: ");
        scanf("%d",&n);
        (*element) -> number = n;
        (*element) -> previous =  NULL;
        (*element) -> next = NULL;
        *head = *element;
        *tail = *head;
        (*(*sizeCounter))++;
    }
    else
    {
        int n;
        (*element) = (Deck *) malloc (sizeof(Deck));
        printf("Iveskite naujo pabaigos elemento reiksme: ");
        scanf("%d",&n);
        (*element) -> number = n;
        (*element) -> next = NULL;
        (*element) -> previous = *tail;
        (*tail) -> next = *element;
        *tail = *element;
        (*(*sizeCounter))++;
    }
}
void IsDeckFull(int **actualDeckSize, int **askedDeckSize)
{
    if ((*(*actualDeckSize)) < (*(*askedDeckSize)))
        printf("Dekas nera pilnas.\n");
    else
        printf("Dekas yra pilnas.\n");
}
void PrintList (Deck **elem, Deck **head, int **sizeCounter)
{
    int i = 0;
    (*elem) = (*head);
    printf("Deko elementai: ");
    for (i = 0; i < (*(*sizeCounter)); i++)
    {
        printf("%d ", (*elem)->number);
        (*elem) = (*elem)->next;
    }
    printf("\n");
}
void RemoveLastElement (Deck **head, Deck **tail, int **elementsData, int **listSize)
{
    if ((*(*listSize)) == 1)
    {
        Deck *element = *tail;
        free(element);
        (*head) = NULL;
        (*tail) = NULL;
        (*(*listSize))--;
    }
    else
    {
        Deck *element;
        element = (*tail) -> previous;
        (*(*elementsData)) = (*tail) -> number;
        element -> next = NULL;
        free((*tail));
        *tail = element;
        (*(*listSize))--;
    }
}
void RemoveFirstElement (Deck **head, Deck **tail, int **elementsData, int **listSize)
{
    if ((*(*listSize)) == 1)
    {
        Deck *element = *tail;
        free(element);
        (*head) = NULL;
        (*tail) = NULL;
        (*(*listSize))--;
    }
    else
    {
        Deck *element;
        element = *head;
        (*(*elementsData)) = element -> number;
        (*head) = element -> next;
        (*head) -> previous = NULL;
        free(element);
        (*(*listSize))--;
    }

}
void DeleteList(Deck** head, Deck **tail, int **sizeCounter)
{
   Deck* current = *head;
   Deck* next;
   printf("Trinamas dekas...\nDeko elementai: ");
   while (current != NULL)
   {
       next = current->next;
       printf("%d ",current ->number);
       free(current);
       current = next;
       (*(*sizeCounter))--;
   }
   printf("\nIstrinta.\n");
    (*head) = NULL;
    (*tail) = NULL;

}
