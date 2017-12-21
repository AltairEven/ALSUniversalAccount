//
//  AliSecXBuffer.h
//  AliSecXCrypto
//
//  Created by jupeng.xia on 14-8-20.
//  Copyright (c) 2014年 alipay. All rights reserved.
//

#ifndef __AliSecXCrypto__AliSecXBuffer__
#define __AliSecXCrypto__AliSecXBuffer__


#import <CoreFoundation/CoreFoundation.h>

#ifndef BYTE
typedef unsigned char BYTE;
#endif

class CAliSecXBuffer {
public:
	CAliSecXBuffer(void);
	~CAliSecXBuffer(void);
	CAliSecXBuffer(const unsigned char* pData, size_t size);
	CAliSecXBuffer(const char* pData);
	CAliSecXBuffer(const CAliSecXBuffer& rhs);
	CAliSecXBuffer& operator=(const CAliSecXBuffer& rhs);
	CAliSecXBuffer(size_t size);
    
	BYTE getAt(size_t i) const;
	int setAt(size_t i, unsigned char c);
	CAliSecXBuffer& append(const CAliSecXBuffer& tail);
    
	char* c_str(void) const {
		return (char*) pData_;
	}
	BYTE* pb(void) const {
		return pData_;
	}
	size_t size() const {
		return nSize_;
	}
	void resize(size_t);
    
	void clear(void);
	//size_t readFromFile(const char* fileName);
	//size_t writeToFile(const char* fileName);
    
	bool compare(const CAliSecXBuffer& rhs);
	void release(void);
    
	CAliSecXBuffer toStringBuffer();
    
protected:
	void _copy(const unsigned char* pData, size_t size);
	unsigned char* pData_;
	size_t nSize_;
};

int Hex2Bin(char* in, size_t inlen, unsigned char* out, size_t & outlen);

int Bin2Hex(const unsigned char* in, size_t inlen, char* out, size_t & outlen);

CAliSecXBuffer alisec_crypto_Hex2Bin(const CAliSecXBuffer& in);

CAliSecXBuffer alisec_crypto_Bin2Hex(const CAliSecXBuffer& in);

CAliSecXBuffer alisec_crypto_EncodeBase64(const CAliSecXBuffer& in);

CAliSecXBuffer alisec_crypto_DecodeBase64(const CAliSecXBuffer& in);

void alisec_crypto_DumpBuffer(const CAliSecXBuffer & buf);

CAliSecXBuffer alisec_crypto_NSData2Buffer(NSData* data);

NSData* alisec_crypto_Buffer2NSData(const CAliSecXBuffer& buf);

//CAliSecXBuffer NSString2Buffer(NSString* str);

//NSString* Buffer2NSString(const CAliSecXBuffer& buf);


#endif /* defined(__AliSecXCrypto__AliSecXBuffer__) */
