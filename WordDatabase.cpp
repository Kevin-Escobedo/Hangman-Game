#include "WordDatabase.h"

WordDatabase::WordDatabase(const char* dbName) : Database(dbName)
{

}

void WordDatabase::addTable()
{
    const char* command = "CREATE TABLE IF NOT EXISTS DICTIONARY(" \
    "WORD TEXT PRIMARY KEY NOT NULL, "\
    "DEFINITION TEXT NOT NULL );";

    rc = sqlite3_exec(db, command, callback, nullptr, &zErrMsg);

    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL Error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void WordDatabase::addWord(const char* word, const char* definition)
{
    char values[256];
    sprintf(values, "VALUES('%s', '%s');", word, definition);
    std::string dataValues(values);
    std::string sqlCommand = "INSERT INTO DICTIONARY(WORD, DEFINITION) ";
    std::string tempCommand = sqlCommand + dataValues;
    const char* command = tempCommand.c_str();

    rc = sqlite3_exec(db, command, callback, nullptr, &zErrMsg);

    if(rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL Error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}
