Summary of Program Purposes and Input Formats


Task 3.1: Simple Calculator
Purpose: Perform arithmetic operations on two integers with a specified operator
Input: ./program <num1> <operator> <num2>


Task 3.2: Sum All Numbers
Purpose: Sum multiple integer arguments, ignoring invalid inputs
Input: ./program <arg1> <arg2> ... <argN>


Task 3.3: Number Statistics
Purpose: Calculate sum, average, minimum, maximum, and count of valid integers
Input: ./program <arg1> <arg2> ... <argN>


Task 3.4: Number Base Converter
Purpose: Convert a number from one base to another among bases 2, 8, 10, and 16
Input: ./converter <number> <from_base> <to_base>


Task 4.1: String Length Counter
Purpose: Print length of each input string and total character count
Input: ./program <string1> <string2> ... <stringN>


Task 4.2: String Operations
Purpose: Apply an operation (upper, lower, reverse, concat) on input strings
Input: ./program <operation> <string1> <string2> ... <stringN>


Task 4.3: Word Search
Purpose: Case-insensitive search for a word in multiple text arguments
Input: ./search <word> <text1> <text2> ... <textN>


Task 5.1: Simple Flags
Purpose: Parse flags for verbose or help mode and process filenames
Input: ./program [-v|--verbose] [-h|--help] <file1> <file2> ...


Task 5.2: Flags with Values
Purpose: Parse flags with optional values and filenames
Input: ./program [-n <number>] [-o <filename>] [-v] <input-files>


Task 5.3: Mixed Arguments Parser
Purpose: Parse flags and filenames in any order, reject unknown flags
Input: ./program [flags] <file1> [flags] <file2> ...


Task 5.4: Configuration Override
Purpose: Override default configuration settings via flags
Input: ./program [--port <num>|-p <num>] [--host <addr>|-h <addr>] [--debug|-d]


Task 6.1: File Display
Purpose: Display contents of files, printing filename before each
Input: ./display <file1> <file2> ...
