#pragma once
#include <iostream>
#include <queue>
#include <string>

class Command
{
protected:
	std::string Key;
public:
	Command(std::string key) : Key(key) {}
	virtual ~Command() = default; // ���� �Ҹ��� : �θ� Ŭ������ ���� �������� �Ҹ�
	virtual std::string execute() const = 0;
	std::string GetKey() { return Key; }

};

class FireBall : public Command
{
public:
	FireBall(std::string key) : Command(key) {}
	std::string execute() const override
	{
		return "���̾!";
	}
};

class DoomsDay : public Command
{
public:
	DoomsDay(std::string key) : Command(key) {}
	std::string execute() const override
	{
		return "���ٽ�!!";
	}
};

template <typename T>
class CircularQueue
{
private:
	T* arr;
	int iCount;
	int capacity;
	int front;
	int rear;
public:
	// ������
	CircularQueue(int size = 4) 
	{
		arr = new T[size];
		iCount = 0;
		capacity = size;
		front = 0;
		rear = 0;
	}
	~CircularQueue() {}
	
	// ������
	T Front()
	{
		return arr[front];
	}
	T Rear()
	{
		return arr[rear];
	}
	int Size()
	{
		return iCount;
	}

	// Helper Method
	bool IsEmpty()
	{
		return front == rear ? true : false;
	}
	bool IsFull()
	{
		return (rear + 1) % capacity == front ? true : false;
	}

	// Main Method
	void Push(T data)
	{
		if (IsFull())
		{
			std::cout << "���� ť�� ����á���ϴ�." << std::endl;
		}
		else
		{
			arr[rear] = data;
			rear = (rear+1) % capacity;
			iCount++;
		}
		
	}
	void Pop()
	{
		if (IsEmpty())
		{
			std::cout << "���� ť�� ������ϴ�." << std::endl;
			return;
		}
		else
		{
			front = (front + 1) % capacity;
			iCount--;
		}
	}
};

class CommandSystem
{
private:
	std::vector<Command*> Commands; // ���Ҽ��� ���� ���� ���Ͱ� ����
	CircularQueue<std::string> Inputs; // ������ ���� ��ȣ�� ������� ����
public:
	void addCommand(Command* command)
	{
		Commands.push_back(command);
	}
	void addInput(const std::string& input)
	{
		if (Inputs.Size() < 3)
		{
			Inputs.Push(input);
		}
		if (Inputs.Size() == 3)
		{
			ProcessCommand();
			ClearQueue();
		}
	}
	void ProcessCommand()
	{
		// ������ �Է��� ������� Ŀ�ǵ� ����
		std::string userCommand = "";

		while (!Inputs.IsEmpty())
		{
			userCommand += Inputs.Front();
			Inputs.Pop();
		}

		// Ŀ�ǵ��� Key�� userCommand �� ���� ��ġ�ϴ��� ��
		for (int i = 0; Commands.size();i++) {
			if (userCommand == Commands[i]->GetKey())
			{
				std::cout << Commands[i]->execute() << std::endl;
				return;
			}
		}
		std::cout << "��ġ�ϴ� Ŀ�ǵ尡 �����ϴ�" << std::endl;
		
	}

	void ClearQueue()
	{
		while (!Inputs.IsEmpty())
		{
			Inputs.Pop();
		}
	}

	void ShowPlayerInput()
	{
		std::cout << "���� �Է� �� : [ ";
		CircularQueue<std::string> temp = Inputs;
		while (!temp.IsEmpty())
		{
			std::cout << temp.Front() << " ";
			temp.Pop();
		}
		std::cout << " ]" << std::endl;
	}

	void ShowCommandList()
	{
		std::cout << "---Ŀ�ǵ� ���---" << std::endl;
		std::cout << "Fire Ŀ�ǵ� : " << "ABC" << std::endl;
		std::cout << "DoomsDay Ŀ�ǵ� : " << "DEF" << std::endl;
		std::cout << "-----------------" << std::endl;
	}
};

void CommandSystemExample()
{
	CommandSystem manager;
	FireBall cm1("ABC");
	DoomsDay cm2("DEF");
	manager.addCommand(&cm1);
	manager.addCommand(&cm2);

	manager.ShowCommandList();

	std::string input;
	
	while (true)
	{
		manager.ShowCommandList();
		manager.ShowPlayerInput();

		std::cin >> input;
		manager.addInput(input);

		if (input == "Q")
		{
			std::cout << "�ý��� ����" << std::endl;
			break;
		}
	}
}