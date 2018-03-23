#ifndef __AliCipherDB_CipherDBCommon__
#define __AliCipherDB_CipherDBCommon__

#define DEFAULT_VERSION 0

/**
 * GetOldVersion  get the current version of the database 
 *
 * @param[in] cipherDBHandle the cipherDB handle
 * @param[out] errorCode the error code 
 *
 * @returns  the current version of the database 
 */

int GetOldVersion(CipherDatabase* cipherDBHandle, int& errorCode);

/**
 * UpdateVersion update the version of the database  
 *
 * @param[in] cipherDBHandle the cipherDB handle
 * @param[in] newVersion the new version
 * @return    errorCode
 */
int UpdateVersion(CipherDatabase* cipherDBHandle, int newVersion);

#endif /* define(__AliCipherDB_CipherDBCommon__) */
