#include "core/StateHeaders.hpp"
#include "core/StateManager.hpp"

void StateC::update(StateManager& manager) {
    static uint16_t loopCounter = 0;
    loopCounter++;

    if(loopCounter > 1000){
        loopCounter = 0;
        manager.changeState(std::unique_ptr<StateInterface>(new StateA()));
    }
}

void StateC::enter(StateManager& manager) {
    // Initialization code for StateC
}

void StateC::exit(StateManager& manager) {
    // Cleanup code for StateC
}
