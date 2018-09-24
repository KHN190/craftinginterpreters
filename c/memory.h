//> Chunks of Bytecode memory-h
#ifndef clox_memory_h
#define clox_memory_h

//> Strings memory-include-object
#include "object.h"

//< Strings memory-include-object
//> Strings allocate
#define ALLOCATE(type, count) \
    (type*)reallocate(NULL, 0, sizeof(type) * (count))
//> free

#define FREE(type, pointer) \
    reallocate(pointer, sizeof(type), 0)
//< free

//< Strings allocate
#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2)
//> grow-array

#define GROW_ARRAY(previous, type, oldCount, count) \
    (type*)reallocate(previous, sizeof(type) * (oldCount), \
        sizeof(type) * (count))
//> free-array

#define FREE_ARRAY(type, pointer, oldCount) \
    reallocate(pointer, sizeof(type) * (oldCount), 0)
//< free-array

void* reallocate(void* previous, size_t oldSize, size_t newSize);
//< grow-array
//> Garbage Collection not-yet

void grayObject(Obj* object);
void grayValue(Value value);
void collectGarbage();
//< Garbage Collection not-yet
//> Strings free-objects-h
void freeObjects();
//< Strings free-objects-h

#endif
