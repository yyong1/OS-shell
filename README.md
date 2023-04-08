# OS-shell
Project of basic shell implementation by Andrey Baranov

<h1>Project: Shell</h1>

Purpose: The purpose of this project is to familiarize you with the mechanics of process control
through the implementation of a shell user interface. This includes the relationship between
child and parent processes, the steps needed to create a new process, shell variables, and an
introduction to user-input parsing and verification.


Task 1.1: The shell (command line) is just a program that continually asks for user input,
perhaps does something on the user’s behalf, resets itself, and again asks for user input. Design
and implement a basic shell interface that supports the execution of other programs and a
series of built-in functions. The shell should be robust (e.g., it should not crash under any
circumstance beyond machine failure).

- Basic: The prompt should look like this:
prompt$
- Advanced: The prompt should look like this:
machinename@username:~$
Where machinename and username should change depending on the machine and user.

Task 1.2: Shell programs/commands.
- Basic: Implement the basic functionality of the following programs: mv, du, date, rev

Task 1.3: System calls.
- Basic: Within the C-programming example of your choice, implement the following system calls:
fork(), wait(), and exec().
- Intermediate: Within the C-programming example of your choice, implement waitpid(),
execvpe().

Task 1.4: Add some colors to your shell 

Task 1.5: Provide a concise and descriptive answer to the following questions.
Q1: What is the purpose of the fork() system call?
Q2: Explain the following code snippet and write down the list of process state transitions that
occur during the following program. You may assume that this is the only process that the CPU
is executing.


<h3>COMMENTS:<h3>

<h4>Task 1.2<h4> 
has implemented all of the basic functions (cd, mv, du, date, rev) as well as an additional "art" command. To execute the "art" command, you should have a .jpg file in the same directory as shell-main.c (or type the path to the .jpg file like /Users/username/myshellProj/myimg.jpg). If you encounter any issues, simply install jp2a to your computer using the command "sudo port install jp2a".

<h4>Task 1.5<h4>
- 1) Creating new processes in unix is achieved through the use of fork.When fork is called a duplicate of the current process is createdd with its own address space. This feature enables several tasks to run independently of one another, as if they had exclusive access to the machines full memory.
Some instances where fork is commonly used:
The shell utilizes fork to execute programs invoked from the command line.
Apache servers use fork to create several server processes, each of which manages requests within its individual address space In case one process crashes or leaks memory  others remain unaffected thus providing fault tolerance.
Google Chrome uses fork to handle each page within its unique process. 
Fork is utilized in some parallel programs to spawn processes this differs from using threads which lack their own address space and coexist within a process.
Scripting languages indirectly use fork to initiate child processes.

- 2) The given code initializes an integer variable i with a value of 1 The code then enters a while loop with the condition that i is less than 100 In each iteration of the loop i is incremented by 1 until i becomes equal to 100. After exiting the loop the program prints the value of i which is 100.

Next the program enters another while loop with the condition that i is greater than 0 In each iteration of the loop i is decremented by 1 until i becomes equal to 0 after exiting the loop the program prints the value of i which is 0.

State transitions that occur 

Initially the process is in the running state as it is the only process being executed by the CPU.
When the first while loop is entered, the process transitions to the running state again.
Within the first while loop the process executes the increment operation on the i variable,this operation takes a small amount of time and doesnt cause any transitions.
After the increment operation the process returns to the beginning of the loop to check the loop condition, If the condition is true the process enters the loop again and transitions to the running state. If the condition is false, the process exits the loop and returns to the running state.
After exiting the first while loop the process executes the first print f statement and transitions to the running state again. 
The process then enters the second while loop and transitions to the running state again.
Within the second while loop the process executes the decrement operation on the i variable, this operation takes a small amount of time and doesnt cause any transitions.
After the decrement operation the process returns to the beginning of the loop to check the loop condition, If the condition is true the process enters the loop again and transitions to the runningr state. If the condition is false, the process exits the loop and returns to the running state.
After exiting the second while loop the process executes the second print f statement and transitions to the terminated state.

