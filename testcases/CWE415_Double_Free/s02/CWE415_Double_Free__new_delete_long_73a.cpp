/* TEMPLATE GENERATED TESTCASE FILE
Filename: CWE415_Double_Free__new_delete_long_73a.cpp
Label Definition File: CWE415_Double_Free__new_delete.label.xml
Template File: sources-sinks-73a.tmpl.cpp
*/
/*
 * @description
 * CWE: 415 Double Free
 * BadSource:  Allocate data using new and Deallocae data using delete
 * GoodSource: Allocate data using new
 * Sinks:
 *    GoodSink: do nothing
 *    BadSink : Deallocate data using delete
 * Flow Variant: 73 Data flow: data passed in a list from one function to another in different source files
 *
 * */

#include "std_testcase.h"
#include <list>

#include <wchar.h>

using namespace std;

namespace CWE415_Double_Free__new_delete_long_73
{

#ifndef OMITBAD

/* bad function declaration */
void badSink(list<long *> dataList);

void bad()
{
    long * data;
    list<long *> dataList;
    /* Initialize data */
    data = NULL;
    data = new long;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    badSink(dataList);
}

#endif /* OMITBAD */

#ifndef OMITGOOD

/* goodG2B uses the GoodSource with the BadSink */
void goodG2BSink(list<long *> dataList);

static void goodG2B()
{
    long * data;
    list<long *> dataList;
    /* Initialize data */
    data = NULL;
    data = new long;
    /* FIX: Do NOT delete data in the source - the bad sink deletes data */
    /* Put data in a list */
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    goodG2BSink(dataList);
}

/* goodB2G uses the BadSource with the GoodSink */
void goodB2GSink(list<long *> dataList);

static void goodB2G()
{
    long * data;
    list<long *> dataList;
    /* Initialize data */
    data = NULL;
    data = new long;
    /* POTENTIAL FLAW: delete data in the source - the bad sink deletes data as well */
    delete data;
    dataList.push_back(data);
    dataList.push_back(data);
    dataList.push_back(data);
    goodB2GSink(dataList);
}

void good()
{
    goodG2B();
    goodB2G();
}

#endif /* OMITGOOD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on
   its own for testing or for building a binary to use in testing binary
   analysis tools. It is not used when compiling all the testcases as one
   application, which is how source code analysis tools are tested. */

#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__new_delete_long_73; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITGOOD
    printLine("Calling good()...");
    good();
    printLine("Finished good()");
#endif /* OMITGOOD */
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
