# get_next_line

This project is part of the 42 School curriculum. The goal is to implement a function, `get_next_line`, which reads a line from a file descriptor, handling multiple file descriptors and large files efficiently. The function must return one line at a time, including the newline character if present.

## Cloning the Repository

To get a copy of this project, run:
```bash
git clone https://github.com/Ferreira-Jefferson/get_next_line.git
cd get_next_line
```

## Project Structure

```
get_next_line/
├── get_next_line.c
├── get_next_line.h
├── get_next_line_bonus.c
├── get_next_line_bonus.h
├── get_next_line_utils.c
├── get_next_line_utils_bonus.c
├── Makefile
├── linked list/
│   ├── get_next_line_bonus_linked_list.c
│   ├── get_next_line_bonus_linked_list.h
│   └── get_next_line_utils_bonus_linked_list.c
```

## Usage

1. **Compile the project:**
   ```bash
   make
   ```
   For the bonus version:
   ```bash
   make bonus
   ```

2. **Include in your project:**
   - Include `get_next_line.h` (or `get_next_line_bonus.h` for bonus) in your source files.
   - Link the compiled object files or library.

3. **Function Prototype:**
   ```c
   char *get_next_line(int fd);
   ```
   - `fd`: File descriptor to read from.
   - Returns: A pointer to the next line read, or `NULL` if there is nothing more to read or an error occurs.

## Rules

- No memory leaks allowed.
- Only the allowed functions by 42 School can be used.
- The function must work with any file descriptor, including standard input.
- The bonus part must handle multiple file descriptors simultaneously.

## Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("file.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## License

This project is licensed under the GNU General Public License v3.0 (GPLv3). See the [LICENSE](LICENSE) file for details.

---

*Project developed as part of the 42 School curriculum.*
