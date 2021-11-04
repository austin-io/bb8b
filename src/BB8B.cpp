#include "BB8B.hpp"

bb8b::bb8b(){
    for(auto& addr : this->m_Ram){
        addr = 0x00;
    }
    
    this->m_Ram = {
        0x01, 0x1F,
        0x02, 0x1E,
        0x07, 0x03,
        0x0D, 0x0A,
        0x0F, 0x04,
        
        0x00, 0x00, 
        0x00, 0x00, 
        0x00, 0x00, 
        0x00, 0x00, 
        0x00, 0x00, 
        0x00, 0x00, 
        0x00, 0x00, 
        0x00, 0x00, 
        0x00, 0x00, 
        0x00, 0x00, 
        
        0x05, 0x10 
    };
    
    /*
    this->m_Ram[0] = 0x01; // 0: LDA 31
    this->m_Ram[1] = 0x1F;

    this->m_Ram[2] = 0x02; // 2: LDB 30
    this->m_Ram[3] = 0x1E;
 
    this->m_Ram[4] = 0x07; // 4: SUB
    this->m_Ram[5] = 0x03; // 5: CTA

    this->m_Ram[6] = 0x0D; // 6: JC 10
    this->m_Ram[7] = 0x0A; 
    
    this->m_Ram[8] = 0x0F; // 8: JMP 4
    this->m_Ram[9] = 0x04;

    this->m_Ram[30] = 0x05; // 30: 5
    this->m_Ram[31] = 0x10; // 31: 16
    */

    this->m_Instructions.push_back(
            Instruction("HLT", 0x00, this, [](bb8b* cpu){} ));

    this->m_Instructions.push_back(
            Instruction("LDA", 0x01, this, [](bb8b* cpu){
                cpu->tick();
                cpu->setA(
                        cpu->read(
                            cpu->read( cpu->getPC())
                        ));
            }));

    this->m_Instructions.push_back(
            Instruction("LDB", 0x02, this, [](bb8b* cpu){
                cpu->tick();
                cpu->setB(
                        cpu->read(
                            cpu->read( cpu->getPC())
                        ));
            }));

    this->m_Instructions.push_back(
            Instruction("CTA", 0x03, this, [](bb8b* cpu){
                cpu->setA(cpu->getC());
            }));
    
    this->m_Instructions.push_back(
            Instruction("STA", 0x04, this, [](bb8b* cpu){
                cpu->tick();
                cpu->write(
                        cpu->read(
                            cpu->read( cpu->getPC())
                        ), cpu->getA());
            }));

    this->m_Instructions.push_back(
            Instruction("STB", 0x05, this, [](bb8b* cpu){
                cpu->tick();
                cpu->write(
                        cpu->read(
                            cpu->read( cpu->getPC())
                        ), cpu->getB());
            }));

    this->m_Instructions.push_back(
            Instruction("ADD", 0x06, this, [](bb8b* cpu){
                cpu->setC(cpu->getA() + cpu->getB());
            }));

    this->m_Instructions.push_back(
            Instruction("SUB", 0x07, this, [](bb8b* cpu){
                cpu->setC(cpu->getA() - cpu->getB());
            }));
    
    this->m_Instructions.push_back(
            Instruction("AND", 0x08, this, [](bb8b* cpu){
                cpu->setC(cpu->getA() & cpu->getB());
            }));
    
    this->m_Instructions.push_back(
            Instruction("OR", 0x09, this, [](bb8b* cpu){
                cpu->setC(cpu->getA() | cpu->getB());
            }));
    
    this->m_Instructions.push_back(
            Instruction("NOT", 0x0A, this, [](bb8b* cpu){
                cpu->setC(~(cpu->getA()));
            }));
    
    this->m_Instructions.push_back(
            Instruction("XOR", 0x0B, this, [](bb8b* cpu){
                cpu->setC(cpu->getA() ^ cpu->getB());
            }));
    
    this->m_Instructions.push_back(
            Instruction("JE", 0x0C, this, [](bb8b* cpu){
                cpu->tick();
                if(cpu->getA() == cpu->getB())
                    cpu->jump(cpu->read(cpu->getPC()));
                else
                    cpu->tick();
            }));
    
    this->m_Instructions.push_back(
            Instruction("JC", 0x0D, this, [](bb8b* cpu){
                cpu->tick();
                if(cpu->getB() >= cpu->getA())
                    cpu->jump(cpu->read(cpu->getPC()));
                else
                    cpu->tick();
            }));
    
    this->m_Instructions.push_back(
            Instruction("JZ", 0x0E, this, [](bb8b* cpu){
                cpu->tick();
                if(cpu->getA() == 0x00)
                    cpu->jump(cpu->read(cpu->getPC()));
                else
                    cpu->tick();
            }));
    
    this->m_Instructions.push_back(
            Instruction("JMP", 0x0F, this, [](bb8b* cpu){
                cpu->tick();
                cpu->jump(cpu->read(cpu->getPC()));
            }));
}

bb8b::~bb8b(){}

void bb8b::print(){
    std::cout 
        << "| BB-8B CPU |\n"
        << "---- Registers ----\n" << std::hex
        << "A: " << (int)regA << std::endl
        << "B: " << (int)regB << std::endl
        << "C: " << (int)regC << std::endl
        << "I: " << (int)regI << std::endl
        << "PC: " << (int)pc << std::endl
        << "FLAGS: " << (int)flags << std::endl
        << "---- RAM ----\n";
    
    for(std::uint8_t i = 0; i < m_Ram.size(); i++ ){
        if(i%8 == 0) std::cout << std::endl;
        std::cout << std::setw(3) << std::hex << (int)m_Ram[i] << " ";
    }

    std::cout << std::dec << std::endl;

}

void bb8b::tick(){
    this->pc++;
}

void bb8b::jump(std::uint8_t addr){
    this->pc = addr;
}

bool bb8b::run(){
    this->regI = this->m_Ram[pc];

    if(regI == 0x00) {
        std::cout << "HALT\n";
        return 0;
    }

    this->m_Instructions[regI].Run();
   
    if(regI < 0x0C) 
        pc++;

    return 1;
}

void bb8b::setA(std::uint8_t b){
    this->regA = b;
}

void bb8b::setB(std::uint8_t b){
    this->regB = b;
}

void bb8b::setC(std::uint8_t b){
    this->regC = b;
}

std::uint8_t bb8b::read(std::uint8_t addr){
    return m_Ram[addr];
}

void bb8b::write(std::uint8_t addr, std::uint8_t data){
    this->m_Ram[addr] = data;
}
