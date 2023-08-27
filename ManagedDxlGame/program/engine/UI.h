#pragma once
#include "GameEngine.h"
#include "GameObject.h"

//���A�����ԍr��Ă܂�

class UI:public GameObject{

public:
	UI();
	virtual ~UI();
	
	//-----���b�V��-----//
	dxe::Mesh* m_mesh_hp = nullptr;				//�̗̓o�[
	dxe::Mesh* m_mesh_face = nullptr;			//�t�F�C�X�o�[
	
	//�\�̓o�[
	dxe::Mesh* m_mesh_ability_normal = nullptr;	//�@�m�[�}��
	dxe::Mesh* m_mesh_ability_fire = nullptr;		//�A��
	dxe::Mesh* m_mesh_ability_beam = nullptr;		//�B�r�[��
	//-----�J����-----//
	dxe::Camera* m_camera = nullptr;

public:
	//-----�����o�֐�-----//
	void Initialize() override;
	void Update(float delta_time) override;
	void Draw(float delta_time) override;
	void Finalize() override;
};

//UI�̏����ꊇ���s���N���X