#include "chunk.h"
#include "debug.h"

int main(void) {
    Chunk chunk;
    initChunk(&chunk);

    writeConstant(&chunk, 1.2, 1);
    writeChunk(&chunk, OP_RETURN, 1);
    disassembleChunk(&chunk, "test chunk");

    freeChunk(&chunk);
    return 0;
}