//
//  CipherStatement.h
//  AliCipherDBDemo
//
//  Created by Pavel on 15/8/11.
//  Copyright (c) 2015年 Pavel. All rights reserved.
//

#ifndef __AliCipherDB__CipherStatement__
#define __AliCipherDB__CipherStatement__

#include "sqlite3.h"
#include "CipherError.h"
#include <map>

class CipherDatabase;

class CipherStatement
{
public:
    /**
     * Constructor
     * Compile and register the SQL query for the provided SQLite Database Connection
     *
     * @param[in]  aDatabase the SQLite Database Connection
     * @param[in]  aQuery   an UTF-8 encoded query string
     * @param[out] aError    NULL if construct succeed, or else return CipherError
     */
    CipherStatement(CipherDatabase* aDatabase, const char* aQuery, CipherError*& aError);
    
    /**
     * Destructor
     * Finalize and unregister the SQL query from the SQLite Database Connection.
     * if the caller don't destruct CipherStatement, the SQLite Database Connection can not close
     */
    ~CipherStatement();
    
    /**
     * Get the param count of the statement.
     */
    int GetParamCount();
    
    /**
     * Reset the statement to make it ready for a new execution.
     */
    CipherError* Reset();
    
    /**
     * Clears away all the bindings of a prepared statement.
     *
     * Contrary to the intuition of many, reset() does not reset
     * the bindings on a prepared statement.
     * Use this routine to reset all parameters to NULL.
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     */
    CipherError* ClearBindings();
    
    /**
     * Bind an int value to a parameter "?", "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     */
    CipherError* Bind(const int aIndex, const int& aValue);
    
    /**
     * Bind a 64bits int value to a parameter "?", "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     */
    CipherError* Bind(const int aIndex, const sqlite3_int64& aValue);
    
    /**
     * Bind a double (64bits float) value to a parameter "?", "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     */
    CipherError* Bind(const int aIndex, const double& aValue);
    
    /**
     * Bind a text value to a parameter "?", "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     * @note This uses the SQLITE_TRANSIENT flag, making a copy of the data, for SQLite internal use
     */
    CipherError* Bind(const int aIndex, const char* aValue);
    
    /**
     * Bind a binary blob value to a parameter "?", "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     * @note This uses the SQLITE_TRANSIENT flag, making a copy of the data, for SQLite internal use
     */
    CipherError* Bind(const int aIndex, const void* aValue, const int aSize);
    
    /**
     * Bind a NULL value to a parameter "?", "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     */
    CipherError* Bind(const int aIndex);
    
    /**
     * Bind an int value to a named parameter "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     */
    CipherError* Bind(const char* aName, const int& aValue);
    
    /**
     * Bind a 64bits int value to a named parameter "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     */
    CipherError* Bind(const char* aName, const sqlite3_int64&  aValue);
    
    /**
     * Bind a double (64bits float) value to a named parameter "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     */
    CipherError* Bind(const char* aName, const double& aValue);
    
    /**
     * Bind a text value to a named parameter "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     * @note This uses the SQLITE_TRANSIENT flag, making a copy of the data, for SQLite internal use
     */
    CipherError* Bind(const char* aName, const char* aValue);
    
    /**
     * Bind a binary blob value to a named parameter "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     * @note This uses the SQLITE_TRANSIENT flag, making a copy of the data, for SQLite internal use
     */
    CipherError* Bind(const char* aName, const void* aValue, const int aSize);
    
    /**
     * Bind a NULL value to a named parameter "?NNN", ":VVV", "@VVV" or "$VVV" in the SQL prepared statement (aIndex >= 1)
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     */
    CipherError* Bind(const char* aName);
    
    /**
     * Execute a step of the prepared query to fetch one row of results.
     *
     * While true is returned, a row of results is available, and can be accessed
     * thru the GetColumn() method
     *
     * @param[out] aError    NULL if execute succeed, or else return CipherError
     *
     * @return - true  (SQLITE_ROW)  if there is another row ready : you can call GetColumn(N) to get it
     *                               then you have to call ExecuteStep() again to fetch more rows until the query is finished
     *         - false (SQLITE_DONE) if the query has finished executing : there is no (more) row of result
     *                               (case of a query with no result, or after N rows fetched successfully)
     */
    bool ExecuteStep(CipherError*& aError);
    
