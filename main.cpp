// Include Precompiled Headers
#include "pch.hpp"

// Include BB8B Headers
#include "src/BB8B.hpp"

int main(){
    bb8b cpu = bb8b();
    
    while(cpu.run());

    cpu.print();
}
