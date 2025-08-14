#include "core/StateHeaders.hpp"
#include "core/StateManager.hpp"

void StateA::update(StateManager& manager) {
    static uint16_t loopCounter = 0;
    loopCounter++;

    if(loopCounter > 1000){
        loopCounter = 0;
        // 状態遷移時にunique_ptr<StateInterface>で安全に管理
        manager.changeState(std::make_unique<StateB>());
    }
}

void StateA::enter(StateManager& manager) {


}

void StateA::exit(StateManager& manager) {


}
