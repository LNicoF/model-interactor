#pragma once
#include "common.h"
#include "interactor_itf.h"
#include "model_itf.h"
#include "reader_itf.h"
#include "writer_itf.h"

class Interactor : implements IInteractor {
    int refCount ;

    IModel* model ;

    IReader* reader ;
    IWriter* writer ;

    DISABLE_COPY( Interactor ) ;
public:
    Interactor( IModel* rModel ) : refCount( 1 ), model( rModel ) {
        model->acquire() ;
        reader = createReader() ;
        writer = createWriter() ;
    }

    virtual ~Interactor() {
        writer->release() ;
        reader->release() ;
        model->release() ;
        LOG_DESTRUCTION( Interactor ) ;
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
        if ( iid == Iid< IInteractor >::getIid() )
            return this ;
        return nullptr ;
    }

    virtual void init() ;
    virtual void edit() ;
} ;
