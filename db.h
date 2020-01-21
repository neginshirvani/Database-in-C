//
// Created by negin on 20/01/20.
//

#ifndef DATABASE_DB_H
#define DATABASE_DB_H



struct TableField;

struct Property;
struct Row;
struct Table;
void printProperty(struct Property *p);
struct Table* CreatATable() ;
struct Property* CreateThing();

//struct Row* deletee(struct Row* all, char * MyFieldName);
struct Row* selectt (struct Row* all, void * data);
struct Table* Deletee(struct Table* the_table, void *query);

        char prefix(const char *pre, const char *str);

struct Table* execcQuery(char *query);
struct Table* insert(struct Table* the_table, char *query);

#endif //DATABASE_DB_H