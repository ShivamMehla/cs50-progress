#include <stdio.h>
#include <string.h>

void display_menu();
void add_student();
void display_students();
void find_student();
void edit_student();
void delete_student();
void save();
void load();
void print_header();

typedef struct
{
    char name[50];
    int roll_no;
    int marks;
} STUDENT;

STUDENT students[100];
int student_count = 0;

int main()
{
    int choice;

    do
    {
        display_menu();
        scanf("%i", &choice);

        if(choice == 1)
        {
            add_student();
        }
        else if(choice == 2)
        {
            display_students();
        }
        else if(choice == 3)
        {
            find_student();
        }
        else if(choice == 4)
        {
            edit_student();
        }
        else if(choice == 5)
        {
            delete_student();
        }
        else if(choice == 6)
        {
            save();
        }
        else if(choice == 7)
        {
            load();
        }
        else if(choice == 8)
        {
            printf("Exited Successfully.\n");
            return 0;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }while (choice != 8);
}

void display_menu()
{
    printf(
        "===== Student Record Manager =====\n"
        "1. Add Student\n"
        "2. Display Students\n"
        "3. Find Student\n"
        "4. Edit Student\n"
        "5. Delete Student\n"
        "6. Save\n"
        "7. Load\n"
        "8. Exit\n"
        "Enter your choice: "
    );
}

void add_student()
{
    // Check if the student limit is reached (100)
    if (student_count == 100)
    {
        printf("Can't exceed max students.\n");
        return;
    }

    STUDENT temp;
    printf("Enter Student name: ");
    scanf("%s", temp.name);

    printf("Enter Roll Number: ");
    scanf("%i", &temp.roll_no);

    printf("Enter marks: ");
    scanf("%i", &temp.marks);

    for(int i = 0; i < student_count; i++)
    {
        if(students[i].roll_no == temp.roll_no)
        {
            printf("Roll number already exists.\n");
            return;
        }
    }

    students[student_count] = temp;
    student_count++;
    printf("Student added successfully.\n\n");
}

void display_students()
{
    if(student_count == 0)
    {
        printf("No students added yet.\n\n");
        return;
    }

    printf
    (
        "        ===== Student Record =====\n"
        "|%-5s|%-20s|%-10s|%-5s|\n",
        "S.No.", "Name", "Roll No.", "Marks"
    );
    for(int i = 0; i < student_count; i++)
    {
        printf
        (
            "|%-5i|%-20s|%-10i|%-5i|\n",
             i + 1,students[i].name, students[i].roll_no, students[i].marks
        );
    }
    printf("\n");
}

void find_student()
{
    if(student_count == 0)
    {
        printf("No students added yet.\n\n");
        return;
    }

    int search;
    int enter_rollno;
    char enter_name[50];
    int found = 0;

    do
    {
        printf
        (
            "1. Search by Roll No\n"
            "2. Search by Name\n"
            "3. Back\n"
            "Select : "
        );
        scanf("%i", &search);

        if(search < 1 || search > 3)
        {
            printf("Invalid choice.\n");
        }

        else if(search == 1)
        {
            printf("Enter Roll No. : ");
            scanf("%i", &enter_rollno);

            for(int i = 0; i < student_count; i++)
            {
                if(enter_rollno == students[i].roll_no)
                {
                    found = 1;
                    printf
                    (
                        "|%-5s|%-20s|%-10s|%-5s|\n",
                        "S. No", "Name", "Roll No.", "Marks"
                    );
                    printf
                    (
                        "|%-5i|%-20s|%-10i|%-5i|\n",
                        i + 1, students[i].name, students[i].roll_no, students[i].marks
                    );
                    break;
                }
            }

            if(found == 0)
            {
                printf("Could not find the roll no.\n");
            }
            found = 0;
        }

        else if(search == 2)
        {
            printf("Enter student name: ");
            scanf("%s", enter_name);

            for(int i = 0; i < student_count; i++)
            {
                if(strcmp(enter_name, students[i].name) == 0)
                {
                    if(found == 0)
                    {
                        printf("===== Student Record =====\n");
                        printf
                        (
                            "|%-5s|%-20s|%-10s|%-5s|\n",
                            "S.No", "Name", "Roll No.", "Marks"
                        );
                    }

                    found = 1;
                    printf
                    (
                        "| %-5i |  %-20s  |   %-10i  |   %-5i  |\n",
                        i + 1, students[i].name, students[i].roll_no, students[i].marks
                    );
                }
            }
            if(found == 0)
            {
                printf("Student not found.\n");
            }
            found = 0;
        }
    }while (search != 3);
}

void edit_student()
{
    int s_no;
    int repeat = 1;
    int loop;
    do
    {
        display_students();
        if(student_count == 0)
        {
            return;
        }
        printf("\n0. Back to main menu\n");

        printf("Select : ");
        scanf("%i", &s_no);
        if(s_no >= 1 && s_no <= student_count)
        {
            loop = 1;
            do
            {
                int select;
                printf
                (
                    "1. Edit name\n"
                    "2. Edit roll No.\n"
                    "3. Edit marks\n"
                    "4. Edit all\n"
                    "5. Back to Student List\n\n"
                    "Select : "
                );
                scanf("%i", &select);

                if(select == 1)
                {
                    printf("Updated name : ");
                    scanf("%s", students[s_no - 1].name);
                    printf("Successfully Updated.\n");
                }

                else if(select == 2)
                {
                    int found;
                    int temp;
                    do
                    {
                        found = 0;
                        printf("Updated roll No. : ");
                        scanf("%i", &temp);

                        for(int i = 0; i < student_count; i++)
                        {
                            if(students[i].roll_no == temp && i != s_no - 1)
                            {
                                found = 1;
                                printf("Roll number already exists.\n");
                                break;
                            }
                        }
                    }while(found == 1);
                    students[s_no - 1].roll_no = temp;
                    printf("Updated Successfully.\n");
                }

                else if(select == 3)
                {
                    printf("Updated marks : ");
                    scanf("%i", &students[s_no - 1].marks);
                    printf("Successfully Updated.\n");
                }

                else if(select == 4)
                {
                    // Update name
                    printf("Updated name : ");
                    scanf("%s", students[s_no - 1].name);

                    // Update roll number
                    int duplicate;
                    int temp;
                    do
                    {
                        duplicate = 0;
                        printf("Updated roll No. : ");
                        scanf("%i", &temp);

                        for(int i = 0; i < student_count; i++)
                        {
                            if(students[i].roll_no == temp && i != s_no - 1)
                            {
                                duplicate = 1;
                                printf("Roll number already exist.\n");
                                break;
                            }
                        }
                    }while(duplicate == 1);
                    students[s_no - 1].roll_no = temp;

                    // Update marks
                    printf("Updated marks : ");
                    scanf("%i", &students[s_no - 1].marks);
                    printf("Successfully Updated.\n");

                }

                else if(select == 5)
                {
                    loop = 0;
                }
                else
                {
                    printf("Invalid choice.\n");
                }
            }while(loop == 1);
        }
        else if(s_no == 0)
        {
            repeat = 0;
        }
        else
        {
            printf("Invalid student number.\n");
        }
    }while(repeat == 1);
}

void delete_student()
{
    int s_no;
    int select;
    int repeat;
    int loop = 1;

    do
    {
        if(student_count == 0)
        {
            return;
        }

        do
        {
            repeat = 0;
            printf("0. Return to main menu\n");
            display_students();
            printf("Select : ");
            scanf("%i", &s_no);

            if(s_no >= 1 && s_no <= student_count)
            {
                printf
                (
                    "1. Delete\n"
                    "2. Back\n"
                    "Select: "
                );
                scanf("%i", &select);

                if(select == 1)
                {
                    char y_or_no;
                    char ask;
                    do
                    {
                        y_or_no = 0;
                    printf("Are you sure you want to delete? (Y/N): ");
                    scanf(" %c", &ask);

                    if(ask == 'y' || ask == 'Y')
                    {
                        for(int i = s_no - 1; i < student_count - 1; i++)
                        {
                            students[i] = students[i + 1];
                        }
                        student_count--;
                        printf("Student sucessfully deleted.\n");
                    }
                    else if(ask == 'n' || ask == 'N')
                    {
                        repeat = 1;
                    }
                    else
                    {
                        y_or_no = 1;
                    }
                }while(y_or_no == 1);
                }
                else if(select == 2)
                {
                    repeat = 0;
                }
            }
            else if(s_no == 0)
            {
                loop = 0;
            }
            else
            {
                printf("Invalid choice.\n");
                repeat = 1;
            }
        }while(repeat == 1);
    }while(loop == 1);
}

void save()
{
    FILE *file = fopen("students.txt", "w");
    if(file == NULL)
    {
        printf("Couldn't save the file.\n");
        return;
    }
    fprintf
    (file,
            "        ===== Student Record =====\n"
            "|%-5s|%-20s|%-10s|%-5s|\n",
            "S.No", "Name", "Roll No.", "Marks"
    );

    for(int i = 0; i < student_count; i++)
    {
        fprintf
        (file,
                "|%-5i|%-20s|%-10i|%-5i|\n"
                ,i + 1, students[i].name, students[i].roll_no, students[i].marks
        );
    }
    fclose(file);
    printf("Saved file successfully.\n");
}

void load()
{
    student_count = 0;
    char buffer[50];
    FILE *file = fopen("students.txt", "r");
    if(file == NULL)
    {
        printf("No file saved yet.\n");
        return;
    }
    fgets(buffer, 50, file);    // Read line 1
    fgets(buffer, 50, file);    // Read line 2

    int temp_sno;
    int result;
    do
    {
        // Leading whitespace before literal characters in fscanf fixed a parsing issue.
        // Revisit after becoming more comfortable with file I/O.
        result = fscanf(file, " | %i | %s | %i | %i |",
        &temp_sno,
        students[student_count].name,
        &students[student_count].roll_no,
        &students[student_count].marks);

        if(result == 4)
        {
            student_count++;
        }
        if(student_count == 100)
        {
            printf("Student limit reached. Only the first 100 students were loaded.\n");
            fclose(file);
            return;
        }
    }while (result == 4);

    if(feof(file) != 0) // Or just (feof(file))
    {
        printf("Successfully loaded.\n");
    }
    else
    {
        printf("Could not load the file.\n");
    }
    fclose(file);
}
