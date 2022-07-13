## Register allocation
Look at https://cfallin.org/blog/2022/06/09/cranelift-regalloc2/

## Allocator
Instead of using standard containers such as ``std::vector`` or ``std::list``, the L9 uses custom 
allocator. The allocator is can be used for small and large elements as well. The code is is 
``include/lib`` directory.