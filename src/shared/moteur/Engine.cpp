#include "Engine.h"
#include "Engine.h"
#include <iostream>


using namespace state;
using namespace moteur;
using namespace std;

Engine::Engine():currentState("engine"){

}

state::State& Engine::getState() {
    return this->currentState;
}