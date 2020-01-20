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


struct data { /** data about indivisuals */

};

struct Property {  /** indivisuals */
    struct TableField * table_field;
    void * data;
    struct Property* next;
};

struct Row { /** the whole database */
    struct Property* properties;
    struct Row* next;
};

struct Table {
    char table_name[20];
    struct Row* the_rows;
};


void printProperty(struct Property *p) {
    if(p->table_field->field_type == 0) {
        printf("%s %d\n", p->table_field->field_name, *(int *) (p->data));

    } else if(p->table_field->field_type == 1) {

        printf("%s %s\n", p->table_field->field_name, *(char **) (p->data));

    }
}


struct Row* CreatATable() {
    struct Row *new_row = malloc(sizeof(struct Row));

    new_row->properties = (struct Property*)malloc(sizeof(struct Property));
    new_row->properties->table_field = (struct TableField*)malloc(sizeof(struct TableField));

    new_row->next = NULL;

    return new_row;

};

struct Property* CreateThing() {
  struct Property* new_property = malloc(sizeof(struct Property));

  new_property->table_field = (struct TableField*)malloc(sizeof(struct TableField));
  new_property->next = NULL;

  return new_property;
};


struct Row* new_insrt(struct Row* all, char * MyFieldName, void * Mydata) {
    struct Property * new_property;
    strcpy(new_property->table_field->field_name, MyFieldName);
    if (new_property->table_field->field_type == 0)
        new_property->data = *(int *)(Mydata);
    else if(new_property->table_field->field_type == 1)
        new_property->data = *(char **)(Mydata);

    new_property->next = NULL;

    if(all->next == NULL)
        return new_property;
    if (strcmp(all->properties->table_field->field_name, MyFieldName) == 1) {
        new_property->next = all->properties->next;
    }

    while (all->next != NULL && strcmp(all->properties->table_field->field_name, MyFieldName) == -1) {
        all->properties = all->properties->next;
    }

    new_property->next = all->properties->next;
    all->properties->next = new_property;
    return all;
}



struct Row* insert(struct Row* all, char * MyFieldName, void * Mydata) {

    struct Row* new_row;
    strcpy(new_row->properties->table_field->field_name, MyFieldName);
    if(all->properties->table_field->field_type == 0)
        new_row->properties->data = *(int *)(Mydata);
    else if(all->properties->table_field->field_type == 1)
        new_row->properties->data = *(char **)(Mydata);

    new_row->next = NULL;

    if(all->next == NULL)
        return new_row;

    if(strcmp(all->properties->table_field->field_name, MyFieldName) == 1) {
        new_row->next = all;
        return new_row;
    }

    while(all->next != NULL && strcmp(all->properties->table_field->field_name, MyFieldName) == -1)
        all = all->next;

    new_row->next = all->next;
    all->next = new_row;
    return all;
};


struct Row* deletee(struct Row* all, char * MyFieldName) { /** Does we delete a data or a propert? */

    if (all == NULL)
        return NULL;

    while(all->next != NULL) {
        if(strcmp(all->properties->table_field->field_name, MyFieldName) == 0) {
            struct Property * tmp;
            tmp = all->properties->next->next;
            free(all->properties->next);
            all->properties->next = tmp;
        }
    }

    return all;
};


struct Row* selectt (struct Row* all, void * data) {

    if(all == NULL)
        return NULL;

    while (all->next != NULL && strcmp(all->properties->data, data) == 0) {
        printProperty(all->properties);
        all = all->next;
    }

};

char prefix(const char *pre, const char *str){
    return strncmp(pre, str, strlen(pre)) == 0;
}

void execcQuery(char *query){
    // starts with "insert"
    int len = strlen(query);
    char *p1, *p2;
    char temp[100];

    if(prefix("insertTo", query)){
        p2 = p1 = query + 9;
        while(*p2 != ' ') p2++;
        char *table_name = (char *) malloc((p2 - p1 + 1) * sizeof(char));
        strncpy(table_name, p1, p2 - p1);
        //printf(table_name);

        p2 = p1 = p2+1;
        while(*p2){
            while(*p2 != '=') p2++;
            char *field_name;
            //for(int i = 0 ; i < p2; i++) {
            field_name = (char *) malloc((p2 - p1 + 1) * sizeof(char));
            strncpy(field_name, p1, p2 - p1);
            printf(field_name);

            p2 = p1 = p2+1;
            while(*p2 && *p2 != ',') p2++;
            char *data;
            //for(int i = 0 ; i < p2; i++) {
            data = (char *) malloc((p2 - p1 + 1) * sizeof(char));
            strncpy(data, p1, p2 - p1);
            printf(data);
            if(*p2)
                p2 = p1 = p2+1;
            }
//        }
    }
}


