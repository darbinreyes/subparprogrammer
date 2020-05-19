// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED

#include <assert.h>
#include <stdlib.h> // for malloc

#define NUM_CELLS 8
#define LEFT_MOST_CELL 0
#define RIGHT_MOST_CELL (NUM_CELLS - 1)
#define LEFT_NEIGHBOR(CellIndex) (CellIndex - 1)
#define RIGHT_NEIGHBOR(CellIndex) (CellIndex + 1)
#define CELL_ACTIVE   1
#define CELL_INACTIVE 0

/* Update states to next day. */
void UpdateToNextDay(int *CurrentDayBuffer, int *NextDayBuffer) {
    int Index;

    for(Index = 0; Index < NUM_CELLS; Index++) {
        if(Index != LEFT_MOST_CELL && Index != RIGHT_MOST_CELL) {
            NextDayBuffer[Index] = (CurrentDayBuffer[LEFT_NEIGHBOR(Index)] == CurrentDayBuffer[RIGHT_NEIGHBOR(Index)]);
        } else if(Index == LEFT_MOST_CELL) {
            NextDayBuffer[Index] = (CELL_INACTIVE == CurrentDayBuffer[RIGHT_NEIGHBOR(Index)]);
        } else if(Index == RIGHT_MOST_CELL) {
            NextDayBuffer[Index] = (CurrentDayBuffer[LEFT_NEIGHBOR(Index)] == CELL_INACTIVE);
        } else {
            assert(0); // Should never occur!
        }
    }
}
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
boundedarray* cellCompete(int* states, int days)
{
    int *next_states, *tmp_states; // match variable naming style of "states" argument.
    int DayIndex;
    boundedarray *result;

    // WRITE YOUR CODE HERE
    // I might be able to avoid a malloc by returning the filnal result in states. But I'm not sure if test code would get fucked up by that. Use malloc to be safe.

    // Handle invalid args.
    if(states == NULL) {
        return NULL;
    }

    if(days < 0) {
        return NULL;
    }

    result = malloc(sizeof(boundedarray));

    if(result == NULL) {
        // malloc error, bail.
        assert(0);
        return NULL;
    }

    next_states = malloc(sizeof(int) * NUM_CELLS);

    if(next_states == NULL) {
        // malloc error, bail.
        assert(0);
        return NULL;
    }

    memcpy(next_states, states, sizeof(int) * NUM_CELLS); // handle if days == 0

    // Update states for the specified number of days.
    for(DayIndex = 0; DayIndex < days; DayIndex++) {
        UpdateToNextDay(states, next_states);
        // swap the state buffers so that the current day's states buffer will become the next day's states buffer
        if(DayIndex < days - 1) { // Don't swap on the last day since we don't need to perform an additional state update.
          tmp_states = states;
          states = next_states;
          next_states = tmp_states;
        }
        // after single day, we should return next states.
    }
    // woops! - use given return struct.
    result->size = NUM_CELLS;
    result->arr = next_states;
    return result;
}
// FUNCTION SIGNATURE ENDS