    /**
     *  Execute a one-step query with no expected result.
     *
     *  This method is useful for any kind of statements other than the Data Query Language (DQL) "SELECT" :
     *  - Data Definition Language (DDL) statements "CREATE", "ALTER" and "DROP"
     *  - Data Manipulation Language (DML) statements "INSERT", "UPDATE" and "DELETE"
     *  - Data Control Language (DCL) statements "GRANT", "REVOKE", "COMMIT" and "ROLLBACK"
     *
     * It is similar to CipherDatabase::Exec(), but using a precompiled statement, it adds :
     * - the ability to Bind() arguments to it (best way to insert data),
     * - reusing it allows for better performances (efficient for multiple insertion).
     *
     * return NULL if succeed, or else return CipherError, caller need to destroy CipherError when CipherError != NULL
     */
    CipherError* Exec();
    
    /**
     * Return the integer value of the column.
     *
     * @param[in]  aIndex    Index of the column, starting at 0
     * @param[out] aError    NULL if get succeed, or else return CipherError
     */
    int GetColumnInt(const int aIndex, CipherError*& aError);
    
    /**
     * Return the 64bit integer value of the column.
     *
     * @param[in]  aIndex    Index of the column, starting at 0
     * @param[out] aError    NULL if get succeed, or else return CipherError
     */
    sqlite3_int64 GetColumnInt64(const int aIndex, CipherError*& aError);
    
    /**
     * Return the double (64bits float) value of the column.
     *
     * @param[in]  aIndex    Index of the column, starting at 0
     * @param[out] aError    NULL if get succeed, or else return CipherError
     */
    double GetColumnDouble(const int aIndex, CipherError*& aError);
    
    /**
     * Return the text value (NULL terminated string) of the column.
     *
     * @param[in]  aIndex    Index of the column, starting at 0
     * @param[out] aError    NULL if get succeed, or else return CipherError
     */
    const char* GetColumnText(const int aIndex, CipherError*& aError);
    
    /**
     * Return a pointer to the binary blob value of the column.
     *
     * @param[in]  aIndex    Index of the column, starting at 0
     * @param[out] aError    NULL if get succeed, or else return CipherError
     *
     * @warning The value pointed at is only valid while the statement is valid (ie. not finalized),
     *          thus you must copy it before using it beyond its scope (to a std::string for instance).
     */
    const void* GetColumnBlob(const int aIndex, CipherError*& aError);
    
    /**
     * Return the number of bytes used by the text (or blob) value of the column
     *
     * @param[in]  aIndex    Index of the column, starting at 0
     * @param[out] aError    NULL if get succeed, or else return CipherError
     *
     * Return either :
     * - size in bytes (not in characters) of the string returned by getText() without the '\0' terminator
     * - size in bytes of the string representation of the numerical value (integer or double)
     * - size in bytes of the binary blob returned by getBlob()
     * - 0 for a NULL value
     */
    int GetColumnBytes(const int aIndex, CipherError*& aError);
    
    /**
     * Return the integer value of the column.
     *
     * @param[in]  aName   Aliased name of the column, that is, the named specified in the query (not the original name)
     * @param[out] aError   NULL if get succeed, or else return CipherError
     */
    int GetColumnInt(const char* aName, CipherError*& aError);
    
    /**
     * Return the 64bit integer value of the column.
     *
     * @param[in]  aName   Aliased name of the column, that is, the named specified in the query (not the original name)
     * @param[out] aError   NULL if get succeed, or else return CipherError
     */
    sqlite3_int64 GetColumnInt64(const char* aName, CipherError*& aError);
    
    /**
     * Return the double (64bits float) value of the column.
     *
     * @param[in]  aName   Aliased name of the column, that is, the named specified in the query (not the original name)
     * @param[out] aError   NULL if get succeed, or else return CipherError
     */
    double GetColumnDouble(const char* aName, CipherError*& aError);
    
    /**
     * Return the text value of the column.
     *
     * @param[in]  aName   Aliased name of the column, that is, the named specified in the query (not the original name)
     * @param[out] aError   NULL if get succeed, or else return CipherError
     */
    const char* GetColumnText(const char* aName, CipherError*& aError);
    
