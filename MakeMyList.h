#pragma once

//�o�������X�g�̍\���̂̒�`
typedef struct Cell {
	int val;//�l

	struct Cell* prev;//�O�̃|�C���^

	struct Cell* next;//��̃|�C���^

	Cell() {
		prev = this;
		next = this;
	};

	Cell(int value_, Cell* prev_, Cell* next_)
	{
		val = value_;
		prev = prev_;
		next = next_;

	}

};

class MakeMyList {
public:

	MakeMyList()
	{
		dummy = new Cell();

		size = 0;
	}

	//�_�~�[
	Cell* dummy;
	int size;

public:

	//��ԑO�ɒǉ�
	void PushFront(int value_)
	{
		Cell* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// ��Ԍ��ɒǉ�
	/// </summary>
	/// <param name="value_">�l</param>
	void PushBack(int value_)
	{
		Cell* cur = dummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// �ꗗ�\��
	/// </summary>
	void Dump()
	{
		Cell* ptr = dummy->next;

		std::cout << "�v�f�ꗗ:{" << std::endl;

		int index = 0;
		for (int i = 0; i < size - 1; i++)
		{
			std::cout << ' ' << index << ':' << '"' << ptr->val << '"' << ',' << std::endl;
			ptr = ptr->next;
			index++;
		}
		std::cout << ' ' << index << ':' << '"' << ptr->val << '"' << std::endl;

		std::cout << '}' << std::endl;
	}

	//�Z�����w�������ɒǉ�
	void Add(int v, Cell* node)
	{
		//�V�����Z���𐶐�
		Cell* newNode = new Cell(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	void SpecifyElement(int num)
	{
		Cell* tmpCell = nullptr;
		tmpCell = dummy;

		int index = -1;

		for (int i = 0; i < num + 1; i++)
		{
			tmpCell = tmpCell->next;
			index++;
		}

		std::cout << index << ':' << tmpCell->val << '\n';
	}

	int Size() {
		return size;
	}

	Cell* getInsertCellAddress(Cell* endCELL, int iterator) {
		for (int i = 0; i < iterator; i++) {
			if (endCELL->next) {
				endCELL = endCELL->next;
			}
			else {
				break;
			}
		}
		return endCELL;
	}

};