#pragma once
#include "npc.hpp"

class Visitor {
public:
    virtual bool visit(const std::shared_ptr<NPC>&) const = 0;
};

class ElfVisitor final : public Visitor {
public:
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::ElfType:
                result = false;
                break;

            case NpcType::BearType:
                result = false;
                break;

            case NpcType::RogueType:
                result = true;
                break;
        }
        return result;
    }
};

class BearVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::ElfType:
                result = true;
                break;

            case NpcType::BearType:
                result = false;
                break;

            case NpcType::RogueType:
                result = false;
                break;
        }
        return result;
    }
};

class RogueVisitor final : public Visitor {
    bool visit(const std::shared_ptr<NPC>& npc) const override {
        bool result{};
        switch (npc->get_type()) {
            case NpcType::ElfType:
                result = false;
                break;

            case NpcType::BearType:
                result = false;
                break;

            case NpcType::RogueType:
                result = true;
                break;
        }
        return result;
    }
};

class VisitorFactory {
public:
    static std::shared_ptr<Visitor> CreateVisitor(const NpcType& type) {
        std::shared_ptr<Visitor> result;
        switch (type) {
            case NpcType::ElfType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<ElfVisitor>());
                break;

            case NpcType::BearType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<BearVisitor>());
                break;

            case NpcType::RogueType:
                result = std::static_pointer_cast<Visitor>(std::make_shared<RogueVisitor>());
                break;
            default:
                break;
        }
        return result;
    }
};
