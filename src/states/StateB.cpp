#include "core/StateHeaders.hpp"
#include "core/StateManager.hpp"

void StateB::update(StateManager& manager) {
    static uint16_t loopCounter = 0;
    loopCounter++;

    if(loopCounter > 1000){
        loopCounter = 0;
        // 状態遷移時にunique_ptr<StateInterface>で安全に管理
        manager.changeState(std::make_unique<StateC>());
    }
}

void StateB::enter(StateManager& manager) {


}
void StateB::exit(StateManager& manager) {


}
