//
//  AliSecXCryptoHelper.h
//  AliSecXCrypto
//
//  Created by jupeng.xia on 14-8-20.
//  Copyright (c) 2014年 alipay. All rights reserved.
//

#ifndef __AliSecXCrypto__AliSecXCryptoHelper__
#define __AliSecXCrypto__AliSecXCryptoHelper__

#include <iostream>
#include "AliSecXBuffer.h"

#define CRYPTO_NUM 46

typedef unsigned char* (*ENCDEC_FuncPtr)(unsigned char*, size_t);

typedef struct st_Processor{
	ENCDEC_FuncPtr enc;
	ENCDEC_FuncPtr dec;
} PROCESSOR;

class CAliSecXCryptoHelper{
public:
	CAliSecXCryptoHelper();
    
    /*
     *功能：对buffer数据进行动态加密
     *线程安全：是
     *可重入：是
     *@return：加密后数据大小
     *@param index:算法随机选取加密算法数组中多个算法对数据进行串联加密，该参数为随机选取的加密算法在数组中的下标，*********必须小于46**********
     *@param index_size:index数组大小
     *@param data:待加密数据
     *@param cipher:密文
     */
	size_t DynEncrypt(int * index, int index_size, const CAliSecXBuffer & data, CAliSecXBuffer & cipher);
    
    /*
     *功能：对密文进行动态解密
     *线程安全：是
     *可重入：是
     *@return：解密后数据大小
     *@param index:加密算法下标数组，应为动态加密index数组的逆序，*********必须小于46********
     *@param index_size:index数组大小
     *@param data:密文
     *@param cipher:解密数据
     */
	size_t DynDecrypt(int * index, int index_size, const CAliSecXBuffer & cipher, CAliSecXBuffer & data);
    
    /*
     *功能：对buffer数据进行动态加密,去除index元素限制
     *线程安全：是
     *可重入：是
     *@return：加密后数据大小
     *@param index:算法随机选取加密算法数组中多个算法对数据进行串联加密，该参数为随机选取的加密算法在数组中的下标
     *@param index_size:index数组大小
     *@param data:待加密数据
     *@param cipher:密文
     */
    size_t DynEncryptEx(int *index, int index_size, const CAliSecXBuffer &data, CAliSecXBuffer &cipher);
    
    /*
     *功能：对密文进行动态解密,去除index元素限制
     *线程安全：是
     *可重入：是
     *@return：解密后数据大小
     *@param index:加密算法下标数组，应为动态加密index数组的逆序
     *@param index_size:index数组大小
     *@param data:密文
     *@param cipher:解密数据
     */
    size_t DynDecryptEx(int *index, int index_size, const CAliSecXBuffer &cipher, CAliSecXBuffer &data);
    
    /*
     *功能：对buffer数据进行aes加密
     *线程安全：是
     *可重入：是
     *@return：加密后数据大小
     *@param key: ********不能小于16字节********
     *@param data:待加密数据
     *@param cipher:密文
     */
    static size_t Encrypt(const CAliSecXBuffer & key, const CAliSecXBuffer & data,
                          CAliSecXBuffer & cipher);
    
    /*
     *功能：对buffer数据进行aes解密
     *线程安全：是
     *可重入：是
     *@return：解密后数据大小
     *@param key:加密时密钥
     *@param cipher:密文
     *@param data:解密数据
     */
	static size_t Decrypt(const CAliSecXBuffer & key, const CAliSecXBuffer & cipher,
                          CAliSecXBuffer & data);
    
    /*
     *功能：利用系统API对buffer数据进行aes解密
     *线程安全：是
     *可重入：是
     *@return：加密后数据大小，失败返回nil
     *@param data:待加密数据
     *@param key:密钥，*******必须大于32字节*******
     */
    static NSData* EncryptAESBySystem(NSData * data, NSString * key);
    
    /*
     *功能：利用系统API对buffer数据进行aes解密
     *线程安全：是
     *可重入：是
     *@return：解密后数据大小，失败返回nil
     *@param data:密文
     *@param key:密钥
     */
    static NSData* DecryptAESBySystem(NSData * data, NSString * key);
   
    /*
     *功能：利用sha1计算数据的签名
     *线程安全：是
     *可重入：是
     *@return：数字签名，20字节
     *@param in:待签名数据
     */
	static CAliSecXBuffer Sha1(const CAliSecXBuffer & in);
    
    /*
     *功能：带密钥的数字签名
     *线程安全：是
     *可重入：是
     *@return：数字签名，20字节
     *@param in:待签名数据
     *@param key:密钥,*********必须小于64字节**********
     */
	static CAliSecXBuffer HmacSha1(const CAliSecXBuffer & in, const CAliSecXBuffer & key);
    
    /*
     *功能：基于hmac的一次性口令
     *线程安全：是
     *可重入：是
     *@return：一次性口令，长度由digits确定，失败返回空buffer
     *@param in:数据
     *@param key:*********unused**********
     *@param key:digits,一次性口令长度，*******必须小于12********
     */
    static CAliSecXBuffer HOTPex(const CAliSecXBuffer & in, const CAliSecXBuffer & key, int digits);
    
    /*
     *功能：生成设备ID
     *线程安全：是
     *可重入：是
     *@return：设备ID，失败返回空
     *@param tag:设备标签
     *@param version:版本号
     *@param rawID:ID数据
     *@param verify:(out)基于前面三个buffer的HOTPex数据
     *@param indexes:用于打乱前三个buffer串联的数据，其长度由count决定，********数组内每个int值应在［tag.size + version.size, tag.size + version.size + rawID.size）之间********
     *@param count:indexes数组长度，同时为verify长度，*******应在[4, 12]之间******
     */
    static CAliSecXBuffer GenerateID(const CAliSecXBuffer & tag, const CAliSecXBuffer & version, const CAliSecXBuffer& rawid, CAliSecXBuffer& verify, int* indexs, int count);
    
    /*
     *功能：对buffer数据进行aes256加密
     *线程安全：是
     *可重入：是
     *@return：加密后数据大小，失败返回nil
     *@param data:待加密数据
     *@param key:密钥，*******必须大于32字节*******
     */
    static NSData *AES256Encrypt(NSData *data, NSString *key);
    
    static NSData *AES256Decrypt(NSData *data, NSString *key);
        
    /*
     *功能：签名数据
     *线程安全：是
     *可重入：是
     *@return：数字签名，20字节
     *@param in:待签名数据
     */
	static CAliSecXBuffer SignData(const CAliSecXBuffer & in);
    
    /*
     *功能：对buffer数据进行aes256解密
     *线程安全：是
     *可重入：是
     *@return：解密后数据大小，失败返回nil
     *@param data:密文
     *@param key:密钥
     */
	static CAliSecXBuffer RandBytes(int bytes);
    
private:
	PROCESSOR processor[CRYPTO_NUM+1];
};

#endif /* defined(__AliSecXCrypto__AliSecXCryptoHelper__) */
