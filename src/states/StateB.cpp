#include "core/StateHeaders.hpp"
#include "core/StateManager.hpp"

void StateB::update(StateManager& manager) {
    static uint16_t loopCounter = 0;
    loopCounter++;

    if(loopCounter > 1000){
        loopCounter = 0;
        manager.changeState(std::unique_ptr<StateInterface>(new StateC()));
    }
}

void StateB::enter(StateManager& manager) {


}
void StateB::exit(StateManager& manager) {


}
