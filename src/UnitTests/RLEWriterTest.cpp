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
#include "RLEWriterTest.h"

RLEWriterTest::RLEWriterTest()
{
}

RLEWriterTest::~RLEWriterTest()
{
}

bool RLEWriterTest::run(Globals* g, const vector<string>& args) {
	bool success=true;
	TestDataSrc* src=new TestDataSrc();
	int val=5;
	for (int i=0; i<10; i++) {
		BasicBlock* blck=new BasicBlock(true, true, true);
		blck->setValue(new IntValPos(i, val));
		src->addBlock(blck);
	}

	val++;
	for (int i=10; i<16; i++) {
		BasicBlock* blck=new BasicBlock(true, true, true);
		blck->setValue(new IntValPos(i, val));
		src->addBlock(blck);
	}
	

	RLEWriter* writer=new RLEWriter(src, 0);
	RLEBlock* block=(RLEBlock*) writer->getNextValBlock(0);
	RLETriple* triple=block->getTriple();
	assert(triple->value->type == ValPos::INTTYPE);

	success&=test("Triple Value:", true, *(int*)triple->value->value, 5);
	success&=test("Triple Start Pos:", true, triple->startPos, 0);
	success&=test("Triple Reps:", true, triple->reps, 10);


	block=(RLEBlock*) writer->getNextValBlock(0);
	triple=block->getTriple();
	assert(triple->value->type == ValPos::INTTYPE);

	success&=test("Triple Value:", true, *(int*)triple->value->value, 6);
	success&=test("Triple Start Pos:", true, triple->startPos, 10);
	success&=test("Triple Reps:", true, triple->reps, 6);
	

	return success;	
}
bool RLEWriterTest::test(const char* msg_, bool retBool_, int val_, int exp_) {
	using namespace std;
	if (retBool_) {
		cout << msg_ << " X: " << val_ << "\tE[X]: " << exp_ << " \t";
		if (val_==exp_) {
			cout << "SUCCESS" << endl;
			return true;
		}
		else {
			cout << "FAILED" << endl;
			return false;
		}
		
	}
	else {
		cout << "FAILED (function return failed)" <<  endl;
		return false;
	}	
}

