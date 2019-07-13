– List of relevant files: client.c, server.c, client, server, newFile.txt, a1.txt


– Compilation instructions: executable files are already generated. 
If you want to recompile, use the command gcc file.c -o filename. Requires two terminal windows.
When executing, MAKE SURE YOU START THE SERVER FIRST OTHERWISE IT WILL FAIL.
If an error is detected, or you want to end the program, or the program crashes (unlikely)
the server program may take a few minutes to let go of the socket. 
Can take anywhere between 1-5 minutes. If it is taking a while, close and reopen terminal. 
If this does not, open activity monitor and end processes remotely (called server, and client).

– Configuration file(s): If your code uses any configuration file(s), describe the format of such file(s)
clearly. Also include in the directory some example configuration files.
No Configuration files required. The first text file contains text, 
the second can be used to create an optional second, with whatever text you choose.

– Running instructions: You may be generating more than one executable. Describe logically what each
executable does. In addition, for each such executable file, how should one run it? What are the
command line arguments (describe each argument)?
Two executables are required: server and client. Use ./server and ./client (in that order).
No command line arguments are required, both programs take user input. 