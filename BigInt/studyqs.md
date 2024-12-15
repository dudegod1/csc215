## Study Questions

1. **Suppose you want to add unary operations (e.g., unary minus or absolute value). What changes are needed?**
 - Add new cases for unary operators like `M` (negate) and `A` (absolute value) in the calculator logic.
 - Implement functions for these operations in the `BigInt` class.
 - Modify the input handling to accept and process unary operator commands.

2. **If words (e.g., "times" instead of "asterick") are used for operators, where would changes be necessary?**
    - Replace single-character operator checks (`+`, `-`, `*`) with string comparisons. ==
    - also update input parsing logic to recognize string based commands

3.  **How would the calculator handle C++ double values instead of integers?**
    - Modify the `BigInt` class to store and operate on floating-point values.
    - Change the calculator’s logic to handle floating-point arithmetic.

4. **How can a "Clear" command (`C`) be added to the calculator?**
    - Create a new function which is called when C is typed which would take where the current value is and set it to zero.

5. **How could the calculator be modified to support parentheses?**
    - Use an `if` statement to identify when parentheses are encountered in the input.
