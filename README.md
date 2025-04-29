# Simple Shell Project

![Shell Banner](https://i.pinimg.com/736x/bc/d9/1a/bcd91aa57fd4d13c5f4e1581404c1d74.jpg)

## 📝 Overview

This project is a simple implementation of a UNIX command-line interpreter (shell) as part of the ALX Software Engineering program. Our shell, called `hsh` (Holberton Shell), is designed to mimic the basic functionality of the `/bin/sh` shell.

## 🛠️ Features

- Display a prompt and wait for the user to type a command
- Execute commands with their arguments
- Handle the PATH to find executable programs
- Support for built-in commands: `exit`, `env`, `cd`, `help`
- Handle command lines with arguments
- Support for logical operators (`&&` and `||`)
- Support for comments using `#`
- Handle variables replacement (`$?` and `$$`)
- Handle the command separator `;`

## 🚀 Installation

Clone this repository:

```bash
git clone https://github.com/yourusername/simple_shell.git
cd simple_shell
```

Compile the shell:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## 💻 Usage

### Interactive Mode

```bash
$ ./hsh
($) /bin/ls
file1 file2 directory/
($) pwd
/home/user/simple_shell
($) exit
$
```

### Non-Interactive Mode

```bash
$ echo "/bin/ls" | ./hsh
file1 file2 directory/
$
$ cat commands.txt | ./hsh
# Output of commands in commands.txt
```

## 📋 List of Built-in Commands

| Command | Description |
|---------|-------------|
| `exit [status]` | Exit the shell with optional status code |
| `env` | Print the current environment variables |
| `cd [directory]` | Change the current directory |
| `help [command]` | Display help information for built-in commands |
| `setenv VARIABLE VALUE` | Initialize or modify an environment variable |
| `unsetenv VARIABLE` | Remove an environment variable |

## 📁 Project Files

| File | Description |
|------|-------------|
| `main.c` | Entry point for the shell program |
| `shell.h` | Header file with all function prototypes |
| `parser.c` | Functions for parsing user input |
| `executor.c` | Functions for executing commands |
| `builtins.c` | Implementation of built-in commands |
| `path_handler.c` | Functions for handling the PATH |
| `string_helpers.c` | Helper functions for string manipulation |
| `memory_handlers.c` | Functions for memory management |
| `error_handlers.c` | Functions for error handling |

## ✨ Examples

```bash
$ ./hsh
($) ls -la
total 112
drwxr-xr-x   9 user user  4096 May  2 14:10 .
drwxr-xr-x   4 user user  4096 May  2 12:32 ..
drwxr-xr-x   8 user user  4096 May  2 14:01 .git
-rw-r--r--   1 user user   159 May  2 12:32 .gitignore
-rw-r--r--   1 user user  1078 May  2 12:32 AUTHORS
-rw-r--r--   1 user user  2142 May  2 12:32 README.md
-rw-r--r--   1 user user  2370 May  2 14:10 builtins.c
-rw-r--r--   1 user user  2679 May  2 14:09 executor.c
-rwxr-xr-x   1 user user 40144 May  2 14:10 hsh
-rw-r--r--   1 user user  1592 May  2 14:01 main.c
-rw-r--r--   1 user user  2255 May  2 14:03 parser.c
-rw-r--r--   1 user user  1831 May  2 14:04 path_handler.c
-rw-r--r--   1 user user  1867 May  2 14:02 shell.h
-rw-r--r--   1 user user  2110 May  2 14:05 string_helpers.c

($) echo "Hello World"
Hello World

($) exit
$
```

## ⚡ Man Page

A manual page for the shell is available. Use the following command to view it:

```bash
$ man ./man_1_simple_shell
```

## 🔄 Flowchart

```
+-------------------+
|  Start Program    |
+-------------------+
         |
         v
+-------------------+
|  Display Prompt   |<--------------+
+-------------------+               |
         |                          |
         v                          |
+-------------------+               |
|   Read Command    |               |
+-------------------+               |
         |                          |
         v                          |
+-------------------+               |
|   Parse Command   |               |
+-------------------+               |
         |                          |
         v                          |
+-------------------+               |
|  Is it Built-in?  |--Yes-->+      |
+-------------------+        |      |
         | No               v      |
         v            +-------------+
+-------------------+ | Execute     |
| Search in PATH    | | Built-in    |
+-------------------+ +-------------+
         |                  |
         v                  |
+-------------------+       |
| Found command?    |--No-->+
+-------------------+       |
         | Yes             |
         v                 |
+-------------------+      |
|  Fork Process     |      |
+-------------------+      |
         |                 |
         v                 |
+-------------------+      |
|  Execute Command  |      |
+-------------------+      |
         |                 |
         v                 |
+-------------------+      |
| Wait for Child    |      |
+-------------------+      |
         |                 |
         v                 |
+-------------------+      |
| Exit command?     |--Yes-+
+-------------------+
         | No
         +------------------+
```

## 🧪 Testing

To test the shell, run the following command:

```bash
$ ./tests/check_simple_shell.bash
```

## 👥 Authors

* **Your Name** - [GitHub Profile](https://github.com/yourusername)
* **Team Member Name** - [GitHub Profile](https://github.com/teammember)

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

* ALX Software Engineering Program
* Holberton School Staff
* All the peers who provided feedback during the development

## 📝 Notes

For any additional information or questions, please contact the authors.
