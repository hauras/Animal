#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal
{

public:
	virtual void makeSound() const = 0;
};

class Dog : public Animal
{
	void makeSound() const override
	{
		cout << "Woof!" << endl;
	}
};

class Cat : public Animal
{
	void makeSound() const override
	{
		cout << "Meow!" << endl;
	}
};

class Cow : public Animal 
{
public:
	void makeSound() const override 
	{
		cout << "Moo!" << endl; 
	}
};

class Zoo
{

private:
	Animal* animals[10];
	int count=0;

public:
	void addAnimal(Animal* animal)
	{
		if (count < 10)
		{
			animals[count++] = animal;
		}
		else
		{
			cout << "자리가 없습니다" << endl;
		}
	}

	void performActions()
	{
		for (int i = 0; i < count; i++)
		{
			animals[i]->makeSound();
		}
	}

	~Zoo()
	{
		for (int i = 0; i < count; i++)
		{
			delete animals[i];
		}
	}

};

Animal* createRandomAnimal() 
{

	int randNum = rand() % 3; // 0 1 2

	if (randNum == 0)
		return new Dog();
	else if (randNum == 1)
		return new Cat();
	else if (randNum == 2)
		return new Cow();
	else
		return nullptr;
}
int main()
{
	const int size = 3;

	Animal* animal[size];

	animal[0] = new Dog();
	animal[1] = new Cat();
	animal[2] = new Cow();

	for (int i = 0; i < size; i++) {
		animal[i]->makeSound(); 
	}

	// 메모리 해제
	for (int i = 0; i < size; i++) {
		delete animal[i];
	}

	Zoo zoo;

	// 위에서 처럼 수동으로 안넣고 난수사용과 합쳐서 한번에 넣기
	for (int i = 0; i < 7; i++)
	{
		zoo.addAnimal(createRandomAnimal());
	}

	cout << " 랜덤으로 추가후 출력" << endl;
	zoo.performActions();
}