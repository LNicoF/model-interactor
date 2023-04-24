#pragma once
#include "common.h"
#include "interactor_itf.h"
#include "adder_itf.h"
#include "reader_itf.h"
#include "writer_itf.h"

class Interactor : implements IInteractor {
    int refCount ;

    IAdder* model ;

    IReader* reader ;
    IWriter* writer ;

    DISABLE_COPY( Interactor ) ;
public:
    Interactor( IAdder* rModel ) : refCount( 1 ), model( rModel ) {
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

    virtual void init() {
        int currentValue = model->value() ;
        writer->write( currentValue ) ;
    }

    virtual void edit() {
        int input ;
looper:
        input = reader->read() ;
        if ( input != 0 ) {
            writer->write( model->add( input ) ) ;
            goto looper ;
        }
    }
} ;
