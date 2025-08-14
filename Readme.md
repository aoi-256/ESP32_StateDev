## 処理の流れについて

- 具体的な処理の流れについて書いてあります

- 関数・メソッド名（ファイル名）という書式で書いてあるので、実際に処理を追ってみてください

#### プログラムスタート(main.cpp)

1. `StateManager` のオブジェクト `stateManager` を作成

#### void setup()

2. `StateManager` クラス（`StateManager.hpp`/`StateManager.cpp`）のコンストラクタ `StateManager::StateManager()` で初期状態が `StateA` に設定され、`StateA::enter()` が呼ばれる

3.  ```StateA::enter()```の処理が行われる（今回は空のメソッド）

#### void loop()

4.  `stateManager.update()` が呼ばれる

5. `StateManager::update()`（`StateManager.cpp`）から現在の状態である `StateA::update()`（`StateA.cpp`）が呼ばれる

**更新タイミングのループ**

6. 4の処理が1000回実行されると、`StateA::update()` から `manager.changeState()`（`StateManager.cpp`） が呼ばれる

7. `manager.changeState()`（`StateManager.cpp`）で`StateA::exit()`が呼ばれる（今回は空のメソッド）

8. `manager.changeState()`（`StateManager.cpp`）の`currentState`が新しい状態`StateB`に更新

9. `manager.changeState()`（`StateManager.cpp`）で`StateB::enter()`が呼ばれる（今回は空のメソッド）

10. `manager.changeState()`（`StateManager.cpp`）でprintln()が実行（シリアルモニタ用の出力）

**更新タイミングのループが終了**

11. `stateManager.update()` が呼ばれる

12. `StateManager::update()`（`StateManager.cpp`）から現在の状態である `StateB::update()`（`StateA.cpp`）が呼ばれる

13. 以下繰り返し(StateA -> StateB -> StateCの順番に遷移していく)


**main.cpp**
```cpp
#include <Arduino.h>
#include "core/StateManager.hpp"

StateManager stateManager;

void setup() {

  Serial.begin(115200);
  Serial.println("State Manager Example Started");
}

void loop() {

  stateManager.update();

  delay(1);
}
```
