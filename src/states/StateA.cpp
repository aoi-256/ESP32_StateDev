#include "core/StateHeaders.hpp"
#include "core/StateManager.hpp"

void StateA::update(StateManager& manager) {
    static uint16_t loopCounter = 0;
    loopCounter++;

    if(loopCounter > 1000){
        loopCounter = 0;
        manager.changeState(std::unique_ptr<StateInterface>(new StateB()));
    }
}

void StateA::enter(StateManager& manager) {


}

void StateA::exit(StateManager& manager) {


}
