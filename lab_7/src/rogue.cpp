#include "../include/rogue.hpp"

Rogue::Rogue(const std::string& name, int x, int y) : NPC(RogueType, name, x, y) {
    move_distance = 5;
    kill_distance = 5;
}

Rogue::Rogue(std::istream& is) : NPC(RogueType, is) {
    move_distance = 5;
    kill_distance = 5;
}

bool Rogue::accept(const std::shared_ptr<NPC>& attacker) const {
    std::shared_ptr<Visitor> attacker_visitor = VisitorFactory::CreateVisitor(attacker->get_type());
    std::shared_ptr<Rogue> defender = std::dynamic_pointer_cast<Rogue>(std::const_pointer_cast<NPC>(shared_from_this()));
    bool result = attacker_visitor->visit(defender);
    attacker->fight_notify(defender, result);
    return result;
}

void Rogue::print() {
    std::cout << *this;
}

void Rogue::save(std::ostream& os) {
    os << RogueType << std::endl;
    NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Rogue& rogue) {
    os << "Rogue " << *static_cast<NPC*>(&rogue) << std::endl;
    return os;
}
