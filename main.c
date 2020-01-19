#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db.c"



int main() {
    struct Property * p1 = malloc(sizeof(struct Property));
    p1->table_field = (struct TableField *) malloc(sizeof(struct TableField));
    strcpy(p1->table_field->field_name, "score");
    p1->table_field->field_type = 0;

    int *score = malloc(sizeof(int));
    *score = 5;
    p1->data = score;

    printProperty(p1);


    struct Property * p2 = malloc(sizeof(struct Property));
    p2->table_field = (struct TableField *) malloc(sizeof(struct TableField));
    strcpy(p2->table_field->field_name, "name");
    p2->table_field->field_type = 1;

    char **name = malloc(sizeof(char *));
    *name = malloc(10 * sizeof(char));
    strcpy(*name, "ali");
    p2->data = name;

    printProperty(p2);
}