    /**
     * Return a pointer to the binary blob value of the column.
     *
     * @param[in]  aName   Aliased name of the column, that is, the named specified in the query (not the original name)
     * @param[out] aError   NULL if get succeed, or else return CipherError
     *
     * @warning The value pointed at is only valid while the statement is valid (ie. not finalized),
     *          thus you must copy it before using it beyond its scope (to a std::string for instance).
     */
    const void* GetColumnBlob(const char* aName, CipherError*& aError);
    
    /**
     * Return the number of bytes used by the text (or blob) value of the column
     *
     * @param[in]  aName   Aliased name of the column, that is, the named specified in the query (not the original name)
     * @param[out] aError   NULL if get succeed, or else return CipherError
     *
     * Return either :
     * - size in bytes (not in characters) of the string returned by getText() without the '\0' terminator
     * - size in bytes of the string representation of the numerical value (integer or double)
     * - size in bytes of the binary blob returned by getBlob()
     * - 0 for a NULL value
     */
    int GetColumnBytes(const char* aName, CipherError*& aError);
    
    /**
     * Return the type of the value of the column
     *
     * @param[in]  aIndex    Index of the column, starting at 0
     * @param[out] aError    NULL if get succeed, or else return CipherError
     *
     * Return either SQLITE_INTEGER, SQLITE_FLOAT, SQLITE_TEXT, SQLITE_BLOB, or SQLITE_NULL.
     *
     * @warning After a type conversion (by a call to a getXxx on a Column of a Yyy type),
     *          the value returned by sqlite3_column_type() is undefined.
     */
    int GetType(const int aIndex, CipherError*& aError);
    
    /**
     * Return the type of the value of the column
     *
     * @param[in]  aName   Aliased name of the column, that is, the named specified in the query (not the original name)
     * @param[out] aError   NULL if get succeed, or else return CipherError
     *
     * Return either SQLITE_INTEGER, SQLITE_FLOAT, SQLITE_TEXT, SQLITE_BLOB, or SQLITE_NULL.
     *
     * @warning After a type conversion (by a call to a getColumnXxx on a Column of a Yyy type),
     *          the value returned by sqlite3_column_type() is undefined.
     */
    int GetType(const char* aName, CipherError*& aError);
    
    /**
     * Return the index to the specified result column
     * @param[in]  aName    Name of the column
     * @param[out] aError   NULL if get succeed, or else return CipherError
     *
     *  return -1 if the column not exist.
     */
    int GetColumnIndex(const char* aName);
    
    /**
     * Return the named assigned to the specified result column (potentially aliased)
     *
     * @param[in]  aIndex    Index of the column, starting at 0
     *
     * return NULL if the column not exist.
     */
    const char* GetColumnName(const int aIndex);
    
#ifdef SQLITE_ENABLE_COLUMN_METADATA
    /**
     * Return the table column name that is the origin of this result column
     *
     * Require definition of the SQLITE_ENABLE_COLUMN_METADATA preprocessor macro :
     * - when building the SQLite library itself,
     * - and also when compiling this wrapper.
     *
     * @param[in]  aIndex    Index of the column, starting at 0
     */
    const char* GetColumnOriginName(const int aIndex);
#endif
    
    // Return the number of columns in the result set returned by the prepared statement
    int GetColumnCount();
    
    /**
     * Return the index to the bind name
     * @param[in]  aName    bind name
     *
     *  return -1 if the column not exist.
     */
    int GetParamIndex(const char* aName);
    
    /**
     * Destroy cipher error.
     * @param[in] aError
     */
    void DestroyError(CipherError* aError);
    
private:
    /**
     * Get Error.
     * @param[in] aErrCode
     * @param[in] aSQLite  database handle
     * return CipherError
     */
    CipherError* GetError(int aErrCode, sqlite3* aSQLite);
    
    /**
     * Check Index.
     * @param[in] aIndex
     * return CipherError
     */
    CipherError* CheckIndex(int aIndex);
        
private:
    sqlite3*                    iSQLite;                //!< Pointer to SQLite Database Connection Handle
    sqlite3_stmt*               iSQLiteStatement;       //!< Pointer to SQLite Statement Object
    int                         iColumnCount;
    std::map<std::string, int>  iColumnNames;
};

#endif /* defined(__AliCipherDB__CipherStatement__) */
