#define  _CRT_SECURE_NO_WARNINGS

#include <string>

#include <sys/types.h>
#include <sys/stat.h>

#include "TimerMessageBox.h"
#include "�Q�[���f�[�^�\��.h"

using namespace std;
using namespace �֐�;


// 004D2CB8  41 3A 4D 41 50 44 41 54 41 2E 4E 36 50 00 00 00  A:MAPDATA.N6P...
#define GAMEDATASTRUCT_MAPDATAN6P_NAME_ADDRESS	0x4D2CB8	// mapdata.n6p�Ƃ������O�̃A�h���X�B�004D2CB8  A:MAPDATA.N6P...��Ƃ���NULL���R����̂ŁA�Q�����܂łȂ�ȒP�ɒ����o����B
															// ����ȏ㒷���������ꍇ�ɂ́A���̏ꏊ�̃A�h���X���Q�Ƃ��Ă��鏊�̎Q�Ɛ��ύX���邱�ƁB

#define GAMEDATASTRUCT_MAPDATAN6P_REF_ADDRESS1	0x490B60	// �umapdata.n6p�Ƃ������O�̃A�h���X�v���Q�Ƃ��Ă���ꏊ�P��
#define GAMEDATASTRUCT_MAPDATAN6P_REF_ADDRESS2	0x490C79	// �umapdata.n6p�Ƃ������O�̃A�h���X�v���Q�Ƃ��Ă���ꏊ�Q��


char szMapDataFileName[32] = "A:MAPDATAOBGK.N6P"; // ���̃v���O�������A�čēx�A���O��ύX���\�Ƃ��邽�߁A�\���ȃo�b�t�@���m�ۂ��Ă����B
												  // TSMOD�́A��ɏ�L�Q�̏ꏊ�ŎQ�Ƃ��Ă���A�h���X����A���O�̏ꏊ�𓾂Čv�Z���邽�߁A
												  // �ǂ��ɖ��O�����݂��Ă����Ȃ��Ǐ]����B

// Obgk�}�b�v�͂���̂������̂��H
bool isExistMapDataFileName = true;

void WINAPI On_������(HANDLE �Ăяo�����n���h��) {

	HANDLE hCurProcess = GetCurrentProcess();

	// �t�@�C���̑��݂̃`�F�b�N���đ��݂��Ȃ���΃G���[���o���B
	struct stat  st;
	if (! stat(szMapDataFileName+2, &st) == 0) { // +2==�ŏ��̂Q�����͖���

		// �����Ƃ������ƂŁc
		isExistMapDataFileName = false;

	}

	// �o���}�b�v�����݂��Ă��Ȃ������̂Ȃ�΃G���[���b�Z�[�W�B
	if (!isExistMapDataFileName) { 

		// �G���[���b�Z�[�W����
		string error = string(szMapDataFileName+2) +"��������܂���B\n��W�������[�h��ŋN�����܂��B";

		TimedMessageBox(NULL, error.c_str(), "�G���[", NULL, 4000); // �����ŏ�����~���b�B(���̏ꍇ3�b)

	// �o���}�b�v�����݂���Ȃ�΁c
	} else {

		// TENSHOU.EXE����"A:MAPDATA.N6P"���Q�Ƃ��Ă���ӏ����A����DLL��szMapDataFilename�|�C���^�ɒu��������B
		// �����A4D2CB8���w�������j�[���j�b�N���AszMapDataFileName���w�������j�[���j�b�N�ւƏ���������
		int Address = (int)szMapDataFileName;
		WriteProcessMemory( hCurProcess, (LPVOID)GAMEDATASTRUCT_MAPDATAN6P_REF_ADDRESS1, (LPCVOID)&Address, 4, NULL);
		WriteProcessMemory( hCurProcess, (LPVOID)GAMEDATASTRUCT_MAPDATAN6P_REF_ADDRESS2, (LPCVOID)&Address, 4, NULL);
	}
}

void WINAPI On_�V�i���I�喼�I�𒼑O() {
}

