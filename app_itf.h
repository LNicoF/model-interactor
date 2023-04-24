#pragma once
#include "common.h"
#include "object_itf.h"

interface IApp : extends IObject {
    virtual void init() = 0 ;
    virtual void run() = 0 ;
} ;
SET_IID( IApp, 26204 ) ;

IApp* createApp() ;
