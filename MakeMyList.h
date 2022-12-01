#pragma once
#include <iostream>

template <typename T>
struct Cell
{
	//�l
	T value;

	//�O�̃Z�����w���|�C���^
	Cell* prev;

	//���̃Z�����w���|�C���^
	Cell* next;

	//�R���X�g���N�^
	Cell()
	{
		//�_�~�[�m�[�h��p��
		prev = this;
		next = this;
	}

	Cell(T value_, Cell* prev_, Cell* next_)
	{
		value = value_;
		prev = prev_;
		next = next_;

	}
};

template <class T>
class MakeMylist
{
public:
	MakeMylist()
	{
		sampleDummy = new Cell<T>();

		size = 0;
	}

	~MakeMylist()
	{
		
	}

	//��ԑO�ɒǉ�
	void Push_Front(T value_)
	{
		Cell<T>* cur = sampleDummy;
		Add(value_, cur);
	}

	/// <summary>
	/// ��Ԍ��ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	void Push_Back(T value_)
	{
		Cell<T>* cur = sampleDummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ǉ�����ꏊ(0~)</param>
	void Insert(T value_, int num)
	{
		Cell<T>* cell = nullptr;
		cell = sampleDummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num; i++)
		{
			cell = cell->next;
		}

		//�ǉ�
		Add(value_, cell);
	}

	//
	bool Search(int num)
	{
		if (num < 0 || num>size)
		{
			return false;
		}

		return true;
	}

	/// <summary>
	/// �C�ӂ̏ꏊ�̒l��ύX
	/// </summary>
	/// <param name="value_">�l</param>
	/// <param name="num">�ύX����ꏊ(0~)</param>
	bool ChangeValue(T value_, int num)
	{

		if (num < 0 || num>size)
		{
			return false;
		}

		Cell<T>* cell = nullptr;
		cell = sampleDummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			cell = cell->next;
		}

		//�ύX
		cell->value = value_;

		return true;

	}

	/// <summary>
	/// �ꗗ�\��
	/// </summary>
	void Dump()
	{
		Cell<T>* ptr = sampleDummy->next;

		std::cout << "�v�f�ꗗ:{" << std::endl;

		int index = 0;
		for (int i = 0; i < size - 1; i++)
		{
			std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << ',' << std::endl;
			ptr = ptr->next;
			index++;
		}
		std::cout << ' ' << index << ':' << '"' << ptr->value << '"' << std::endl;

		std::cout << '}' << std::endl;
	}

	void DesignatedElement(int num)
	{
		Cell<T>* cell = nullptr;
		cell = sampleDummy;

		int index = -1;

		for (int i = 0; i < num + 1; i++)
		{
			cell = cell->next;
			index++;
		}

		std::cout << index << ':' << cell->value << '\n';
	}

	T GetElement(int num)
	{
		Cell<T>* cell = nullptr;
		cell = sampleDummy;

		for (int i = 0; i < num + 1; i++)
		{
			cell = cell->next;
		}

		return cell->value;
	}

	int Size()
	{
		return size;
	}

	bool Delete(int num)
	{
		if (num < 0 || num>size)
		{
			return false;
		}

		Cell<T>* cell = nullptr;
		cell = sampleDummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			cell = cell->next;
		}

		cell->prev->next = cell->next;
		cell->next->prev = cell->next;

		delete cell;

		size--;

		return true;
	}


	void Sort(bool flag = true)
	{
		
	}

private:

	//�T���v���_�~�[
	Cell<T>* sampleDummy;

	int size;

	//�Z�����w�������ɒǉ�
	void Add(T v, Cell<T>* node)
	{
		//�V�����Z���𐶐�
		Cell<T>* newNode = new Cell<T>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	Cell<T>* GetCell(int num)
	{
		Cell<T>* cell = sampleDummy;

		//�C�ӂ̏ꏊ�܂ňړ�
		for (int i = 0; i < num + 1; i++)
		{
			cell = cell->next;
		}

		return cell;
	}
};