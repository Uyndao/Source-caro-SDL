//Thêm vào các hàm từ phần bắt đầu thêm vào đến kết thúc thêm vào
//Sửa ở các hàm cho sẵn: player_baseline, attack, defend, check_win
#ifndef BOTBASELINE
#define BOTBASELINE

#include <iostream>
#include <stdlib.h>
#include "config.h"
// Bắt đầu phần hàm thêm vào
const long atk_score[7] = { 0,3,20,180,1200,10000,80000 };
const long def_score[7] = { 0,1,11,100,900,7000,65000 };
void value_row(int board_game[][WIDTH], int player_id, int m, int n, int units[]) {
	int value_max = 0;
	int up = 1;
	int down = 1;
	int space = 1;
	while (board_game[m][n + up] != -player_id && n + up < 50) {
		space++;
		up++;
	}
	while (board_game[m][n - down] != -player_id && n - down > -1) {
		space++;
		down++;
	}
	if (space < 6) {
		return;
	}
	board_game[m][n] = player_id;
	for (int i = 0; i < 4; i++) {
		if (n - 3 + i < 0)
			i += (0 - (n - 3 + i));
		int valuer = 0;
		if (board_game[m][n - 3 + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m][n - 2 + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m][n - 1 + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m][n + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m][n - 3 + i] == -player_id) {
			valuer = 0;
		}
		if (board_game[m][n - 2 + i] == -player_id) {
			valuer = 0;
		}
		if (board_game[m][n - 1 + i] == -player_id) {
			valuer = 0;
		}
		if ((n - 4 + i < 0 || board_game[m][n - 4 + i] == -player_id)) {
			valuer--;
		}
		else if (n - 5 + i < 0 || board_game[m][n - 5 + i] == -player_id) {
			if (board_game[m][n - 3 + i] == player_id) {
				valuer--;
			}
		}
		if (n - 4 + i > -1 && board_game[m][n - 4 + i] == player_id) {
			if (valuer == 5) {
				valuer += 2;
			}
			else if (valuer >= 2 && valuer < 7) {
				valuer++;
			}
		}
		if ((n + 1 + i > 49 || board_game[m][n + 1 + i] == -player_id)) {
			valuer--;
			i += 4;
		}
		else if (n + 2 + i > 49 || board_game[m][n + 2 + i] == -player_id) {
			if (board_game[m][n + i] == player_id) {
				valuer--;
			}
		}
		if (n + 1 + i < 50 && board_game[m][n + 1 + i] == player_id) {
			if (valuer == 5) {
				valuer += 2;
			}
			else if (valuer >= 2 && valuer < 7) {
				valuer++;
			}
		}
		if (valuer > value_max) {
			value_max = valuer;
		}
	}
	units[value_max]++;
	board_game[m][n] = 0;
}
void value_col(int board_game[][WIDTH], int player_id, int m, int n, int units[]) {
	int value_max = 0;
	int up = 1;
	int down = 1;
	int space = 1;
	while (board_game[m + up][n] != -player_id && m + up < 30) {
		space++;
		up++;
	}
	while (board_game[m - down][n] != -player_id && m - down > -1) {
		space++;
		down++;
	}
	if (space < 6) {
		return;
	}
	board_game[m][n] = player_id;
	for (int i = 0; i < 4; i++) {
		if (m - 3 + i < 0)
			i += (0 - (m - 3 + i));
		int valuer = 0;
		if (board_game[m - 3 + i][n] == player_id) {
			valuer += 2;
		}
		if (board_game[m - 2 + i][n] == player_id) {
			valuer += 2;
		}
		if (board_game[m - 1 + i][n] == player_id) {
			valuer += 2;
		}
		if (board_game[m + i][n] == player_id) {
			valuer += 2;
		}
		if (board_game[m - 3 + i][n] == -player_id) {
			valuer = 0;
		}
		if (board_game[m - 2 + i][n] == -player_id) {
			valuer = 0;
		}
		if (board_game[m - 1 + i][n] == -player_id) {
			valuer = 0;
		}
		if ((m - 4 + i < 0 || board_game[m - 4 + i][n] == -player_id)) {
			valuer--;
		}
		else if (m - 5 + i < 0 || board_game[m - 5 + i][n] == -player_id) {
			if (board_game[m - 3 + i][n] == player_id) {
				valuer--;
			}
		}
		if (m - 4 + i > -1 && board_game[m - 4 + i][n] == player_id) {
			if (valuer == 5) {
				valuer += 2;
			}
			else if (valuer >= 2 && valuer < 7) {
				valuer++;
			}
		}
		if ((m + 1 + i > 29 || board_game[m + 1 + i][n] == -player_id)) {
			valuer--;
			i += 4;
		}
		else if (m + 2 + i > 29 || board_game[m + 2 + i][n] == -player_id) {
			if (board_game[m + i][n] == player_id) {
				valuer--;
			}
		}
		if (m + 1 + i < 30 && board_game[m + 1 + i][n] == player_id) {
			if (valuer == 5) {
				valuer += 2;
			}
			else if (valuer >= 2 && valuer < 7) {
				valuer++;
			}
		}
		if (valuer > value_max) {
			value_max = valuer;
		}
	}
	units[value_max]++;
	board_game[m][n] = 0;
}
void value_cross_1(int board_game[][WIDTH], int player_id, int m, int n, int units[]) {
	int value_max = 0;
	int up = 1;
	int down = 1;
	int space = 1;
	while (board_game[m + up][n + up] != -player_id && m + up < 30 && n + up < 50) {
		space++;
		up++;
	}
	while (board_game[m - down][n - down] != -player_id && m - down > -1 && n - down > -1) {
		space++;
		down++;
	}
	if (space < 6) {
		return;
	}
	board_game[m][n] = player_id;
	for (int i = 0; i < 4; i++) {
		while (m - 3 + i < 0 || n - 3 + i < 0) {
			i++;
		}
		int valuer = 0;
		if (board_game[m - 3 + i][n - 3 + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m - 2 + i][n - 2 + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m - 1 + i][n - 1 + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m + i][n + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m - 3 + i][n - 3 + i] == -player_id) {
			valuer = 0;
		}
		if (board_game[m - 2 + i][n - 2 + i] == -player_id) {
			valuer = 0;
		}
		if (board_game[m - 1 + i][n - 1 + i] == -player_id) {
			valuer = 0;
		}
		if ((m - 4 + i < 0 || n - 4 + i < 0 || board_game[m - 4 + i][n - 4 + i] == -player_id)) {
			valuer--;
		}
		else if (m - 5 + i < 0 || n - 5 + i < 0 || board_game[m - 5 + i][n - 5 + i] == -player_id) {
			if (board_game[m - 3 + i][n - 3 + i] == player_id) {
				valuer--;
			}
		}
		if (m - 4 + i > -1 && n - 4 + i > -1 && board_game[m - 4 + i][n - 4 + i] == player_id) {
			if (valuer == 5) {
				valuer += 2;
			}
			else if (valuer >= 2 && valuer < 7) {
				valuer++;
			}
		}
		if ((m + 1 + i > 29 || n + 1 + i > 49 || board_game[m + 1 + i][n + 1 + i] == -player_id)) {
			valuer--;
			i += 4;
		}
		else if (m + 2 + i > 29 || n + 2 + i > 49 || board_game[m + 2 + i][n + 2 + i] == -player_id) {
			if (board_game[m + i][n + i] == player_id) {
				valuer--;
			}
		}
		if (m + 1 + i < 30 && n + 1 + i < 50 && board_game[m + 1 + i][n + 1 + i] == player_id) {
			if (valuer == 5) {
				valuer += 2;
			}
			else if (valuer >= 2 && valuer < 7) {
				valuer++;
			}
		}
		if (valuer > value_max) {
			value_max = valuer;
		}
	}
	units[value_max]++;
	board_game[m][n] = 0;
}
void value_cross_2(int board_game[][WIDTH], int player_id, int m, int n, int units[]) {
	int value_max = 0;
	int up = 1;
	int down = 1;
	int space = 1;
	while (board_game[m - up][n + up] != -player_id && m - up > -1 && n + up < 50) {
		space++;
		up++;
	}
	while (board_game[m + down][n - down] != -player_id && m + down<30 && n - down>-1) {
		space++;
		down++;
	}
	if (space < 6) {
		return;
	}
	board_game[m][n] = player_id;
	for (int i = 0; i < 4; i++) {
		while (m + 3 - i > 29 || n - 3 + i < 0) {
			i++;
		}
		int valuer = 0;
		if (board_game[m + 3 - i][n - 3 + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m + 2 - i][n - 2 + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m + 1 - i][n - 1 + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m - i][n + i] == player_id) {
			valuer += 2;
		}
		if (board_game[m + 3 - i][n - 3 + i] == -player_id) {
			valuer = 0;
		}
		if (board_game[m + 2 - i][n - 2 + i] == -player_id) {
			valuer = 0;
		}
		if (board_game[m + 1 - i][n - 1 + i] == -player_id) {
			valuer = 0;
		}
		if ((m + 4 - i > 29 || n - 4 + i < 0 || board_game[m + 4 - i][n - 4 + i] == -player_id)) {
			valuer--;
		}
		else if (m + 5 - i > 29 || n - 5 + i < 0 || board_game[m + 5 - i][n - 5 + i] == -player_id) {
			if (board_game[m + 3 - i][n - 3 + i] == player_id) {
				valuer--;
			}
		}
		if (m + 4 - i < 30 && n - 4 + i > -1 && board_game[m + 4 - i][n - 4 + i] == player_id) {
			if (valuer == 5) {
				valuer += 2;
			}
			else if (valuer >= 2 && valuer < 7) {
				valuer++;
			}
		}
		if ((m - 1 - i < 0 || n + 1 + i>49 || board_game[m - 1 - i][n + 1 + i] == -player_id)) {
			valuer--;
			i += 4;
		}
		else if (m - 2 - i < 0 || n + 2 + i > 49 || board_game[m - 2 - i][n + 2 + i] == -player_id) {
			if (board_game[m - i][n + i] == player_id) {
				valuer--;
			}
		}
		if (m - 1 - i > -1 && n + 1 + i < 50 && board_game[m - 1 - i][n + 1 + i] == player_id) {
			if (valuer == 5) {
				valuer += 2;
			}
			else if (valuer >= 2 && valuer < 7) {
				valuer++;
			}
		}
		if (valuer > value_max) {
			value_max = valuer;
		}
	}
	units[value_max]++;
	board_game[m][n] = 0;
}
long value(int board_game[][WIDTH], int player_id, int m, int n) {
	int atk_units[9];
	int def_units[9];
	for (int i = 0; i < 9; i++) {
		atk_units[i] = 0;
		def_units[i] = 0;
	}
	value_row(board_game, player_id, m, n, atk_units);
	value_col(board_game, player_id, m, n, atk_units);
	value_cross_1(board_game, player_id, m, n, atk_units);
	value_cross_2(board_game, player_id, m, n, atk_units);
	value_row(board_game, -player_id, m, n, def_units);
	value_col(board_game, -player_id, m, n, def_units);
	value_cross_1(board_game, -player_id, m, n, def_units);
	value_cross_2(board_game, -player_id, m, n, def_units);
	if (atk_units[8] >= 1) {
		return 10000000;
	}
	if (atk_units[7] >= 2) {
		return 10000000;
	}
	if (atk_units[7] >= 1 && atk_units[6] >= 1) {
		return 10000000;
	}
	if (def_units[8] >= 1) {
		return 4999999;
	}
	if (def_units[7] >= 2) {
		return 4999999;
	}
	if (def_units[7] >= 1 && def_units[6] >= 1) {
		return 4999999;
	}
	if (atk_units[6] >= 2) {
		return 2499999;
	}
	if (def_units[6] >= 2) {
		return 1249999;
	}
	long v = 0;
	for (int i = 1; i < 8; i++) {
		v += atk_score[i - 1] * atk_units[i];
		v += def_score[i - 1] * def_units[i];
	}
	return v;
}
void input_winpath(int first_x, int first_y, int direction_x, int direction_y) {
	for (int i = 0; i < 5; i++) {
		int x = first_x + i * direction_x;
		int y = first_y + i * direction_y;
		win_path[i] = Point(y, x);
	}
	started = false;
}
// Kết thúc phần hàm thêm vào
// Ngoài ra là sửa trong những hàm có sẵn
void check_player_win(int board_game[][WIDTH], int player_id) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			int unit = 0;
			int x;
			int y;
			for (int up_row = 0; j + up_row < 50; up_row++) {
				if (up_row == 5) {
					break;
				}
				if (board_game[i][j + up_row] == -player_id) {
					break;
				}
				else if (board_game[i][j + up_row] == player_id) {
					unit++;
				}
				else {
					break;
				}
				if (up_row == 4) {
					if (j - 1 > -1 && j + 5 < 50) {
						if (unit == 5 && (board_game[i][j - 1] != -player_id || board_game[i][j + 5] != -player_id)) {
							input_winpath(i, j, 0, 1);
							winner = player_id;
						}
					}
					else if (j - 1 > -1) {
						if (unit == 5 && board_game[i][j - 1] != -player_id) {
							input_winpath(i, j, 0, 1);
							winner = player_id;
						}
					}
					else if (j + 5 < 50) {
						if (unit == 5 && board_game[i][j + 5] != -player_id) {
							input_winpath(i, j, 0, 1);
							winner = player_id;
						}
					}
				}
			}
			unit = 0;
			for (int up_col = 0; i + up_col < 30; up_col++) {
				if (up_col == 5) {
					break;
				}
				if (board_game[i + up_col][j] == -player_id) {
					break;
				}
				else if (board_game[i + up_col][j] == player_id) {
					unit++;
				}
				else {
					break;
				}
				if (up_col == 4) {
					if (i - 1 > -1 && i + 5 < 30) {
						if (unit == 5 && (board_game[i - 1][j] != -player_id || board_game[i + 5][j] != -player_id)) {
							input_winpath(i, j, 1, 0);
							winner = player_id;
						}
					}
					else if (i - 1 > -1) {
						if (unit == 5 && board_game[i - 1][j] != -player_id) {
							input_winpath(i, j, 1, 0);
							winner = player_id;
						}
					}
					else if (i + 5 < 30) {
						if (unit == 5 && board_game[i + 5][j] != -player_id) {
							input_winpath(i, j, 1, 0);
							winner = player_id;
						}
					}
				}
			}
			unit = 0;
			for (int up_cross = 0; i + up_cross < 30 && j + up_cross < 50; up_cross++) {
				if (up_cross == 5) {
					break;
				}
				if (board_game[i + up_cross][j + up_cross] == -player_id) {
					break;
				}
				else if (board_game[i + up_cross][j + up_cross] == player_id) {
					unit++;
				}
				else {
					break;
				}
				if (up_cross == 4) {
					if (i - 1 > -1 && i + 5 < 30 && j - 1 > -1 && j + 5 < 50) {
						if (unit == 5 && (board_game[i - 1][j - 1] != -player_id || board_game[i + 5][j + 5] != -player_id)) {
							input_winpath(i, j, 1, 1);
							winner = player_id;
						}
					}
					else if (i - 1 > -1 && j - 1 > -1) {
						if (unit == 5 && board_game[i - 1][j - 1] != -player_id) {
							input_winpath(i, j, 1, 1);
							winner = player_id;
						}
					}
					else if (i + 5 < 30 && j + 5 < 50) {
						if (unit == 5 && board_game[i + 5][j + 5] != -player_id) {
							input_winpath(i, j, 1, 1);
							winner = player_id;
						}
					}
				}
			}
			unit = 0;
			for (int up_cross = 0; i - up_cross > -1 && j + up_cross < 50; up_cross++) {
				if (up_cross == 5) {
					break;
				}
				if (board_game[i - up_cross][j + up_cross] == -player_id) {
					break;
				}
				else if (board_game[i - up_cross][j + up_cross] == player_id) {
					unit++;
				}
				else {
					break;
				}
				if (up_cross == 4) {
					if (i + 1 < 30 && i - 5 > -1 && j - 1 > -1 && j + 5 < 50) {
						if (unit == 5 && (board_game[i + 1][j - 1] != -player_id || board_game[i - 5][j + 5] != -player_id)) {
							input_winpath(i, j, -1, 1);
							winner = player_id;
						}
					}
					else if (i + 1 < 30 && j - 1 > -1) {
						if (unit == 5 && board_game[i + 1][j - 1] != -player_id) {
							input_winpath(i, j, -1, 1);
							winner = player_id;
						}
					}
					else if (i - 5 > -1 && j + 5 < 50) {
						if (unit == 5 && board_game[i - 5][j + 5] != -player_id) {
							input_winpath(i, j, -1, 1);
							winner = player_id;
						}
					}
				}
			}
		}
	}
}
Point check_win(int board_game[][WIDTH], int player_id) {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			int unit = 0;
			int x;
			int y;
			for (int up_row = 0; j + up_row < 50; up_row++) {
				if (up_row == 5) {
					break;
				}
				if (board_game[i][j + up_row] == -player_id) {
					break;
				}
				else if (board_game[i][j + up_row] == player_id) {
					unit++;
				}
				else {
					x = i;
					y = j+up_row;
				}
				if (up_row == 4) {
					if (j - 1 > -1 && j + 5 < 50) {
						if (unit == 4 && (board_game[i][j - 1] != -player_id || board_game[i][j + 5] != -player_id)) {
							input_winpath(i, j, 0, 1);
							return Point(x, y);
						}
					}
					else if (j - 1 > -1) {
						if (unit == 4 && board_game[i][j - 1] != -player_id) {
							input_winpath(i, j, 0, 1);
							return Point(x, y);
						}
					}
					else if (j + 5 < 50) {
						if (unit == 4 && board_game[i][j + 5] != -player_id) {
							input_winpath(i, j, 0, 1);
							return Point(x, y);
						}
					}
				}
			}
			unit = 0;
			for (int up_col = 0; i + up_col < 30; up_col++) {
				if (up_col == 5) {
					break;
				}
				if (board_game[i + up_col][j] == -player_id) {
					break;
				}
				else if (board_game[i + up_col] [j] == player_id) {
					unit++;
				}
				else {
					x = i+up_col;
					y = j;
				}
				if (up_col == 4) {
					if (i - 1 > -1 && i + 5 < 30) {
						if (unit == 4 && (board_game[i - 1][j] != -player_id || board_game[i + 5][j] != -player_id)) {
							input_winpath(i, j, 1, 0);
							return Point(x, y);
						}
					}
					else if (i - 1 > -1) {
						if (unit == 4 && board_game[i - 1][j] != -player_id) {
							input_winpath(i, j, 1, 0);
							return Point(x, y);
						}
					}
					else if (i + 5 < 30) {
						if (unit == 4 && board_game[i + 5][j] != -player_id) {
							input_winpath(i, j, 1, 0);
							return Point(x, y);
						}
					}
				}
			}
			unit = 0;
			for (int up_cross = 0; i + up_cross < 30 && j + up_cross < 50; up_cross++) {
				if (up_cross == 5) {
					break;
				}
				if (board_game[i + up_cross][j+up_cross] == -player_id) {
					break;
				}
				else if (board_game[i + up_cross][j+up_cross] == player_id) {
					unit++;
				}
				else {
					x = i + up_cross;
					y = j + up_cross;
				}
				if (up_cross == 4) {
					if (i - 1 > -1 && i + 5 < 30 && j - 1 > -1 && j + 5 < 50) {
						if (unit == 4 && (board_game[i - 1][j - 1] != -player_id || board_game[i + 5][j + 5] != -player_id)) {
							input_winpath(i, j, 1, 1);
							return Point(x, y);
						}
					}
					else if (i - 1 > -1 && j - 1 > -1) {
						if (unit == 4 && board_game[i - 1][j - 1] != -player_id) {
							input_winpath(i, j, 1, 1);
							return Point(x, y);
						}
					}
					else if (i + 5 < 30 && j + 5 < 50) {
						if (unit == 4 && board_game[i + 5][j + 5] != -player_id) {
							input_winpath(i, j, 1, 1);
							return Point(x, y);
						}
					}
				}
			}
			unit = 0;
			for (int up_cross = 0; i - up_cross > -1 && j + up_cross < 50; up_cross++) {
				if (up_cross == 5) {
					break;
				}
				if (board_game[i - up_cross][j + up_cross] == -player_id) {
					break;
				}
				else if (board_game[i - up_cross][j + up_cross] == player_id) {
					unit++;
				}
				else {
					x = i - up_cross;
					y = j + up_cross;
				}
				if (up_cross == 4) {
					if (i + 1 < 30 && i - 5 > -1 && j - 1 > -1 && j + 5 < 50) {
						if (unit == 4 && (board_game[i + 1][j - 1] != -player_id || board_game[i - 5][j + 5] != -player_id)) {
							input_winpath(i, j, -1, 1);
							return Point(x, y);
						}
					}
					else if (i + 1 < 30 && j - 1 > -1) {
						if (unit == 4 && board_game[i + 1][j - 1] != -player_id) {
							input_winpath(i, j, -1, 1);
							return Point(x, y);
						}
					}
					else if (i - 5 > -1 && j + 5 < 50) {
						if (unit == 4 && board_game[i - 5][j + 5] != -player_id) {
							input_winpath(i, j, -1, 1);
							return Point(x, y);
						}
					}
				}
			}
		}
	}
	return Point(-1, -1);
}
Point defend(int board_game[][WIDTH], int player_id) {
	player_id = -player_id;
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			int unit = 0;
			int x;
			int y;
			for (int up_row = 0; j + up_row < 50; up_row++) {
				if (up_row == 5) {
					break;
				}
				if (board_game[i][j + up_row] == -player_id) {
					break;
				}
				else if (board_game[i][j + up_row] == player_id) {
					unit++;
				}
				else {
					x = i;
					y = j + up_row;
				}
				if (up_row == 4) {
					if (j - 1 > -1 && j + 5 < 50) {
						if (unit == 4 && (board_game[i][j - 1] != -player_id || board_game[i][j + 5] != -player_id)) {
							if (board_game[x][y - 1] == -player_id) {
								return Point(i, j + 5);
							}
							if (board_game[x][y + 1] == -player_id) {
								return Point(i, j - 1);
							}
							return Point(x, y);
						}
					}
					else if (j - 1 > -1) {
						if (unit == 4 && board_game[i][j - 1] != -player_id) {
							if (y + 1 == 50) {
								return Point(i, j - 1);
							}
							return Point(x, y);
						}
					}
					else if (j + 5 < 50) {
						if (unit == 4 && board_game[i][j + 5] != -player_id) {
							if (y - 1 == -1) {
								return Point(i, j + 5);
							}
							return Point(x, y);
						}
					}
				}
			}
			unit = 0;
			for (int up_col = 0; i + up_col < 30; up_col++) {
				if (up_col == 5) {
					break;
				}
				if (board_game[i + up_col][j] == -player_id) {
					break;
				}
				else if (board_game[i + up_col][j] == player_id) {
					unit++;
				}
				else {
					x = i + up_col;
					y = j;
				}
				if (up_col == 4) {
					if (i - 1 > -1 && i + 5 < 30) {
						if (unit == 4 && (board_game[i - 1][j] != -player_id || board_game[i + 5][j] != -player_id)) {
							if (board_game[x - 1][y] == -player_id) {
								return Point(i + 5, j);
							}
							if (board_game[x + 1][y] == -player_id) {
								return Point(i - 1, j);
							}
							return Point(x, y);
						}
					}
					else if (i - 1 > -1) {
						if (unit == 4 && board_game[i - 1][j] != -player_id) {
							if (x + 1 == 30)
								return Point(i - 1, j);
							return Point(x, y);
						}
					}
					else if (i + 5 < 30) {
						if (unit == 4 && board_game[i + 5][j] != -player_id) {
							if (x - 1 == -1)
								return Point(i + 5, j);
							return Point(x, y);
						}
					}
				}
			}
			unit = 0;
			for (int up_cross = 0; i + up_cross < 30 && j + up_cross < 50; up_cross++) {
				if (up_cross == 5) {
					break;
				}
				if (board_game[i + up_cross][j + up_cross] == -player_id) {
					break;
				}
				else if (board_game[i + up_cross][j + up_cross] == player_id) {
					unit++;
				}
				else {
					x = i + up_cross;
					y = j + up_cross;
				}
				if (up_cross == 4) {
					if (i - 1 > -1 && i + 5 < 30 && j - 1 > -1 && j + 5 < 50) {
						if (unit == 4 && (board_game[i - 1][j - 1] != -player_id || board_game[i + 5][j + 5] != -player_id)) {
							if (board_game[x - 1][y - 1] == -player_id) {
								return Point(i + 5, j + 5);
							}
							if (board_game[x + 1][y + 1] == -player_id) {
								return Point(i - 1, j - 1);
							}
							return Point(x, y);
						}
					}
					else if (i - 1 > -1 && j - 1 > -1) {
						if (unit == 4 && board_game[i - 1][j - 1] != -player_id) {
							if (x + 1 == 30 || y + 1 == 50)
								return Point(i - 1, j - 1);
							return Point(x, y);
						}
					}
					else if (i + 5 < 30 && j + 5 < 50) {
						if (unit == 4 && board_game[i + 5][j + 5] != -player_id) {
							if (x - 1 == -1 || y - 1 == -1)
								return Point(i + 5, j + 5);
							return Point(x, y);
						}
					}
				}
			}
			unit = 0;
			for (int up_cross = 0; i - up_cross > -1 && j + up_cross < 50; up_cross++) {
				if (up_cross == 5) {
					break;
				}
				if (board_game[i - up_cross][j + up_cross] == -player_id) {
					break;
				}
				else if (board_game[i - up_cross][j + up_cross] == player_id) {
					unit++;
				}
				else {
					x = i - up_cross;
					y = j + up_cross;
				}
				if (up_cross == 4) {
					if (i + 1 < 30 && i - 5 > -1 && j - 1 > -1 && j + 5 < 50) {
						if (unit == 4 && (board_game[i + 1][j - 1] != -player_id || board_game[i - 5][j + 5] != -player_id)) {
							if (board_game[x + 1][y - 1] == -player_id) {
								return Point(i - 5, j + 5);
							}
							if (board_game[x - 1][y + 1] == -player_id) {
								return Point(i + 1, j - 1);
							}
							return Point(x, y);
						}
					}
					else if (i + 1 < 30 && j - 1 > -1) {
						if (unit == 4 && board_game[i + 1][j - 1] != -player_id) {
							if (x - 1 == -1 || y + 1 == 50);
								return Point(i + 1, j - 1);
							return Point(x, y);
						}
					}
					else if (i - 5 > -1 && j + 5 < 50) {
						if (unit == 4 && board_game[i - 5][j + 5] != -player_id) {
							if (x + 1 == 30 || y - 1 == -1)
								return Point(i - 5, j + 5);
							return Point(x, y);
						}
					}
				}
			}
		}
	}
	return Point(-1, -1);
}
Point attack(int board_game[][WIDTH], int player_id) {
	long value_max = 0;
	int x;
	int y;
	for (int m = 0; m < 30; m++) {
		for (int n = 0; n < 50; n++) {
			if (board_game[m][n] == 0) {
				long v = value(board_game, player_id, m, n);
				if (v > value_max) {
					value_max = v;
					x = m;
					y = n;
				}
			}
		}
	}
	return Point(x, y);
}
Point check_n_tile(int board_game[][WIDTH], int player_id, int n) {
	return Point(-1, -1);
}

// player_id = 1 || -1
Point player_rand(int board_game[][WIDTH], int player_id) {
	int row, col;
	row = rand() % HEIGHT;
	col = rand() % WIDTH;
	return Point(row, col);
}

Point player_baseline(int board_game[][WIDTH], int player_id) {
	// Đánh 2 nước đầu vào khu vực chính giữa
	if (board_game[14][24] == 0) {
		return Point(14, 24);
	}
	//
	Point p = check_win(board_game, player_id);// đánh vào nước thứ 5 không bị chặn 1 trong 2 đầu để chiến thắng
	if (p.x != -1 && p.y != -1) {
		winner = player_id;
		return p;
	}
	else {
		p = defend(board_game, player_id);// đánh vào nước thứ 5 không bị chặn 1 trong 2 đầu của đối phương để không thua
		if (p.x != -1 && p.y != -1) {
			return p;
		}
		else {
			return attack(board_game, player_id);// đánh vào nước có value cao nhất
			//return player_rand(board_game, player_id);
		}
	}
}

#endif // BOTBASELINE
