#pragma once

#include <math.h>

#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <random>
#include <set>
#include <shared_mutex>
#include <string>

class NPC;
class Elf;
class Bear;
class Rogue;
using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType { UnknownType, ElfType, BearType, RogueType, Max };

class Observer { 
public:
    virtual void on_fight(const std::shared_ptr<NPC>, const std::shared_ptr<NPC>, bool) = 0;
};

class NPC : public std::enable_shared_from_this<NPC> { 
protected:
    std::mutex mtx;

    NpcType type;
    std::string name{""};
    int x{0};
    int y{0};
    bool alive{true};
    int move_distance{0};
    int kill_distance{0};

    std::vector<std::shared_ptr<Observer>> observers;

public:
    NPC(NpcType, const std::string&, int, int);
    NPC(NpcType, std::istream&);

    NpcType get_type();

    virtual bool accept(const std::shared_ptr<NPC>&) const = 0;

    void subscribe(const std::shared_ptr<Observer>&);
    void fight_notify(const std::shared_ptr<NPC>, bool) const;
    virtual bool is_close(const std::shared_ptr<NPC>&);

    std::pair<int, int> position();
    virtual void print() = 0;
    virtual void save(std::ostream&);

    friend std::ostream& operator<<(std::ostream&, NPC&);

    int get_move_distance();
    void move(int, int, int, int);

    bool is_alive();
    void must_die();

    int throw_dice() const noexcept;
};
