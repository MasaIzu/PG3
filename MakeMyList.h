#pragma once
#include <iostream>

template <typename T>
struct Cell
{
	//値
	T value;

	//前のセルを指すポインタ
	Cell* prev;

	//次のセルを指すポインタ
	Cell* next;

	//コンストラクタ
	Cell()
	{
		//ダミーノードを用意
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

	//一番前に追加
	void Push_Front(T value_)
	{
		Cell<T>* cur = sampleDummy;
		Add(value_, cur);
	}

	/// <summary>
	/// 一番後ろに追加
	/// </summary>
	/// <param name="value_">値</param>
	void Push_Back(T value_)
	{
		Cell<T>* cur = sampleDummy->prev;
		Add(value_, cur);
	}

	/// <summary>
	/// 任意の場所に追加
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">追加する場所(0~)</param>
	void Insert(T value_, int num)
	{
		Cell<T>* cell = nullptr;
		cell = sampleDummy;

		//任意の場所まで移動
		for (int i = 0; i < num; i++)
		{
			cell = cell->next;
		}

		//追加
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
	/// 任意の場所の値を変更
	/// </summary>
	/// <param name="value_">値</param>
	/// <param name="num">変更する場所(0~)</param>
	bool ChangeValue(T value_, int num)
	{

		if (num < 0 || num>size)
		{
			return false;
		}

		Cell<T>* cell = nullptr;
		cell = sampleDummy;

		//任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			cell = cell->next;
		}

		//変更
		cell->value = value_;

		return true;

	}

	/// <summary>
	/// 一覧表示
	/// </summary>
	void Dump()
	{
		Cell<T>* ptr = sampleDummy->next;

		std::cout << "要素一覧:{" << std::endl;

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

		//任意の場所まで移動
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

	//サンプルダミー
	Cell<T>* sampleDummy;

	int size;

	//セルが指した後ろに追加
	void Add(T v, Cell<T>* node)
	{
		//新しいセルを生成
		Cell<T>* newNode = new Cell<T>(v, node, node->next);
		node->next->prev = newNode;
		node->next = newNode;
		node = newNode;
		size++;
	}

	Cell<T>* GetCell(int num)
	{
		Cell<T>* cell = sampleDummy;

		//任意の場所まで移動
		for (int i = 0; i < num + 1; i++)
		{
			cell = cell->next;
		}

		return cell;
	}
};