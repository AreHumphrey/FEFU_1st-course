mov 0, r0
mov 9, r1
mov 1, r2
mov 1, r3

nop

mov r1, r0
shl 6, r1
shl 4, r0
add r0, r1
shr 4, r0
shl 4, r0
add r0, r1
shr 4, r0
shl 2, r0
add r0, r1

nop

mov r2, r0
shl 3, r0
shl 1, r2
add r0, r2

nop

mov 0, r0
add r1, r0
add r2, r0
add r3, r0

stop
