# Student Record Manager (C)

A console-based Student Record Manager built in C as my first independent project after learning the fundamentals from Harvard's CS50.

## Features

- Add a student
- Display all students
- Search by roll number
- Search by name
- Edit student details
- Delete a student
- Save records to a file
- Load records from a file

## Concepts Practiced

- Functions
- Arrays
- Structures (`struct`)
- File handling (`fopen`, `fprintf`, `fscanf`, `fgets`, `fclose`)
- String handling (`strcmp`)
- Input validation
- Linear search
- Basic debugging
- Modular programming

## Project Structure

```
student_manager.c
students.txt
README.md
```

## How to Compile

```bash
make student_manager
```

or

```bash
gcc student_manager.c -o student_manager
```

## How to Run

```bash
./student_manager
```

On Windows:

```bash
student_manager.exe
```

## What I Learned

While building this project, I learned:

- How to organize a program using multiple functions.
- Why `struct` is useful for managing related data.
- How to read from and write to files.
- How to debug parsing and file I/O issues.
- How to validate user input.
- Basic Git workflow (`add`, `commit`, `push`).

## Future Improvements

- Better table formatting
- Support names with spaces
- Sort students by marks or roll number
- Binary search for faster lookups
- Dynamic memory allocation
- CSV file support

## Author

Shivam Mehla
