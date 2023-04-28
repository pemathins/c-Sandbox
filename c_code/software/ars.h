#ifndef PASSWORD
#define PASSWORD

#define USER "PEMA"
#define PASS "Pema@123"

long int LoginCheck(char* user,size_t uSize,char* pass, size_t pSize);
/* error value is -1

** 001 case access level 001
** 002 case access level 010
** 003 case access level 011
** 004 case access level 100

*/

#endif
