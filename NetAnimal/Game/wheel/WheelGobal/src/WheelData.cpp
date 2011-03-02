#include "WheelGobalStableHeaders.h"
#include "WheelData.h"
#include "WinData.h"
#include "TVListMap.h"
#include <orz/Toolkit_Base/Exception.h>

using namespace Orz;
//WheelData::~WheelData(void)
//{
//
//}
WheelData_::WheelData_(void)
{
	
	using namespace WheelEnum;


	/*  0x00   ����
	0x01   ����
	0x02   ����*/
	
	_wheelMap[YELLOW_RABBIT] = WheelMsg( NONE, AnimalType( RABBIT , PEOPLE),  Yellow); 
	_wheelMap[GREEN_RABBIT] = WheelMsg( NONE, AnimalType( RABBIT , PEOPLE),  Green); //0x01  ����
	_wheelMap[RED_RABBIT] = WheelMsg( NONE, AnimalType( RABBIT , PEOPLE),  Red);   //0x02  ����



	_wheelMap[YELLOW_MONKEY] = WheelMsg( NONE, AnimalType( MONKEY , PEOPLE),  Yellow);//�ƺ� 
	_wheelMap[GREEN_MONKEY] = WheelMsg( NONE, AnimalType( MONKEY , PEOPLE),  Green); //�̺�
	_wheelMap[RED_MONKEY] = WheelMsg( NONE, AnimalType( MONKEY , PEOPLE),  Red);   //���

	/*   
	0x06   ����è
	0x07   ����è
	0x08   ����è*/


	_wheelMap[YELLOW_PANDA] = WheelMsg( NONE, AnimalType( PANDA , PEOPLE),  Yellow); //����è
	_wheelMap[GREEN_PANDA] = WheelMsg( NONE, AnimalType( PANDA , PEOPLE),  Green); //����è
	_wheelMap[RED_PANDA] = WheelMsg( NONE, AnimalType( PANDA , PEOPLE),  Red);  //����è



	/*
	0x09   ��ʨ��
	0x0A   ��ʨ��
	0x0B   ��ʨ��*/


	_wheelMap[YELLOW_LION] = WheelMsg( NONE, AnimalType( LION , PEOPLE),  Yellow); //  ��ʨ��
	_wheelMap[GREEN_LION] = WheelMsg( NONE, AnimalType( LION , PEOPLE),  Green);//��ʨ�� 
	_wheelMap[RED_LION] = WheelMsg( NONE, AnimalType( LION , PEOPLE),  Red); //	��ʨ��


	
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



	_wheelMap[G_YELLOW_RABBIT] = WheelMsg( GOLD, AnimalType( RABBIT , KING),  Yellow); //	�ƽ���
	_wheelMap[G_GREEN_RABBIT] = WheelMsg( GOLD, AnimalType( RABBIT , KING),  Green); //�̽���
	_wheelMap[G_RED_RABBIT] = WheelMsg( GOLD, AnimalType( RABBIT , KING),  Red); // �����

	_wheelMap[G_YELLOW_MONKEY] = WheelMsg( GOLD, AnimalType( MONKEY , KING),  Yellow);//�ƽ��
	_wheelMap[G_GREEN_MONKEY] = WheelMsg( GOLD, AnimalType( MONKEY , KING),  Green); //	�̽��
	_wheelMap[G_RED_MONKEY] = WheelMsg( GOLD, AnimalType( MONKEY , KING),  Red);   // ����


	_wheelMap[G_YELLOW_PANDA] = WheelMsg( GOLD, AnimalType( PANDA , KING),  Yellow); //�ƽ���è
	_wheelMap[G_GREEN_PANDA] = WheelMsg( GOLD, AnimalType( PANDA , KING),  Green); //�̽���è
	_wheelMap[G_RED_PANDA] = WheelMsg( GOLD, AnimalType( PANDA , KING),  Red);  //�����è

	_wheelMap[G_YELLOW_LION] = WheelMsg( GOLD, AnimalType( LION , KING),  Yellow); //  �ƽ�ʨ��
	_wheelMap[G_GREEN_LION] = WheelMsg( GOLD, AnimalType( LION , KING),  Green);//�̽�ʨ��
	_wheelMap[G_RED_LION] = WheelMsg( GOLD, AnimalType( LION , KING),  Red);//���ʨ��
		

	/*    
	0x18   ��ɫȫ��
	0x19   ��ɫȫ��
	0x1a   ��ɫȫ��*/



	_wheelMap[ALL_YELLOW] = WheelMsg( ALL_COLOR, AnimalType( LION , PEOPLE),  Yellow); //   ��ɫȫ��
	_wheelMap[ALL_GREEN] = WheelMsg( ALL_COLOR, AnimalType( LION , PEOPLE),  Green); //  ��ɫȫ��
	_wheelMap[ALL_RED] = WheelMsg( ALL_COLOR, AnimalType( LION , PEOPLE),  Red);  // ��ɫȫ��
	/*   
	0x1b   ����ȫ��
	0x1c   ����ȫ��
	0x1d    ��èȫ��
	0x1e   ʨ��ȫ��*/





	_wheelMap[ALL_RABBIT] = WheelMsg( ALL_ANIMAL, AnimalType( RABBIT , PEOPLE),  Yellow); //   ����ȫ��
	_wheelMap[ALL_MONKEY] = WheelMsg( ALL_ANIMAL, AnimalType( MONKEY , PEOPLE),  Green);// ����ȫ��
	_wheelMap[ALL_PANDA] = WheelMsg( ALL_ANIMAL, AnimalType( PANDA , PEOPLE),  Red); //   ��èȫ��
	_wheelMap[ALL_LION] = WheelMsg( ALL_ANIMAL, AnimalType( LION , PEOPLE),  Red); //     ʨ��ȫ��                      

		

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






	_wheelMap[DOUBLE_YELLOW_RABBIT] = WheelMsg( DOUBLE, AnimalType( RABBIT , PEOPLE),  Yellow); //	����2��
	_wheelMap[DOUBLE_GREEN_RABBIT] = WheelMsg( DOUBLE, AnimalType( RABBIT , PEOPLE),  Green); //����2��
	_wheelMap[DOUBLE_RED_RABBIT] = WheelMsg( DOUBLE, AnimalType( RABBIT , PEOPLE),  Red); // ����	2��

	_wheelMap[DOUBLE_YELLOW_MONKEY] = WheelMsg( DOUBLE, AnimalType( MONKEY , PEOPLE),  Yellow);//�ƺ� 2��
	_wheelMap[DOUBLE_GREEN_MONKEY] = WheelMsg( DOUBLE, AnimalType( MONKEY , PEOPLE),  Green); //	�̺� 2��
	_wheelMap[DOUBLE_RED_MONKEY] = WheelMsg( DOUBLE, AnimalType( MONKEY , PEOPLE),  Red);   // ���2��


	_wheelMap[DOUBLE_YELLOW_PANDA] = WheelMsg( DOUBLE, AnimalType( PANDA , PEOPLE),  Yellow); //����è	2��
	_wheelMap[DOUBLE_GREEN_PANDA] = WheelMsg( DOUBLE, AnimalType( PANDA , PEOPLE),  Green); //����è2��
	_wheelMap[DOUBLE_RED_PANDA] = WheelMsg( DOUBLE, AnimalType( PANDA , PEOPLE),  Red);  //����è 2��

	_wheelMap[DOUBLE_YELLOW_LION] = WheelMsg( DOUBLE, AnimalType( LION , PEOPLE),  Yellow); //  ��ʨ��2��
	_wheelMap[DOUBLE_GREEN_LION] = WheelMsg( DOUBLE, AnimalType( LION , PEOPLE),  Green);//��ʨ��	 2��
	_wheelMap[DOUBLE_RED_LION] = WheelMsg( DOUBLE, AnimalType( LION , PEOPLE),  Red); //	��ʨ��   2��


		
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



	_wheelMap[TREBLE_YELLOW_RABBIT] = WheelMsg( TREBLE, AnimalType( RABBIT , PEOPLE),  Yellow); //	����3��
	_wheelMap[TREBLE_GREEN_RABBIT] = WheelMsg( TREBLE, AnimalType( RABBIT , PEOPLE),  Green); //����3��
	_wheelMap[TREBLE_RED_RABBIT] = WheelMsg( TREBLE, AnimalType( RABBIT , PEOPLE),  Red); // ����	3��

	_wheelMap[TREBLE_YELLOW_MONKEY] = WheelMsg( TREBLE, AnimalType( MONKEY , PEOPLE),  Yellow);//�ƺ� 3��
	_wheelMap[TREBLE_GREEN_MONKEY] = WheelMsg( TREBLE, AnimalType( MONKEY , PEOPLE),  Green); //	�̺� 3��
	_wheelMap[TREBLE_RED_MONKEY] = WheelMsg( TREBLE, AnimalType( MONKEY , PEOPLE),  Red);   // ���3��


	_wheelMap[TREBLE_YELLOW_PANDA] = WheelMsg( TREBLE, AnimalType( PANDA , PEOPLE),  Yellow); //����è	3��
	_wheelMap[TREBLE_GREEN_PANDA] = WheelMsg( TREBLE, AnimalType( PANDA , PEOPLE),  Green); //����è3��
	_wheelMap[TREBLE_RED_PANDA] = WheelMsg( TREBLE, AnimalType( PANDA , PEOPLE),  Red);  //����è 3��

	_wheelMap[TREBLE_YELLOW_LION] = WheelMsg( TREBLE, AnimalType( LION , PEOPLE),  Yellow); //  ��ʨ��3��
	_wheelMap[TREBLE_GREEN_LION] = WheelMsg( TREBLE, AnimalType( LION , PEOPLE),  Green);//��ʨ��	 3��
	_wheelMap[TREBLE_RED_LION] = WheelMsg( TREBLE, AnimalType( LION , PEOPLE),  Red);//��ʨ��	 3��


	/*   
	0x37   ����+��è
	0x38   ����+��è
	0x39   �ƺ�+��ʨ
	0x3a   ����+�̺�
	0x3b   ���+��è*/




	_wheelMap[RED_RABBIT_YELLOW_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Red);//����+��è
	_wheelMap[GREEN_RABBIT_RED_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Green);//����+��è
	_wheelMap[YELLOW_MONKEY_GREEN_LION] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Yellow);//�ƺ�+��ʨ
	_wheelMap[YELLOW_RABBIT_GREEN_MONKEY] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Yellow);//����+�̺�
	_wheelMap[RED_MONKEY_GREEN_PANDA] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Red);//���+��è

	//0x3c   ����+�̺�+��ʨ
	//0x3d   ����+����+��è
	//0x3e   ���+����+��è

	_wheelMap[YELLOW_RABBIT_GREEN_MONKEY_RED_LION] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Yellow);//����+�̺�+��ʨ
	_wheelMap[GREEN_RABBIT_RED_RABBIT_GREEN_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Green);//����+����+��è
	_wheelMap[RED_MONKEY_YELLOW_RABBIT_YELLOW_PANDA] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Red);// ���+����+��è


	//0x3f   ����+����+�ƺ�+��è
	//0x40   ����+�̺�+�ƺ�+��è
	//0x41  �ƺ�+����+�̺�+��ʨ


	_wheelMap[YELLOW_RABBIT_RED_RABBIT_YELLOW_MANKEY_GREEN_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Yellow);// ����+����+�ƺ�+��è
	_wheelMap[GREEN_RABBIT_GREEN_MONKEY_YELLOW_MONKEY_YELLOW_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Green);//����+�̺�+�ƺ�+��è
	_wheelMap[YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Yellow);//�ƺ�+����+�̺�+��ʨ

	/*   0x42  ����+�ƺ�+���+��è+�̺�
	0x43  ����+����+��è+��è+��ʨ
	0x44  ����+�ƺ�+�̺�+���+��è*/
	_wheelMap[RED_RABBIT_YELLOW_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_MONKEY] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Red);// ����+�ƺ�+���+��è+�̺�
	_wheelMap[YELLOW_RABBIT_RED_RABBIT_YELLOW_PANDA_GREEN_PANDA_RED_LION] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Yellow);//����+����+��è+��è+��ʨ
	_wheelMap[GREEN_RABBIT_YELLOW_MONKEY_GREEN_MONKEY_RED_MONKEY_GREEN_PANDA] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Green);//����+�ƺ�+�̺�+���+��è

			
	/*   
	0x45 ����+����+�̺�+��è+��è+��ʨ
	0x46 �ƺ�+����+�̺�+��è+��ʨ+��ʨ
	0x47 �̺�+���+��è+��è+��è+��ʨ*/
	_wheelMap[YELLOW_RUBBIT_RED_RABBIT_GREEN_MONKEY_YELLOW_PANDA_GREEN_PANDA_YELLOW_LION] = WheelMsg( MANY, AnimalType( RABBIT , PEOPLE),  Yellow);// ����+����+�̺�+��è+��è+��ʨ
	_wheelMap[YELLOW_MOKEY_YELLOW_RABBIT_GREEN_MONKEY_GREEN_PANDA_YELLOW_LION_RED_LION] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Yellow);//�ƺ�+����+�̺�+��è+��ʨ+��ʨ
	_wheelMap[GREEN_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_PANDA_RED_PANDA_GREEN_LION] = WheelMsg( MANY, AnimalType( MONKEY , PEOPLE),  Green);//�̺�+���+��è+��è+��è+��ʨ



	 /*5,8,6,8,13,10,14,23,17,28,46,35,(����,����,����,�ƺ�,�̺�,���,����,����,����,��ʨ,��ʨ,��ʨ)
 5,6,7,8,10,11,15,17,26,31,35,40,
  7,5,6,11,8,10,20,15,17,40,31,35,
  4,7,8,7,11,13,12,20,23,25,40,46,
  7,8,4,11,13,7,20,23,12,40,46,25,
  8,4,7,13,7,11,23,12,20,46,25,40*/

	_rates[0][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 5;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 8;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 6;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 8;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 13;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 10;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 14;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 23;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 17;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 28;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 46;
	_rates[0][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 35;

////////////////////////////////////////////////////////////////////

	_rates[1][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 5;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 6;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 7;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 8;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 10;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 11;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 15;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 17;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 26;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 31;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 35;
	_rates[1][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 40;

///////////////////////////////////////////////////////////////////

	_rates[2][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 7;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 5;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 6;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 11;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 8;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 10;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 20;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 15;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 17;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 40;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 31;
	_rates[2][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 35;


	
///////////////////////////////////////////////////////////////////

	_rates[3][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 4;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 7;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 8;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 7;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 11;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 13;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 12;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 20;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 23;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 25;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 40;
	_rates[3][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 46;

///////////////////////////////////////////////////////////////////


	_rates[4][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 7;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 8;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 4;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 11;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 13;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 7;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 20;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 23;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 12;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 40;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 46;
	_rates[4][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 25;

///////////////////////////////////////////////////////////////////
 
	_rates[5][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow)] = 8;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green)] = 4;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red)] = 7;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow)] = 13;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green)] = 7;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red)] = 11;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow)] = 23;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green)] = 12;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red)] = 20;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow)] = 46;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green)] = 25;
	_rates[5][WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red)] = 40;



