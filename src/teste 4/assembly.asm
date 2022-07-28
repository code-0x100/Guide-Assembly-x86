bits 64

global assembly
assembly:
  mov rax, 12345
  push rax

  mov rax, 112233
  pop rax
  ret