# 状態遷移クラスサンプル

- State型と呼ばれる代表的な状態遷移プログラムのサンプルです

- 実際の処理の流れを1行ずつ説明してあるのでわかりやすいはず

## ファイル構成と説明

```
ESP32_StateDev/
├── src/                  # メインのソースコード
│   ├── main.cpp          # プログラムのエントリポイント（setup/loop）
│   ├── core/             # 状態管理の基幹部
│   │   ├── StateManager.hpp   # 状態管理クラスのヘッダ
│   │   ├── StateManager.cpp   # 状態管理クラスの実装
│   │   ├── StateHeaders.hpp   # 各状態クラスのヘッダまとめ
│   │   ├── StateInterface.hpp # 状態クラスのインターフェース
│   ├── states/           # 各状態の処理
│   │   ├── StateA.cpp    # 状態Aの実装
│   │   ├── StateB.cpp    # 状態Bの実装
│   │   ├── StateC.cpp    # 状態Cの実装
├── lib/                  # プロジェクト固有ライブラリ（未使用なら空）
│   └── README            # ライブラリ用説明ファイル
├── .gitignore            # Git管理対象外ファイルの指定
├── platformio.ini        # PlatformIOプロジェクト設定
├── Readme.md             # このプロジェクトの説明・使い方
```

### 各フォルダ・ファイルの説明

- **src/**  
  プログラムのメインソース。`main.cpp`から実行が始まります。

- **core/**  
  状態管理の基幹部。状態遷移や状態クラスの共通インターフェースを定義しています。

- **states/**  
  各状態ごとの処理を記述したファイル群です。状態A→B→Cと遷移します。

- **lib/**  
  プロジェクト独自のライブラリを追加する場合に使用します。

- **.gitignore**  
  Gitで管理しないファイルやフォルダを指定します。

- **platformio.ini**  
  PlatformIOのプロジェクト設定ファイルです。

- **Readme.md**  
  プロジェクトの概要や使い方、処理の流れを説明しています。

## 処理の流れについて

- 具体的な処理の流れについて書いてあります

- 関数・メソッド名（ファイル名）という書式で書いてあるので、実際に処理を追ってみてください

#### プログラムスタート(main.cpp)

1. `StateManager` のオブジェクト `stateManager` を作成

#### void setup()

2. `StateManager` クラス（`StateManager.hpp`/`StateManager.cpp`）のコンストラクタ `StateManager::StateManager()` で初期状態が `StateA` に設定され、`StateA::enter()` が呼ばれる

3.  ```StateA::enter()```の処理が行われる（今回は内部の処理はない）

#### void loop()

4.  `stateManager.update()` が呼ばれる

5. `StateManager::update()`（`StateManager.cpp`）から現在の状態である `StateA::update()`（`StateA.cpp`）が呼ばれる

**更新タイミングのループ**

6. 4の処理が1000回実行されると、`StateA::update()` から `manager.changeState()`（`StateManager.cpp`） が呼ばれる

7. `manager.changeState()`（`StateManager.cpp`）で`StateA::exit()`が呼ばれる

8. `manager.changeState()`（`StateManager.cpp`）の`currentState`が新しい状態`StateB`に更新

9. `manager.changeState()`（`StateManager.cpp`）で`StateB::enter()`が呼ばれる

**更新タイミングのループが終了**

10. `stateManager.update()` が呼ばれる

11. `StateManager::update()`（`StateManager.cpp`）から現在の状態である `StateB::update()`（`StateA.cpp`）が呼ばれる

12. 以下繰り返し(StateA -> StateB -> StateCの順番に遷移していく)


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