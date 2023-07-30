#include "backGround.h"

backGround::backGround() {
	Initialize();
}

backGround::~backGround() { Finalize(); }

void backGround::Initialize() {

	//�J�����ݒ�
	m_camera = new Camera(DXE_WINDOW_WIDTH, DXE_WINDOW_HEIGHT);
	
	//{0,0,0}���G���[
	// x�F�l�偨���փX���C�h�A�l�����E�փX���C�h
	//y�F�l�偨��փX���C�h�i���Ղ��Č��銴���j�A�l�������փX���C�h�i���グ�銴���j
	//z�F�l�偨���@�����A���ǂ�����l���傫���Ȃ�قǉ��ɍs��
	m_camera->pos_ = { 0,0,100 };
	 
	//���b�V���̎������]���Ȃ���f���悤�ȃJ����
	//{0,0,0}���񎟌��ł̐���
	//x:�E����̉�]�ړ��H�i������摜��`������悤�Ȋ����j
	//��:�����̉�]�ړ��H�i1000���Ɖ����猩�グ��悤�Ȋ����j
	//z:��i�ω��Ȃ����������ǁA-1000���ƕ`��݂��Ȃ��Ȃ�j
	m_camera->target_ = { 0,0,0 };

	//���b�V���ɔw�i�摜��ݒ�
	 
	//x:����,y:�c��,z:���s��(�v���[�����Ɩ����H�悭�������)
	m_mesh = Mesh::CreatePlaneMV({1000,1000,0});
	m_mesh->setTexture(Texture::CreateFromFile("graphics/PT_Skybox_Texture_01.png"));
	
	//x,y:��{�O��OK
	//Z�F���s�i���̒l�偨��O�A���̒l�偨���j
	m_mesh->pos_= { 0,0,-100 };
}

void backGround::Update(float delta_time) {
	m_mesh->render(m_camera);
	m_camera->update();
}


void backGround::Finalize() {
	if (m_mesh) {
		delete m_mesh;
		m_mesh = nullptr;
	}
	if (m_camera) {
		delete m_camera;
		m_camera = nullptr;
	}
}
