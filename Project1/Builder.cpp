//��������� ���� ���������� ������� �� ������������ � �������������� ������, 
//������� ����� �������� ������� ���������������� � ����������� �� ����, 
//��� ����� ����� ������������� ���������

#include <string>
#include <iostream>

//��������� ���� - �������, ������� ����� ������ ����������.
class SystemUnit {                  
public:
    bool Housing;
    std::string CPU;
    std::string Motherboard;
    std::string VideoCard;
};

//���������, ������� ��������� ���������, ����������� 
//��� ������� ��������� ����
class ICanBuildSystemUnit {
public:
    virtual void CreateProduct() { }
	virtual void AddHousing(){}
	virtual void AddCPU(std::string CPU){}
	virtual void AddMotherboard(std::string Motherboard){}
    virtual void AddVideoCard(std::string VideoCard){}
    virtual SystemUnit* GetResult() { return nullptr; }
};

//����� - ���������, ���������� ��������� ����. 
class ConcreteBuilder : public ICanBuildSystemUnit 
{
private:
    SystemUnit* currentUnit;

public:
  ConcreteBuilder()   // �����������
  {
      currentUnit = nullptr;
  }

  /// ���������� ����������� ������� ��� ����� ����� ///
  virtual void CreateProduct()
  {
    std::cout << "ConcreteBuilder::CreateProduct()" << std::endl;
    currentUnit = new SystemUnit();
  }
  
  virtual void AddHousing()
  {
      std::cout << "ConcreteBuilder::currentBuilder->Housing" << std::endl;
      currentUnit->Housing = true;
  }

  virtual void AddCPU(std::string CPU)
  {
    std::cout << "ConcreteBuilder::currentBuilder->CPU = " << CPU << std::endl;
    currentUnit->CPU = CPU;
  }

  virtual void AddMotherboard(std::string Motherboard)
  {
    std::cout << "ConcreteBuilder::currentBuilder->Motherboard = " << Motherboard << std::endl;
    currentUnit->Motherboard = Motherboard;
  }

  virtual void AddVideoCard(std::string VideoCard)
  {
      std::cout << "ConcreteBuilder::currentBuilder->VideoCard = " << VideoCard << std::endl;
      currentUnit->VideoCard = VideoCard;
  }

  // �����, ������������ ������� ��� �������
  virtual SystemUnit* GetResult()
  {
    return currentUnit;
  }

  // ����������
  ~ConcreteBuilder()
  {
    if (currentUnit != nullptr)
      delete currentUnit;
  }
};

// ����� - ��������, ����������� ��������� ������
//���������� ����������� ������� �� ������ ���������
class Director
{
public:
  // �����, �������������� �����
  void Construct(ICanBuildSystemUnit& builder)
  {
      builder.CreateProduct();
      builder.AddHousing();
      builder.AddCPU("123");
      builder.AddMotherboard("456");
      builder.AddVideoCard("789");
  }
};