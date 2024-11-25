#pragma once
#include <concepts>
#include <type_traits>

// this class is oversiplified just to illustrate the scaling mechanism
// also it only supports arithmetic types via std::is_arithmetic<T>
namespace Player {
    enum class PlayerClass {
        Knight,
        Warrior,
        Wizard
    };

    template<typename T>
    concept Numeric = std::is_arithmetic_v<T>;

    template<typename T, PlayerClass U> requires Numeric<T>
    struct Player {
        Player() : playerClass{U}{}
        T attack;
        T deffense;
        T healtPoints;
        T specialAttack;
        T specialDefense;
        T speed;

        PlayerClass playerClass;
    };
}