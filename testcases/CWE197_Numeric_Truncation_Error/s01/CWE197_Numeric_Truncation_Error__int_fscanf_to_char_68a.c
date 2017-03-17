/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68a.c
Label Definition File: CWE197_Numeric_Truncation_Error__int.label.xml
Template File: sources-sink-68a.tmpl.c
*/
/*
 * @description
 * CWE: 197 Numeric Truncation Error
 * BadSource: fscanf Read data from the console using fscanf()
 * GoodSource: Less than CHAR_MAX
 * Sink: to_char
 *    BadSink : Convert data to a char
 * Flow Variant: 68 Data flow: data passed as a global variable from one function to another in different source files
 *
 * */

#include "std_testcase.h"

int CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_badData;
int CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_goodG2BData;

#ifndef OMITBAD

/* bad function declaration */
void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68b_badSink();

void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_bad()
{
    int data;
    /* Initialize data */
    data = -1;
    /* POTENTIAL FLAW: Read data from the console using fscanf() */
    fscanf(stdin, "%d", &data);
    CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_badData = data;
    CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68b_badSink();
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* good function declarations */
void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68b_goodG2BSink();

/* goodG2B uses the GoodSource with the BadSink */
static void goodG2B()
{
    int data;
    /* Initialize data */
    data = -1;
    /* FIX: Use a positive integer less than CHAR_MAX*/
    data = CHAR_MAX-5;
    CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_goodG2BData = data;
    CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68b_goodG2BSink();
}

void CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_good()
{
    goodG2B();
}

#endif /* OMITGOOD */

/* Below is the main(). It is only used when building this testcase on
 * its own for testing or for building a binary to use in testing binary
 * analysis tools. It is not used when compiling all the testcases as one
 * application, which is how source code analysis tools are tested.
 */

#ifdef INCLUDEMAIN

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    CWE197_Numeric_Truncation_Error__int_fscanf_to_char_68_bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
