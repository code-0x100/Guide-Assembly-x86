bits 64

global assembly
assembly:
  mov eax, 0

  mov rbx, 7
  mov rcx, 5
  cmp rbx, rcx
  jle .end

.end:
  ret