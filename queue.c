#include "os.h"
#include "kernel.h"

void init_queue(task_queue * q) {
    q->head = NULL;
    q->tail = NULL;
    q->size = 0;
}

void enqueue(task_queue * q, PD * task) {
    if (q->size == 0) {
        q->head = task;
    } else {
        q->tail->next = task;
    }

    q->tail = task;
    task->next = NULL;
    q->size++;
}

PD * deque(task_queue * q) {
    PD * p = NULL;

    if (q->size == 0) {
        return p;
    } else if (q->size == 1) {
        p = q->head;
        q->head = NULL: 
        q->tail = NULL;
        q->size--;
        return p;
    } else {
        p = q->head;
        q->head = p->next;
        q->size--;
        return p;
    }
}

PD * peek(task_queue * q) {
	return q->head;
}

void enqueue_in_offset_order(task_queue * q, PD * task) {
	if (q->size == 0) {
		enqueue(q, task);
        return;
	} else {
		PD * p = q->head;
		PD * prev = NULL;
		while (p != NULL && p->next_start < task->next_start) {
			prev = p;
			p = p->next;
		}

		if (p_prev == NULL) {
			// insert at head
			q->head = task;
			task->next = p;
		} else if (p == NULL) {
			// insert at tail
            q->tail->next = task;
            q->tail = task;
            q->tail->next = NULL;
		} else {
			// insert in middle
			p_prev->next = task;
			task->next = p;
		}

        q->size++;
        return;
	}
}