///////////////////////////////////////////////////////////////////////

	
	TVListMapPtr listMap(new TVListMap());
	WheelEnum::TVListPtr list;


	//0x37   ����+��è

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	listMap->insert(*list->begin(), list);

	/*0x38   ����+��è*/

	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red));
	listMap->insert(*list->begin(), list);

	/*0x39   �ƺ�+��ʨ*/

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green));
	listMap->insert(*list->begin(), list);

	//0x3a   ����+�̺�

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	listMap->insert(*list->begin(), list);


	/*0x3b   ���+��è*/
	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	listMap->insert(*list->begin(), list);

	
	_tvListMap[0] = listMap;


////////////////////////////////
	
	listMap.reset(new TVListMap());


//0x3c   ����+�̺�+��ʨ

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red));
	listMap->insert(*list->begin(), list);

//0x3d   ����+����+��è

	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	listMap->insert(*list->begin(), list);
//0x3e   ���+����+��è

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	listMap->insert(*list->begin(), list);
	
	_tvListMap[1] = listMap;

////////////////////////////////
	
	listMap.reset(new TVListMap());

//0x3f   ����+����+�ƺ�+��è


	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	listMap->insert(*list->begin(), list);

//0x43 ����+�̺�+�ƺ�+��è

	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	listMap->insert(*list->begin(), list);

