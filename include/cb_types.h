/**
 * node.h
 * Author: Charly Batista
 * Date: 2021-05-28
 **/

#ifndef __CB_TYPES_H
#define __CB_TYPES_H
#if defined __STDC__ && defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
#include <stdbool.h>
#endif

typedef enum __attribute__ ((__packed__))
{
    CB_OK            = 0,
    CB_ERR_MEM_INIT  = -1,
    CB_ERR_NULL      = -2,
    CB_ERR_GENERIC   = -99
} CB_RETURN;

#ifdef bool
typedef bool CB_BOOL;
#define CB_TRUE true
#define CB_FALSE false
#else
typedef enum __attribute__ ((__packed__))
{
    CB_TRUE          = 1,
    CB_FALSE         = 0
} CB_BOOL;
#endif


#endif // __CB_TYPES_H
