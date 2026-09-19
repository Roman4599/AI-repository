# AI: Preemptive Bug Fixing

## Task
Use a role-based prompt (Senior C Developer) to review a vulnerable C function `add_node_end` that adds a node to the end of a singly linked list, then fix it.

## Files
- initial_code.c: the original vulnerable function
- refactored_code.c: the corrected function

## AI tool used
Gemini

## Prompt used
I asked Gemini to act as a Senior C Developer with 15 years of experience and review the function for (1) logical errors when adding a node to a non-empty list and (2) memory and error handling problems (missing NULL checks, memory leaks, uninitialized fields). I asked for a numbered list of flaws and the complete corrected function with comments.

## Flaws found
1. Logical error: `while (current)` runs past the last node, and `current = new_node;` never links the new node to the list.
2. Missing NULL check after `malloc`, which can cause a segmentation fault.
3. Fields `n` and `next` were not initialized before the early return for an empty list.
4. Memory leak: the new node was never linked, so it became unreachable.

## Analysis of the Logical Fix
The loop `while (current)` only stops when current becomes NULL, so current has already moved past the last node. The line `current = new_node;` only changes the local pointer and never updates the last node's next field, so the new node is never linked. The fix is to stop on the last node with `while (current->next)` and link with `current->next = new_node;`.

## Analysis of the Memory Fix
`malloc` returns NULL when allocation fails. Without a check, `new_node->n = n;` would write to a NULL address and cause a segmentation fault. The fix is `if (new_node == NULL) return (NULL);` right after `malloc`. Linking the node correctly also removes the memory leak.
