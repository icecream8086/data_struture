# GDB模拟输入文本

> 使用gdb自动输入文本调试信息

```bash
# pwsh
C:.
│   .gitignore
│   a.exe
│   License
│   main.c
│   main.exe [debugger file]
│   main.o
│   Makefile
│   mock_input.txt [input file]
│   note.md
│
└───.vscode
        settings.json
        tasks.json

```

```bash
gcc -g -o main.exe main.c
gdb .\main.exe
break main
run < .\mock_input.txt
```
