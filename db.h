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


struct Row* selectt (struct Table* the_table, void * query);
struct Table* Deletee(struct Table* the_table, void *query);
char prefix(const char *pre, const char *str);

struct Table* UpdatexeccQuery(struct Table *the_table ,char *query);
struct Table* FindexeccQuery(struct Table *the_table ,char *query);
struct Table* delexeccQuery(struct Table * the_table, char *query);
struct Table* execcQuery(char *query);
struct Table* insert(struct Table* the_table, char *query);

#endif //DATABASE_DB_H