//0x44 �ƺ�+����+�̺�+��ʨ

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow));
	listMap->insert(*list->begin(), list);
	
	_tvListMap[2] = listMap;


////////////////////////////////////////
	

	listMap.reset(new TVListMap());

//0x42  ����+�ƺ�+���+��è+�̺�

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	listMap->insert(*list->begin(), list);

//0x43  ����+����+��è+��è+��ʨ
	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red));
	listMap->insert(*list->begin(), list);

//0x44 ����+�ƺ�+�̺�+���+��è

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	listMap->insert(*list->begin(), list);
	
	_tvListMap[3] = listMap;



////////////////////////////////////////
	

	listMap.reset(new TVListMap());

//0x45 ����+����+�̺�+��è+��è+��ʨ

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow));
	listMap->insert(*list->begin(), list);

//0x46  �ƺ�+����+�̺�+��è+��ʨ+��ʨ
	
	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::RABBIT, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Red));
	listMap->insert(*list->begin(), list);

//0x47 �̺�+���+��è+��è+��è+��ʨ

	list.reset(new WheelEnum::TVList());
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::MONKEY, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Yellow));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Green));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::PANDA, WheelEnum::Red));
	list->push_back(WheelEnum::AnimalItem(WheelEnum::LION, WheelEnum::Green));
	listMap->insert(*list->begin(), list);
	
	_tvListMap[4] = listMap;

}
int getN(WheelEnum::HARDWARE_WIN_MODE mode)
{
	using namespace WheelEnum;
	switch(mode)
	{
	case RED_RABBIT_YELLOW_PANDA:
	case GREEN_RABBIT_RED_PANDA:
	case YELLOW_MONKEY_GREEN_LION:
	case YELLOW_RABBIT_GREEN_MONKEY:
	case RED_MONKEY_GREEN_PANDA:
		return 0;
	case YELLOW_RABBIT_GREEN_MONKEY_RED_LION:
	case GREEN_RABBIT_RED_RABBIT_GREEN_PANDA:
	case RED_MONKEY_YELLOW_RABBIT_YELLOW_PANDA:
		return 1;
		
	case YELLOW_RABBIT_RED_RABBIT_YELLOW_MANKEY_GREEN_PANDA:
	case GREEN_RABBIT_GREEN_MONKEY_YELLOW_MONKEY_YELLOW_PANDA:
	case YELLOW_MONKEY_YELLOW_RABBIT_GREEN_PANDA_YELLOW_LION:
		return 2;
	case RED_RABBIT_YELLOW_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_MONKEY:
	case YELLOW_RABBIT_RED_RABBIT_YELLOW_PANDA_GREEN_PANDA_RED_LION:
	case GREEN_RABBIT_YELLOW_MONKEY_GREEN_MONKEY_RED_MONKEY_GREEN_PANDA:
		return 3;
	case YELLOW_RUBBIT_RED_RABBIT_GREEN_MONKEY_YELLOW_PANDA_GREEN_PANDA_YELLOW_LION:
	case YELLOW_MOKEY_YELLOW_RABBIT_GREEN_MONKEY_GREEN_PANDA_YELLOW_LION_RED_LION:
	case GREEN_MONKEY_RED_MONKEY_YELLOW_PANDA_GREEN_PANDA_RED_PANDA_GREEN_LION:
		return 4;
			
	}
	return 4;
}
		
