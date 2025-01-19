Here's a more concise version of your notes in markdown format:

```markdown
# Makefile Notes

### 1. How `make` Decides to Run a Target:
- `make` runs a target if:
  - The target doesn't exist, or
  - Any of its prerequisites are newer than the target.
- This ensures that if a prerequisite changes, the target gets rebuilt.

**Example:**
```makefile
some_file: other_file
    echo "Runs second"
    touch some_file

other_file:
    echo "Runs first"
```

### 2. `clean` Target:
- `clean` is a common convention, but not a special keyword in `make`.
- It’s used to remove generated files (e.g., compiled binaries).

**Example:**
```makefile
some_file: touch some_file

clean:
    rm -f some_file
```
- Running `make clean` will delete `some_file`.

### 3. `.PHONY` Target:
- `.PHONY` tells `make` that a target is not a file and should always run.

**Example:**
```makefile
.PHONY: clean
clean:
    rm -f some_file
