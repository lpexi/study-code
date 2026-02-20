#include <stdio.h>
#include <stdlib.h>

static int write_file_with_fputc(void);
static int write_file_with_fputs(void);
static int write_file_with_fprintf(void);
static int write_file_for_fscanf_demo(void);

static int read_file_with_fgetc(void);
static int read_file_with_fgets(void);
static int read_file_with_fscanf(void);

int main(void)
{
    /*
     * result stores the return value of each demo function.
     * 0 means: OK
     * 1 means: Error
     */
    int result = 0;

    /* 1) Write files (WRITE) */
    result = write_file_with_fputc();
    if (result != 0)
    {
        /* If writing fails, reading does not make sense -> stop the program */
        return 1;
    }

    result = write_file_with_fputs();
    if (result != 0)
    {
        return 1;
    }

    result = write_file_with_fprintf();
    if (result != 0)
    {
        return 1;
    }

    /*
     * Create an extra file for the fscanf demo.
     */
    result = write_file_for_fscanf_demo();
    if (result != 0)
    {
        return 1;
    }

    /* User info: which files were created */
    printf("Files written: out_fputc.txt, out_fputs.txt, report.txt, data.txt\n\n");

    /* 2) Read files (READ) */
    result = read_file_with_fgetc();
    if (result != 0)
    {
        return 1;
    }

    result = read_file_with_fgets();
    if (result != 0)
    {
        return 1;
    }

    result = read_file_with_fscanf();
    if (result != 0)
    {
        return 1;
    }

    printf("\nDone.\n");
    return 0;
}

/* ------------------------------------------------------------
   WRITE DEMOS
   ------------------------------------------------------------ */

static int write_file_with_fputc(void)
{
    /*
     * fopen(..., "w") opens the file for writing.
     * - The file is created if it does not exist
     * - The file is overwritten/cleared if it exists
     */
    FILE *p_file = fopen("out_fputc.txt", "w");
    if (p_file == NULL)
    {
        /* perror prints a system-level error message (e.g., Permission denied) */
        perror("fopen out_fputc.txt");
        return 1;
    }

    /*
     * p_message points to the text we want to write to the file.
     * const = we do not modify the text.
     */
    const char *p_message = "Hello from fputc!\nThis file was written char by char.\n";

    /*
     * p_char is our read pointer inside the string.
     * iterate character by character until the string terminator '\0'.
     */
    const char *p_char = p_message;

    while (*p_char != '\0')
    {
        /*
         * fputc writes exactly ONE character to the file.
         * Return value EOF means: write error.
         */
        if (fputc((unsigned char)*p_char, p_file) == EOF)
        {
            perror("fputc out_fputc.txt");

            /*
             * Try to close the file before aborting.
             * (void) = intentionally ignore the return value in error handling.
             */
            (void)fclose(p_file);
            return 1;
        }

        /* Next character in the string */
        p_char++;
    }

    /*
     * fclose closes the file and flushes buffers.
     * Return value 0 = ok, !=0 = error while closing.
     */
    if (fclose(p_file) != 0)
    {
        perror("fclose out_fputc.txt");
        return 1;
    }

    return 0;
}

static int write_file_with_fputs(void)
{
    /*
     * fputs writes a full string (until '\0') to the file.
     * write multiple lines here.
     */
    FILE *p_file = fopen("out_fputs.txt", "w");
    if (p_file == NULL)
    {
        perror("fopen out_fputs.txt");
        return 1;
    }

    /*
     * fputs returns EOF on error.
     * check every write call.
     */
    if (fputs("First line written with fputs()\n", p_file) == EOF)
    {
        perror("fputs out_fputs.txt");
        (void)fclose(p_file);
        return 1;
    }

    if (fputs("Second line written with fputs()\n", p_file) == EOF)
    {
        perror("fputs out_fputs.txt");
        (void)fclose(p_file);
        return 1;
    }

    if (fputs("Third line written with fputs()\n", p_file) == EOF)
    {
        perror("fputs out_fputs.txt");
        (void)fclose(p_file);
        return 1;
    }

    if (fclose(p_file) != 0)
    {
        perror("fclose out_fputs.txt");
        return 1;
    }

    return 0;
}

