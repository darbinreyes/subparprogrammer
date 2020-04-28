// Linked List Add, Remove, Print.

/*

  1. [x] Define Linked List Node Structure. Data = Int.
  2. [x] Implement add.
  3. [x] Implement Print.
  4. [x] Implement remove.
  5. xxx[ ] Generalize Data to store Point Structure.
  6. x[ ] Implement Insert.
  7. [ ] Implement Remove At.
  8. x[ ] Implement Enqueue.
  9. x[ ] Implement Dequeue.

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// typedef
/*
struct _LIST_NODE {
  int data;
  struct _LIST_NODE *next;
};
*/
/*
// Compilation Error.
typedef struct _LIST_NODE {
  int data;
  struct _LIST_NODE *next;
} LIST_NODE;
*/

typedef struct _LIST_NODE LIST_NODE; // "forward declaration"

struct _LIST_NODE {
  int Data;
  LIST_NODE *Next;
};

/**

  Inserts NewNode at the specified Position in the list Head.

  @param[in] Head      The head of the list in which a node will be inserted.
  @param[in] NewNode   The node being inserted.
  @param[in] Position  The position of the insertion. NewNode will be inserted
                       after the node identified by this index. 0 = replaces the
                       head. > length of list replaces tail. Otherwise the
                       insertion occurs between the ith and ith+1 node.

  @return The head of the list. NULL if NewNode is NULL.

**/
LIST_NODE *
ListInsertAt(
  LIST_NODE *Head,
  LIST_NODE *NewNode,
  size_t    Position
  )
{
  LIST_NODE *CurrentNode, *PrevNode;
  size_t i;

  if(NewNode == NULL || Head == NULL) {
    return NULL;
  }

/*
  if(Head->Next == NULL && Position == 0) {
    NewNode->Next = NULL;
    Head->Next = NewNode;
    return Head;
  }
*/

  for(PrevNode = NULL, CurrentNode = Head, i = 0; CurrentNode != NULL && i < Position; PrevNode = CurrentNode, CurrentNode = CurrentNode->Next, i++)
    ;

  if(PrevNode == NULL && CurrentNode == Head) {
    // Head replacement
    NewNode->Next = Head;
    return NewNode;
  }

  if(PrevNode != NULL && CurrentNode == NULL) {
    // Tail add
    NewNode->Next = NULL;
    PrevNode->Next = NewNode;
    return Head;
  }

  // assert(PrevNode != NULL)
  NewNode->Next = CurrentNode;
  PrevNode->Next = NewNode;

  return Head;
}

/**
  Remove the node at the tail of the given list.

  @param[in] Head  The head of the list.
  @param[out] Tail The node that was removed if the list was not empty.

  @return The head of the list or NULL of the list has become empty.
**/
LIST_NODE *
ListRemoveTail(
  LIST_NODE *Head,
  LIST_NODE **RemovedNode
  ) {

  LIST_NODE *CurrentNode;
  LIST_NODE *PrevNode;

  if(RemovedNode == NULL) {
    return NULL;
  }

  if(Head == NULL) {
    return NULL;
  }

  // Case of a single node in list.
  if(Head->Next == NULL) {
    *RemovedNode = Head;
    return NULL;
  }

  // Find the node at the tail of the list and unlink it.
  for(PrevNode = NULL, CurrentNode = Head; CurrentNode->Next != NULL; PrevNode = CurrentNode, CurrentNode = CurrentNode->Next)
    ;

  PrevNode->Next = NULL;
  *RemovedNode = CurrentNode;
  // assert(CurrentNode->Next == NULL)

  return Head;
}

