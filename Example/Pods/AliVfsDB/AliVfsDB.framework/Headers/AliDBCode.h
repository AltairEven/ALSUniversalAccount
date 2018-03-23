//
//  AliDBCode.h
//  AliDBCenter
//
//  Created by Pavel on 16/3/16.
//  Copyright © 2016年 Pavel. All rights reserved.
//

#ifndef AliDBCode_h
#define AliDBCode_h

// 自定义错误码
#define ALIDB_ERR_NONE                       0
#define ALIDB_ERR_NONE_MESSAGE               @"Successful"

#define ALIDB_ERR_GENERAL                    -1
#define ALIDB_ERR_GENERAL_MESSAGE            @"General error"

#define ALIDB_ERR_ARGUMENT                   -2
#define ALIDB_ERR_ARGUMENT_MESSAGE           @"Input argument error"

#define ALIDB_ERR_HANDLE                     -3
#define ALIDB_ERR_HANDLE_MESSAGE             @"Handle is NULL"

#define ALIDB_ERR_NOCODEC                    -4
#define ALIDB_ERR_NOCODEC_MESSAGE            @"SQLITE_HAS_CODEC undefined"

#define ALIDB_ERR_OPEN                       -5
#define ALIDB_ERR_OPEN_MESSAGE               @"Data base is already open"

#define ALIDB_ERR_TRANSACTION                -6
#define ALIDB_ERR_TRANSACTION_MESSAGE        @"A transaction is in progress"

#define ALIDB_ERR_JVM                        -7
#define ALIDB_ERR_JVM_MESSAGE                @"JVM error"

#define ALIDB_ERR_VERSION                    -8
#define ALIDB_ERR_VERSION_MESSAGE            @"The AliVfsDB new version is lower than the old version"

#define ALIDB_ERR_CLOSED                     -9
#define ALIDB_ERR_CLOSED_MESSAGE             @"The db is closed, please open first"

#define ALIDB_ERR_EXTPROCESS                 -10
#define ALIDB_ERR_EXTPROCESS_MESSAGE         @"SQLExt process exception"

#define ALIDB_ERR_NOT_SUPPORTED              -11
#define ALIDB_ERR_NOT_SUPPORTED_MESSAGE      @"The operation is not supported"

#define ALIDB_ERR_UNDEFINED_MESSAGE          @"Undefined error"

// SQLite错误码
#define ALIDB_SQLITE_ERROR                   1
#define ALIDB_SQLITE_ERROR_MESSAGE           @"SQL error or missing database"

#define ALIDB_SQLITE_INTERNAL                2
#define ALIDB_SQLITE_INTERNAL_MESSAGE        @"Internal logic error in SQLite"

#define ALIDB_SQLITE_PERM                    3
#define ALIDB_SQLITE_PERM_MESSAGE            @"Access permission denied"

#define ALIDB_SQLITE_ABORT                   4
#define ALIDB_SQLITE_ABORT_MESSAGE           @"Callback routine requested an abort"

#define ALIDB_SQLITE_BUSY                    5
#define ALIDB_SQLITE_BUSY_MESSAGE            @"The database file is locked"

#define ALIDB_SQLITE_LOCKED                  6
#define ALIDB_SQLITE_LOCKED_MESSAGE          @"A table in the database is locked"

#define ALIDB_SQLITE_NOMEM                   7
#define ALIDB_SQLITE_NOMEM_MESSAGE           @"A malloc() failed"

#define ALIDB_SQLITE_READONLY                8
#define ALIDB_SQLITE_READONLY_MESSAGE        @"Attempt to write a readonly database"

#define ALIDB_SQLITE_INTERRUPT               9
#define ALIDB_SQLITE_INTERRUPT_MESSAGE       @"Operation terminated by sqlite3_interrupt()"

#define ALIDB_SQLITE_IOERR                   10
#define ALIDB_SQLITE_IOERR_MESSAGE           @"Some kind of disk I/O error occurred"

#define ALIDB_SQLITE_CORRUPT                 11
#define ALIDB_SQLITE_CORRUPT_MESSAGE         @"The database disk image is malformed"

#define ALIDB_SQLITE_NOTFOUND                12
#define ALIDB_SQLITE_NOTFOUND_MESSAGE        @"Unknown opcode in sqlite3_file_control()"

#define ALIDB_SQLITE_FULL                    13
#define ALIDB_SQLITE_FULL_MESSAGE            @"Insertion failed because database is full"

#define ALIDB_SQLITE_CANTOPEN                14
#define ALIDB_SQLITE_CANTOPEN_MESSAGE        @"Unable to open the database file"

#define ALIDB_SQLITE_PROTOCOL                15
#define ALIDB_SQLITE_PROTOCOL_MESSAGE        @"Database lock protocol error"

#define ALIDB_SQLITE_EMPTY                   16
#define ALIDB_SQLITE_EMPTY_MESSAGE           @"Database is empty"

#define ALIDB_SQLITE_SCHEMA                  17
#define ALIDB_SQLITE_SCHEMA_MESSAGE          @"The database schema changed"

#define ALIDB_SQLITE_TOOBIG                  18
#define ALIDB_SQLITE_TOOBIG_MESSAGE          @"String or BLOB exceeds size limit"

#define ALIDB_SQLITE_CONSTRAINT              19
#define ALIDB_SQLITE_CONSTRAINT_MESSAGE      @"Abort due to constraint violation"

#define ALIDB_SQLITE_MISMATCH                20
#define ALIDB_SQLITE_MISMATCH_MESSAGE        @"Data type mismatch"

#define ALIDB_SQLITE_MISUSE                  21
#define ALIDB_SQLITE_MISUSE_MESSAGE          @"Library used incorrectly"

#define ALIDB_SQLITE_NOLFS                   22
#define ALIDB_SQLITE_NOLFS_MESSAGE           @"Uses OS features not supported on host"

#define ALIDB_SQLITE_AUTH                    23
#define ALIDB_SQLITE_AUTH_MESSAGE            @"Authorization denied"

#define ALIDB_SQLITE_FORMAT                  24
#define ALIDB_SQLITE_FORMAT_MESSAGE          @"Auxiliary database format error"

#define ALIDB_SQLITE_RANGE                   25
#define ALIDB_SQLITE_RANGE_MESSAGE           @"2nd parameter to sqlite3_bind out of range"

#define ALIDB_SQLITE_NOTADB                  26
#define ALIDB_SQLITE_NOTADB_MESSAGE          @"File is encrypted or is not a database"

#define ALIDB_SQLITE_NOTICE                  27
#define ALIDB_SQLITE_NOTICE_MESSAGE          @"Notifications from sqlite3_log()"

#define ALIDB_SQLITE_WARNING                 28
#define ALIDB_SQLITE_WARNING_MESSAGE         @"Warnings from sqlite3_log()"

#define ALIDB_SQLITE_ROW                     100
#define ALIDB_SQLITE_ROW_MESSAGE             @"sqlite3_step() has another row ready"

#define ALIDB_SQLITE_DONE                    101
#define ALIDB_SQLITE_DONE_MESSAGE            @"sqlite3_step() has finished executing"

#endif /* AliDBCode_h */
