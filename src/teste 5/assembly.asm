bits 64

global assembly
assembly:
  mov eax, 555
  jmp .end

  mov eax, 333

.end:
  ret