void WINAPI On_���C���Q�[���J�n() {

	// �o���}�b�v�����݂���Ȃ�΁A����ړ�����B
	if (isExistMapDataFileName) {

		Set_��ʒu(	9	,	163	,	3	);	// ���R
		Set_��ʒu(	10	,	5	,	6	);	// ����
		Set_��ʒu(	12	,	33	,	6	);	// �O�{��
		Set_��ʒu(	15	,	81	,	6	);	// �k�m��
		Set_��ʒu(	16	,	85	,	6	);	// �吹��
		Set_��ʒu(	18	,	130	,	6	);	// ���Y
		Set_��ʒu(	23	,	46	,	6	);	// ����
		Set_��ʒu(	24	,	50	,	6	);	// ����
		Set_��ʒu(	26	,	126	,	6	);	// �{��
		Set_��ʒu(	28	,	147	,	6	);	// ����
		Set_��ʒu(	29	,	150	,	6	);	// �p��
		Set_��ʒu(	31	,	12	,	9	);	// ������
		Set_��ʒu(	33	,	22	,	10	);	// ���J
		Set_��ʒu(	39	,	81	,	9	);	// ���J
		Set_��ʒu(	44	,	37	,	10	);	// ���q�R
		Set_��ʒu(	47	,	98	,	10	);	// ����
		Set_��ʒu(	49	,	123	,	9	);	// �V���c
		Set_��ʒu(	50	,	135	,	10	);	// �đ�
		Set_��ʒu(	55	,	15	,	12	);	// �Ï��R
		Set_��ʒu(	59	,	60	,	12	);	// ����
		Set_��ʒu(	66	,	132	,	12	);	// ����
		Set_��ʒu(	67	,	142	,	13	);	// ����
		Set_��ʒu(	72	,	22	,	13	);	// �{��
		Set_��ʒu(	82	,	53	,	15	);	// �V�_�R
		Set_��ʒu(	84	,	60	,	15	);	// �|�c
		Set_��ʒu(	96	,	135	,	16	);	// �O�t
		Set_��ʒu(	97	,	143	,	16	);	// ����
		Set_��ʒu(	99	,	38	,	18	);	// ����
		Set_��ʒu(	104	,	77	,	18	);	// ���l
		Set_��ʒu(	107	,	95	,	18	);	// ��
		Set_��ʒu(	118	,	111	,	18	);	// �X��
		Set_��ʒu(	120	,	138	,	19	);	// ���
		Set_��ʒu(	125	,	56	,	22	);	// �O��
		Set_��ʒu(	127	,	65	,	22	);	// ����
		Set_��ʒu(	140	,	115	,	22	);	// �E
		Set_��ʒu(	149	,	83	,	24	);	// ���F
		Set_��ʒu(	154	,	27	,	25	);	// ����
		Set_��ʒu(	160	,	115	,	25	);	// �͉z
		Set_��ʒu(	163	,	5	,	27	);	// ��F��
		Set_��ʒu(	164	,	35	,	27	);	// ���L
		Set_��ʒu(	166	,	52	,	27	);	// �F�{
		Set_��ʒu(	170	,	83	,	27	);	// �ߌÖ�
		Set_��ʒu(	173	,	121	,	27	);	// ��t
		Set_��ʒu(	175	,	18	,	28	);	// �K��
		Set_��ʒu(	183	,	37	,	30	);	// ���|
		Set_��ʒu(	193	,	52	,	30	);	// �ݘa�c
		Set_��ʒu(	203	,	87	,	33	);	// ����
		Set_��ʒu(	210	,	112	,	34	);	// �
		Set_��ʒu(	211	,	115	,	34	);	// �v����
		Set_��ʒu(	212	,	98	,	37	);	// ���V�_

	// �o���}�b�v�����݂��Ȃ��Ȃ�΃f�t�H���g�ɖ߂��Ă����B
	// ���W�́A�V�i���I�f�[�^�����ł͂Ȃ��A�Z�[�u�f�[�^�Ɏc���Ă��邽�߁A���̂悤�ɢ�߂���Ƃ����������K�v�ł���B
	} else {

		Set_��ʒu(	9	,	163	,	4	);	// ���R
		Set_��ʒu(	10	,	6	,	6	);	// ����
		Set_��ʒu(	12	,	32	,	6	);	// �O�{��
		Set_��ʒu(	15	,	82	,	6	);	// �k�m��
		Set_��ʒu(	16	,	86	,	6	);	// �吹��
		Set_��ʒu(	18	,	131	,	6	);	// ���Y
		Set_��ʒu(	23	,	45	,	7	);	// ����
		Set_��ʒu(	24	,	50	,	7	);	// ����
		Set_��ʒu(	26	,	126	,	7	);	// �{��
		Set_��ʒu(	28	,	145	,	7	);	// ����
		Set_��ʒu(	29	,	150	,	7	);	// �p��
		Set_��ʒu(	31	,	11	,	9	);	// ������
		Set_��ʒu(	33	,	20	,	9	);	// ���J
		Set_��ʒu(	39	,	82	,	9	);	// ���J
		Set_��ʒu(	44	,	36	,	10	);	// ���q�R
		Set_��ʒu(	45	,	48	,	10	);	// ���c
		Set_��ʒu(	47	,	97	,	10	);	// ����
		Set_��ʒu(	49	,	123	,	10	);	// �V���c
		Set_��ʒu(	50	,	136	,	10	);	// �đ�
		Set_��ʒu(	55	,	16	,	12	);	// �Ï��R
		Set_��ʒu(	59	,	61	,	12	);	// ����
		Set_��ʒu(	66	,	130	,	12	);	// ����
		Set_��ʒu(	67	,	140	,	12	);	// ����
		Set_��ʒu(	72	,	21	,	13	);	// �{��
		Set_��ʒu(	73	,	28	,	13	);	// �Ɗ|�R
		Set_��ʒu(	79	,	8	,	15	);	// ����]
		Set_��ʒu(	82	,	52	,	15	);	// �V�_�R
		Set_��ʒu(	84	,	61	,	15	);	// �|�c
		Set_��ʒu(	96	,	136	,	16	);	// �O�t
		Set_��ʒu(	97	,	140	,	16	);	// ����
		Set_��ʒu(	99	,	35	,	18	);	// ����
		Set_��ʒu(	104	,	78	,	18	);	// ���l
		Set_��ʒu(	105	,	81	,	18	);	// ��_
		Set_��ʒu(	107	,	96	,	18	);	// ��
		Set_��ʒu(	118	,	111	,	19	);	// �X��
		Set_��ʒu(	120	,	136	,	19	);	// ���
		Set_��ʒu(	125	,	57	,	21	);	// �O��
		Set_��ʒu(	127	,	66	,	21	);	// ����
		Set_��ʒu(	139	,	111	,	22	);	// ����
		Set_��ʒu(	140	,	116	,	22	);	// �E
		Set_��ʒu(	149	,	82	,	24	);	// ���F
		Set_��ʒu(	151	,	123	,	24	);	// �É�
		Set_��ʒu(	154	,	28	,	25	);	// ����
		Set_��ʒu(	160	,	116	,	25	);	// �͉z
		Set_��ʒu(	163	,	6	,	27	);	// ��F��
		Set_��ʒu(	164	,	36	,	27	);	// ���L
		Set_��ʒu(	166	,	51	,	27	);	// �F�{
		Set_��ʒu(	170	,	82	,	27	);	// �ߌÖ�
		Set_��ʒu(	173	,	120	,	27	);	// ��t
		Set_��ʒu(	174	,	12	,	28	);	// ������
		Set_��ʒu(	175	,	17	,	28	);	// �K��
		Set_��ʒu(	183	,	38	,	30	);	// ���|
		Set_��ʒu(	193	,	52	,	31	);	// �ݘa�c
		Set_��ʒu(	203	,	88	,	33	);	// ����
		Set_��ʒu(	205	,	5	,	34	);	// ��q��
		Set_��ʒu(	210	,	113	,	34	);	// �
		Set_��ʒu(	211	,	117	,	34	);	// �v����
		Set_��ʒu(	212	,	98	,	36	);	// ���V�_

	}

}



