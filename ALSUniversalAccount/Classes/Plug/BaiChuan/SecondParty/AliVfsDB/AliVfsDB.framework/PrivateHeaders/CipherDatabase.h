//
//  CipherDatabase.h
//  AliCipherDBDemo
//
//  Created by Pavel on 15/8/11.
//  Copyright (c) 2015年 Pavel. All rights reserved.
//

#ifndef __AliCipherDB__CipherDatabase__
#define __AliCipherDB__CipherDatabase__

#include "sqlite3.h"
#include "CipherError.h"

class CipherDatabase
{
    friend class CipherStatement;

public:
    /**
     * Constructor
     */
    CipherDatabase();
    
    /**
     * Destructor
     */
    virtual ~CipherDatabase();
    
    /**
     * Open the provided database UTF-8 filename.
     *
     * Uses sqlite3_open_v2() with readonly default flag, which is the opposite behavior
     * of the old sqlite3_open() function (READWRITE+CREATE).
     * This makes sense if you want to use it on a readonly filesystem
     * or to prevent creation of a void file when a required file is missing.
     * 
     * @param[in] apFilename        UTF-8 path/uri to the database file ("filename" sqlite3 parameter)
     * @param[in] aFlags            SQLITE_OPEN_READONLY/SQLITE_OPEN_READWRITE/SQLITE_OPEN_CREATE...
     * @param[in] aBusyTimeoutMs    Amount of milliseconds to wait before returning SQLITE_BUSY (see setBusyTimeout())
     * @param[in] apVfs             UTF-8 name of custom VFS to use, or nullptr for sqlite3 default
     *
     * return NULL if open succeed, or else return CipherError,
     * caller need to call DestroyError to destroy CipherError when CipherError != NULL
     */
    CipherError* Open(const char* apFilename,
                      const int   aFlags         = SQLITE_OPEN_READONLY,
                      const int   aBusyTimeoutMs = 0,
                      const char* apVfs          = NULL);

    /**
     * Close database.
     *
     * return NULL if close succeed, or else return CipherError,
     * caller need to call DestroyError to destroy CipherError when CipherError != NULL
     */
    CipherError* Close();
    
    /**
     * Set the key which is used to encry the database.
     * @param[in] aKey
     * return NULL if succeed, or else return CipherError, 
     * caller need to call DestroyError to destroy CipherError when CipherError != NULL
     */
    CipherError* SetKey(const char* aKey);
    
    /**
     * Remove the key which is used to encry the database.
     * @param[in] aKey
     * return NULL if succeed, or else return CipherError
     * caller need to call DestroyError to destroy CipherError when CipherError != NULL
     */
    CipherError* ReKey(const char* aKey);

    /**
     * Begin the SQLite transaction
     * return NULL if succeed, or else return CipherError
     * caller need to call DestroyError to destroy CipherError when CipherError != NULL
     */
    CipherError* BeginTransaction();
    
    /**
     * Set the SQLite transaction successful
     */
    void SetTransactionSuccessful();

    /**
     * End the SQLite transaction.
     */
    void EndTransaction();
    
    /**
     * Set a busy handler that sleeps for a specified amount of time when a table is locked.
     *
     * This is usefull in multithreaded program to handle case where a table is locked for writting by a thread.
     * Any other thread cannot access the table and will receive a SQLITE_BUSY error:
     * setting a timeout will wait and retry up to the time specified before returning this SQLITE_BUSY error.
     * Reading the value of timeout for current connection can be done with SQL query "PRAGMA busy_timeout;".
     * Default busy timeout is 0ms.
     *
     * @param[in] aBusyTimeoutMs    Amount of milliseconds to wait before returning SQLITE_BUSY
     * return NULL if succeed, or else return CipherError
     * caller need to call DestroyError to destroy CipherError when CipherError != NULL
     */
    CipherError* SetBusyTimeout(const int aBusyTimeoutMs);
    
    /**
     * Shortcut to execute one or multiple statements without results.
     *
     * This is useful for any kind of statements other than the Data Query Language (DQL) "SELECT" :
     *  - Data Manipulation Language (DML) statements "INSERT", "UPDATE" and "DELETE"
     *  - Data Definition Language (DDL) statements "CREATE", "ALTER" and "DROP"
     *  - Data Control Language (DCL) statements "GRANT", "REVOKE", "COMMIT" and "ROLLBACK"
     *     *
     * @param[in] apQueries  one or multiple UTF-8 encoded, semicolon-separate SQL statements
     *
     * return NULL if succeed, or else return CipherError, 
     * caller need to call DestroyError to destroy CipherError when CipherError != NULL
     */
    CipherError* Exec(const char* apStatement);
    
    /**
     * Use transactaion, execute one or multiple statements without results
     * Any statement exec failed, transaction rollback.
     *
     * This is useful for any kind of statements other than the Data Query Language (DQL) "SELECT" :
     *  - Data Manipulation Language (DML) statements "INSERT", "UPDATE" and "DELETE"
     *  - Data Definition Language (DDL) statements "CREATE", "ALTER" and "DROP"
     *  - Data Control Language (DCL) statements "GRANT", "REVOKE", "COMMIT" and "ROLLBACK"
     *     *
     * @param[in] apQueries  one or multiple UTF-8 encoded, semicolon-separate SQL statements
     *
     * return NULL if succeed, or else return CipherError,
     * caller need to call DestroyError to destroy CipherError when CipherError != NULL
     */
    CipherError* ExecBatch(const char* apStatement);
    
    /**
     * Get the filename used to open the database.
     *
     * return the filename used to open the database.
     */
    const std::string GetFilename() const;
    
    /**
     * Get the sqlite3 handle.
     *
     * return the sqlite3 handle.
     */
    sqlite3* GetSQLiteHandle() const;
    
    /**
     * Destroy cipher error.
     * @param[in] aError
     */
    void DestroyError(CipherError* aError);
    
    /**
     * Returns the number of rows modified, inserted or deleted by the most recently completed INSERT, UPDATE or DELETE statement
     * @param[in] bIsMulti=false, one change count; bIsMulti=yes, return iChangeCount, sum of batch change count
     */
    int GetChangeCount(bool bIsMulti);
	
	/**
     * Return the ROWID of the most recent insert
     */
    sqlite3_int64 GetLastInsertRowId();
    
private:
    /**
     * Get Error.
     * @param[in] aErrCode
     * @param[in] aSQLite  database handle
     * return CipherError
     */
    CipherError* GetError(int aErrCode, sqlite3* aSQLite);
    
private:
    sqlite3*                iSQLite;                    //!< Pointer to SQLite Database Connection Handle
    std::string             iFilename;                  //!< UTF-8 filename used to open the database
    bool                    iTransactionSuccessful;
    int                     iChangeCount;               //!< Value of change count after SQLite update >
};

#endif /* defined(__AliCipherDB__CipherDatabase__) */
