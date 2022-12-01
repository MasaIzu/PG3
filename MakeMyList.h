#pragma once

//双方向リストの構造体の定義
typedef struct Cell {
	int val;//値

	struct Cell* prev;//前のポインタ

	struct Cell* next;//後のポインタ

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

	//ダミー
	Cell* dummy;
	int size;

public:

	//一番前に追加
	void PushFront(int value_)
	{
		Cell* cur = dummy;
		Add(value_, cur);
	}

	/// <summary>
	/// 一番後ろに追加
	/// </summary>
	/// <param name="value_">値</param>
	void PushBack(int value_)
	{
		Cell* cur = dummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// 一覧表示
	/// </summary>
	void Dump()
	{
		Cell* ptr = dummy->next;

		std::cout << "要素一覧:{" << std::endl;

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

	//セルが指した後ろに追加
	void Add(int v, Cell* node)
	{
		//新しいセルを生成
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