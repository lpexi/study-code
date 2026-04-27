#include <stdio.h>      // printf, scanf
#include <stdlib.h>     // malloc, calloc, realloc, free, rand, srand
#include <string.h>     // strlen, memcpy

typedef struct song
{
    char *p_title;                             // dynamically allocated title string
    char *p_artist;                            // dynamically allocated artist string
    struct song *p_next;                       // next song in playlist
} song_t;

typedef struct playlist
{
    song_t *p_first;                           // first song in the list
} playlist_t;

/**
 * @brief Allocate and copy a C-string into heap memory.
 *
 * @param[in] p_src  Source string
 * @return           Heap string copy, or NULL on failure
 */
static char *copy_string(const char *p_src)
{
    char *p_dst = NULL;                        // destination pointer
    size_t len = 0U;                           // string length

    if (p_src == NULL)                         // validate input
    {
        return NULL;                           // cannot copy NULL
    }

    len = strlen(p_src);                       // get length without '\0'

    p_dst = (char *)malloc(len + 1U);          // allocate len + 1 for '\0'
    if (p_dst == NULL)                         // check allocation
    {
        return NULL;                           // return NULL on failure
    }

    memcpy(p_dst, p_src, len + 1U);            // copy string including '\0'
    return p_dst;                               // return heap copy
}

/**
 * @brief Initialize an empty playlist.
 *
 * @param[out] p_playlist  Playlist to initialize
 */
static void init_playlist(playlist_t *p_playlist)
{
    if (p_playlist == NULL)                    // validate pointer
    {
        return;                                // do nothing if invalid
    }

    p_playlist->p_first = NULL;                // empty list => no first song
}

/**
 * @brief Add a song at the end of the playlist.
 *
 * @param[in,out] p_playlist  Playlist to modify
 * @param[in]     p_title     Song title (C-string)
 * @param[in]     p_artist    Artist name (C-string)
 */
static void add_song(playlist_t *p_playlist, const char *p_title, const char *p_artist)
{
    song_t *p_new = NULL;                      // new song node
    song_t *p_cur = NULL;                      // iterator

    if ((p_playlist == NULL) || (p_title == NULL) || (p_artist == NULL))
    {
        return;                                // invalid input => do nothing
    }

    p_new = (song_t *)malloc(sizeof *p_new);   // allocate song node
    if (p_new == NULL)
    {
        return;                                // allocation failed
    }

    p_new->p_title = copy_string(p_title);     // allocate + copy title
    p_new->p_artist = copy_string(p_artist);   // allocate + copy artist
    p_new->p_next = NULL;                      // new song is last for now

    if ((p_new->p_title == NULL) || (p_new->p_artist == NULL))
    {
        free(p_new->p_title);                  // free title if allocated
        p_new->p_title = NULL;                 // avoid dangling pointer
        free(p_new->p_artist);                 // free artist if allocated
        p_new->p_artist = NULL;                // avoid dangling pointer
        free(p_new);                           // free node
        return;                                // stop
    }

    if (p_playlist->p_first == NULL)           // empty playlist?
    {
        p_playlist->p_first = p_new;           // first song becomes new song
        return;                                // done
    }

    p_cur = p_playlist->p_first;               // start at first song
    while (p_cur->p_next != NULL)              // move to last song
    {
        p_cur = p_cur->p_next;                 // step forward
    }

    p_cur->p_next = p_new;                     // link last to new song
}

/**
 * @brief Print all songs in the playlist.
 *
 * @param[in] p_playlist  Playlist to print
 */
static void print_playlist(const playlist_t *p_playlist)
{
    const song_t *p_cur = NULL;                // iterator

    if (p_playlist == NULL)
    {
        return;                                // invalid input
    }

    p_cur = p_playlist->p_first;               // start at first song
    while (p_cur != NULL)
    {
        printf("Title: %s, Artist: %s\n",      // required format
               p_cur->p_title,
               p_cur->p_artist);

        p_cur = p_cur->p_next;                 // go to next song
    }
}

/**
 * @brief Delete the first song and free all its allocated memory.
 *
 * @param[in,out] p_playlist  Playlist to modify
 */
static void delete_first_song(playlist_t *p_playlist)
{
    song_t *p_first = NULL;                    // node to delete

    if (p_playlist == NULL)
    {
        return;                                // invalid input
    }

    p_first = p_playlist->p_first;             // take first node
    if (p_first == NULL)
    {
        return;                                // nothing to delete
    }

    p_playlist->p_first = p_first->p_next;     // move head to next node

    free(p_first->p_title);                    // free title string
    p_first->p_title = NULL;                   // avoid dangling pointer
    free(p_first->p_artist);                   // free artist string
    p_first->p_artist = NULL;                  // avoid dangling pointer
    free(p_first);                             // free the node itself
}

/**
 * @brief Delete the entire playlist and free all allocated memory.
 *
 * @param[in,out] p_playlist  Playlist to clear
 */
static void delete_playlist(playlist_t *p_playlist)
{
    if (p_playlist == NULL)
    {
        return;                                // invalid input
    }

    while (p_playlist->p_first != NULL)        // loop until list empty
    {
        delete_first_song(p_playlist);         // delete first song repeatedly
    }
}

/**
 * @brief Run Section III: playlist manager demo.
 */
static void run_section_iii(void)
{
    playlist_t playlist;                       // playlist object (stack)

    printf("=== Section III ===\n");

    init_playlist(&playlist);                  // 1) create + init playlist

    add_song(&playlist, "Crawling", "Linkin Park");      // 2) add songs
    add_song(&playlist, "Layla", "Eric Clapton");
    add_song(&playlist, "Esperanto", "Max Herre");

    printf("\nPlaylist (initial):\n");
    print_playlist(&playlist);                 // 3) print playlist

    delete_first_song(&playlist);              // 4) delete first song

    printf("\nPlaylist (after deleting first song):\n");
    print_playlist(&playlist);                 // 5) print again

    delete_playlist(&playlist);                // 6) delete complete playlist

    printf("\nPlaylist deleted.\n");
}

int main(void)
{
    run_section_iii();                         // run playlist manager demo

    return 0;                                  // program ended successfully
}
