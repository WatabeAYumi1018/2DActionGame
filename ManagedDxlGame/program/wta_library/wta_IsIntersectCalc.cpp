#include "wta_IsIntersectCalc.h"
#include <fstream>
#include <time.h>
#include <string>
#include "../dxlib_ext/dxlib_ext.h"

namespace wta {

	//    //�摜�t�@�C�������[�h����
	//    int loadAnimLoopFile(const char* path) {
	//        std::string folderPath = path;
	//        //WIN32_FIND_DATA�\���́FWindows�Ńt�@�C���������s���ۂɎg�p�����f�[�^�\����
	//        //Windows API�̃t�@�C�������֐��ł���FindFirstFile��FindNextFile���g�p�����
	//        //�������ʂ̃t�@�C�������i�[���邽�߂Ɏg����
	//        WIN32_FIND_DATA findData;
	//        //�t�@�C���������J�n����
	//        HANDLE hFind = FindFirstFile((folderPath + "/*").c_str(), &findData);
	//        //�t�@�C����������Ȃ������ꍇ�͏I������
	//        if (hFind == INVALID_HANDLE_VALUE) { return 1; }
	//        do {
	//            //�t�@�C���݂̂��擾(���C�u�����łȂ����)
	//            if (!(findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
	//                //�t�@�C�������擾
	//                std::string fileName = findData.cFileName;
	//                //�t�@�C���̃t���p�X���擾
	//                std::string fullPath = folderPath + "/" + fileName;
	//                //�摜�����[�h
	//                Imgs.emplace_back(LoadGraph(fullPath.c_str()));
	//            }
	//        } while (FindNextFile(hFind, &findData) != 0);
	//        //�t�@�C���������I������
	//        FindClose(hFind);
	//        //�摜�̖������擾
	//        NumImgs = static_cast<int>(Imgs.size());
	//
	//        return 0;
	//    }
	//
	//    //�摜�����[�v�`�悷��
	//    int drawAnimLoopFile(float delta_time, tnl::Vector3 pos, int path_hdl, float angle, float scale) {
	//        elapsedTime += delta_time;
	//        //�o�ߎ��Ԃ��t���[�����Ԃ𒴂����ꍇ
	//        if (elapsedTime >= frameDuration) {
	//            elapsedTime -= frameDuration;
	//            ++currentFrame;
	//            //���[�v����(�]��̐��Ń��[�v)
	//            if (LoopFlag) { currentFrame %= NumImgs; }
	//            //���[�v���Ȃ�
	//            else if (currentFrame >= NumImgs) { currentFrame = NumImgs - 1; }
	//        }
	//        DrawRotaGraph(static_cast<int>(pos.x), static_cast<int>(pos.y), 1.0f, tnl::ToRadian(-45), Imgs[currentFrame], TRUE);
	//
	//        return 0;
	//    }
	//}
	