static int write_file_with_fprintf(void)
{
    /*
     * fprintf writes formatted text into a file (like printf, but to a file).
     */
    FILE *p_file = fopen("report.txt", "w");
    if (p_file == NULL)
    {
        perror("fopen report.txt");
        return 1;
    }

    /*
     * Regular variables. One per line (better readability).
     */
    const char *p_name = "Alice";
    int age = 19;
    double grade = 1.70;

    /*
     * fprintf returns a value < 0 on error.
     * (On success, it returns the number of written characters.)
     */
    if (fprintf(p_file, "=== Student Report (fprintf) ===\n") < 0)
    {
        perror("fprintf report.txt");
        (void)fclose(p_file);
        return 1;
    }

    if (fprintf(p_file, "Name: %s\nAge: %d\nGrade: %.2f\n", p_name, age, grade) < 0)
    {
        perror("fprintf report.txt");
        (void)fclose(p_file);
        return 1;
    }

    if (fprintf(p_file, "Formatted number example: %d %0.3f\n", 42, 3.14159) < 0)
    {
        perror("fprintf report.txt");
        (void)fclose(p_file);
        return 1;
    }

    if (fclose(p_file) != 0)
    {
        perror("fclose report.txt");
        return 1;
    }

    return 0;
}

static int write_file_for_fscanf_demo(void)
{
    /*
     * build this file so fscanf can later read lines as
     * "name age height".
     */
    FILE *p_file = fopen("data.txt", "w");
    if (p_file == NULL)
    {
        perror("fopen data.txt");
        return 1;
    }

    /*
     * use fprintf because it is simple for writing structured data.
     */
    if (fprintf(p_file, "Alice 19 1.72\n") < 0)
    {
        perror("fprintf data.txt");
        (void)fclose(p_file);
        return 1;
    }

    if (fprintf(p_file, "Bob 21 1.80\n") < 0)
    {
        perror("fprintf data.txt");
        (void)fclose(p_file);
        return 1;
    }

    if (fprintf(p_file, "Charlie 20 1.75\n") < 0)
    {
        perror("fprintf data.txt");
        (void)fclose(p_file);
        return 1;
    }

    if (fclose(p_file) != 0)
    {
        perror("fclose data.txt");
        return 1;
    }

    return 0;
}

/* ------------------------------------------------------------
   READ DEMOS
   ------------------------------------------------------------ */

static int read_file_with_fgetc(void)
{
    /*
     * fgetc reads exactly ONE character from the file.
     * Return type is int so EOF (-1) can be detected.
     */
    printf("=== Reading out_fputc.txt with fgetc() ===\n");

    FILE *p_file = fopen("out_fputc.txt", "r");
    if (p_file == NULL)
    {
        perror("fopen out_fputc.txt");
        return 1;
    }

    /*
     * character is int because fgetc() can return EOF.
     */
    int character = 0;

    while (1)
    {
        /* 1) Read a character */
        character = fgetc(p_file);

        /* 2) If EOF -> end of file or error -> stop loop */
        if (character == EOF)
        {
            break;
        }

        /* 3) Print character */
        putchar(character);
    }

    if (fclose(p_file) != 0)
    {
        perror("fclose out_fputc.txt");
        return 1;
    }

    printf("\n");
    return 0;
}

static int read_file_with_fgets(void)
{
    /*
     * fgets reads a full line (or until the buffer is full) from the file.
     * It returns NULL when no more data can be read.
     */
    printf("=== Reading out_fputs.txt with fgets() ===\n");

    FILE *p_file = fopen("out_fputs.txt", "r");
    if (p_file == NULL)
    {
        perror("fopen out_fputs.txt");
        return 1;
    }

    /*
     * buffer stores one line read from the file.
     * 256 is a simple demo size here.
     */
    char buffer[256];

    /*
     * fgets reads at most sizeof(buffer)-1 characters and appends '\0'.
     * Return value != NULL means one line (or partial line) was read successfully.
     */
    while (fgets(buffer, (int)sizeof(buffer), p_file) != NULL)
    {
        /*
         * buffer usually already contains '\n' if the line was fully read.
         * So no extra \n is needed in printf.
         */
        printf("LINE: %s", buffer);
    }

    if (fclose(p_file) != 0)
    {
        perror("fclose out_fputs.txt");
        return 1;
    }

    printf("\n");
    return 0;
}

static int read_file_with_fscanf(void)
{
    /*
     * fscanf reads formatted data from a file (similar to scanf).
     * expect: name (string) + age (int) + height (double)
     */
    printf("=== Reading data.txt with fscanf() ===\n");

    FILE *p_file = fopen("data.txt", "r");
    if (p_file == NULL)
    {
        perror("fopen data.txt");
        return 1;
    }

    /*
     * name is a char array for a name without spaces.
     * age and height are initialized (guideline: always initialize).
     */
    char name[50];
    int age = 0;
    double height = 0.0;

    /*
     * fscanf returns how many values were read successfully.
     * expect 3 values per line -> == 3
     *
     * %49s limits length to 49 characters + '\0' -> protects against buffer overflow.
     */
    while (fscanf(p_file, "%49s %d %lf", name, &age, &height) == 3)
    {
        printf("Name=%s | Age=%d | Height=%.2f\n", name, age, height);
    }

    if (fclose(p_file) != 0)
    {
        perror("fclose data.txt");
        return 1;
    }

    return 0;
}
