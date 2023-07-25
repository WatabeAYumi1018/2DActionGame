#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"
#include "gm_main.h"


using namespace std;
using namespace tnl;

//〜8月中旬まで〜
//�@マップ描画
//�Aキャラクターの動向と当たり判定の実装
//�B攻撃の当たり判定
//�C敵キャラのAI
//�DUIやパラメータなどとの紐づけ
//�Eアクションの動向とアニメーションなどの確認とひと通りのプレイ実現

//〜８月中まで〜
//�Fステージセレクト画面作成
//�Gひと通りゲームとして完成
//�Hボス戦
//�Iアイテム実装

//〜9月中旬まで〜
//�Jデバック
//�K画面セレクト作成
//�Lタイトル作成
//�Mエンディング作成

// 〜期限まで〜
//�N最終確認

class SceneBase {};

//プレイヤー、敵、カメラ、アイテム、攻撃etc
class ScenePlay
	//:public SceneBase
{};

class Camera {};

class Effect {};

class UI {};

class Collision {};

class Character {

	Character(Vector3 m_pos, Vector3 m_velocity);
	virtual ~Character();

protected:
	int graph_hdl;						//画像ハンドル
	int hp;


	Vector3 m_pos;						//座標
	Vector3 m_velocity;					//速度
	Vector3 m_gravity;					//重力

	bool is_Exit;						//存在フラグ
	bool is_Jump;						//ジャンプ中
	bool is_Attack;						//攻撃中

	Collision* collision = nullptr;		//当たり判定
	//Effect* effect = nullptr;
};

class Player :public Character {};

class Enemy :public Character {};

class Item :public Character {};



//------------------------------------------------------------------------------------------------------------
// ゲーム起動時に１度だけ実行されます
void gameStart() {
	srand(time(0));

}

//------------------------------------------------------------------------------------------------------------
// 毎フレーム実行されます
void gameMain(float delta_time) {
}

//------------------------------------------------------------------------------------------------------------
// ゲーム終了時に１度だけ実行されます
void gameEnd() {

}
