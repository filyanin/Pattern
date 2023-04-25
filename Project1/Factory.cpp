//јбстрактна€ фабрика
//—бор домашнего компьютера

//¬ состав компьютера, как правило, но не об€зательно вход€т:
//	- системный блок
//	- монитор
//	- клавиатура
//	- мышь

class BasePC{									//об€зательные составл€ющие
	virtual void hasSystemUnit(){}
	virtual void hasDisplay(){}
	virtual void hasKeyBoard(){}
};

class InputMouse {								//функции, по€вл€ющиес€ при добавлении мыши
	virtual void canUseMouse(){}
};

class Headset {									//функции, по€вл€ющиес€ при добавлении гарнитуры
	virtual void canPlayMusic(){}
	virtual void canRecord(){}
};

class PCComfort : BasePC, InputMouse {			//компьютер с мышью

};

class PCEexpanded: BasePC, InputMouse, Headset{	//компьютер с мышью и гарнитурой

};