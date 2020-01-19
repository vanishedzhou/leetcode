//
// Created by Zhou,Zhiyong(DAPD) on 2018/12/26.
//

#include <iostream>
#include <pthread>

#include <pthread.h>
#include <cstdio>
#include <cstdlib>
#include <assert.h>
#include <stdint.h>

__thread uint64_t pkey = 0;

void run2( )
{
    FILE* fp = NULL;

    if( !pkey )
    {
        char fName[128] = "";
        sprintf( fName, "thread%lu.log", static_cast<unsigned long>( pthread_self() ) );
        fp   = fopen( fName, "w" );
        pkey = reinterpret_cast<uint64_t>( fp );

    }else fp = reinterpret_cast<FILE*>( pkey );

    fprintf( fp, "hello __thread 2\n" );
    return ;
}

void* run1( void* arg )
{
    FILE* fp = NULL;

    if( !pkey )
    {
        char fName[128] = "";
        sprintf( fName, "thread%lu.log", static_cast<unsigned long>( pthread_self() ) );
        fp   = fopen( fName, "w" );
        pkey = reinterpret_cast<uint64_t>( fp );

    }else fp = reinterpret_cast<FILE*>( pkey );

    fprintf( fp, "hello __thread 1\n" );

    run2();

    return NULL;
}

int main(int argc, char const *argv[])
{
    char fName[128] = "";
    sprintf( fName, "thread%lu.log", static_cast<unsigned long>( pthread_self() ) );
    FILE* fp = fopen( fName, "w" );
    pkey = reinterpret_cast<uint64_t>( fp );
    fprintf( fp, "hello __thread\n" );

    pthread_t threads[2];
    pthread_create( &threads[0], NULL, run1, NULL );
    pthread_create( &threads[1], NULL, run1, NULL );
    pthread_join( threads[0], NULL );
    pthread_join( threads[1], NULL );
    return 0;
}
