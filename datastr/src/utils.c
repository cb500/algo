/**
 * 
 * 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cb_utils.h"

#define BUFFER_SIZE 512
#define WORD_MIN_SIZE 4

CB_RETURN cb_init_void (void **value)
{
    return CB_OK; 
}

/**
 * Read all the lines of a file, split them into words and return the number of words
 */

static void cb_sanitize_word(char *word, int pos)
{
    if (
        //(word[pos] <= 0x40) ||
        (word[pos] <= 64) ||
        //(word[pos] >= 0x5a && word[pos] <= 60) ||
        (word[pos] >= 91 && word[pos] <= 96) ||
        //(word[pos] >= 0x7b)
        (word[pos] >= 0x7b)
    )
    {
        // printf("Character[%d]: %c\n", word[pos], word[pos]);
        if(pos > 0)
            word[pos] = '\0';
        else
            memcpy(word, &word[pos + 1], strlen(word) - pos);
    }
}

CB_RETURN cb_read_file_line(CB_RETURN (*cb_add_node)(void **node, char *value),
        CB_RETURN (*cb_init_struct)(void **cb_struct), FILE *file, void **list, u_int8_t sanitize)
{
    if(file == NULL)
        return CB_ERR_NULL;

    CB_RETURN retval = CB_OK;
    if((retval = cb_init_struct(list)) != CB_OK)
        return retval;


    char buffer[BUFFER_SIZE];

    CB_NODE *tmpList = NULL;
    CB_NODE *current = NULL;

    //while(fgets(buffer, BUFFER_SIZE, file))
    while(fscanf(file,"%39s",buffer) == 1)
    {
        if(sanitize)
        {
            cb_sanitize_word(buffer, (strlen(buffer) - 1));
            cb_sanitize_word(buffer, 0);
        }

        // Check if the word has the minimum lenght limit
        if(strlen(buffer) < WORD_MIN_SIZE)
        {
            printf("Word [%s] is too small\n", buffer);
            continue;
        }

        cb_add_node(list, buffer);
    }

    // The ret_val variable contains the number of items in the list
    return retval;
}

void cb_print(void (* cb_print)(void *), void *root)
{
    cb_print(root);
}
