//
//  CipherError.h
//  AliCipherDBDemo
//
//  Created by Pavel on 15/8/11.
//  Copyright (c) 2015年 Pavel. All rights reserved.
//

#ifndef __AliCipherDB__CipherError__
#define __AliCipherDB__CipherError__

#include <iostream>

#include "CipherCode.h"

class CipherError
{
public:
    /*
     * Constructor
     */
    CipherError();
    
    /*
     * Destructor
     */
    ~CipherError();
    
    /**
     * Return error message according errorCode
     */
    static std::string GetErrMessage(int aErrorCode);
    
public:
    int             code;
    std::string     message;
};

#endif /* defined(__AliCipherDB__CipherError__) */
