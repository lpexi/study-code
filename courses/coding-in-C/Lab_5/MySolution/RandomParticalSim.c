/*
 * File: main.c
 * Description: 1D random particle simulation using pointers and a temporary field.
 *              Three particles start at random positions with even spacing.
 *              Each time step, every particle moves left or right by one cell (stays in bounds).
 *              If two or more particles move into the same cell, they collide and are removed.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    const int FIELD_SIZE = 10;
    const int STEPS = 20;
    const int PARTICLE_COUNT = 3;

    int field[FIELD_SIZE];
    int next_field[FIELD_SIZE];

    int *p_field = &field[0];
    int *p_next_field = &next_field[0];

    int spacing = 0;
    int max_spacing = 0;
    int start_index = 0;

    srand((unsigned int)time(NULL));

    /* Initialize field */
    for (int i = 0; i < FIELD_SIZE; i++)
    {
        *(p_field + i) = 0;
    }

    /*
     * Place three particles randomly spaced in even intervals:
     * start_index, start_index + spacing, start_index + 2*spacing
     * spacing must be even and must fit inside the field.
     */
    max_spacing = (FIELD_SIZE - 1) / (PARTICLE_COUNT - 1);

    if (max_spacing < 2)
    {
        /* Field too small for 3 particles with even spacing */
        return 1;
    }

    spacing = 2 * (1 + (rand() % (max_spacing / 2)));
    start_index = rand() % (FIELD_SIZE - ((PARTICLE_COUNT - 1) * spacing));

    *(p_field + start_index) = 1;
    *(p_field + (start_index + spacing)) = 1;
    *(p_field + (start_index + (2 * spacing))) = 1;

    for (int step = 0; step < STEPS; step++)
    {
        /* Print current state */
        printf("Time %d: ", step);
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            printf("%d ", *(p_field + i));
        }
        printf("\n");

        /* Clear next_field (used as target counter first) */
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            *(p_next_field + i) = 0;
        }

        /* Count targets */
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            if (*(p_field + i) == 1)
            {
                int move_right = rand() % 2; /* 0 = left, 1 = right */
                int next_index = i + (move_right ? 1 : -1);

                if (next_index < 0)
                {
                    next_index = 0;
                }
                else if (next_index >= FIELD_SIZE)
                {
                    next_index = FIELD_SIZE - 1;
                }

                *(p_next_field + next_index) = *(p_next_field + next_index) + 1;
            }
        }

        /* Resolve collisions and build next state */
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            if (*(p_next_field + i) >= 2)
            {
                printf("Collision on index %d\n", i);
                *(p_next_field + i) = 0;
            }
            else if (*(p_next_field + i) == 1)
            {
                *(p_next_field + i) = 1;
            }
            else
            {
                *(p_next_field + i) = 0;
            }
        }

        /* Copy next_field into field */
        for (int i = 0; i < FIELD_SIZE; i++)
        {
            *(p_field + i) = *(p_next_field + i);
        }
    }

    return 0;
}