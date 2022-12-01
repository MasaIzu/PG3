#pragma once

//双方向リストの構造体の定義
typedef struct cell {
	int val;//値

	struct cell* prev;//前のポインタ

	struct cell* next;//後のポインタ

}CELL;