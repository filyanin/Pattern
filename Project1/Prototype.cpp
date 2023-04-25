//����������, ��������� �������� ����� ���������, ��������, ������ ������ �������

#include <string>

// ������ ������� �������� ����������,����������� ����� clone()
class ICanClone {
public:
	virtual void* Clone() {};
};

// "���������" ����� �������� ��������� ��������� � ��������� ���,
// �������� ����� ������� ������ �� ������������ ��������
class HairCut : ICanClone {
public:
	virtual void* Clone() {
		//���������� ����� ����������� ����� �������
		//� ��������� ��� �������
		auto newHaircut = new HairCut();
		newHaircut->length = this->length;
		newHaircut->accessories = this->accessories;
	};
private:
	std::string color;
	std::string length;
	std::string structure;
	std::string accessories;
};