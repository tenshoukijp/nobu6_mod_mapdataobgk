#include <cassert>
#include "�Q�[���f�[�^�\��.h"

namespace �֐� {



// �閼���擾����
string Get_�閼( int ��ԍ��y�z��p�z) {

	// �͈̓`�F�b�N
	assert( 0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z�� ); 

	return string( p����[��ԍ��y�z��p�z]._�閼 );
}


// �閼��ݒ肷��
void   Set_�閼( int ��ԍ��y�z��p�z, string �閼 ) {

	// �͈̓`�F�b�N
	assert( 0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z�� ); 

	strcpy_s( p����[��ԍ��y�z��p�z]._�閼, �閼.c_str() );
}


// ����ړ�����B
void	Set_��ʒu(int ��ԍ��y�z��p�z, int �w�ʒu, int �x�ʒu) {
	// �͈̓`�F�b�N
	assert( 0 <= ��ԍ��y�z��p�z && ��ԍ��y�z��p�z < �ő吔::����::�z�� ); 

	p��t�����[��ԍ��y�z��p�z].�w�ʒu = �w�ʒu;
	p��t�����[��ԍ��y�z��p�z].�x�ʒu = �x�ʒu;
}

}
