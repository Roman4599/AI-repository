#include <stdlib.h>

list_t *add_node_end(list_t *head, const int n)
{
    list_t *new_node, *current;

    /* Allocate memory for the new node */
    new_node = malloc(sizeof(list_t));

    /* Check that malloc succeeded */
    if (new_node == NULL)
        return (NULL);

    /* Initialize fields before any return */
    new_node->n = n;
    new_node->next = NULL;

    /* Empty list: the new node becomes the head */
    if (head == NULL)
        return (new_node);

    /* Stop ON the last node, not after it */
    current = head;
    while (current->next != NULL)
        current = current->next;

    /* Link the last node to the new node */
    current->next = new_node;

    return (head);
}
