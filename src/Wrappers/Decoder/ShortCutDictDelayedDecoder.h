/* Copyright (c) 2005, Regents of Massachusetts Institute of Technology, 
 * Brandeis University, Brown University, and University of Massachusetts 
 * Boston. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice, 
 *     this list of conditions and the following disclaimer.
 *   - Redistributions in binary form must reproduce the above copyright 
 *     notice, this list of conditions and the following disclaimer in the 
 *     documentation and/or other materials provided with the distribution.
 *   - Neither the name of Massachusetts Institute of Technology, 
 *     Brandeis University, Brown University, or University of 
 *     Massachusetts Boston nor the names of its contributors may be used 
 *     to endorse or promote products derived from this software without 
 *     specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED 
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR 
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, 
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
// Decodes Int pages

#ifndef _SHORTCUTDICTDELAYEDDECODER_H_
#define _SHORTCUTDICTDELAYEDDECODER_H_

#include "IntDecoder.h"
#include "../Util/IntReader.h"
#include "../Util/ByteReader.h"
#include "../MultiBlock.h"
#include "../DictByteBlock.h"
#include "../DictShortBlock.h"
#include "../../common/Constants.h"

class ShortCutDictDelayedDecoder : public IntDecoder
{
public:
	ShortCutDictDelayedDecoder(bool valSorted_);
	ShortCutDictDelayedDecoder(byte* buffer_, bool valSorted_);
	ShortCutDictDelayedDecoder(ShortCutDictDelayedDecoder& decoder_); 
	virtual ~ShortCutDictDelayedDecoder();
	
	virtual void setBuffer(byte* buffer_);
	virtual int getPageLengthBits();
	//virtual Block* peekNextBlock();
	//virtual Block* getNextBlock();
	//virtual Block* getNextBlockSingle();

protected:

	unsigned int* fieldSizePtr;
	int numvalsperint;
	int fieldBytes;
	unsigned int realsize;
	DictByteBlock* db1;
	DictShortBlock* db2;
	
};

#endif //_SHORTCUTDICTDELAYEDDECODER_H_
