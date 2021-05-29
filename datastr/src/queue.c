/**
 * Queue implementation
 * Author: Charly Batista
 * Date: 2021-05-28
 **/

/**
 * Functions:
 *  - enqueue
 *  - dequeue
 *  - queueFront
 *  - queueRear
 *  - queueCount
 *  - emptyQueue
 *  - fullQueue
 *
 **/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "cb_utils.h"

void cb_queue_destroy(CB_QUEUE *queue)
{
    if(queue != (CB_QUEUE *)NULL)
    {
        cb_list_destroy(queue->front);
        queue->front = NULL;
        queue->rear = NULL;
        free(queue);
    }
}

CB_RETURN cb_queue_create(CB_QUEUE **queue)
{
    CB_QUEUE *nq;
    CB_RETURN ret;

    nq = (CB_QUEUE *)malloc(sizeof nq);
    if(nq == (CB_QUEUE *)NULL)
        return CB_ERR_MEM_INIT;

    nq->count = 0;
    nq->front = NULL;
    nq->rear  = NULL;
    *queue = nq;

    return CB_OK;
}

CB_RETURN cb_queue_enqueue(CB_QUEUE *queue, CB_NODE *node)
{
    if(queue == (CB_QUEUE *)NULL)
        return CB_ERR_NULL;

    if(queue->count == 0)
    {
        queue->front = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->count++;

    return CB_OK;
}

// CB_RETURN (*cb_add_node)(void **node, char *value)
CB_RETURN cb_queue_enqueue2(void **queue, char *value)
{
    CB_QUEUE *nq;
    CB_NODE *node;
    CB_RETURN ret;

    if((CB_QUEUE **)queue == (CB_QUEUE **)NULL)
        return CB_ERR_NULL;

    nq = (CB_QUEUE *)*queue;
    if(nq == (CB_QUEUE *)NULL)
        cb_queue_create(&nq);

    if(ret = cb_node_initialize((void **)&node))
        return ret;

    if(ret = cb_node_add_value(node, value))
        return ret;

    if(ret = cb_queue_enqueue(nq, node))
        return ret;

    return CB_OK;
}