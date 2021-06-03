/**
 * node.h
 * Author: Charly Batista
 * Date: 2021-05-28
 **/

#ifndef __CB_TYPES_H
#define __CB_TYPES_H

typedef enum 
{
    CB_OK            = 0,
    CB_ERR_MEM_INIT  = -1,
    CB_ERR_NULL      = -2,
    CB_ERR_GENERIC   = -99
} CB_RETURN;

typedef enum
{
    CB_TRUE          = 1,
    CB_FALSE         = 0
} CB_BOOL;



#endif // __CB_TYPES_H
