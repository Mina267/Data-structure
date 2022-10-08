#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>


typedef struct node{
    int number;
    struct node *next;
}
node;


bool Search(node *list,int num);

int main(void)
{
    // List of size 0
    node *list = NULL;
    node *tmp_node = NULL;
    node *p = NULL;


    // Ask user for length of list

    printf("orginal list {1 2 3 4 5} \n");


    // Loop to length of list
    for(int i = 0; i < 5; i++)
    {
        // Create new node very iteration
        tmp_node = malloc(sizeof(node));


        tmp_node->number = i + 1;
        tmp_node->next = NULL;

        if(tmp_node ==  NULL)
        {
            return 1;
        }

        // Condition at begin of create linked list
        if(list == NULL)
        {
            list = tmp_node;
        }
        else
        {
            // We start from begaining of linked list so p will be equal to list
            // p will point to began of Linked List
            p = list;
            // then we will iterate until reach to end of loop when lass element of list equal NULL
            while(p->next != NULL)
            {
                p = p->next;
            }
            // Now we store and attached last node to end of the list
            p->next = tmp_node;

            /* ex. if we have list = 1->2->3->4->5->NULL   and  n = 6->NULL
            use p to point at beagan  of linked list then will iterate til reach last node
            in the list where is number 5
            Then we add node n to end of linked list
            list = 1->2->3->4->5->6->NULL
            */

        }
    }




     // Add element to begain of linked list
    char s[3];
    do
    {
        
        int num = 0;
        
        printf("Enter number you want to search for: ");
        scanf("%i",&num);
        if(Search(list, num))
            printf("Found! \n");
        else
            printf("Not found! \n ");
        

       
        // Ask User if he want to add another number
        printf("Do you want to search another (Yes/No): ");
        scanf("%s",s);
        for (int i = 0, L = strlen(s); i < L; i++)
        {
            s[i] = tolower(s[i]);
        };


    }
    while(strcmp(s,"yes") == 0);







    // Free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;

    }

    return 0;


}


bool Search(node *list,int num)
{
    node *trav;
    trav = list;
    while(trav != NULL)
    {
        if(trav->number == num)
        {
            return true;
        }
        else
        {
            trav = trav->next;
        }    
    }
    
    return false;
}