//
// Created by Zhou,Zhiyong(DAPD) on 2019/1/25.
//

#include "../common_includes.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    int i = 10;
    int second = i;
    cout << second << endl;

    __asm {
        mov dword ptr [ebp-4], 20h;
    }

    int third = i;
    cout << third << endl;

    return 0;
}