bool WheelData_::hasTVNext(WheelEnum::HARDWARE_WIN_MODE mode,  WheelEnum::AnimalItem ai, size_t i)
{
	TVListMapPtr listMap = _tvListMap[getN(mode)];
	return listMap->hasAnimalItem(ai, i);
}
WheelEnum::AnimalItem WheelData_::getTVNext(WheelEnum::HARDWARE_WIN_MODE mode,  WheelEnum::AnimalItem ai, size_t i)
{
	TVListMapPtr listMap = _tvListMap[getN(mode)];
	return listMap->getAnimalItem(ai, i);
}
int WheelData_::getOverride(WheelEnum::AnimalItem ai) 
{

	return _rates[_rate][ai];
}


void WheelData_::setRate(WheelEnum::RATE rate) 
{
	_rate = rate;
}


WheelData_ & WheelData_::getInstance(void)
{
	return *(getInstancePtr());
}
WheelData_ * WheelData_::getInstancePtr(void)
{
	static WheelData_ instance;
	return &instance;
}

//WheelEnum::RATE

const WheelData_::WheelMsg & WheelData_::getWheelMsg(WheelEnum::HARDWARE_WIN_MODE mode) const
{
	WheelMap::const_iterator it = _wheelMap.find(mode);
	if(it == _wheelMap.end())
	{
		throw ORZ_EXCEPTION(Exception::ERR_ITEM_NOT_FOUND)<<errno_info_text("Can't find WheelEnum::HARDWARE_WIN_MODE in the _wheelMap!");
	}
	return it->second;
}