//
//  AliSecXURL.h
//  AliSecXCrypto
//
//  Created by jupeng.xia on 14-8-23.
//  Copyright (c) 2014年 alipay. All rights reserved.
//

#ifndef __AliSecXCrypto__AliSecXURL__
#define __AliSecXCrypto__AliSecXURL__

#include <string>
#include "AliSecXBuffer.h"

class CAliSecXURL
{
public:
    /*
     *功能：对URI中的二进制字节及某些ascii字符进行编码
     *线程安全：是
     *可重入：是
     *@return：编码后字符串
     *@param input:待编码的URI
     */
    static std::string encodeURIComponent(CAliSecXBuffer& input);
    
    /*
     *功能：对编码后的URI进行解码
     *线程安全：是
     *可重入：是
     *@return：解码后的URI
     *@param input:待解码的URI
     */
    static CAliSecXBuffer decodeURIComponent(const std::string & input);
};

#endif /* defined(__AliSecXCrypto__AliSecXURL__) */
