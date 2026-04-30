    .text
    .globl sum_array
    .type sum_array, @function

# int sum_array(const int *arr, int n)
# %rdi = arr
# %rsi = n
# return in %eax

sum_array:
    xorl    %eax, %eax        # sum = 0
    xorl    %ecx, %ecx        # i = 0

    testq   %rsi, %rsi        # if (n <= 0) return 0
    jle     .done

.loop:
    addl    (%rdi,%rcx,4), %eax   # sum += arr[i]
    incq    %rcx                 # i++
    cmpq    %rsi, %rcx           # i < n ?
    jl      .loop

.done:
    ret
.section .note.GNU-stack,"",@progbits
