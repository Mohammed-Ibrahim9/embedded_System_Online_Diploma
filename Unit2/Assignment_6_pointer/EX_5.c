#include <stdio.h>

struct employee
{
	char* ename;
	int eid;
};

int main() {
   static struct employee emp1={"Omar",10},emp2={"Amr",11},emp3={"Amar",12};
   struct employee (*a[])={&emp1,&emp2,&emp3};
   struct employee (*(*p)[3])=&a;
   printf("Employee name: %s \n", (**(*p+1)).ename);
   printf("Employee ID: %d \n", (*(*p+1))->eid);

    return 0;
}
