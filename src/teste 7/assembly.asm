bits 64

global assembly
assembly:
  mov eax, 3
  call setarA

  ret

setarA:
  mov eax, 5
  ret