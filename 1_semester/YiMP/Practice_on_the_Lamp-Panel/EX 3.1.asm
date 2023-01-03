mov 0, R0
mov 1, R1
mov 64, R2
n:
   add R1, R0
   add 1, R1
   sub 1, R2
jnz n

