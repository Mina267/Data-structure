#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int number;
    struct node *next;
}
node;

node* reverse(node *list);

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
        if(i == 0)
        {
            list = tmp_node;
        }
        else
        {
            // We start from begaining of linked list so p will be equal to list
            p = list;
            // then we will iterate until reach to end of loop when lass element of list equal NULL
            while(p->next != NULL)
            {
                p = p->next;
            }
            // Now we store and attached last node to end of the list
            p->next = tmp_node;

        }
    }




    list = reverse(list);

    // Print list
    for(node* tmp = list ; tmp != NULL;tmp = tmp->next)
    {
        printf("%i\n",tmp->number);
    }


    // Free list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;

    }

    return 0;


}

//https://www.youtube.com/watch?v=XgABnoJLtG4
node* reverse(node *list)
{
    node *prev = NULL;
    node *next = NULL;
    while(list != NULL)
    {
        next = list->next;
        list->next = prev;
        prev = list;
        list = next;
    }
    list = prev;
    return list;
}

/*
    1      ->     2    ->3   ->4->5->NULL
    |
    list      prev=NULL   next=NULL

    1->              2->       3->       4->       5->NULL
    |                |
    list prev=NULL  next

    1->NULL          2->       3->       4->       5->NULL
    |                |
    list prev=NULL  next

    1->NULL          2->       3->       4->       5->NULL
    |     \          |
    list  prev      next

    1->NULL          2->       3->       4->       5->NULL
         \           |  \
         prev      next list

    1->NULL          2->       3->       4->       5->NULL
         \             \       |
         prev          list   next

    1->NULL         <-2        3->       4->       5->NULL
         \            |        |
         prev        list     next

    1->NULL         <-2        3->       4->       5->NULL
         \            |        |
         prev        list     next

     1->NULL         <-2        3->       4->       5->NULL
                      |  \      |
                    list prev   next

    1->NULL         <-2        3->       4->       5->NULL
                      |        |  \
                     perv     list next


*/