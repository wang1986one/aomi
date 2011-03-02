#include "WheelData.h"
#include <orz/Toolkit_Base/Exception.h>
using namespace Orz;
//WheelData::~WheelData(void)
//{
//
//}
WheelData::WheelData(void)
{
	
	using namespace WheelEnum;
	using namespace AnimalEnum;


	/*  0x00   ����
	0x01   ����
	0x02   ����*/
	
	_wheelMap[YELLOW_RABBIT] = WheelMsg( NONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow); 
	_wheelMap[GREEN_RABBIT] = WheelMsg( NONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Green); //0x01  ����
	_wheelMap[RED_RABBIT] = WheelMsg( NONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Red);   //0x02  ����



	_wheelMap[YELLOW_MONKEY] = WheelMsg( NONE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//�ƺ� 
	_wheelMap[GREEN_MONKEY] = WheelMsg( NONE, ANIMAL_TYPE( MONKEY , PEOPLE),  Green); //�̺�
	_wheelMap[RED_MONKEY] = WheelMsg( NONE, ANIMAL_TYPE( MONKEY , PEOPLE),  Red);   //���

	/*   
	0x06   ����è
	0x07   ����è
	0x08   ����è*/


	_wheelMap[YELLOW_PANDA] = WheelMsg( NONE, ANIMAL_TYPE( PANDA , PEOPLE),  Yellow); //����è
	_wheelMap[GREEN_PANDA] = WheelMsg( NONE, ANIMAL_TYPE( PANDA , PEOPLE),  Green); //����è
	_wheelMap[RED_PANDA] = WheelMsg( NONE, ANIMAL_TYPE( PANDA , PEOPLE),  Red);  //����è



	/*
	0x09   ��ʨ��
	0x0A   ��ʨ��
	0x0B   ��ʨ��*/


	_wheelMap[YELLOW_LION] = WheelMsg( NONE, ANIMAL_TYPE( LION , PEOPLE),  Yellow); //  ��ʨ��
	_wheelMap[GREEN_LION] = WheelMsg( NONE, ANIMAL_TYPE( LION , PEOPLE),  Green);//��ʨ�� 
	_wheelMap[RED_LION] = WheelMsg( NONE, ANIMAL_TYPE( LION , PEOPLE),  Red); //	��ʨ��


	
	/*    
	0x0c   ��ɫ������
	0x0d   ��ɫ������
	0x0e    ��ɫ������

	0x0f   ��ɫ�ƺ���
	0x10   ��ɫ�̺���
	0x11   ��ɫ�����

	0x12  ��ɫ����è
	0x13  ��ɫ����è
	0x14   ��ɫ����è

	0x15   ��ɫ��ʨ��
	0x16   ��ɫ��ʨ��
	0x17   ��ɫ��ʨ��*/



	_wheelMap[G_YELLOW_RABBIT] = WheelMsg( GOLD, ANIMAL_TYPE( RABBIT , KING),  Yellow); //	�ƽ���
	_wheelMap[G_GREEN_RABBIT] = WheelMsg( GOLD, ANIMAL_TYPE( RABBIT , KING),  Green); //�̽���
	_wheelMap[G_RED_RABBIT] = WheelMsg( GOLD, ANIMAL_TYPE( RABBIT , KING),  Red); // �����

	_wheelMap[G_YELLOW_MONKEY] = WheelMsg( GOLD, ANIMAL_TYPE( MONKEY , KING),  Yellow);//�ƽ��
	_wheelMap[G_GREEN_MONKEY] = WheelMsg( GOLD, ANIMAL_TYPE( MONKEY , KING),  Green); //	�̽��
	_wheelMap[G_RED_MONKEY] = WheelMsg( GOLD, ANIMAL_TYPE( MONKEY , KING),  Red);   // ����


	_wheelMap[G_YELLOW_PANDA] = WheelMsg( GOLD, ANIMAL_TYPE( PANDA , KING),  Yellow); //�ƽ���è
	_wheelMap[G_GREEN_PANDA] = WheelMsg( GOLD, ANIMAL_TYPE( PANDA , KING),  Green); //�̽���è
	_wheelMap[G_RED_PANDA] = WheelMsg( GOLD, ANIMAL_TYPE( PANDA , KING),  Red);  //�����è

	_wheelMap[G_YELLOW_LION] = WheelMsg( GOLD, ANIMAL_TYPE( LION , KING),  Yellow); //  �ƽ�ʨ��
	_wheelMap[G_GREEN_LION] = WheelMsg( GOLD, ANIMAL_TYPE( LION , KING),  Green);//�̽�ʨ��
	_wheelMap[G_RED_LION] = WheelMsg( GOLD, ANIMAL_TYPE( LION , KING),  Red);//���ʨ��
		

	/*    
	0x18   ��ɫȫ��
	0x19   ��ɫȫ��
	0x1a   ��ɫȫ��*/



	_wheelMap[ALL_YELLOW] = WheelMsg( ALL_COLOR, ANIMAL_TYPE( LION , PEOPLE),  Yellow); //   ��ɫȫ��
	_wheelMap[ALL_GREEN] = WheelMsg( ALL_COLOR, ANIMAL_TYPE( LION , PEOPLE),  Green); //  ��ɫȫ��
	_wheelMap[ALL_RED] = WheelMsg( ALL_COLOR, ANIMAL_TYPE( LION , PEOPLE),  Red);  // ��ɫȫ��
	/*   
	0x1b   ����ȫ��
	0x1c   ����ȫ��
	0x1d    ��èȫ��
	0x1e   ʨ��ȫ��*/





	_wheelMap[ALL_RABBIT] = WheelMsg( ALL_ANIMAL, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow); //   ����ȫ��
	_wheelMap[ALL_MONKEY] = WheelMsg( ALL_ANIMAL, ANIMAL_TYPE( MONKEY , PEOPLE),  Green);// ����ȫ��
	_wheelMap[ALL_PANDA] = WheelMsg( ALL_ANIMAL, ANIMAL_TYPE( PANDA , PEOPLE),  Red); //   ��èȫ��
	_wheelMap[ALL_LION] = WheelMsg( ALL_ANIMAL, ANIMAL_TYPE( LION , PEOPLE),  Red); //     ʨ��ȫ��                      

		

	/*        
	0x1f   ����2��
	0x20   ����2��
	0x21   ����2��
	0x22   �ƺ�2��
	0x23   �̺�2��
	0x24   ���2��
	0x25   ��è2��
	0x26   ��è2��
	0x27   ��è2��
	0x28  ��ʨ2��
	0x29   ��ʨ2��
	0x2a  ��ʨ2��*/






	_wheelMap[DOUBLE_YELLOW_RABBIT] = WheelMsg( DOUBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow); //	����2��
	_wheelMap[DOUBLE_GREEN_RABBIT] = WheelMsg( DOUBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Green); //����2��
	_wheelMap[DOUBLE_RED_RABBIT] = WheelMsg( DOUBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Red); // ����	2��

	_wheelMap[DOUBLE_YELLOW_MONKEY] = WheelMsg( DOUBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//�ƺ� 2��
	_wheelMap[DOUBLE_GREEN_MONKEY] = WheelMsg( DOUBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Green); //	�̺� 2��
	_wheelMap[DOUBLE_RED_MONKEY] = WheelMsg( DOUBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Red);   // ���2��


	_wheelMap[DOUBLE_YELLOW_PANDA] = WheelMsg( DOUBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Yellow); //����è	2��
	_wheelMap[DOUBLE_GREEN_PANDA] = WheelMsg( DOUBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Green); //����è2��
	_wheelMap[DOUBLE_RED_PANDA] = WheelMsg( DOUBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Red);  //����è 2��

	_wheelMap[DOUBLE_YELLOW_LION] = WheelMsg( DOUBLE, ANIMAL_TYPE( LION , PEOPLE),  Yellow); //  ��ʨ��2��
	_wheelMap[DOUBLE_GREEN_LION] = WheelMsg( DOUBLE, ANIMAL_TYPE( LION , PEOPLE),  Green);//��ʨ��	 2��
	_wheelMap[DOUBLE_RED_LION] = WheelMsg( DOUBLE, ANIMAL_TYPE( LION , PEOPLE),  Red); //	��ʨ��   2��


		
	/*  
	0x2b   ����3��
	0x2c   ����3��
	0x2d   ����3��
	0x2e   �ƺ�3��
	0x2f   �̺�3��
	0x30   ���3��
	0x31   ��è3��
	0x32   ��è3��
	0x33   ��è3��
	0x34   ��ʨ3��
	0x35   ��ʨ3��
	0x36   ��ʨ3��*/



	_wheelMap[TREBLE_YELLOW_RABBIT] = WheelMsg( TREBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow); //	����3��
	_wheelMap[TREBLE_GREEN_RABBIT] = WheelMsg( TREBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Green); //����3��
	_wheelMap[TREBLE_RED_RABBIT] = WheelMsg( TREBLE, ANIMAL_TYPE( RABBIT , PEOPLE),  Red); // ����	3��

	_wheelMap[TREBLE_YELLOW_MONKEY] = WheelMsg( TREBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//�ƺ� 3��
	_wheelMap[TREBLE_GREEN_MONKEY] = WheelMsg( TREBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Green); //	�̺� 3��
	_wheelMap[TREBLE_RED_MONKEY] = WheelMsg( TREBLE, ANIMAL_TYPE( MONKEY , PEOPLE),  Red);   // ���3��


	_wheelMap[TREBLE_YELLOW_PANDA] = WheelMsg( TREBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Yellow); //����è	3��
	_wheelMap[TREBLE_GREEN_PANDA] = WheelMsg( TREBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Green); //����è3��
	_wheelMap[TREBLE_RED_PANDA] = WheelMsg( TREBLE, ANIMAL_TYPE( PANDA , PEOPLE),  Red);  //����è 3��

	_wheelMap[TREBLE_YELLOW_LION] = WheelMsg( TREBLE, ANIMAL_TYPE( LION , PEOPLE),  Yellow); //  ��ʨ��3��
	_wheelMap[TREBLE_GREEN_LION] = WheelMsg( TREBLE, ANIMAL_TYPE( LION , PEOPLE),  Green);//��ʨ��	 3��
	_wheelMap[TREBLE_RED_LION] = WheelMsg( TREBLE, ANIMAL_TYPE( LION , PEOPLE),  Red);//��ʨ��	 3��


	/*   
	0x37   ����+��è
	0x38   ����+��è
	0x39   �ƺ�+��ʨ
	0x3a   ����+�̺�
	0x3b   ���+��è*/




	_wheelMap[RED_RABBIT_YELLOW_PANDA] = WheelMsg( ONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Red);//����+��è
	_wheelMap[GREEN_RABBIT_RED_PANDA] = WheelMsg( ONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Green);//����+��è
	_wheelMap[YELLOW_MONKEY_GREEN_LION] = WheelMsg( ONE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//�ƺ�+��ʨ
	_wheelMap[YELLOW_RABBIT_GREEN_MONKEY] = WheelMsg( ONE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow);//����+�̺�
	_wheelMap[RED_MONKEY_GREEN_PANDA] = WheelMsg( ONE, ANIMAL_TYPE( MONKEY , PEOPLE),  Red);//���+��è

	//0x3c   ����+�̺�+��ʨ
	//0x3d   ����+����+��è
	//0x3e   ���+����+��è

	_wheelMap[YELLOW_RABBIT_GREEN_MONKEY_RED_LION] = WheelMsg( TWO, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow);//����+�̺�+��ʨ
	_wheelMap[GREEN_RABBIT_RED_RABBIT_GREEN_PANDA] = WheelMsg( TWO, ANIMAL_TYPE( RABBIT , PEOPLE),  Green);//����+����+��è
	_wheelMap[RED_MONKEY_YELLOW_RABBIT_YELLOW_PANDA] = WheelMsg( TWO, ANIMAL_TYPE( MONKEY , PEOPLE),  Red);// ���+����+��è


	//0x3f   ����+����+�ƺ�+��è
	//0x40   ����+�̺�+�ƺ�+��è
	//0x41  �ƺ�+����+�̺�+��ʨ


	_wheelMap[YELLOW_RABBIT_RED_RABBIT_YELLOW_MANKEY_GREEN_PANDA] = WheelMsg( THREE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow);// ����+����+�ƺ�+��è
	_wheelMap[GREEN_RABBIT_GREEN_MONKEY_YELLOW_MONKEY_YELLOW_PANDA] = WheelMsg( THREE, ANIMAL_TYPE( RABBIT , PEOPLE),  Green);//����+�̺�+�ƺ�+��è
	_wheelMap[YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION] = WheelMsg( THREE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//�ƺ�+����+�̺�+��ʨ

	/*   0x42  ����+�ƺ�+���+��è+�̺�
	0x43  ����+����+��è+��è+��ʨ
	0x44  ����+�ƺ�+�̺�+���+��è*/
	_wheelMap[RED_RABBIT_YELLOW_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_MONKEY] = WheelMsg( FOUR, ANIMAL_TYPE( RABBIT , PEOPLE),  Red);// ����+�ƺ�+���+��è+�̺�
	_wheelMap[YELLOW_RABBIT_RED_RABBIT_YELLOW_PANDA_GREEN_PANDA_RED_LION] = WheelMsg( FOUR, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow);//����+����+��è+��è+��ʨ
	_wheelMap[GREEN_RABBIT_YELLOW_MONKEY_GREEN_MONKEY_RED_MONKEY_GREEN_PANDA] = WheelMsg( FOUR, ANIMAL_TYPE( RABBIT , PEOPLE),  Green);//����+�ƺ�+�̺�+���+��è

			
	/*   
	0x45 ����+����+�̺�+��è+��è+��ʨ
	0x46 �ƺ�+����+�̺�+��è+��ʨ+��ʨ
	0x47 �̺�+���+��è+��è+��è+��ʨ*/
	_wheelMap[YELLOW_RUBBIT_RED_RABBIT_GREEN_MONKEY_YELLOW_PANDA_GREEN_PANDA_YELLOW_LION] = WheelMsg( FIVE, ANIMAL_TYPE( RABBIT , PEOPLE),  Yellow);// ����+����+�̺�+��è+��è+��ʨ
	_wheelMap[YELLOW_MOKEY_YELLOW_RABBIT_GREEN_MONKEY_GREEN_PANDA_YELLOW_LION_RED_LION] = WheelMsg( FIVE, ANIMAL_TYPE( MONKEY , PEOPLE),  Yellow);//�ƺ�+����+�̺�+��è+��ʨ+��ʨ
	_wheelMap[GREEN_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_PANDA_RED_PANDA_GREEN_LION] = WheelMsg( FIVE, ANIMAL_TYPE( MONKEY , PEOPLE),  Green);//�̺�+���+��è+��è+��è+��ʨ









}


WheelData & WheelData::getInstance(void)
{
	return *(getInstancePtr());
}
WheelData * WheelData::getInstancePtr(void)
{
	static WheelData instance;
	return &instance;
}

const WheelData::WheelMsg & WheelData::getWheelMsg(WheelEnum::HARDWARE_WIN_MODE mode) const
{
	WheelMap::const_iterator it = _wheelMap.find(mode);
	if(it == _wheelMap.end())
	{
		throw ORZ_EXCEPTION(Exception::ERR_ITEM_NOT_FOUND)<<errno_info_text("Can't find WheelEnum::HARDWARE_WIN_MODE in the _wheelMap!");
	}
	return it->second;
}