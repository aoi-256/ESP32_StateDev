/* StateHeaders.cpp
* 
*  ここでは、メインから呼び出す状態遷移の処理と各状態処理の呼び出しを行います
*
*  すべての状態クラスはStateInterfaceを継承しているため、Update()メソッドを持っています
*  そこで、どの状態クラスのUpdate()メソッドを呼び出すかを現在の状態(current_state)によって切り替えるだけで状態遷移が実装できます
*
*  状態の変更は各状態の処理内から、changeState()メソッドを呼び出すことで行います
*  各状態が実行されるとき、privateに書いた変数や構造体などは共有されるため、センサーデータはこのクラスで管理することができます
*  これは、void StateA::update(StateManager& manager)のように、StateManagerの参照を引数にとることで実現しています
*
*  クラスは変数のように直接代入することはできないため、std::unique_ptrを使用して状態オブジェクトを管理します(これは状態クラスのオブジェクトのポインタです)
*  std::unique_ptrを使うことで、このクラス以外からアクセスできなくなるため、想定していない状態遷移を防ぐことができます（ついでに難しいメモリ管理もしてくれます）
*/

#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include "core/StateInterface.hpp"
#include <memory>

class StateManager {

    public:

        StateManager();
        ~StateManager() = default;

        // 状態遷移
        void changeState(std::unique_ptr<StateInterface> newState);
        
        // メインループ
        void update();

    private:

    std::unique_ptr<StateInterface> current_state;

};

#endif // STATE_MANAGER_HPP