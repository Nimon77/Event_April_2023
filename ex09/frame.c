#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_words {
    char *word;
    struct s_words *next;
} t_words;

t_words *add_word(t_words *words, char *word)
{
    t_words *new = malloc(sizeof(t_words));
    new->word = word;
    new->next = NULL;
    if (words == NULL)
        return new;
    t_words *tmp = words;
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return words;
}

void clean_words(t_words *words)
{
    t_words *tmp = words;
    while (words != NULL){
        tmp = words;
        words = words->next;
        free(tmp);
    }
}

int main(int argc, char *argv[])
{
    t_words *words = NULL;
    t_words *tmp = NULL;
    int longest = 0;

    if (argc == 1)
        return 1;
    for (int i = 1; i < argc; i++){
        char *ptr = strtok(argv[i], " ");
        while (ptr != NULL){
            words = add_word(words, ptr);
            if (strlen(ptr) > longest)
                longest = strlen(ptr);
            ptr = strtok(NULL, " ");
        }
    }
    tmp = words;
    for (int i = 0; i < longest + 4; i++)
        printf("*");
    printf("\n");
    for (t_words *tmp = words; tmp != NULL; tmp = tmp->next){
        printf("* %s", tmp->word);
        for (int i = 0; i < longest - strlen(tmp->word); i++)
            printf(" ");
        printf(" *\n");
    }
    for (int i = 0; i < longest + 4; i++)
        printf("*");
    printf("\n");
    clean_words(words);
    return 0;
}