#include <stdio.h>      // printf, scanf
#include <stdlib.h>     // malloc, calloc, realloc, free, rand, srand
#include <string.h>     // strlen, memcpy


/**
 * @brief Print an int array to the console.
 *
 * @param[in] p_arr  Pointer to the first element of the array
 * @param[in] len    Number of elements in the array
 */
static void print_int_array(const int *p_arr, size_t len)
{
    size_t i = 0U;                           // loop index

    for (i = 0U; i < len; i++)
    {
        printf("arr[%u] = %d\n", (unsigned int)i, p_arr[i]); // print index + value
    }
}

/**
 * @brief Run Section I: malloc/calloc/realloc/free exercise.
 */
static void run_section_i(void)
{
    int *p_n = NULL;                          // pointer to dynamically stored N
    int user_n = 0;                           // user input (stack variable)
    size_t n = 0U;                            // validated N as size_t (for sizes)
    int *p_arr = NULL;                        // array allocated with calloc
    int *p_tmp = NULL;                        // temp pointer for realloc
    size_t i = 0U;                            // loop index

    printf("=== Section I ===\n");
    printf("Enter N (positive integer): ");   // ask user for N

    if (scanf("%d", &user_n) != 1)            // read integer; check input worked
    {
        printf("Input error.\n");             // tell user input failed
        return;                               // stop this section
    }

    if (user_n <= 0)                          // reject invalid values
    {
        printf("N must be > 0.\n");           // explain requirement
        return;                               // stop this section
    }

    /* 1) Reserve memory for ONE integer with malloc and store N there */
    p_n = (int *)malloc(sizeof *p_n);         // allocate memory for 1 int (no init)
    if (p_n == NULL)                          // check allocation success
    {
        printf("malloc failed.\n");           // report failure
        return;                               // stop this section
    }

    *p_n = user_n;                            // store N into allocated memory
    n = (size_t)(*p_n);                       // convert to size_t for allocations

    /* 2) Reserve memory for N integers using calloc */
    p_arr = (int *)calloc(n, sizeof *p_arr);  // allocate N ints, set them to 0
    if (p_arr == NULL)                        // check allocation success
    {
        printf("calloc failed.\n");           // report failure
        free(p_n);                            // free the first allocation
        p_n = NULL;                           // avoid dangling pointer
        return;                               // stop this section
    }

    /*
     * 7) Main differences between calloc() and malloc():
     * - calloc initializes the allocated memory with zero-bits (e.g. 0 for int),
     *   malloc does NOT initialize (content is "random"/undefined).
     * - calloc takes (count, element_size) and allocates count*element_size bytes,
     *   malloc takes (total_bytes) directly.
     */

    /* 3) Fill array with square numbers: arr[i] = i*i */
    for (i = 0U; i < n; i++)
    {
        p_arr[i] = (int)(i * i);              // store square of index
    }

    /* 4) Resize array to 2*N and fill new indices with squares */
    p_tmp = (int *)realloc(p_arr, (2U * n) * sizeof *p_arr); // try to grow memory
    if (p_tmp == NULL)                        // realloc failed => old p_arr still valid
    {
        printf("realloc failed.\n");          // report failure
        free(p_arr);                          // free old array
        p_arr = NULL;                         // avoid dangling pointer
        free(p_n);                            // free stored N
        p_n = NULL;                           // avoid dangling pointer
        return;                               // stop this section
    }

    p_arr = p_tmp;                            // take resized pointer

    for (i = n; i < (2U * n); i++)
    {
        p_arr[i] = (int)(i * i);              // fill squares for new part
    }

    /* 5) Print the array */
    printf("\nArray content (len = %u):\n", (unsigned int)(2U * n));
    print_int_array(p_arr, 2U * n);           // print all values

    /* 6) Free all allocated memory */
    free(p_arr);                              // free array
    p_arr = NULL;                             // avoid dangling pointer

    free(p_n);                                // free stored N
    p_n = NULL;                               // avoid dangling pointer

    printf("Section I done.\n\n");
}


int main(void)
{
    run_section_i();                           // run malloc/calloc/realloc/free task

    return 0;                                  // program ended successfully
}