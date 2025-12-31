# Chapter 3: Debugging C++ Programs

## Code

* `debug.cpp`: Print error messages to `cerr`
* `main.cpp`: Code to play with a debugger

## Using a Debugger

* When debugging a program, don't enable compiler optimizations, as the compiler may change the program structure in ways that make “source-level” debugging misleading.

Here are some concepts that are universal across debuggers and IDEs.

### Stepping

Stepping means executing statements line by line. There are three modes:

1. **Step into**: Execute the next line/statement. If it calls a function, the debugger enters that function and stops at its first line.

2. **Step over**: Execute the next line/statement. If it calls a function, the function runs, but the debugger does not enter it; it stops at the next line in the current function after the call returns.

3. **Step out**: Continue running until the current function returns; the debugger then stops back in the caller at the line after the call site.

### Running and Breakpoints

1. **Run to cursor**: Execute the program until execution reaches the statement selected by your cursor. Then it returns control to you so you can debug starting at that point.

2. **Continue**: Continues running the program as per normal, either until the program terminates, or until something triggers control to return back to you again (e.g., breakpoints).

3. **Start**: Same as continue, just starting from the beginning of the program. It can only be invoked when not already in a debug session.

4. **Breakpoints**: A breakpoint is a marker you set on a line of code that tells the debugger to pause execution when the program reaches that line in a debug session. Unlike Run to Cursor, which is a one-time action to continue until a selected line, breakpoints stay in place until you remove or disable them. You can also set multiple breakpoints throughout the program.

5. **Set next**: Change the point of execution to some other statement ("jump"). The set next statement command will change the point of execution, but will not otherwise change the program state. Your variables will retain whatever values they had before the jump. So this is different from "step back".

### Watching Variables

Some debuggers provide tools to inspect program state, such as a Watch window where you can track expressions or variables as you step through code. 

Many debuggers also support watchpoints (data breakpoints), which pause execution when a specific variable or memory location is modified (and sometimes when it is accessed).

**Local Watches**: Because inspecting the value of local variables inside a function is common while debugging, many debuggers will offer some way to quickly watch the value of all local variables in scope.

### Call Stack

The debugger often provides a debugger that shows the current call stack.

## Using LLDB on CLI

On macOS, LLDB is the "default" debugger.

1. First, check if LLDB is installed.

```bash!
lldb --version
```

2. Compile with debug symbols (and no optimization).

```bash!
clang++ -g -O0 main.cpp -o main
```

3. Launch LLDB

```bash!
lldb ./main
```

## Using LLDB on VS Code

1. First, check if LLDB is installed.

```bash!
lldb --version
```

2. Add CodeLLDB extension. 

Add CodeLLDB by Vadim Chugunov. VS Code provides the debugging UI, and LLDB is the backend. CodeLLDB is the glue between the two.

3. Configure VS Code (LLDB)

When you start debugging in VS Code (Run and Debug → Start Debugging or press F5), VS Code typically runs a build task to compile your code, then launches the resulting executable under LLDB.

To enable this workflow, we have to configure `tasks.json` and `launch.json`:

* `tasks.json`: defines the build command VS Code should run (e.g., a clang++ compile).
  * Open / edit `tasks.json`: `Cmd+Shift+P` → Tasks: Configure Task (or Tasks: Open User Tasks / Tasks: Open Workspace Tasks if it already exists).

* `launch.json`: defines how to run/debug the program (which executable, working directory, args), and can trigger the build first via preLaunchTask.
  * Open / edit `launch.json`: `Cmd+Shift+P` → Debug: Open `launch.json` (or Debug: Add Configuration… and select LLDB / CodeLLDB).