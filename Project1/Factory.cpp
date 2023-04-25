//����������� �������
//���� ��������� ����������

//� ������ ����������, ��� �������, �� �� ����������� ������:
//	- ��������� ����
//	- �������
//	- ����������
//	- ����

class BasePC{									//������������ ������������
	virtual void hasSystemUnit(){}
	virtual void hasDisplay(){}
	virtual void hasKeyBoard(){}
};

class InputMouse {								//�������, ������������ ��� ���������� ����
	virtual void canUseMouse(){}
};

class Headset {									//�������, ������������ ��� ���������� ���������
	virtual void canPlayMusic(){}
	virtual void canRecord(){}
};

class PCComfort : BasePC, InputMouse {			//��������� � �����

};

class PCEexpanded: BasePC, InputMouse, Headset{	//��������� � ����� � ����������

};