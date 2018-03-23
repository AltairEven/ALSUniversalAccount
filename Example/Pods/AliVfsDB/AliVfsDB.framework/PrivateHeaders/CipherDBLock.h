#ifndef __AliCipherDB_CipherDBLock__
#define __AliCipherDB_CipherDBLock__

#include <mutex>

class CipherDBLock
{
public:
    /**
     * Lock  start the lock
     */
    void Lock();

    /**
     * Unlock stop the lock
     */
    void Unlock();
    
private:
    /**
     *  the lock
     */
    std::mutex mu;
};


#endif /* define(__AliCipherDB_CipherDBLock__) */
