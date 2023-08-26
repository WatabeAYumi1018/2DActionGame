#pragma once
#include "GameEngine.h"
#include "GameObject.h"

//���A�����ԍr��Ă܂�

class UI:public GameObject{

public:
	UI(tnl::Vector3 m_pos);
	virtual ~UI();

	//-----�����o�ϐ�-----//
	tnl::Vector3 m_pos;				//���W
	
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
	void Initialize();
	void Update(float delta_time);
	void Finalize();
};

//UI�̏����ꊇ���s���N���X