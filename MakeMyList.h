#pragma once

//双方向リストの構造体の定義
typedef struct cell {
	int val;//値

	struct cell* prev;//前のポインタ

	struct cell* next;//後のポインタ

}CELL;

class MyList {
public:
	int size = 0;

public:

	void create(CELL* currentCell, int val) {
		CELL* newCell;
		newCell = (CELL*)malloc(sizeof(CELL));
		newCell->val = val;
		newCell->prev = currentCell;
		newCell->next = currentCell->next;

		if (currentCell->next) {
			CELL* newCell = currentCell->next;
			newCell->prev = newCell;
		}
		currentCell->next = newCell;
		size++;
	}

	int Size() {
		return size;
	}

};