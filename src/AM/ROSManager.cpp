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
//#include <iostream>
#include <fstream>
#include <sstream>
#include <strstream>
#include <iterator>
#include <algorithm>
#include <db_cxx.h>
#include <vector>

#include "ROSManager.h"

ROSManager::ROSManager( string table_, int numColumns )
{
  _table = CatalogInstance::stripOffDirectory( table_ );
  cout << "Creating ROSManager from " << table_ << endl;

  _numColumns = numColumns;
  /*
  _db_ros = new Db( NULL, 0 );
  _db_wos = new Db( NULL, 0 );

  _db_ros->set_bt_compare( ROSAM::compare_int );
  _db_wos->set_bt_compare( ROSAM::compare_int );
  
  _db_ros->set_error_stream( &cout );
  _db_wos->set_error_stream( &cout );


  _db_ros->set_cachesize( 0, SMALL_CACHE_SIZE/5, 1 ); // 5Mb cache
  _db_ros->set_pagesize( 4096 );

  _db_wos->set_cachesize( 0, SMALL_CACHE_SIZE/5, 1 ); // 5Mb cache
  _db_wos->set_pagesize( 4096 );
  */
  //initCursors();
}

ROSManager::~ROSManager()
{
  // What goes here?
}

ROSAM* ROSManager::getROSAM( int colNum )
{
  cout << " Getting a ROSAM from ROSManager " << _fName << endl;
  //WOSAM* wm = new WOSAM( table, _numindicies, _numColumns, colNum, rwseg );
  cerr << "ROSManager: getROSAM not implemented" << endl;
  throw AccessException( "Not implemented" );

  return NULL;
}

string ROSManager::toString()
{
	return string("This is a ROSManager reporting ") + 
	  string( " name? " );
}

int ROSManager::getLastStorageKey()
{
  cerr << "Throw AccessException, NOT IMPLEMENTED " <<endl;
  throw UnimplementedException(" NOT IMPLEMENTED ");
}

/*int ROSManager::getLastPosition( bool ros )
{
  if (!ros) {
    return rwseg->getLastPosition();
  } else {
    //throw UnimplementedException(" NOT IMPLEMENTED ");
    CatalogInstance* pCI = new CatalogInstance();
    ROSAM* pROS = pCI->getROSAM(table, pCI->getPrimaryColumnName(table));
    int lastPosition = pROS->getLastIndexValuePrimary();
    delete pROS;
    delete pCI;
    return lastPosition;
  }
}*/

/*int ROSManager::getLastValue( bool ros )
{
  if (!ros) {
    return rwseg->getLastValue();
  } else {
    //throw UnimplementedException(" NOT IMPLEMENTED ");
    CatalogInstance* pCI = new CatalogInstance();
    ROSAM* pROS = pCI->getROSAM(_fName, pCI->getPrimaryColumnName(_fName));
    int lastValue = pROS->getLastIndexValueSecondary();
    delete pROS;
    delete pCI;
    return lastValue;
  }
}*/
