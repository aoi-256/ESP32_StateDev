#include "core/StateHeaders.hpp"
#include "core/StateManager.hpp"

void StateC::update(StateManager& manager) {
    static uint16_t loopCounter = 0;
    loopCounter++;

    if(loopCounter > 1000){
        loopCounter = 0;
        // 状態遷移時にunique_ptr<StateInterface>で安全に管理
        manager.changeState(std::make_unique<StateA>());
    }
}

void StateC::enter(StateManager& manager) {
    // Initialization code for StateC
}

void StateC::exit(StateManager& manager) {
    // Cleanup code for StateC
}
