#pragma once
#include "../../../../engine/GameEngine.h"
#include "../Character.h"

class Camera;
class Map;
class Collision;

//プレイヤーのクラス
//主にボタン操作の挙動処理を行う
//描画についての主な定義はwta_LoadAnim, wta_DrawAnimにて

class Player :public Character
{
public:
	Player(Collision* collision, Map* map);
	virtual ~Player();

private:
	//-----定数-----//
	static constexpr float PLAYER_POS_X = 100;			//初期位置
	static constexpr float PLAYER_POS_Y = 0;

	static constexpr int PLAYER_SIZE = 35;				//サイズ
	static constexpr int PLAYER_MAX_HP = 5;				//HP

	static constexpr float PLAYER_VELOCITY_X = 100;		//移動速度（pix/fps）
	static constexpr float PLAYER_VELOCITY_Y = 500;

	const float DASH_THRESHOLD = 0.8f;					/*ダッシュのしきい値を定義*/

	const float PLAYER_INITIAL_HOVER_FORCE = 1.5f; // 初期の浮遊力
	const float PLAYER_HOVER_DECAY_RATE = 1.0f; // 浮遊力の減衰率

	//-----メンバ変数-----//
	int m_hp_hdl = 0;									//HP画像
	
	float m_hovering_force = 0.0f;						// 現在の浮遊力
	float m_landing_time = 0.0f;						// 着地してからの経過時間
	
	bool m_is_hovering = false;							// 空中にいるかどうかのフラグ
	bool m_is_hovered = false;							// 空気が抜けたかどうかのフラグ
	bool m_was_in_air = false;							// 空中にいたかどうかのフラグ
	bool m_hover_end_drawed=false;						// 着地時のアクションが設定されているかどうかのフラグ

	//ゲームスティック用
	float normalized_input_x;							/*アナログスティックの傾きベクトル*/
	int m_input_x;
	int m_input_y;

	Collision* m_collision=nullptr;
	Map* m_map=nullptr;

	ePlayerAction e_currentAction = ePlayerAction::Idle_right;		//アクション

public:
	//-----メンバ関数-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time, const Camera* camera) override;
	void Finalize() override;

private:

	void MoveHandle(float delta_time);		//ゲームパッドスティック操作
	void ActionHandle(float delta_time);	//入力処理
	
	void MoveRange();						//移動範囲の制限
	void Gravity(float delta_time);			//重力処理

	void Hovering(float delta_time);		//ホバリング処理
	void HoveringDirection(float delta_time);	//ホバリング操作
	void HoveringStartRight(float delta_time);				//ホバリング開始処理（右）
	void HoveringStartLeft(float delta_time);				//ホバリング開始処理（左）
	void HoveringEnd();						//ホバリング終了処理
	bool CheckIsGround();					//接地判定
	
	void Invincible(float delta_time);		//無敵時間の処理
};

//Playerのボタン操作の挙動処理を行うクラス
//アニメーションの再生については別クラスを定義した方が分かりやすいかも