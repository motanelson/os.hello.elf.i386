program hello;

{$asmmode intel}
{$apptype console}
{$linklib c} { ← não é usado, mas evita warnings }

const
  SYS_WRITE = 4;
  SYS_EXIT  = 1;
  STDOUT    = 1;

var
  msg: PChar = 'Hello from FPC without libc'#10;

procedure sys_write(fd: longint; buf: PChar; len: longint); assembler; nostackframe;
asm
  mov eax, SYS_WRITE
  mov ebx, fd
  mov ecx, buf
  mov edx, len
  int 80h
end;

procedure sys_exit(code: longint); assembler; nostackframe;
asm
  mov eax, SYS_EXIT
  mov ebx, code
  int 80h
end;

begin
  sys_write(STDOUT, msg, 27);
  sys_exit(0);
end.