/**
  Remove head node from the given list.

  @param[in]  Head           The head of the list from which to remove the head node.
  @param[out] RemovedNode   The node that was removed if the list wasn't empty or
                            NULL of the list was empty.

  @return  The new head of the list or NULL if the list contained only a single node.

**/
LIST_NODE *
ListRemoveHead(
  LIST_NODE *Head,
  LIST_NODE **RemovedNode
  ) {

  LIST_NODE *NewHead;

  if(RemovedNode == NULL) {
    // Require RemovedNode argument to be non-null.
    return NULL;
  }

  if(Head == NULL) {
    // List is empty. Nothing to do.
    return NULL;
  }

  if(Head->Next == NULL) {
    // List contains only one node.
    *RemovedNode = Head;
    return NULL;
  }

  NewHead = Head->Next;

  Head->Next = NULL; // Unlink the current head node from the list.
  *RemovedNode = Head;
  return NewHead;
}

/**
  Add a new node to the end of the list with the given data. Memory for the node
  is allocated using malloc().

  @param[in] Head  Head of the list. If NULL, a new node will be created and returned.
  @param[in] Data  The data to be stored inside the new node.

  @return  The head of the list. NULL on error.

**/
LIST_NODE *ListAddTail(LIST_NODE *Head, int Data) {
  LIST_NODE *NewNode, *CurrentNode;
  // Handle case of NULL head. Return new node to serve as head.
  if(Head == NULL) {
    Head = malloc(sizeof(*Head));
    if(Head == NULL){
      return NULL;
    }
    Head->Data = Data;
    Head->Next = NULL;
    return Head;
  }

  NewNode = malloc(sizeof(*NewNode));
  if(NewNode == NULL){
    return NULL;
  }

  NewNode->Data = Data;
  NewNode->Next = NULL;

  // Find the end of the list and attach the new node.
  for(CurrentNode = Head; CurrentNode->Next != NULL; CurrentNode = CurrentNode->Next)
    ;

  CurrentNode->Next = NewNode;

  return Head;
}

/*
  Print node data assuming its type is int.
*/
void PrintNodeDataInt(LIST_NODE *Node) {
  printf("%d\n", Node->Data);
}

typedef void (*LIST_NODE_PRINT_CALLBACK)(LIST_NODE *Node);

void ListPrintNodes(LIST_NODE *Head, LIST_NODE_PRINT_CALLBACK PrintCallback) {
  LIST_NODE *CurrentNode;

  if(Head == NULL) {
    printf("List Empty (Head == NULL).\n");
    return;
  }

  for(CurrentNode = Head; CurrentNode != NULL; CurrentNode = CurrentNode->Next) {
    PrintCallback(CurrentNode);
  }
}

int main(void) {
  int a[] = {2, 3, 5, 7, 11, 13};
  size_t c = sizeof(a)/sizeof(int);
  int i;
  LIST_NODE *Head = NULL;
  LIST_NODE *TmpNode = NULL;
  LIST_NODE *NewNode = NULL;

  printf("In Dijkstra I trust.\n");
  for (i = 0; i < c; i++) {
    Head = ListAddTail(Head, a[i]);
  }

  printf("List Created. Printing it.\n");
  ListPrintNodes(Head, PrintNodeDataInt);

  printf("Inserting a node.\n");

  NewNode = malloc(sizeof(*NewNode));

  if(NewNode == NULL) {
    printf("malloc returned NULL. Bye.\n");
    return 1;
  }

  NewNode->Next = NULL;
  NewNode->Data = 17;

  Head = ListInsertAt(Head, NewNode, 2);

  printf("Inserted in list. Printing it.\n");
  ListPrintNodes(Head, PrintNodeDataInt);

  printf("Removing nodes.\n");
  /*
  while((Head = ListRemoveHead(Head, &TmpNode)) != NULL || TmpNode != NULL) {
    if(TmpNode != NULL) {
      PrintNodeDataInt(TmpNode);
      free(TmpNode);
      TmpNode = NULL;
    }
  }
  */

  while((Head = ListRemoveTail(Head, &TmpNode)) != NULL || TmpNode != NULL) {
    if(TmpNode != NULL) {
      PrintNodeDataInt(TmpNode);
      free(TmpNode);
      TmpNode = NULL;
    }
  }
  return 0;
}