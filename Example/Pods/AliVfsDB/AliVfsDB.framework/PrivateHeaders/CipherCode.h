//
//  CipherCode.h
//  AliCipherDBDemo
//
//  Created by Pavel on 16/1/5.
//  Copyright © 2016年 Pavel. All rights reserved.
//

#ifndef CipherCode_h
#define CipherCode_h

// 自定义错误码
#define CIPHERDB_ERR_NONE                       0
#define CIPHERDB_ERR_NONE_MESSAGE               "Successful"

#define CIPHERDB_ERR_GENERAL                    -1
#define CIPHERDB_ERR_GENERAL_MESSAGE            "General error"

#define CIPHERDB_ERR_ARGUMENT                   -2
#define CIPHERDB_ERR_ARGUMENT_MESSAGE           "Input argument error"

#define CIPHERDB_ERR_HANDLE                     -3
#define CIPHERDB_ERR_HANDLE_MESSAGE             "Handle is NULL"

#define CIPHERDB_ERR_NOCODEC                    -4
#define CIPHERDB_ERR_NOCODEC_MESSAGE            "SQLITE_HAS_CODEC undefined"

#define CIPHERDB_ERR_OPEN                       -5
#define CIPHERDB_ERR_OPEN_MESSAGE               "Data base is already open"

#define CIPHERDB_ERR_TRANSACTION                -6
#define CIPHERDB_ERR_TRANSACTION_MESSAGE        "A transaction is in progress"

#define CIPHERDB_ERR_JVM                        -7
#define CIPHERDB_ERR_JVM_MESSAGE                "JVM error"

#define CIPHERDB_ERR_VERSION                    -8
#define CIPHERDB_ERR_VERSION_MESSAGE            "The CipherDB new version is lower than the old version"

#define CIPHERDB_ERR_CLOSED                     -9
#define CIPHERDB_ERR_CLOSED_MESSAGE             "The db is closed, please open first"

#define CIPHERDB_ERR_UNDEFINED_MESSAGE          "Undefined error"

// SQLite错误码
#define CIPHERDB_SQLITE_ERROR                   1
#define CIPHERDB_SQLITE_ERROR_MESSAGE           "SQL error or missing database"

#define CIPHERDB_SQLITE_INTERNAL                2
#define CIPHERDB_SQLITE_INTERNAL_MESSAGE        "Internal logic error in SQLite"

#define CIPHERDB_SQLITE_PERM                    3
#define CIPHERDB_SQLITE_PERM_MESSAGE            "Access permission denied"

#define CIPHERDB_SQLITE_ABORT                   4
#define CIPHERDB_SQLITE_ABORT_MESSAGE           "Callback routine requested an abort"

#define CIPHERDB_SQLITE_BUSY                    5
#define CIPHERDB_SQLITE_BUSY_MESSAGE            "The database file is locked"

#define CIPHERDB_SQLITE_LOCKED                  6
#define CIPHERDB_SQLITE_LOCKED_MESSAGE          "A table in the database is locked"

#define CIPHERDB_SQLITE_NOMEM                   7
#define CIPHERDB_SQLITE_NOMEM_MESSAGE           "A malloc() failed"

#define CIPHERDB_SQLITE_READONLY                8
#define CIPHERDB_SQLITE_READONLY_MESSAGE        "Attempt to write a readonly database"

#define CIPHERDB_SQLITE_INTERRUPT               9
#define CIPHERDB_SQLITE_INTERRUPT_MESSAGE       "Operation terminated by sqlite3_interrupt()"

#define CIPHERDB_SQLITE_IOERR                   10
#define CIPHERDB_SQLITE_IOERR_MESSAGE           "Some kind of disk I/O error occurred"

#define CIPHERDB_SQLITE_CORRUPT                 11
#define CIPHERDB_SQLITE_CORRUPT_MESSAGE         "The database disk image is malformed"

#define CIPHERDB_SQLITE_NOTFOUND                12
#define CIPHERDB_SQLITE_NOTFOUND_MESSAGE        "Unknown opcode in sqlite3_file_control()"

#define CIPHERDB_SQLITE_FULL                    13
#define CIPHERDB_SQLITE_FULL_MESSAGE            "Insertion failed because database is full"

#define CIPHERDB_SQLITE_CANTOPEN                14
#define CIPHERDB_SQLITE_CANTOPEN_MESSAGE        "Unable to open the database file"

#define CIPHERDB_SQLITE_PROTOCOL                15
#define CIPHERDB_SQLITE_PROTOCOL_MESSAGE        "Database lock protocol error"

#define CIPHERDB_SQLITE_EMPTY                   16
#define CIPHERDB_SQLITE_EMPTY_MESSAGE           "Database is empty"

#define CIPHERDB_SQLITE_SCHEMA                  17
#define CIPHERDB_SQLITE_SCHEMA_MESSAGE          "The database schema changed"

#define CIPHERDB_SQLITE_TOOBIG                  18
#define CIPHERDB_SQLITE_TOOBIG_MESSAGE          "String or BLOB exceeds size limit"

#define CIPHERDB_SQLITE_CONSTRAINT              19
#define CIPHERDB_SQLITE_CONSTRAINT_MESSAGE      "Abort due to constraint violation"

#define CIPHERDB_SQLITE_MISMATCH                20
#define CIPHERDB_SQLITE_MISMATCH_MESSAGE        "Data type mismatch"

#define CIPHERDB_SQLITE_MISUSE                  21
#define CIPHERDB_SQLITE_MISUSE_MESSAGE          "Library used incorrectly"

#define CIPHERDB_SQLITE_NOLFS                   22
#define CIPHERDB_SQLITE_NOLFS_MESSAGE           "Uses OS features not supported on host"

#define CIPHERDB_SQLITE_AUTH                    23
#define CIPHERDB_SQLITE_AUTH_MESSAGE            "Authorization denied"

#define CIPHERDB_SQLITE_FORMAT                  24
#define CIPHERDB_SQLITE_FORMAT_MESSAGE          "Auxiliary database format error"

#define CIPHERDB_SQLITE_RANGE                   25
#define CIPHERDB_SQLITE_RANGE_MESSAGE           "2nd parameter to sqlite3_bind out of range"

#define CIPHERDB_SQLITE_NOTADB                  26
#define CIPHERDB_SQLITE_NOTADB_MESSAGE          "File is encrypted or is not a database"

#define CIPHERDB_SQLITE_NOTICE                  27
#define CIPHERDB_SQLITE_NOTICE_MESSAGE          "Notifications from sqlite3_log()"

#define CIPHERDB_SQLITE_WARNING                 28
#define CIPHERDB_SQLITE_WARNING_MESSAGE         "Warnings from sqlite3_log()"

#define CIPHERDB_SQLITE_ROW                     100
#define CIPHERDB_SQLITE_ROW_MESSAGE             "sqlite3_step() has another row ready"

#define CIPHERDB_SQLITE_DONE                    101
#define CIPHERDB_SQLITE_DONE_MESSAGE            "sqlite3_step() has finished executing"

#endif /* CipherCode_h */
