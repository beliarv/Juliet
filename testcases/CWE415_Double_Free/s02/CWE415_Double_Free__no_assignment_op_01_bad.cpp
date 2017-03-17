/*
 * @description Double Free
 * 
 * */

#include "std_testcase.h"

namespace CWE415_Double_Free__no_assignment_op_01
{

#ifndef OMITBAD

class BadClass 
{
    public:
        BadClass(const char *data)
        {
            if (data) 
            {
                this->data = new char[strlen(data) + 1];
                strcpy(this->data, data);
            } 
            else 
            {
                this->data = new char[1];
                *(this->data) = '\0';
            }
        }

        ~BadClass()
        {
            delete [] data;
        }

        void printData()
        {
            printLine(data);
        }

        BadClass(BadClass &badClassObject)
        { 
            this->data = new char[strlen(badClassObject.data) + 1];
            strcpy(this->data, badClassObject.data); 
        }

    private:
        char *data;
};

void bad()
{
    BadClass badClassObject1("One"), badClassObject2("Two");

    /* FLAW: There is no assignment operator in the class - this will cause a double free in the destructor */
    badClassObject2 = badClassObject1;

    badClassObject2.printData();
}

#endif /* OMITBAD */

} /* close namespace */

/* Below is the main(). It is only used when building this testcase on 
 * its own for testing or for building a binary to use in testing binary 
 * analysis tools. It is not used when compiling all the testcases as one 
 * application, which is how source code analysis tools are tested. 
 */ 

#ifdef INCLUDEMAIN

using namespace CWE415_Double_Free__no_assignment_op_01; /* so that we can use good and bad easily */

int main(int argc, char * argv[])
{
    /* seed randomness */
    srand( (unsigned)time(NULL) );
#ifndef OMITBAD
    printLine("Calling bad()...");
    bad();
    printLine("Finished bad()");
#endif /* OMITBAD */
    return 0;
}

#endif
