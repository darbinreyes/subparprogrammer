#include <assert.h>

#define MIN_PID 300
#define MAX_PID 5000
#define NUM_PIDS (MAX_PID - MIN_PID + 1)

#define PID_STATE_IS_FREE 0
#define PID_STATE_IS_IN_USE 1

void push(int pid);
int pop(void);
int is_empty(void);
void init(void);

static char pid_state[NUM_PIDS];

/*



*/
int allocate_map(void) {

  // All of this can be done at compile time so we need not worry about its time complexity.
  init();

  for (int i = 0; i < NUM_PIDS; i++) {
    pid_state[i] = PID_STATE_IS_FREE;
    push(i + MIN_PID);
  }

  return 0; // Successful.
}

/*



*/
int allocate_pid(void) {
  int pid;

  if (is_empty()) {
    return -1; // No free PID is available.
  }

  pid = pop(); // Get a free PID from the stack.

  assert(pid >= MIN_PID && pid <= MAX_PID); // Assert that this PID's range is valid.

  assert(pid_state[pid - MIN_PID] == PID_STATE_IS_FREE); // assert that the PID from the stack is indeed free.

  pid_state[pid - MIN_PID] = PID_STATE_IS_IN_USE; // Mark this PID as in use.

  return pid;
}

/*



*/
void release_pid(int pid) {
  if (!(pid >= MIN_PID && pid <= MAX_PID)) { // PID out of range.
    return;
  }

  // A PID that is being released should be currently in use. Return if it is not.
  if(pid_state[pid - MIN_PID] != PID_STATE_IS_IN_USE) {
    return;
  }

  assert(pid_state[pid - MIN_PID] == PID_STATE_IS_IN_USE);

  pid_state[pid - MIN_PID] = PID_STATE_IS_FREE; // Mark this PID as free.

  push(pid); // Push the PID onto the stack.
}

static int free_pid_stack[NUM_PIDS];
static int  stack_next_free = 0;

void push(int pid) {
  assert(stack_next_free < NUM_PIDS); // assert that the stack is not full.
  free_pid_stack[stack_next_free] = pid;
  stack_next_free++;
}

int pop(void) {
  assert(stack_next_free > 0); // assert that the stack is not empty.
  stack_next_free--;
  return free_pid_stack[stack_next_free];
}

int is_empty(void) {
  return (stack_next_free == 0);
}

void init(void) {
  stack_next_free = 0;
}