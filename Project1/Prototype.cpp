//Парикмахер, создающий прическу может покрасить, постричь, завить волосы клиента

#include <string>

// Шаблон требует создания интерфейса,содержищего метод clone()
class ICanClone {
public:
	virtual void* Clone() {};
};

// "Смысловой" класс Прическа наследует интерфейс и реализует его,
// создавая копию объекта класса по определенным правилам
class HairCut : ICanClone {
public:
	virtual void* Clone() {
		//парикмахер может скопировать длину стрижки
		//и аксесуары для клиента
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