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


node* delete_began(node *list);
node* delete_end(node *list);
node* delete_num(node *list, int num);

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






    
    // Remove element from begain of linked list
    char s[3];
    do
    {
        int num = 0;
        
        printf("Enter number you want to delete: ");
        scanf("%i",&num);
        
        list = delete_num(list, num);

        // Print list
        for(node* tmp = list ; tmp != NULL;tmp = tmp->next)
        {
            printf("%i\n",tmp->number);
        }

        printf("Do you want to delete another element (Yes/No): ");
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


node* delete_began(node *list)
{
        node *n = NULL;
        if(list == NULL)
        {
            printf("there is no element in list to delete");
        }
        n = list->next;
        free(list);
        list = n;
        return list;
}

node* delete_end(node *list)
{
    node *p;
    node *pre;
    // If there is no element in list
    if(list == NULL)
        {
            printf("there is no element in list to delete\n");
        }
    // If there is only ine element in list    
    else if(list->next == NULL)
    {
        list = NULL;
    }
    else
    {
        // We start from begaining of linked list so p will be equal to list
        p = list;
        // then we will iterate until reach to end of loop when lass element of list equal NULL
        while(p->next != NULL)
        {
                // pre node to point at node previous to node p
                pre = p;
                p = p->next;
        }
            // Now we make pre to NULL
            pre->next = NULL;
            // and free last element
            free(p);

    }
    return list;
}

node* delete_num(node *list, int num)
{
    node *tmp;
    node *pre;
    tmp = list;
    // If there is no element in list
    if(list == NULL)
    {
        printf("there is no element in list to delete\n");
    }
    else
    {
        while(tmp != NULL)
        {
            if(tmp->number == num)
            {
                if(list->number == num)
                {
                    list = list->next;
                    free(tmp);
                    return list;
                }
                else
                {
                    pre->next = tmp->next;
                    free(tmp);
                    return list;
                }
            }
            else{
                    pre = tmp;
                    tmp = tmp->next;
                }
            
        }
        printf("Element not found!\n");
    }
    
    return list;
    
    
    
}    