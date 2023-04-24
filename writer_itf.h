#pragma once
#include "common.h"
#include "object_itf.h"

interface IWriter : extends IObject {
    virtual void write( int n ) = 0 ;
} ;
SET_IID(IWriter, 8531) ;

IWriter* createWriter() ;
