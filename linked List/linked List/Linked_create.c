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

int main(void)
{
    // List of size 0
    node *list = NULL;
    node *tmp_node = NULL;
    node *p = NULL;
    int num = 0;

    // Ask user for length of list
    int length;
    printf("Enter size of list: ");
    scanf("%i",&length);
    
    // Loop to length of list
    for(int i = 0; i < length; i++)
    {
        // Create new node very iteration
        tmp_node = malloc(sizeof(node));
        // Ask the user for number, he want to store in linked list
        printf("Enter %i number: ", i + 1);
        scanf("%i",&num);
        
        tmp_node->number = num;
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