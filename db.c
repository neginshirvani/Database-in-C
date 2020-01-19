//
// Created by negin on 18/01/20.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TableField {
    char field_name[10];
    char field_type;
};

struct Property {
    struct TableField * table_field;
    void * data;
};

void printProperty(struct Property *p) {
    if(p->table_field->field_type == 0) {
        printf("%s %d\n", p->table_field->field_name, *(int *) (p->data));

    } else if(p->table_field->field_type == 1) {

        printf("%s %s\n", p->table_field->field_name, *(char **) (p->data));

    }
}


struct *Property insert(struct Property *p, char* MyFieldName) {
    struct Property * new_property;
    strcpy(new_property->table_field->field_name, MyFieldName);


};

