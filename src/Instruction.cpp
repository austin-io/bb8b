#include "Instruction.hpp"

Instruction::Instruction(std::string n, std::uint8_t op, bb8b* cpu, std::function<void(bb8b*)> fn)
    : name(n), opcode(op), run(fn), m_CpuRef(cpu) {}
