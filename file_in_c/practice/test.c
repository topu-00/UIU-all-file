#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inputFile, *outputFile;
    char *filename = "example.txt";
    int line_number_to_delete = 3; // Change this to the line number you want to delete
    int current_line_number = 0;
    char line[100]; // Adjust the size according to your needs

    // Open the input file for reading
    inputFile = fopen(filename, "r");
    if (inputFile == NULL)
    {
        fprintf(stderr, "Unable to open input file %s\n", filename);
        return 1;
    }

    // Open a temporary output file for writing
    outputFile = fopen("temp.txt", "w");
    if (outputFile == NULL)
    {
        fprintf(stderr, "Unable to open temporary file\n");
        fclose(inputFile);
        return 1;
    }

    // Read lines from the input file and write them to the output file,
    // skipping the line to be deleted
    while (fgets(line, sizeof(line), inputFile))
    {
        current_line_number++;
        if (current_line_number != line_number_to_delete)
        {
            fputs(line, outputFile);
        }
    }

    // Close the input and output files
    fclose(inputFile);
    fclose(outputFile);

    // Rename the temporary file to replace the original file
    if (rename("temp.txt", filename) != 0)
    {
        fprintf(stderr, "Error renaming temporary file\n");
        return 1;
    }

    return 0;
}
