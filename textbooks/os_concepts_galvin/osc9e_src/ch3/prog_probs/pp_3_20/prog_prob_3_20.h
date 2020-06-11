#ifndef _PROG_PROB_3_20_H_
#define _PROG_PROB_3_20_H_

#define MIN_PID 300
#define MAX_PID 5000
#define NUM_PIDS (MAX_PID - MIN_PID + 1)

int allocate_map(void);
int allocate_pid(void);
void release_pid(int pid);

#endif