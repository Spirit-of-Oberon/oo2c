#include <stdio.h>

class T {
public:
    T() { }

    virtual void String(char * str, int length) {
        printf("%s", str);
    }

    virtual void Int(int a) {
        printf("%d", a); fflush(stdout);
    }

    virtual void Ln() {
        printf("\n"); fflush(stdout);
    }

    virtual void Chain(T * obj, int a) {
        printf("VTable3:T %d\n", a); fflush(stdout);
        if (a > 0)
            obj->Chain(this, a-1);
    }
};

extern "C" T * VTable3__NewT(void) {
    return new T();
}

extern "C" void OOC_VTable3_open(void) {
}
