A tensor is really just a single continuous block of memory laid out in a 1D array. The reason we can have multidimensional tensors is that we have attached metadata that defines how to view that memory as a multi-dimensional grid.

One of the pieces of metadata is the stride. The stride is just a tuple of numbers that tells the computer how many elements to skip in the raw 1D storage to move 1 step along a specific dimension.

Here is the formula. To find the memory index of any element at position (dim0, dim1, dim2, ...) the computer calculates:
memory idx = summation(index in dimension * stride of dimension)

Imagine we have a 2D tensor with shape (3, 2) containing the numbers 1 through 6.

