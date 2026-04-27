#include <stdio.h>      // printf, scanf
#include <stdlib.h>     // malloc, calloc, realloc, free, rand, srand
#include <string.h>     // strlen, memcpy

typedef struct node
{
    double value;                             // stored value
    struct node *p_next;                      // pointer to next node
} node_t;

/**
 * @brief Create a new linked-list node on the heap.
 *
 * @param[in] value  Value to store in the node
 * @return           Pointer to new node, or NULL on failure
 */
static node_t *create_node(double value)
{
    node_t *p_node = NULL;                    // pointer to new node

    p_node = (node_t *)malloc(sizeof *p_node);// allocate memory for one node
    if (p_node == NULL)                       // check allocation success
    {
        return NULL;                          // return NULL on failure
    }

    p_node->value = value;                    // store the value
    p_node->p_next = NULL;                    // end of list for now

    return p_node;                            // give node back to caller
}

/**
 * @brief Append a node at the end of the list.
 *
 * @param[in,out] pp_head  Address of head pointer (so we can change it)
 * @param[in]     p_new    Node to append
 */
static void append_node(node_t **pp_head, node_t *p_new)
{
    node_t *p_cur = NULL;                     // iterator pointer

    if ((pp_head == NULL) || (p_new == NULL)) // validate pointers
    {
        return;                               // do nothing on invalid input
    }

    if (*pp_head == NULL)                     // empty list?
    {
        *pp_head = p_new;                     // new node becomes head
        return;                               // done
    }

    p_cur = *pp_head;                         // start at head
    while (p_cur->p_next != NULL)             // walk until last node
    {
        p_cur = p_cur->p_next;                // go to next node
    }

    p_cur->p_next = p_new;                    // link last node to new node
}

/**
 * @brief Insert a node at a 0-based position in the list.
 *
 * Example: position=2 inserts as the "3rd node".
 *
 * @param[in,out] pp_head    Address of head pointer
 * @param[in]     position   0-based position
 * @param[in]     value      Value for the new node
 */
static void insert_node_at(node_t **pp_head, size_t position, double value)
{
    node_t *p_new = NULL;                     // new node
    node_t *p_cur = NULL;                     // iterator
    size_t i = 0U;                            // counter

    if (pp_head == NULL)                      // validate pointer
    {
        return;                               // do nothing if invalid
    }

    p_new = create_node(value);               // allocate a new node
    if (p_new == NULL)                        // check allocation success
    {
        return;                               // stop if allocation failed
    }

    if ((position == 0U) || (*pp_head == NULL)) // insert at start or empty list
    {
        p_new->p_next = *pp_head;             // new points to old head
        *pp_head = p_new;                     // head becomes new node
        return;                               // done
    }

    p_cur = *pp_head;                         // start at head

    /* Move to the node BEFORE the insertion point */
    for (i = 0U; (i < (position - 1U)) && (p_cur->p_next != NULL); i++)
    {
        p_cur = p_cur->p_next;                // move forward
    }

    p_new->p_next = p_cur->p_next;            // new points to "rest of list"
    p_cur->p_next = p_new;                    // previous points to new node
}

/**
 * @brief Print the linked list values.
 *
 * @param[in] p_head  Head pointer of the list
 */
static void print_list(const node_t *p_head)
{
    const node_t *p_cur = p_head;             // iterator pointer
    unsigned int idx = 0U;                    // print index

    while (p_cur != NULL)                     // loop until end
    {
        printf("node[%u] = %.2f\n", idx, p_cur->value); // print value
        p_cur = p_cur->p_next;                // go to next node
        idx++;                                // increase index
    }
}

/**
 * @brief Free all nodes in the list.
 *
 * @param[in,out] pp_head  Address of head pointer
 */
static void free_list(node_t **pp_head)
{
    node_t *p_cur = NULL;                     // iterator pointer
    node_t *p_next = NULL;                    // next pointer

    if (pp_head == NULL)                      // validate pointer
    {
        return;                               // do nothing if invalid
    }

    p_cur = *pp_head;                         // start at head
    while (p_cur != NULL)                     // loop until end
    {
        p_next = p_cur->p_next;               // save next pointer
        free(p_cur);                          // free current node
        p_cur = p_next;                       // move to next node
    }

    *pp_head = NULL;                          // list is now empty
}

/**
 * @brief Run Section II: linked list + array insertion exercise.
 */
static void run_section_ii(void)
{
    node_t *p_head = NULL;                    // head pointer of linked list
    int arr[51];                              // array with 51 elements (stack)
    size_t i = 0U;                            // loop index
    int new_value = 0;                        // extra random number

    printf("=== Section II ===\n");

    /* 2) Define head pointer (already done above) */

    /* 4) Create 50 nodes and add them to the list */
    for (i = 0U; i < 50U; i++)
    {
        node_t *p_node = create_node((double)i); // node stores i as double
        if (p_node == NULL)                       // allocation check
        {
            printf("Node allocation failed.\n");
            free_list(&p_head);                   // cleanup what we already built
            return;
        }

        append_node(&p_head, p_node);             // add node to end
    }

    /* 5+6) Fill array indices 0..49 with random ints in range 0..49 */
    srand(1U);                                 // fixed seed => reproducible result

    for (i = 0U; i < 50U; i++)
    {
        arr[i] = rand() % 50;                  // random number 0..49
    }

    /* index 50 is currently unused "free slot" for insertion */
    arr[50] = 0;                               // set to 0 for clean output

    /* 7) Create additional random number and insert it at index 3 */
    new_value = rand() % 50;                   // extra random number 0..49

    for (i = 50U; i > 3U; i--)
    {
        arr[i] = arr[i - 1U];                  // shift elements one step right
    }

    arr[3] = new_value;                        // place new value at index 3

    /* Insert a new node as the 3rd node (0-based position 2) */
    insert_node_at(&p_head, 2U, (double)new_value); // list insert by pointer relink

    /* 8) Print array and list */
    printf("\nArray (51 elements) after insertion at index 3:\n");
    for (i = 0U; i < 51U; i++)
    {
        printf("arr[%u] = %d\n", (unsigned int)i, arr[i]); // print array values
    }

    printf("\nLinked list after insertion as 3rd node:\n");
    print_list(p_head);                        // print list values

    /*
     * 9) Which insertion is more time-consuming?
     * - Array insertion usually needs shifting many elements => O(n) moves.
     * - Linked list insertion needs only pointer changes once the position is found.
     *   But finding the position can still take O(n) traversal.
     * In practice: arrays are expensive for insertion in the middle due to shifting.
     */

    /* 10) Free allocated memory */
    free_list(&p_head);                        // free all nodes

    printf("Section II done.\n\n");
}

int main(void)
{
    run_section_ii();                          // run list+array insertion task

    return 0;                                  // program ended successfully
}
