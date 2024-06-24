section .data
    msg1 db 'Hello, programmers!', 0
    msg2 db 'Welcome to the world of,', 0
    msg3 db 'Linux assembly programming!', 0

section .text
    global _start

_start:
    ; Print message 1
    mov eax, 4          ; Syscall number for sys_write (print)
    mov ebx, 1          ; File descriptor (stdout)
    mov ecx, msg1       ; Message to print
    mov edx, len1       ; Length of message
    int 0x80            ; Call kernel

    ; Print message 2
    mov eax, 4
    mov ebx, 1
    mov ecx, msg2
    mov edx, len2
    int 0x80

    ; Print message 3
    mov eax, 4
    mov ebx, 1
    mov ecx, msg3
    mov edx, len3
    int 0x80

    ; Exit
    mov eax, 1          ; Syscall number for sys_exit (exit)
    xor ebx, ebx        ; Exit status (0)
    int 0x80

section .data
    len1 equ $ - msg1      ; Length of message 1
    len2 equ $ - msg2      ; Length of message 2
    len3 equ $ - msg3      ; Length of message 3
