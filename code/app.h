#pragma once
#include "common.h"
#include "app_itf.h"
#include "interactor_itf.h"
#include "adder_itf.h"

class App : implements IApp {
    int refCount ;

    IAdder*      model ;
    IInteractor* interactor ;

    DISABLE_COPY( App ) ;
public:
    App() : refCount( 1 ) {
        model      = createAdder() ;
        interactor = createInteractor( model ) ;
    }

    virtual ~App() {
        interactor->release() ;
        model->release() ;
        LOG_DESTRUCTION( App ) ;
    }

    virtual void acquire() {
        ++refCount ;
    }

    virtual void release() {
        --refCount ;
        if ( refCount == 0 )
            delete this ;
    }

    virtual IObject* request( const uint& iid ) {
        if ( iid == Iid< IObject >::getIid() )
            return this ;
        if ( iid == Iid< IApp >::getIid() )
            return this ;
        return nullptr ;
    }

    virtual void init() {
        interactor->init() ;
    }

    virtual void run() {
        interactor->edit() ;
    }
} ;
