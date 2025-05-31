# school42_cursus
Cursus of School 42 from 2024 November. The git connected with school 42 is my another github account: [ISDouglas](https://github.com/ISDouglas/Ecole42_Cursus#) , which is more frequently pushed.

List of projects finished:

00_libft (finished with 125/125)
Here is your content rewritten as a GitHub-style `README.md` in English, using Markdown with color indicators for each category via emoji (since GitHub Markdown does not support color text directly):

---

# 📚 Libft Function Overview

This repository contains the implementation of common C standard library functions, utility functions, and linked list operations as part of the `libft` project. Below is a categorized list of functions and their corresponding standard C library headers or classifications.

---

## 🟩 `<stdlib.h>` — Standard Library

| Function    | Description                                       |
| ----------- | ------------------------------------------------- |
| `ft_atoi`   | Convert string to int (`atoi`)                    |
| `ft_calloc` | Allocate zero-initialized memory (`calloc`)       |
| `ft_itoa`   | Convert int to string (custom, similar to `itoa`) |

---

## 🟦 `<string.h>` — String & Memory Functions

| Function     | Description                                   |
| ------------ | --------------------------------------------- |
| `ft_bzero`   | Zero out memory (`bzero`, POSIX)              |
| `ft_memchr`  | Find character in memory block                |
| `ft_memcmp`  | Compare memory blocks                         |
| `ft_memcpy`  | Copy memory block                             |
| `ft_memmove` | Move memory block (handles overlap)           |
| `ft_memset`  | Fill memory block                             |
| `ft_strchr`  | Find first occurrence of char in string       |
| `ft_strdup`  | Duplicate string (`strdup`, POSIX)            |
| `ft_strjoin` | Join two strings (custom)                     |
| `ft_strlcat` | Append string with size limit (BSD extension) |
| `ft_strlcpy` | Copy string with size limit (BSD extension)   |
| `ft_strlen`  | Get string length                             |
| `ft_strncmp` | Compare strings with size limit               |
| `ft_strnstr` | Locate substring within limit (BSD extension) |
| `ft_strrchr` | Find last occurrence of char in string        |

---

## 🟨 `<unistd.h>` — File Descriptor Output

| Function        | Description                                |
| --------------- | ------------------------------------------ |
| `ft_putchar_fd` | Output char to file descriptor (`write`)   |
| `ft_putstr_fd`  | Output string to file descriptor           |
| `ft_putendl_fd` | Output string + newline to file descriptor |
| `ft_putnbr_fd`  | Output number to file descriptor           |

---

## 🟥 `<ctype.h>` — Character Type Checks

| Function     | Description               |
| ------------ | ------------------------- |
| `ft_isalnum` | Alphanumeric check        |
| `ft_isalpha` | Alphabetic check          |
| `ft_isascii` | ASCII value check         |
| `ft_isdigit` | Digit check               |
| `ft_isprint` | Printable character check |
| `ft_tolower` | Convert to lowercase      |
| `ft_toupper` | Convert to uppercase      |

---

## 🟧 Custom Utility Functions

These functions are not directly from standard libraries and are implemented from scratch.

| Function      | Description                                         |
| ------------- | --------------------------------------------------- |
| `ft_split`    | Split string by delimiter char                      |
| `ft_striteri` | Apply function to each character (in-place)         |
| `ft_strmapi`  | Map function to each character (returns new string) |
| `ft_strtrim`  | Trim characters from start and end                  |
| `ft_substr`   | Extract substring from string                       |

---

## 🟪 Bonus — Linked List Utilities

These functions handle operations on a custom `t_list` singly linked list structure.

| Function          | Description                                |
| ----------------- | ------------------------------------------ |
| `ft_lstnew`       | Create new list node                       |
| `ft_lstadd_front` | Add node to the front of the list          |
| `ft_lstsize`      | Get size of the list                       |
| `ft_lstlast`      | Get last node in the list                  |
| `ft_lstadd_back`  | Add node to the end of the list            |
| `ft_lstdelone`    | Delete a single node                       |
| `ft_lstclear`     | Clear and free the entire list             |
| `ft_lstiter`      | Iterate over list and apply function       |
| `ft_lstmap`       | Map function over list and create new list |

---

## 📌 Summary

| Header/File  | Covered Functions                 |
| ------------ | --------------------------------- |
| `<stdlib.h>` | `ft_atoi`, `ft_calloc`, `ft_itoa` |
| `<string.h>` | Memory and string operations      |
| `<unistd.h>` | File descriptor output            |
| `<ctype.h>`  | Character tests and conversions   |
| Custom Logic | `ft_split`, `ft_substr`, etc.     |
| Bonus        | `t_list` linked list functions    |

---

If you'd like, I can also generate a `.md` file or export this as a nicely formatted PDF or HTML for your GitHub repo. Let me know!

01_ft_printf (finished with 100/125)

02_get_next_line (finished with 125/125)

03-Born2beroot (finished with 125/125) --It's not on Git because it's a project running on a virtual machine.

04_push_swap (finished with 125/125)

05_Pipex (finished with 125/125)

06_FDF (finished with 125/125)

07_Minishell (finished with 125/125)

08_philosophers (finished with 116/125)