	//---------------------------------------------------------------------------------------------
	//�~�Ƌ�`�̓����蔻��v�Z
	bool IsIntersectCircleBox(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& box, const int boxSize) {
		int boxSize_half = boxSize >> 1;					//��`�̃T�C�Y�̔����i�r�b�g�V�t�g����)
		int circle_squared = CircleSize * CircleSize;		//�~�̔��a��2��
		//�@��`�̏㉺���E�ӂ̍��W�����߂�
		int left_x = box.x - boxSize_half;
		int top_y = box.y - boxSize_half;
		int right_x = left_x + boxSize;
		int bottom_y = top_y + boxSize;
		//�A�~�̒��S����`�̓����ɂ��邩�ǂ����𔻒肷��
		if (left_x <= circle.x && circle.x <= right_x && top_y <= circle.y && circle.y <= bottom_y) { return true; }	//�~�̒��S����`�̓����ɂ���
		//�B�~�̒��S����`�̊O���ɂ���ꍇ�A�~�̒��S�Ƌ�`�̊e�ӂƂ̋��������߂�
		//�B-1�~�̒��S�Ƌ�`�̊e�ӂƂ̋��������߂�
		int dist_left_x = left_x - circle.x;		//����
		int dist_right_x = circle.x - right_x;		//�E��
		int dist_top_y = top_y - circle.y;			//���
		int dist_bottom_y = circle.y - bottom_y;	//����
		//�B-2�~�̒��S�Ƌ�`�̊e�ӂƂ̋������~�̔��a��菬�������ǂ����𔻒肷��
		if (dist_left_x >= 0 && dist_left_x <= CircleSize) { return true; }
		if (dist_right_x >= 0 && dist_right_x <= CircleSize) { return true; }
		if (dist_top_y >= 0 && dist_top_y <= CircleSize) { return true; }
		if (dist_bottom_y >= 0 && dist_bottom_y <= CircleSize) { return true; }
		//�C��`��4���̍��W
		int corners[4][2] = {
			{left_x, top_y},       // ����
			{right_x, top_y},      // �E��
			{left_x, bottom_y},    // ����
			{right_x, bottom_y}    // �E��
		};
		//��`��4���̍��W���~�̓����ɂ��邩�ǂ����𔻒肷��
		for (int i = 0; i < 4; i++) {
			int distance_squared = (corners[i][0] - circle.x) * (corners[i][0] - circle.x) +
				(corners[i][1] - circle.y) * (corners[i][1] - circle.y);
			if (distance_squared <= circle_squared) { return true; }
		}
		return false;
	}
	//---------------------------------------------------------------------------------------------
	//�~�Ɛ����̓����蔻��v�Z
	bool IsIntersectCircleLine(const tnl::Vector3& circle, const int CircleSize, const tnl::Vector3& lineStart, const tnl::Vector3& lineEnd) {
		int circle_squared = CircleSize * CircleSize;		//�~�̔��a��2��
		//�@�����̎n�_�ƏI�_�̃x�N�g�������߂�
		tnl::Vector3 lineVec = lineEnd - lineStart;
		//�A�����̎n�_����~�̒��S�܂ł̃x�N�g�������߂�
		tnl::Vector3 circleVec = circle - lineStart;
		//�B�����̒�����2������߂�
		float lineLengthPow = lineVec.x * lineVec.x + lineVec.y * lineVec.y;
		//�C�����̎n�_����~�̒��S�܂ł̋��������߂�i���ρj
		float dotProduct = lineVec.x * circleVec.x + lineVec.y * circleVec.y;
		//�D������̌�_���v�Z
		float t = dotProduct / lineLengthPow;
		//�Et��0~1�̊Ԃɂ���ꍇ�F������Ɍ�_�����݂���
		if (t >= 0 && t <= 1.0f) {
			//�E-1��_����~�̒��S�܂ł̋������v�Z
			tnl::Vector3 intersectionPoint;
			intersectionPoint.x = lineStart.x + t * lineVec.x;
			intersectionPoint.y = lineStart.y + t * lineVec.y;
			//�E-2������2����v�Z
			float distanceSquared = (intersectionPoint.x - circle.x) * (intersectionPoint.x - circle.x) +
				(intersectionPoint.y - circle.y) * (intersectionPoint.y - circle.y);
			//�E-3�~�̔��a��2���菬�����ꍇ�F�~�Ɛ����͏d�Ȃ�
			if (distanceSquared <= circle_squared) { return true; }
		}
		//�Ft���O�ɂ���ꍇ�i�������[�̓_�Ɖ~�̓����蔻����v�Z����j
		else {
			//�F-1�����̎n�_�Ɖ~�̒��S�̋������v�Z
			tnl::Vector3 distance_start = lineStart - circle;
			//�F-2�����̏I�_�Ɖ~�̒��S�̋������v�Z
			tnl::Vector3 distance_end = lineEnd - circle;
			//�F-3���ꂼ��̒������v�Z
			float distance_start_squared = distance_start.x * distance_start.x + distance_start.y * distance_start.y;
			float distance_end_squared = distance_end.x * distance_end.x + distance_end.y * distance_end.y;
			//�F-4�~�̔��a��2���菬�����ꍇ�A�~�Ɛ����͏d�Ȃ�
			if (distance_start_squared <= circle_squared || distance_end_squared <= circle_squared) { return true; }
		}
		return false;
	}
	//---------------------------------------------------------------------------------------------
	//�~���m�̓����蔻��v�Z
	bool IsIntersectCircleCircle(const tnl::Vector3& circle01, const int CircleSize01, const tnl::Vector3& circle02, const int CircleSize02) {
		//�@�~�̔��a�̘a���v�Z
		int radius_sum = CircleSize01 + CircleSize02;
		//�A�~�̒��S���m�̋������v�Z
		tnl::Vector3 distance = circle01 - circle02;
		//�B�~�̒��S���m�̋�����2����v�Z
		float distance_squared = distance.x * distance.x + distance.y * distance.y;
		//�C�~�̔��a�̘a��2���菬�����ꍇ�A�~���m�͏d�Ȃ�
		if (distance_squared <= radius_sum * radius_sum) { return true; }

		return false;
	}
}