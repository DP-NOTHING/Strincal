
# 🧮 Strincal: A Simple String Calculator

Strincal is a versatile string calculator that can handle various input formats and perform addition operations. 

catch is used as testing framework.

## 🌟 Features

1. **Flexible Input Handling**: Add any amount of numbers.
2. **New Line Support**: Handle new lines between numbers (e.g., "1\n2,3" returns 6).
3. **Custom Delimiters**: Support different delimiters specified at the beginning of the input.
4. **Negative Number Detection**: Throw an exception for negative numbers, listing all negative values.
5. **Option to give more than one delimiter at a time** : 
one constraint is that we can only give single char delimiter.


## 🛠️ Task Implemented

1. **Create a Simple String Calculator**: Implement an `add` method to handle any amount of numbers.

2. **New Line Handling**: Allow the `add` method to process new lines between numbers.

3. **Custom Delimiter Support**: 
   - To change the delimiter, the input should start with: `//[delimiter]\n[numbers...]`
   - Example: `//;\n1;2` (delimiter is ';', should return 3)

4. **Negative Number Exception**:
   - Throw an exception for negative numbers.
   - Format: "negative numbers not allowed <negative_number>"
   - For multiple negative numbers, show all in the exception message, separated by commas.

> **⚠️ Additional Task:**
> 
>
>  **Option to give more than one delimiter at a time** : 
one constraint is that we can only give single char delimiter.
 ```
 .//:;
1;2:3,4
1
1:2:1
e

Output:
15
```

## 🚀 How to Run Locally

1. Input your string in the terminal.

> **⚠️ IMPORTANT:**
> 
> 2. **To end the current string, enter `e` and press Enter.**
> 3. **To quit the program, enter `q` and press Enter.**


## 📊 Sample Test Cases

### Basic Addition
```
Input:
1,2,3
e

Output:
6
```

### Custom Delimiter
```
Input:
//:
1:2:3
e

Output:
6
```

### Mixed Delimiters
```
Input:
//:
1,2
3:1,2
e

Output:
9
```

### Negative Number Detection
```
Input:
1,2,3,-1,-2

Output:
Error: Negative Nums : -1 , -2
```

### New Line Handling
```
Input:
1
2
3,1
e

Output:
7
```

### more than one delimiter
```
//:;
1;2:3,4
1
1:2:1
e

Output:
15
```




---

Happy Calculating! 🎉