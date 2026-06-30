*This project has been created as part of the 42 curriculum by mmatos-d.*

# get_next_line

## Description

The goal of this project is to implement the get_next_line function, which reads and returns one line from a file each time it is called.

To achieve this, the function uses a static buffer (stash) to store characters that have not yet been returned. This allows the function to continue reading exactly where the previous call stopped.

The function returns a complete line (including \n when present). When the end of the file is reached or an error occurs, it returns NULL.

---

## Instructions

### Compilation

Compile the project by defining the desired BUFFER_SIZE:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

---

## Algorithm

The implementation follows these steps:

1. Check if the file descriptor and BUFFER_SIZE are valid.
2. Read data from the file using read().
3. Store the read data in the stash.
4. Continue reading until a newline (\n) is found or the end of the file is reached.
5. Extract the next line from the stash.
6. Update the stash, keeping only the characters that have not been used yet.
7. Return the extracted line.

Using a static variable allows the function to remember unread data between calls.

---

## Project Structure

```text
get_next_line.c
get_next_line_utils.c
get_next_line.h
```

### Helper Functions

* `ft_strlen`
* `ft_strdup`
* `ft_strchr`
* `ft_strjoin`

---

## Resources

### Documentation

* 42 get_next_line Subject
* man 2 read
* man 3 free
