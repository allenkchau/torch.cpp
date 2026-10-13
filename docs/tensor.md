A tensor is really just a single continuous block of memory laid out in a 1D array. The reason we can have multidimensional tensors is that we have attached metadata that defines how to view that memory as a multi-dimensional grid.

By default, tensors are allocated in row-major order. This just means the computer stores entires rows back to back (all elements of row 1, then row 2 etc.). Because of this, there is high spatial locality for reading across a row since processors load data from main memory in chunks. For tensors with >=3 dimensions we just flatten the array by moving from the leftmost dimension to the rightmost dimension and the rightmost dimension changes the fastest in memory (still row-major order).

ex: we have a 3D tensor of BxHxW. We want to get the element at index (i, j, k). In the memory that would retrive index:
(i * H * W) + (j * W) + k


One important piece of metadata is the stride. The stride is just a tuple of numbers that tells the computer how many elements to skip in the raw 1D storage to move 1 step along a specific dimension.

Here is the formula. To find the memory index of any element at position (dim0, dim1, dim2, ...) the computer calculates:
memory idx = storage offset + summation(index in dimension * stride of dimension)

The storage offset is where the tensor's data begins in the memory block.
The shape is just the geometry which is self-explained. And then we also keep track of whether the tensor is contiguous or non-contiguous.

How do we know if the memory of a tensor is contiguous?
When a computer flattens a multi-dimensional tensor into a 1D strip, it fills out the entire last dimension first, then steps up the second to last dimension etc.
There must be zero memory gaps when moving between any of the outer dimensions (each stride is perfectly calculated from the shape of the dimensions inside it).
For contiguity, the stride of any dimension d must be equal to the stride of the next dimension (d+1 which is 1 to the right) multiplied by the shape of that next dimension. 

stride[d] = stride[d+1] (how long is 1 step in dimension d+1) * shape[d+1] (how many steps are there to take in dimension d+1) -> this gives us how many steps total to complete a single hop in dimension d

Another condition is that there must be a stride of 1 in the last dimension.


Now lets look at an example. Imagine we have a 2D tensor with shape (3, 2) containing the numbers 1 through 6.

2D view:
[[1, 2],
 [3, 4],
 [5, 6]]

 Raw 1D storage: [1, 2, 3, 4, 5, 6]

 To navigate the 1D array as a 3x2 matrix, the system assigns a stride of (2, 1).
 This means that to move down 1 row we skip 2 elements in raw memory and to move right 1 column we skip 1 element in raw memory.

 Lets say we want to access the element at Row 2, Column 1 which has the value 6.
 Index = (2 * row stride) + (1 * column stride) = 5, and looking at position 5 in the raw storage gives us 6.

 Many tensor ops can be performed in constant time because we don't have to copy any data in memory. For example, for the reshpae op we just chang ethe shape and strides mathematically as long as the total number of elements matches and the memory is contiguous. We don't have to touch the raw storage at all. And for the transpose op, we just swap the strides and the shapes of the target dimensions while storage is untourched again.
