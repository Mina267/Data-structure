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

    // node 1
    node *n = malloc(sizeof(node));
    if(n == NULL)
    {
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;

    // node 2
    n = malloc(sizeof(node));
    if(n == NULL)
    {
        free(list);
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // node 3
    n = malloc(sizeof(node));
    if(n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

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