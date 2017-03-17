/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE78_OS_Command_Injection__char_file_w32_spawnvp_81_goodG2B.cpp
Label Definition File: CWE78_OS_Command_Injection.strings.label.xml
Template File: sources-sink-81_goodG2B.tmpl.cpp
*/
/*
 * @description
 * CWE: 78 OS Command Injection
 * BadSource: file Read input from a file
 * GoodSource: Fixed string
 * Sinks: w32_spawnvp
 *    BadSink : execute command with spawnvp
 * Flow Variant: 81 Data flow: data passed in a parameter to an virtual method called via a reference
 *
 * */
#ifndef OMITGOOD

#include "std_testcase.h"
#include "CWE78_OS_Command_Injection__char_file_w32_spawnvp_81.h"

#include <process.h>

namespace CWE78_OS_Command_Injection__char_file_w32_spawnvp_81
{

void CWE78_OS_Command_Injection__char_file_w32_spawnvp_81_goodG2B::action(char * data) const
{
    {
        char *args[] = {COMMAND_INT_PATH, COMMAND_ARG1, COMMAND_ARG2, COMMAND_ARG3, NULL};
        /* spawnvp - searches for the location of the command among
         * the directories specified by the PATH environment variable */
        /* POTENTIAL FLAW: Execute command without validating input possibly leading to command injection */
        _spawnvp(_P_WAIT, COMMAND_INT, args);
    }
}

}
#endif /* OMITGOOD */
