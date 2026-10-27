#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TIntBuffer {
    int* data;
    size_t size;
    size_t capacity;
} TIntBuffer;

// buffer owns its allocation; size <= capacity, data[0..size) is initialized.
// On allocation failure the buffer remains unchanged.
int BufferPush(TIntBuffer* buffer, int value) {
    if (buffer->size == buffer->capacity) {
        size_t newCapacity = 2;
        if (buffer->capacity != 0) {
            if (buffer->capacity > SIZE_MAX / 2) {
                return 0;
            }
            newCapacity = buffer->capacity * 2;
        }
        if (newCapacity > SIZE_MAX / sizeof(*buffer->data)) {
            return 0;
        }
        int* resized = realloc(buffer->data, newCapacity * sizeof(*buffer->data));
        if (resized == NULL) {
            return 0;
        }
        buffer->data = resized;
        buffer->capacity = newCapacity;
    }
    buffer->data[buffer->size] = value;
    ++buffer->size;
    return 1;
}

int main(void) {
    TIntBuffer buffer = {0};
    for (int value = 10; value <= 50; value += 10) {
        if (!BufferPush(&buffer, value)) {
            free(buffer.data);
            return 1;
        }
        printf("size=%zu capacity=%zu\n", buffer.size, buffer.capacity);
    }
    printf("data:");
    for (size_t i = 0; i < buffer.size; ++i) {
        printf(" %d", buffer.data[i]);
    }
    printf("\n");
    free(buffer.data);
    return 0;
}
