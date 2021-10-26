#pragma once

#include "pch.hpp"

class bb8b;

class Instruction {
    public:
        Instruction(std::string, std::uint8_t, bb8b*, std::function<void(bb8b*)>);
        virtual ~Instruction(){}

        void Run(){
            std::cout << this->name << " [" << (int)opcode<< "]\n";
            this->run(this->m_CpuRef);
        }

        std::string name = "";
        std::uint8_t opcode = 0;

    protected:
        bb8b* m_CpuRef;
        std::function<void(bb8b*)> run;
};
