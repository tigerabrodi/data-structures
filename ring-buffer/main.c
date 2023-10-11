#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // for malloc and free

typedef struct
{
	int *buffer;	   // Pointer to the storage of data items
	int capacity;	   // Max number of items the buffer can hold
	int size;	   // Number of items currently in the buffer
	int write_pointer; // Index where the next element will be written
	int read_pointer;  // Index from where the next element will be read
} RingBuffer;

RingBuffer *init_ringbuffer(int capacity)
{
	// 1. Allocate space for the RingBuffer structure.
	//    - Use `malloc` to allocate memory of size `sizeof(RingBuffer)`.
	//    - Store the returned pointer in a variable, say `rb`.

	// 2. Check if the memory allocation succeeded.
	//    - If `rb` is NULL, then memory allocation failed.

	// 3. Assign the 'capacity' to the RingBuffer's field.
	//    - `rb->capacity` should get the value of the 'capacity' parameter.

	// 4. Allocate memory for the data buffer.
	//    - Use `malloc` to allocate memory of size `capacity * sizeof(int)`.
	//    - Assign the returned pointer to `rb->buffer`.

	// 5. Check if the memory allocation for buffer succeeded.

	// 6. Initialize buffer's metadata.
	//    - Set `rb->size` to 0.
	//    - Set both `rb->read_pointer` and `rb->write_pointer` to 0.

	// 7. Return the `rb` pointer.
}

bool write_ringbuffer(RingBuffer *rb, int data)
{
	// 1. Check if the buffer is full.
	//    - If `rb->size` equals `rb->capacity`, the buffer is full.

	// 2. If the buffer is full, return false.
	//    - Indicating the data cannot be written to the buffer.

	// 3. Write the data.
	//    - Assign `data` to `rb->buffer` at the index `rb->write_pointer`.

	// 4. Update the write_pointer.
	//    - Increment `rb->write_pointer` by 1.
	//    - Use the modulo operation with `rb->capacity` to ensure wrapping around.

	// 5. Increment the size.
	//    - Increase `rb->size` by 1.

	// 6. Return true, indicating data was added successfully.
}

bool read_ringbuffer(RingBuffer *rb, int *data)
{
	// 1. Check if the buffer is empty.
	//    - If `rb->size` is 0, buffer is empty.

	// 2. If the buffer is empty, return false.
	//    - Indicating no data is available for reading.

	// 3. Read data from the buffer.
	//    - Assign value at `rb->buffer[rb->read_pointer]` to the memory location `data` is pointing to.

	// 4. Update the read_pointer.
	//    - Increment `rb->read_pointer` by 1.
	//    - Use the modulo operation with `rb->capacity` to ensure wrapping around.

	// 5. Decrement the size.
	//    - Decrease `rb->size` by 1.

	// 6. Return true, indicating data was read successfully.
}

void free_ringbuffer(RingBuffer *rb)
{
	// 1. Free the buffer's memory.
	//    - Use `free` function to deallocate `rb->buffer`.

	// 2. Free the memory occupied by the RingBuffer structure.
	//    - Use `free` function to deallocate `rb`.
}

int main()
{
	// Test the ring buffer

	// 1. Create a ring buffer with a capacity of 5
	RingBuffer *rb = init_ringbuffer(5);

	// 2. Write some values to it
	for (int i = 0; i < 5; i++)
	{
		if (!write_ringbuffer(rb, i + 1))
		{
			printf("Buffer full. Couldn't write %d\n", i + 1);
		}
	}

	// 3. Try writing when buffer is full
	if (!write_ringbuffer(rb, 6))
	{
		printf("Buffer full. Couldn't write 6\n");
	}

	// 4. Read values from the buffer
	int value;
	for (int i = 0; i < 5; i++)
	{
		if (read_ringbuffer(rb, &value))
		{
			printf("Read %d from buffer\n", value);
		}
		else
		{
			printf("Buffer empty\n");
		}
	}

	// 5. Try reading when buffer is empty
	if (!read_ringbuffer(rb, &value))
	{
		printf("Buffer empty. Couldn't read\n");
	}

	// 6. Free the ring buffer
	free_ringbuffer(rb);

	return 0;
}
