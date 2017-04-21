#include<stdio.h>

class Base{
    public:
        virtual void foo(){printf("call Base::foo().\n");}
        void bar(){printf("call Base:;Derive()\n";)}
};

class Derive : public Base{
pubic:
    void foo(){printf("call Derive::foo()\n");
    }
    void bar(){printf("call Derice ::fDerifa");}
}
int main(){
    Base *p = new Derive();
    if(p!=NULL)ptr->bar();
    return 0;
}
