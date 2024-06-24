section .data
    msg1 db 'Hello, programmers!', 0
    msg2 db 'Welcome to the world of,', 0
    msg3 db 'Linux assembly programming!', 0

section .text
    global _start

_start:
    ; Print message 1
    mov edx, len1       ; Length of message 1
    mov ecx, msg1       ; Message to print
    call print_string   ; Call function to print message

    ; Print message 2
    mov edx, len2       ; Length of message 2
    mov ecx, msg2       ; Message to print
    call print_string   ; Call function to print message

    ; Print message 3
    mov edx, len3       ; Length of message 3
    mov ecx, msg3       ; Message to print
    call print_string   ; Call function to print message

    ; Exit
    mov eax, 0          ; Exit code (0)
    ret                 ; Return from _start

print_string:
    ; WriteFile function for printing to stdout
    mov eax, -11        ; syscall number for sys_write (WriteFile)
    mov ebx, 1          ; File descriptor (stdout)
    int 0x80            ; Call kernel
    ret                 ; Return from print_string

section .data
    len1 equ $ - msg1   ; Length of message 1
    len2 equ $ - msg2   ; Length of message 2
    len3 equ $ - msg3   ; Length of message 3
