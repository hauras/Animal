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
			cout << "�ڸ��� �����ϴ�" << endl;
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

	// �޸� ����
	for (int i = 0; i < size; i++) {
		delete animal[i];
	}

	Zoo zoo;

	// ������ ó�� �������� �ȳְ� �������� ���ļ� �ѹ��� �ֱ�
	for (int i = 0; i < 7; i++)
	{
		zoo.addAnimal(createRandomAnimal());
	}

	cout << " �������� �߰��� ���" << endl;
	zoo.performActions();
}