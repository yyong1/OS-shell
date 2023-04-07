# OS-shell
Project of basic shell implementation 

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