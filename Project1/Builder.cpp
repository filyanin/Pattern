//Системный блок компьютера состоит из обязательных и необязательных частей, 
//которые могут обладать разными характеристиками в зависимости от того, 
//для каких целей приобретается компьютер

#include <string>
#include <iostream>

//Системный блок - продукт, который будет собран строителем.
class SystemUnit {                  
public:
    bool Housing;
    std::string CPU;
    std::string Motherboard;
    std::string VideoCard;
};

//Интерфейс, который реализует строитель, позволяющий 
//ему собрать системный блок
class ICanBuildSystemUnit {
public:
    virtual void CreateProduct() { }
	virtual void AddHousing(){}
	virtual void AddCPU(std::string CPU){}
	virtual void AddMotherboard(std::string Motherboard){}
    virtual void AddVideoCard(std::string VideoCard){}
    virtual SystemUnit* GetResult() { return nullptr; }
};

//Класс - строитель, собирающий системный блок. 
class ConcreteBuilder : public ICanBuildSystemUnit 
{
private:
    SystemUnit* currentUnit;

public:
  ConcreteBuilder()   // Конструктор
  {
      currentUnit = nullptr;
  }

  /// Реализация виртуальных методов для сбора блока ///
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

  // Метод, возвращающий продукт для клиента
  virtual SystemUnit* GetResult()
  {
    return currentUnit;
  }

  // Деструктор
  ~ConcreteBuilder()
  {
    if (currentUnit != nullptr)
      delete currentUnit;
  }
};

// Класс - директор, управляющий процессом сборки
//вызывающий необходимые функции из класса строитель
class Director
{
public:
  // Метод, конструирующий части
  void Construct(ICanBuildSystemUnit& builder)
  {
      builder.CreateProduct();
      builder.AddHousing();
      builder.AddCPU("123");
      builder.AddMotherboard("456");
      builder.AddVideoCard("789");
  }
};