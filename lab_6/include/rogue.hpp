#pragma once
#include "npc.hpp"
#include "visitor.hpp"

class Rogue final : public NPC {
public:
    Rogue(const std::string&, int, int);
    Rogue(std::istream&);

    virtual bool accept(const std::shared_ptr<NPC>&) const override;

    void print() override;
    void save(std::ostream&) override;

    friend std::ostream& operator<<(std::ostream&, Rogue&);
};