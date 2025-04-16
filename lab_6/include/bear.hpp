#pragma once
#include "npc.hpp"
#include "visitor.hpp"

class Bear final : public NPC {
public:
    Bear(const std::string&, int, int);
    Bear(std::istream&);

    virtual bool accept(const std::shared_ptr<NPC>&) const override;

    void print() override;
    void save(std::ostream&) override;

    friend std::ostream& operator<<(std::ostream&, Bear&);
};