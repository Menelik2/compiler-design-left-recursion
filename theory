# Left Recursion and Top-Down Parsers

## Definition
A grammar is **left recursive** if a non-terminal appears as the leftmost symbol in its own production.

### General Form
A → Aα | β



## Example
E → E + T | T



## Types of Left Recursion
### 1. Direct Left Recursion
A → A a | b



### 2. Indirect Left Recursion
A → B a
B → A b | c


## Why Left Recursion Must Be Removed
- Causes infinite recursion
- Top-down parsers never consume input
- LL(1) parsing table conflicts
- Leads to stack overflow

## Solution: Remove Left Recursion
### Original
E → E + T | T



### Transformed
E → T E'
E' → + T E' | ε



## Conclusion
Left recursion must be eliminated before implementing recursive descent or LL(1) parsers.
