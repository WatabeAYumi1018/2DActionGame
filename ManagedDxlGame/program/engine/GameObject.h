#pragma once
#include "../engine/GameEngine.h"

class PlayCamera;

class GameObject
{
public:
	GameObject(const tnl::Vector3& pos) : m_pos(pos) {}
	virtual ~GameObject() { Finalize(); }

protected:
	// ---- �����o�ϐ� ---- //
	tnl::Vector3 m_pos;
	
	bool m_is_exist = true;						//���݃t���O
	bool m_is_update = true;					//�X�V�t���O
	bool m_is_draw = true;						//�`��t���O

public:
	//-----�����o�֐�-----//
	virtual void Initialize() {}
	virtual void Update(float delta_time) { }
	virtual void Draw(float delta_time, const PlayCamera* camera) {}
	virtual void Finalize() {}

	//-----Setter&Getter-----//
	const tnl::Vector3 GetPos() const { return m_pos; }
	void SetPos(const tnl::Vector3 pos) { m_pos = pos; }
	
	bool GetIsExist() const { return m_is_exist; }
	void SetIsExist(bool is_exist) { m_is_exist = is_exist; }
	
	bool GetIsUpdate() const { return m_is_update; }
	void SetIsUpdate(bool is_update) { m_is_update = is_update; }
	
	bool GetIsDraw() const { return m_is_draw; }
	void SetIsDraw(bool is_draw) { m_is_draw = is_draw; }
};