#pragma once

#include "pch.hpp"
#include "Instruction.hpp"

class bb8b {
    public:
        bb8b();
        virtual ~bb8b();

        void print();

        bool run();
        void tick();
        
        std::uint8_t read(std::uint8_t addr);
        void write(std::uint8_t addr, std::uint8_t data);

        void jump(std::uint8_t addr);

        void setA(std::uint8_t);
        void setB(std::uint8_t);
        void setC(std::uint8_t);

        std::uint8_t getPC(){return pc;};
        std::uint8_t getA(){return regA;};
        std::uint8_t getB(){return regB;};
        std::uint8_t getC(){return regC;};

    protected:
        std::array<std::uint8_t, 32> m_Ram;
        std::vector<Instruction> m_Instructions;
        
        std::uint8_t pc = 0x00;
        std::uint8_t flags = 0x00;
        std::uint8_t regI = 0x00;

        std::uint8_t regA = 0x00;
        std::uint8_t regB = 0x00;
        std::uint8_t regC = 0x00;
        
};
