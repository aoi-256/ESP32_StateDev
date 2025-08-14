#include "StateManager.hpp"
#include "StateHeaders.hpp"

#include <Arduino.h>
#include <memory>

// コンストラクタ
StateManager::StateManager() {

    // 初期状態をStateAに設定
    current_state = std::unique_ptr<StateA>(new StateA());

    // StateAのenter関数を呼び出して初期化処理を行う
    current_state->enter(*this);
}

// 状態遷移
void StateManager::changeState(std::unique_ptr<StateInterface> new_state) {

    // 現在の状態の終了処理（exit関数の呼び出し）
    if (current_state) {

        current_state->exit(*this);
    }

    // 新しい状態クラスのオブジェクトのポインタを代入
    current_state = std::move(new_state);

    // 新しい状態の開始処理（enter関数の呼び出し）
    current_state->enter(*this);

    // 状態遷移メッセージの出力(デバッグ用)
    if (current_state) {

        printf("[StateManager] 状態遷移: %s\n", current_state->getStateName());
    }
}

// メインループの更新処理
void StateManager::update() {

    if (current_state) {

        // 現在状態の更新処理
        current_state->update(*this);
    }
}