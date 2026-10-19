#include <stdio.h>

#include "chunk.h"
#include "debug.h"
#include "vm.h"

int main(void) {
    initVM();
    Chunk chunk;
    initChunk(&chunk);

    writeConstant(&chunk, 1.2, 1);
    writeChunk(&chunk, OP_RETURN, 1);
    disassembleChunk(&chunk, "test chunk");

    Value result;
    if (interpret(&chunk, &result) != INTERPRET_OK) {
        freeChunk(&chunk);
        freeVM();
        return 1;
    }
    printf("Result: ");
    printValue(result);
    printf("\n");

    freeChunk(&chunk);
    freeVM();
    return 0;
}