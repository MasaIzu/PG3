#pragma once

//�o�������X�g�̍\���̂̒�`
typedef struct cell {
	int val;//�l

	struct cell* prev;//�O�̃|�C���^

	struct cell* next;//��̃|�C���^

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