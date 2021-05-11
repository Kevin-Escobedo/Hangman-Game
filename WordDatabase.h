#ifndef WORDDATABASE_H
#define WORDDATABASE_H
#include "Database.h"

class WordDatabase : public Database
{
public:
    WordDatabase(const char* dbName);
    void addTable();
    void addWord(const char* word, const char* definition);
};

#endif /* WORDDATABASE_H */
