#include <stdio.h>

int main (void) {

/* Variable declarations */
char empNo [10];
int dept;
float payRate;
char exempt;
float hoursWorked;
float basePay;
char headerLine[200];

/* File pointer declarations */
FILE *inFile;
FILE *outFile;

/* Open the input file for reading */
inFile = fopen("employee.txt", "r");
if (inFile == NULL) {
      printf("Error opening employee.txt\n");
      return 1;
}

/* Open the output file for writing */
outFile = fopen("payroll_register.txt", "w");
if (outFile == NULL) {
    printf("Error creating payroll_register.txt\n");
    fclose(inFile);
    return 1;
}

/* Skip the header line in the employee.txt */
fgets(headerLine, sizeof (headerLine), inFile);

/* Write headings to payroll_register.txt */
fprintf(outFile, "=======================================================================\n");
fprintf(outFile, "                       PAYROLL REGISTER\n");
fprintf(outFile, "=======================================================================\n");
fprintf(outFile, "%-14s %-12s %-10s %-8s %-14s %s\n",
	"Employee No.", "Department", "Pay Rate",
              "Exempt", "Hours Worked", "Base Pay");
fprintf(outFile, "-----------------------------------------------------------------------\n");

/* Read each employee record until end of file */
while (fscanf(inFile, "%s %d %f %c %f",
            empNo, &dept, &payRate, &exempt, &hoursWorked) == 5) {

/* Calculate base pay */
basePay = payRate * hoursWorked;

/* Write employee data to output file */
fprintf(outFile, "%-14s %-12d %-10.2f %-8c %-14.1f %.2f\n",
              empNo, dept, payRate, exempt, hoursWorked, basePay);
}

printf("Payroll register has been created.\n");

fclose(inFile);
fclose(outFile);

return 0;
}

